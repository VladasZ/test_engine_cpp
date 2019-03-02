//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#if DESKTOP_BUILD
#include "GLFW/glfw3native.h"
#endif

using namespace std;

#include                  "ui.hpp"
#include                 "Log.hpp"
#include                 "Box.hpp"
#include                "Time.hpp"
#include                "Mesh.hpp"
#include                "Grid.hpp"
#include               "Input.hpp"
#include               "Paths.hpp"
#include               "Touch.hpp"
#include               "Event.hpp"
#include               "Scene.hpp"
#include              "System.hpp"
#include              "Camera.hpp"
#include              "Buffer.hpp"
#include              "Screen.hpp"
#include             "LogData.hpp"
#include            "Keyboard.hpp"
#include            "RootView.hpp"
#include           "GLWrapper.hpp"
#include          "TestEngine.hpp"
#include          "TEUIDrawer.hpp"
#include         "ImageConfig.hpp"
#include        "GlobalEvents.hpp"
#include       "TEImageLoader.hpp"
#include       "ModelImporter.hpp"
#include       "DebugInfoView.hpp"
#include       "TESceneDrawer.hpp"
#include       "TEModelDrawer.hpp"
#include     "TestSlidersView.hpp"
#include "BufferConfiguration.hpp"

void Screen::_initialize_gl() {
    GL::initialize(size);
}

void Screen::_initialize_ui() {

    ui::config::set_drawer(new TEUIDrawer());
    ui::config::default_font = new ui::Font(Paths::fonts_directory() + "SF.otf");

    ui::Input::on_touch_event([](ui::Touch* touch) {
        Events::touch(touch);
    });

    Events::on_screen_size_change(display_resolution);

    _root_view = new te::RootView(Rect { Screen::size });
    _root_view->_setup();

#ifdef DEBUG_VIEW
    debug_view = new DebugInfoView({ 400, 108 });
    debug_view->_setup();
#endif

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
}

void Screen::_initialize_scene() {
    scene::config::drawer = new TESceneDrawer();
}

void Screen::_initialize_image() {
    image::config::set_loader(new TEImageLoader());
}

void Screen::initialize(const Size& size) {
    Screen::size = size;
    _initialize_gl();
    _initialize_image();
    _initialize_ui();
    _initialize_scene();
    Screen::set_size(size);
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
    
    System::sleep(0.03f);
}

void Screen::set_size(const Size& size) {
    Screen::size = size;
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
    }
}

scene::Scene* Screen::scene() const {
    return _scene;
}

te::RootView* Screen::root_view() const {
    return _root_view;
}
