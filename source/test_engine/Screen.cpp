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
#include "Dispatch.hpp"
#include "Keyboard.hpp"
#include "RootView.hpp"
#include "GLWrapper.hpp"
#include "TEUIDrawer.hpp"
#include "ImageConfig.hpp"
#include "GlobalEvents.hpp"
#include "TEImageLoader.hpp"
#include "TESceneDrawer.hpp"
#include "TESpriteDrawer.hpp"

using namespace gm;
using namespace te;
using namespace cu;
using namespace ui;
using namespace std;


void Screen::_initialize_ui() {

    ui::config::set_drawer(new TEUIDrawer());
    ui::config::default_font =
            //   new ui::Font(Paths::fonts / "DroidSansMono.ttf");
            new ui::Font(Paths::fonts / "SF.otf");

	ui::config::default_font = ui::config::default_font->with_size(24);

#ifdef USING_SPRITES
    sprite::config::set_drawer(new TESpriteDrawer());
#endif

    _root_view = new RootView();
    _root_view->setup();

    //debug_view = new DebugInfoView({ 400, 108 });
    //debug_view->setup();
}

float Screen::render_scale() {
    return GL::render_scale;
}

Screen::Screen(const gm::Size& _size) {

    size = _size;
    current = this;

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

    scene::config::set_drawer(new TESceneDrawer());

    GL::initialize(size);

    Assets::initialize();

    _initialize_ui();

    setup_input();

    set_size(size * GL::render_scale);

    GL::on_window_size_change = [this](gm::Size _size) {
        set_size(_size);
    };
}

#ifdef DESKTOP_BUILD
void Screen::start_main_loop() {
    Events::screen_did_appear();
    GL::start_main_loop([this] { update(); });
}
#endif

void Screen::update() const {

    Dispatch::execute_tasks();

    GL::set_clear_color(clear_color);
    GL::clear();

    GL::set_viewport(size);

    GL::enable_depth_test();

    if (_scene) {
        _scene->update(frame_time);
        _scene->draw();
    }

    GL::disable_depth_test();

    frame_time = Time::interval() / 1000000000.0f;
    FPS = 1.0f / frame_time;

#ifdef USING_SPRITES
    if (_level) {
        _level->update(frame_time);
        _level->draw();
    }
#endif

    if (_root_view) {
        _root_view->_draw();
    }

    GL::set_viewport({ size });

    if (debug_view) {
        debug_view->_draw();
    }

    Screen::frames_drawn++;
    Events::frame_drawn();

    //System::sleep(0.03f);
}


void Screen::setup_input() {

    ui::Keyboard::on_key_event = [this](ui::Key key, ui::Keyboard::Event event) {

        if (_scene == nullptr) {
            return;
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

#ifdef DESKTOP_BUILD

    ui::Input::on_ui_free_touch = [this](ui::Touch* touch) {
        if (!_scene) return;
        if (!touch->is_moved()) return;
#ifdef DESKTOP_BUILD
        if (!touch->is_right_click()) return;
#endif
        static int prev_id = ui::Touch::no_id;
        if (touch->id == prev_id) {
            _scene->camera->move_orbit((ui::Mouse::frame_shift) / 200);
        }
        prev_id = touch->id;
    };

    GL::on_mouse_key_pressed = [](GL::MouseButton button, GL::ButtonState state) {
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

    GL::on_cursor_moved = [](gm::Point position) {
        ui::input::mouse->set_position(position * GL::render_scale);
    };

    GL::on_scroll_moved = [this](gm::Point position) {
        _scene->camera->zoom(position.y);
    };

    GL::on_key_pressed = [](auto key, auto mod, auto state) {
        ui::Keyboard::add_key_event(key, static_cast<ui::Keyboard::Mod>(mod), static_cast<ui::Keyboard::Event>(state));
    };

#endif
}

void Screen::set_size(const gm::Size& _size) const {
    size = _size;
    GL::window_size = size;
    GL::set_viewport(size);
    GL::clear();
    Assets::shaders->set_screen_resolution(size);
    _root_view->edit_frame() = size / GL::render_scale;
    if (_view) {
        _view->edit_frame() = size / GL::render_scale;
    }
    if (_scene) {
        _scene->camera->resolution = size;
    }
    Events::on_screen_size_change(size);
    update();
}

void Screen::set_scene(scene::Scene* scene) {
    if (_scene) {
        delete _scene;
        _scene = nullptr;
    }
    if (scene) {
        _scene = scene;
        scene->setup();
        _scene->camera->resolution = size;
    }
}

scene::Scene* Screen::scene() const {
    return _scene;
}

void Screen::set_view(ui::View* view) {
    _root_view->add_subview(view);
    _view = view;
    _view->edit_frame() = _root_view->frame();
}

#ifdef USING_SPRITES
void Screen::set_level(sprite::Level* level) {
    _level = level;
    _level->setup();
}

sprite::Level *Screen::level() const {
    return _level;
}
#endif

ui::View* Screen::view() const {
    return _view;
}

te::RootView* Screen::root_view() const {
    return _root_view;
}
