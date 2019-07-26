//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "Log.hpp"
#include "Time.hpp"
#include "Mesh.hpp"
#include "Grid.hpp"
#include "Input.hpp"
#include "Paths.hpp"
#include "Touch.hpp"
#include "Event.hpp"
#include "Scene.hpp"
#include "Assets.hpp"
#include "System.hpp"
#include "Camera.hpp"
#include "Buffer.hpp"
#include "Screen.hpp"
#include "Sprites.hpp"
#include "LogData.hpp"
#include "Keyboard.hpp"
#include "RootView.hpp"
#include "ImageView.hpp"
#include "GLWrapper.hpp"
#include "TestEngine.hpp"
#include "TEUIDrawer.hpp"
#include "ImageConfig.hpp"
#include "GlobalEvents.hpp"
#include "TEImageLoader.hpp"
#include "ModelImporter.hpp"
#include "DebugInfoView.hpp"
#include "TESceneDrawer.hpp"
#include "TEModelDrawer.hpp"
#include "TESpriteDrawer.hpp"
#include "TestSlidersView.hpp"
#include "BufferConfiguration.hpp"

using namespace gm;
using namespace te;

void Screen::_initialize_gl() {
	GL::initialize(size);
	Assets::initialize();
}

void Screen::_initialize_ui() {

	ui::config::set_drawer(new TEUIDrawer());
	ui::config::default_font =
		new ui::Font((Paths::fonts() / "SF.otf").string());

	_root_view = new te::RootView(Rect{ Screen::size });
	_root_view->_setup();

#ifdef DEBUG_VIEW
	debug_view = new DebugInfoView({ 400, 108 });
	debug_view->_setup();
#endif
}

void Screen::_initialize_sprites() {
	sprites::config::set_drawer(new TESpriteDrawer());
}

void Screen::_initialize_scene() {
	scene::config::set_drawer(new TESceneDrawer());
}

void Screen::_initialize_image() {
	image::config::set_loader(new TEImageLoader());
}

void Screen::initialize(const gm::Size& size) {

	std::srand(static_cast<unsigned int>(time(nullptr)));

	Screen::size = size;
	_initialize_image();
	_initialize_gl();
	_initialize_ui();
	_initialize_sprites();
	_initialize_scene();
	Screen::set_size(size);
	GL::on_window_size_change.subscribe([&](gm::Size size) {
		Screen::set_size(size);
	});
	GL::start_main_loop([&] {
		update();
	});
}

void Screen::update() {

	GL::set_clear_color(clear_color);
	GL::clear();

	GL::set_viewport({ size });

	GL::enable_depth_test();

	if (_scene) {
		_scene->update();
		_scene->draw();
	}

	GL::disable_depth_test();

	_root_view->_draw();

#ifdef DEBUG_VIEW
	debug_view->_draw();
#endif

	FPS = 1000000000 / Time::interval();

	Screen::frames_drawn++;
	Events::frame_drawn();
#ifdef MAC_OS
	System::sleep(0.03f);
#endif
}


void Screen::setup_input() {

	ui::Keyboard::on_key_event.subscribe([&](ui::Keyboard::Key key, ui::Keyboard::Event event) {

		if (event == ui::Keyboard::Event::Up) {
			_scene->camera->stop();
			return;
		}

		if (key == 'W')
			_scene->camera->fly(scene::Flyable::Direction::Forward);

		if (key == 'S')
			_scene->camera->fly(scene::Flyable::Direction::Back);

		if (key == 'A')
			_scene->camera->fly(scene::Flyable::Direction::Left);

		if (key == 'D')
			_scene->camera->fly(scene::Flyable::Direction::Right);

		if (key == 'E')
			_scene->camera->fly(scene::Flyable::Direction::Up);

		if (key == 'Q')
			_scene->camera->fly(scene::Flyable::Direction::Down);
	});

#if DESKTOP_BUILD

	GL::on_mouse_key_pressed.subscribe([&](GL::MouseButton button, GL::ButtonState state) {
		auto ui_button = ui::Mouse::Button::Left;
		if (button == GL::MouseButton::Right) ui_button = ui::Mouse::Button::Right;
		else if (button == GL::MouseButton::Middle) ui_button = ui::Mouse::Button::Middle;
		ui::input::mouse->set_button_state(ui_button,
			state == GL::ButtonState::Down ?
			ui::Mouse::ButtonState::Down :
			ui::Mouse::ButtonState::Up);
	});

	GL::on_cursor_moved.subscribe([&](gm::Point position) {
		ui::input::mouse->set_position(position);
		if (ui::Mouse::button_state == ui::Mouse::ButtonState::Down && ui::Mouse::button == ui::Mouse::Button::Left) {
			auto shift = ui::Mouse::frame_shift;
			shift.invert();
			_scene->camera->move_orbit(shift / 200);
		}
	});

	GL::on_scroll_moved.subscribe([&](gm::Point position) {
		_scene->camera->move_orbit(position / 50);
	});

	GL::on_key_pressed.subscribe([&](char key, unsigned int state) {
		ui::Keyboard::add_key_event(key, static_cast<ui::Keyboard::Event>(state));
	});

#endif
}

void Screen::set_size(const gm::Size& size) {
	Screen::size = size;
	GL::screen_size = size;
	GL::set_viewport(size);
	GL::clear();
	Events::on_screen_size_change(size);
	_root_view->set_frame({ size });
	if (_scene)
		_scene->camera->resolution = size;
	update();
}

void Screen::set_scene(scene::Scene* scene) {
	if (scene) {
		_scene = scene;
		_scene->setup();
		_scene->camera->resolution = size;
	}
}

scene::Scene* Screen::scene() const {
	return _scene;
}

te::RootView* Screen::root_view() const {
	return _root_view;
}
