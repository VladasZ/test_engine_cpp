//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ui.hpp"

#include "Log.hpp"
#include "Screen.hpp"
#include "GL.hpp"
#include "RootView.hpp"
#include "Time.hpp"
#include "FrameBuffer.hpp"
#include "GlobalEvents.hpp"
#include "Scene.hpp"
#include "Buffer.hpp"
#include "View.hpp"
#include "TestEngineDrawer.hpp"
#include "ImageView.hpp"
#include "Window.hpp"

static void size_changed(GLFWwindow* window, int width, int height);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double x, double y);

static ui::Window* new_view = nullptr;
static ui::ImageView* new_image_view = nullptr;

void Screen::initialize(int width, int height) {

    size = ui::Size(static_cast<float>(width), static_cast<float>(height));

#if GLFW

    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 16); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

#ifdef MAC_OS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
#endif

    glfw_window = glfwCreateWindow(width, height, "Test Engine", nullptr, nullptr);

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
    if (glewInit()) {
        Error("Glew initialization failed");
		throw "Glew initialization failed";
    }

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    display_resolution = { static_cast<float>(mode->width), static_cast<float>(mode->height) };
    
    Log("Screen resolution: " << static_cast<int>(display_resolution.width) << "x" << static_cast<int>(display_resolution.height));

#endif

    //GL(glEnable(GL_DEPTH_TEST));
    GL(glEnable(GL_BLEND));
    //GL(glEnable(GL_ALPHA_TEST));
    GL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
   // GL(glLineWidth(1000));
    
   // OldInput::initialize();
    Shader::initialize();
    Image::initialize();
    Font::initialize();
    Buffer::initialize();

    root_frame_buffer = new FrameBuffer(display_resolution);

    ui::config::set_drawer(new TestEngineDrawer());

    setup(); 

    Events::on_screen_size_change(display_resolution);
}

void Screen::setup() {

    new_view = new ui::Window({ 100, 300, 200, 200 });
	new_view->color = ui::Color::green;

	new_image_view = new ui::ImageView({ 10, 10, 100, 100 }, Image::cat);
	new_image_view->set_content_mode(ui::ImageView::ContentMode::AspectFit);

	new_view->add_subview(new_image_view);

    root_view = new RootView({ Screen::size.width, Screen::size.height });
	root_view->_frame_buffer = root_frame_buffer;
    root_view->setup();
    root_view->layout();
    root_view->_frame_buffer->clear();

	//setScene(new Scene());
}

void Screen::update() {
    GL::set_clear_color(ui::C::gray);
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

	if (current_scene) {
		GL(glEnable(GL_DEPTH_TEST));
		current_scene->draw();
	}

	GL(glDisable(GL_DEPTH_TEST));

    root_frame_buffer->clear();
    root_view->draw();

	new_view->draw();


    GL(glViewport(0, 0, static_cast<GLsizei>(size.width), static_cast<GLsizei>(size.height)));

    GL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    GL(glViewport(0, 0, static_cast<GLsizei>(size.width), static_cast<GLsizei>(size.height)));
    Shader::ui_texture.use();
    root_frame_buffer->get_image()->bind();
    Buffer::root_ui_buffer->draw();
    GL(glBindTexture(GL_TEXTURE_2D, 0));

    FPS = 1000000000 / Time::interval();

    Screen::frames_drawn++;
	Events::frame_drawn();
}

void Screen::set_scene(Scene* scene) {
	scene->setup();
	current_scene = scene;
}

#ifdef GLFW

static void size_changed(GLFWwindow* window, int width, int height) {
    Screen::size = ui::Size(static_cast<float>(width), static_cast<float>(height));
    Screen::root_view->set_frame(ui::Rect(static_cast<float>(width), static_cast<float>(height)));
    Screen::root_frame_buffer->clear();
    Buffer::window_size_changed();
    Events::on_screen_size_change(Screen::size);
    Screen::update();
    GL(glfwSwapBuffers(window));
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button != GLFW_MOUSE_BUTTON_LEFT)
        return;
    if (action == GLFW_PRESS)
        ui::input::mouse->set_left_button_state(ui::Mouse::ButtonState::Down);
    else
        ui::input::mouse->set_left_button_state(ui::Mouse::ButtonState::Up);
}

static void cursor_position_callback(GLFWwindow* window, double x, double y) {
    ui::Point cursor_position = { static_cast<float>(x), static_cast<float>(y) };
    Events::cursor_moved(cursor_position);
    ui::input::mouse->position_changed(cursor_position);
}

#endif
