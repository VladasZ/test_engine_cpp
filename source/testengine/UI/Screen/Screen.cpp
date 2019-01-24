//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ui.hpp"

#include "GL.hpp"
#include "Log.hpp"
#include "Box.hpp"
#include "Mesh.hpp"
#include "Time.hpp"
#include "Paths.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"
#include "Screen.hpp"
#include "Buffer.hpp"
#include "TEDrawer.hpp"
#include "RootView.hpp"
#include "GlobalEvents.hpp"
#include "DebugInfoView.hpp"
#include "BufferConfiguration.hpp"

#if GLFW

static void size_changed(GLFWwindow* window, int width, int height);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double x, double y);

#endif

void Screen::initialize(const Size& size) {

    Screen::size = size;

#if GLFW

    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 16); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

#ifdef MAC_OS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
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
    glfwSetMouseButtonCallback(glfw_window, mouse_button_callback);

    glfwSwapInterval(1); // Limit fps to 60
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    glewExperimental = GL_TRUE;

    if (glewInit())
        Fatal("Glew initialization failed");

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    display_resolution = { static_cast<float>(mode->width), static_cast<float>(mode->height) };
    
    Log("Screen resolution: " << static_cast<int>(display_resolution.width) << "x" << static_cast<int>(display_resolution.height));

#endif

    //GL(glEnable(GL_DEPTH_TEST));
    GL(glEnable(GL_BLEND));
    //GL(glEnable(GL_ALPHA_TEST));
    GL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    GL(glDisable(GL_DEPTH_TEST));
   // GL(glLineWidth(1000));

    ui::config::set_drawer(new te::Drawer());
    ui::config::default_font = new ui::Font(Paths::fonts_directory() + "SF.otf");

    ui::Input::on_touch_event([](ui::Touch* touch){
        Events::touch(touch);
    });

    Shader::initialize();
    Buffer::initialize(display_resolution, size);

    setup();

    scene::Scene sc;


    sc.camera->fov = 5;

    Events::on_screen_size_change(display_resolution);


    scene::Box box;

    Buffer buf { box.mesh(), BufferConfiguration::_3 };

    Info(box.mesh()->vertices.size());
    Info(box.mesh()->to_string());

    Info(buf.to_string());

}

void Screen::setup() {
    root_view = new te::RootView({ Screen::size });
    root_view->_setup();
    debug_view = new DebugInfoView({ 400, 108 });
    debug_view->_setup();
}

void Screen::update() {

    GL::set_clear_color(Color::gray);
    GL::set_viewport({ size });
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    root_view->_draw();
    debug_view->_draw();

    FPS = 1000000000 / Time::interval();

    Screen::frames_drawn++;
    Events::frame_drawn();
}

void Screen::set_size(const Size& size) {
    Screen::size = size;
    GL::set_viewport(size);
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    Buffer::window_size_changed(display_resolution, size);
    Events::on_screen_size_change(size);
    root_view->set_frame({ size });
    update();
}

#ifdef GLFW

static void size_changed(GLFWwindow* window, int width, int height) {
    Screen::set_size({ static_cast<float>(width), static_cast<float>(height) });
    GL(glfwSwapBuffers(window));
}

static void mouse_button_callback([[maybe_unused]] GLFWwindow* window, int button, int action, [[maybe_unused]] int mods) {
    if (button != GLFW_MOUSE_BUTTON_LEFT)
        return;
    if (action == GLFW_PRESS)
        ui::input::mouse->set_left_button_state(ui::Mouse::ButtonState::Down);
    else
        ui::input::mouse->set_left_button_state(ui::Mouse::ButtonState::Up);
}

static void cursor_position_callback([[maybe_unused]] GLFWwindow* window, double x, double y) {
    Point cursor_position = { static_cast<float>(x), static_cast<float>(y) };
    Events::cursor_moved(cursor_position);
    ui::input::mouse->position_changed(cursor_position);
}

#endif
