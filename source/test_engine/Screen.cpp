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
#include "Paths.hpp"
#include "Touch.hpp"
#include "Scene.hpp"
#include "Input.hpp"
#include "Assets.hpp"
#include "Camera.hpp"
#include "Screen.hpp"
#include "Sprites.hpp"
#include "Dispatch.hpp"
#include "Keyboard.hpp"
#include "RootView.hpp"
#include "TestView.hpp"
#include "GLWrapper.hpp"
#include "TEUIDrawer.hpp"
#include "ImageConfig.hpp"
#include "GlobalEvents.hpp"
#include "TEImageLoader.hpp"
#include "ModelImporter.hpp"
#include "TESceneDrawer.hpp"
#include "TESpriteDrawer.hpp"
#include "BufferConfiguration.hpp"

using namespace gm;
using namespace te;
using namespace cu;

void Screen::_initialize_ui() {

	ui::config::set_drawer(new TEUIDrawer());
	ui::config::default_font =
		new ui::Font(Paths::fonts() / "DroidSansMono.ttf");

	_root_view = new te::RootView(gm::Rect { Screen::size });
	_root_view->_setup();

#ifdef DEBUG_VIEW
	debug_view = new DebugInfoView({ 400, 108 });
	debug_view->_setup();
#endif
}

Screen::Screen(const gm::Size& size) {

#ifdef DEBUG
	static bool first = true;
	if (first) {
		first = false;
	}
	else {
		Fatal("Only one instance of Screen class is supported currently");
	}
#endif

	image::config::set_loader(new TEImageLoader());
#ifdef USING_BOX2D
	sprites::config::set_drawer(new TESpriteDrawer());
#endif
	scene::config::set_drawer(new TESceneDrawer());

	GL::initialize(size);

	Assets::initialize();

	_initialize_ui();

	setup_input();

	set_size(size);

	GL::on_window_size_change = [&](gm::Size size) {
		set_size(size);
	};
}

#ifdef DESKTOP_BUILD
void Screen::start_main_loop() {
	GL::start_main_loop([&] {
		update();
	});
}
#endif

void Screen::update() {

	GL::set_clear_color(clear_color);
	GL::clear();

	GL::set_viewport({ size });

	GL::enable_depth_test();

	if (_scene) {
		_scene->update(frame_time);
		_scene->draw();
	}

	GL::disable_depth_test();
    
#ifdef USING_BOX2D

	if (_level) {
		_level->update();
		_level->draw();
	}
    
#endif

	_root_view->_draw();

    GL::set_viewport({ size });

#ifdef DEBUG_VIEW
	debug_view->_draw();
#endif

	frame_time = Time::interval() / 1000000000.0f;
	FPS = 1.0f / frame_time;

    Screen::frames_drawn++;
	Events::frame_drawn();

    Dispatch::execute_tasks();

    //System::sleep(0.03f);
}


void Screen::setup_input() {

#ifndef DESKTOP_BUILD
    TestView::on_left_stick_move = [&](auto point) {
       // _scene->camera->velocity = point / 100;
    };
    
    TestView::on_right_stick_move = [&](auto point) {
       // _scene->camera->orbit_velocity = point / 100;
    };
#endif

	ui::Keyboard::on_key_event = [&](ui::Keyboard::Key key, ui::Keyboard::Event event) {

	    if (_scene == nullptr) {
            return;;
	    }

		if (event == ui::Keyboard::Event::Up) {
			_scene->camera->stop();
			return;
		}

		if (key == 'W') {
			_scene->camera->fly(scene::Flyable::Direction::Forward);
		}

		if (key == 'S') {
			_scene->camera->fly(scene::Flyable::Direction::Back);
		}

		if (key == 'A') {
			_scene->camera->fly(scene::Flyable::Direction::Left);
		}

		if (key == 'D') {
			_scene->camera->fly(scene::Flyable::Direction::Right);
		}

		if (key == 'E') {
			_scene->camera->fly(scene::Flyable::Direction::Up);
		}

		if (key == 'Q') {
			_scene->camera->fly(scene::Flyable::Direction::Down);
		}
	};

#if DESKTOP_BUILD

	ui::Input::on_right_button_drag = [&](ui::Touch* touch) {
		static ui::Touch::ID prev_id = -1;
		if (touch->id == prev_id) {
			_scene->camera->move_orbit((ui::Mouse::frame_shift) / 200);
		}
		prev_id = touch->id;
	};

	GL::on_mouse_key_pressed = [&](GL::MouseButton button, GL::ButtonState state) {
		auto ui_button = ui::Mouse::Button::Left;
		if (button == GL::MouseButton::Right) {
			ui_button = ui::Mouse::Button::Right;
		}
		else if (button == GL::MouseButton::Middle) {
			ui_button = ui::Mouse::Button::Middle;
		}
		ui::input::mouse->set_button_state(ui_button,
			state == GL::ButtonState::Down ?
			ui::Mouse::ButtonState::Down :
			ui::Mouse::ButtonState::Up);
	};

	GL::on_cursor_moved = [&](gm::Point position) {
		ui::input::mouse->set_position(position);
	};

	GL::on_scroll_moved = [&](gm::Point position) {
		_scene->camera->zoom(position.y);
	};

	GL::on_key_pressed = [&](char key, unsigned int state) {
		ui::Keyboard::add_key_event(key, static_cast<ui::Keyboard::Event>(state));
	};

#endif
}

void Screen::set_size(const gm::Size& size) {
	this->size = size;
	GL::window_size = size;
	GL::set_viewport(size);
	GL::clear();
	Assets::shaders->sprite->use();
	Assets::shaders->sprite->set_resolution(size);
	_root_view->edit_frame() = {size };
	if (_view) {
		_view->edit_frame() = {size };
    }
	if (_scene) {
        _scene->camera->resolution = size;
    }
	update();
	Events::on_screen_size_change(size);
}

void Screen::set_scene(scene::Scene* scene) {
	if (scene) {
		_scene = scene;
        _scene->_setup();
		_scene->camera->resolution = size;
		if (scene->view) {
		    set_view(scene->view);
		}
	}
}

scene::Scene* Screen::scene() const {
	return _scene;
}

#ifdef USING_BOX2D
void Screen::set_level(sprites::Level* level) {
	_level = level;
}

sprites::Level* Screen::level() const {
	return _level;
}
#endif

void Screen::set_view(ui::View* view) {
    _root_view->add_subview(view);
    _view = view;
	_view->edit_frame() = {size };
}

ui::View* Screen::view() const {
    return _view;
}

te::RootView* Screen::root_view() const {
	return _root_view;
}
