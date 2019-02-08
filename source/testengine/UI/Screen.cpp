//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "GLFW/glfw3native.h"

using namespace std;

#include "ui.hpp"
#include "GL.hpp"
#include "Log.hpp"
#include "Box.hpp"
#include "Time.hpp"
#include "Mesh.hpp"
#include "Grid.hpp"
#include "Input.hpp"
#include "Paths.hpp"
#include "Touch.hpp"
#include "Event.hpp"
#include "Scene.hpp"
#include "System.hpp"
#include "Camera.hpp"
#include "Buffer.hpp"
#include "Screen.hpp"
#include "LogData.hpp"
#include "Keyboard.hpp"
#include "RootView.hpp"
#include "TEUIDrawer.hpp"
#include "ColoredMesh.hpp"
#include "GlobalEvents.hpp"
#include "DebugInfoView.hpp"
#include "TESceneDrawer.hpp"
#include "TEModelDrawer.hpp"
#include "TestSlidersView.hpp"
#include "BufferConfiguration.hpp"

#if GLFW

static void size_changed(GLFWwindow* window, int width, int height);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double x, double y);
static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif

static scene::Scene* _scene;

void Screen::initialize(const Size& size) {

    Screen::size = size;

#if GLFW

    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 16); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //We don't want the old OpenGL

#ifdef MAC_OS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // To make MacOS happy; should not be needed
#endif

    glfw_window = glfwCreateWindow(static_cast<int>(size.width),
                                   static_cast<int>(size.height),
                                   "Test Engine",
                                   nullptr,
                                   nullptr);

    if (glfw_window == nullptr) {
        Error("GLFW window creation failed");
		throw "GLFW window creation failed";
    }

    glfwMakeContextCurrent(glfw_window);

    glfwSetWindowSizeCallback(glfw_window, size_changed);

    glfwSetCursorPosCallback(glfw_window, cursor_position_callback);
    glfwSetScrollCallback(glfw_window, scroll_callback);
    glfwSetMouseButtonCallback(glfw_window, mouse_button_callback);
    glfwSetKeyCallback(glfw_window, key_callback);

    glfwSwapInterval(1); // Limit fps to 60
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);


    glewExperimental = GL_TRUE;

    if (glewInit())
        Fatal("Glew initialization failed");

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    display_resolution = { static_cast<float>(mode->width), static_cast<float>(mode->height) };
    //display_resolution *= 2;
    
    Log("Screen resolution: " << display_resolution.to_string());


    int width;
    int height;
    glfwGetFramebufferSize(glfw_window, &width, &height);
    
    Logvar(width);
    Logvar(height);
    
#endif

    GL(glEnable(GL_DEPTH_TEST));
    GL(glEnable(GL_BLEND));
    //GL(glEnable(GL_ALPHA_TEST));
    GL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
   // GL(glLineWidth(1000));


    ui::config::set_drawer(new te::Drawer());
    ui::config::default_font = new ui::Font(Paths::fonts_directory() + "SF.otf");

    ui::Input::on_touch_event([](ui::Touch* touch) {
        Events::touch(touch);
    });

    Shader::initialize();
    Buffer::initialize(display_resolution, size);
    Events::on_screen_size_change(display_resolution);

    scene::config::drawer = new TESceneDrawer();

    setup();

    _scene = new scene::Scene();
    _scene->camera->fov = 1;
    _scene->camera->set_position({ 0, -4, 1 });

    _scene->add_object(new scene::Box(2.0f, 2.0f, 0.1f));
    _scene->add_object(new scene::Box(1.0f, 1.0f, 1.1f));
    _scene->add_object(new scene::Grid({ 10, 10 }, { 20, 20 }));

//    TestSlidersView::view._box_position_view->multiplier = 1.0f;

//    TestSlidersView::view._box_position_view->on_change.subscribe([&](Vector3 position) {
//        box->set_position(position);
//    });

//    TestSlidersView::view._box_rotation_view->on_change.subscribe([&](Vector3 rotation) {
//        auto rot = grid->rotation();

//        rot.x = rotation.x;
//        rot.y = rotation.y;
//        rot.z = rotation.z;

//        grid->set_rotation(rot);
//    });

//    TestSlidersView::view._box_angle_view->
//            slider_view->on_value_changed.subscribe([&](float angle) {
//        auto rot = grid->rotation();
//        rot.w = angle;
//        grid->set_rotation(rot);
//    });

    ui::Keyboard::on_key_event.subscribe([&](ui::Keyboard::Key key, ui::Keyboard::Event event) {

        if (event == ui::Keyboard::Event::Up) {
            _scene->camera->stop();
            return;
        }

        if (key == 'W')
            _scene->camera->walk(scene::Walkable::Direction::Forward);

        if (key == 'S')
            _scene->camera->walk(scene::Walkable::Direction::Back);

        if (key == 'A')
            _scene->camera->walk(scene::Walkable::Direction::Left);

        if (key == 'D')
            _scene->camera->walk(scene::Walkable::Direction::Right);
    });

    Screen::set_size(size);

}

void Screen::setup() {
    root_view = new te::RootView({ Screen::size });
    root_view->_setup();
#ifdef DEBUG_VIEW
    debug_view = new DebugInfoView({ 400, 108 });
    debug_view->_setup();
#endif
}

void Screen::update() {

    GL::set_clear_color(Color::gray);
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

#ifdef DEBUG_VIEW
    debug_view->_draw();
#endif

    GL::set_viewport({ size });

    GL(glEnable(GL_DEPTH_TEST));

    _scene->update();
    _scene->draw();

    GL(glDisable(GL_DEPTH_TEST));

    root_view->_draw();

    FPS = 1000000000 / Time::interval();

    Screen::frames_drawn++;
    Events::frame_drawn();
    
    System::sleep(0.03f);
}

void Screen::set_size(const Size& size) {
    Screen::size = size;
    GL::set_viewport(size);
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    Buffer::window_size_changed(display_resolution, size);
    Events::on_screen_size_change(size);
    root_view->set_frame({ size });
    _scene->camera->resolution = size;
    update();
}

#ifdef GLFW

static void size_changed(GLFWwindow* window, int width, int height) {
    Screen::set_size({ static_cast<float>(width), static_cast<float>(height) });
    GL(glfwSwapBuffers(window));
}

static void mouse_button_callback([[maybe_unused]] GLFWwindow* window,
int glfw_button,
int action,
[[maybe_unused]] int mods) {
    auto button = ui::Mouse::Button::Left;

    Logvar(glfw_button);

    if (glfw_button == GLFW_MOUSE_BUTTON_RIGHT)
        button = ui::Mouse::Button::Right;
    else if (glfw_button == GLFW_MOUSE_BUTTON_MIDDLE)
        button = ui::Mouse::Button::Middle;

    ui::input::mouse->set_button_state(button,
                                       action == GLFW_PRESS ?
                                           ui::Mouse::ButtonState::Down :
                                           ui::Mouse::ButtonState::Up);
}

static void cursor_position_callback([[maybe_unused]] GLFWwindow* window, double x, double y) {
    Point cursor_position = { static_cast<float>(x), static_cast<float>(y) };
    Events::cursor_moved(cursor_position);
    ui::input::mouse->set_position(cursor_position);
}

static void scroll_callback([[maybe_unused]] GLFWwindow* window, double xoffset, double yoffset) {
    _scene->camera->move_orbit({ static_cast<float>(xoffset) / 50, static_cast<float>(yoffset) / 50 });
}

static void key_callback([[maybe_unused]] GLFWwindow* window,
int key,
int scancode,
int action,
int mods) {
    mods = scancode;
    ui::Keyboard::add_key_event(static_cast<ui::Keyboard::Key>(key),
                                static_cast<ui::Keyboard::Event>(action));
}

#endif
