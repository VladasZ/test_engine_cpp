//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Window.hpp"
#include "GL.hpp"
#include "RootView.hpp"
#include "World.hpp"
#include "Time.hpp"
#include "Log.hpp"
#include "FrameBuffer.hpp"
#include "GlobalEvents.hpp"
#include "Scene.hpp"
#include "Buffer.hpp"
#include "View.hpp"
#include "TestEngineDrawer.hpp"
#include "ui.hpp"

void sizeChanged(GLFWwindow* window, int width, int height);

ui::View* new_view = nullptr;
ui::ImageView* new_image_view = nullptr;
ui::ImageView* mouse_pointer = nullptr;

void Window::initialize(int width, int height) {

    size = ui::Size((float)width, (float)height);

#if GLFW

    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 16); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

#if MAC_OS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
#endif

    window = glfwCreateWindow(width, height, "Test Engine", NULL, NULL);

    if (window == nullptr) {
        Error("GLFW window creation failed");
		throw "GLFW window creation failed";
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, size_changed);
    glfwSwapInterval(1); // Limit fps to 60
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    glewExperimental = GL_TRUE;
    if (glewInit()) {
        Error("Glew initialization failed");
		throw "Glew initialization failed";
    }

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    screen_resolution = { (float)mode->width, (float)mode->height };
    
    Log("Screen resolution: " << (int)screen_resolution.width << "x" << (int)screen_resolution.height);

#endif

    //GL(glEnable(GL_DEPTH_TEST));
    GL(glEnable(GL_BLEND));
    //GL(glEnable(GL_ALPHA_TEST));
    GL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
   // GL(glLineWidth(1000));
    
    Input::initialize();
    Shader::initialize();
    Image::initialize();
    Font::initialize();
    Buffer::initialize();

    root_frame_buffer = new FrameBuffer(screen_resolution);

	ui::config::set_drawer(new TestEngineDrawer(root_frame_buffer));

    setup(); 

	Events::on_screen_size_change(screen_resolution);
}

void Window::setup() {

	new_view = new ui::View({ 100, 300, 200, 200 });
	new_view->color = ui::Color::green;

	new_image_view = new ui::ImageView({ 10, 10, 100, 100 }, Image::cat);
	new_image_view->set_content_mode(ui::ImageView::ContentMode::AspectFit);

	new_view->add_subview(new_image_view);

	float cursor_size = 0.11f;
	mouse_pointer = new ui::ImageView({ 0, 0, 200 * cursor_size, 200 * cursor_size }, Image::mouse_pointer);
	mouse_pointer->set_content_mode(ui::ImageView::ContentMode::AspectFit);
	Events::cursor_moved.subscribe([&](ui::Point position) {
		ui::View::Edge edge = new_image_view->get_edge(position);
		if (static_cast<bool>(edge))
			mouse_pointer->set_center(position);
		else
			mouse_pointer->set_origin(position);
		mouse_pointer->set_image(Image::for_edge(new_image_view->get_edge(position)));
	});



    root_view = new RootView({ Window::size.width, Window::size.height });
	root_view->_frame_buffer = root_frame_buffer;
    root_view->setup();
    root_view->layout();
    root_view->_frame_buffer->clear();

	//setScene(new Scene());
}

void Window::update() {
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

	//mouse_pointer->set_origin(Input::cursor_position);
	mouse_pointer->draw();

	GL(glViewport(0, 0, (GLsizei)size.width, (GLsizei)size.height));

    GL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
	GL(glViewport(0, 0, (GLsizei)size.width, (GLsizei)size.height));
    Shader::ui_texture.use();
    root_frame_buffer->get_image()->bind();
    Buffer::root_ui_buffer->draw();
    GL(glBindTexture(GL_TEXTURE_2D, 0));

    FPS = 1000000000 / Time::interval();

    Window::frames_drawn++;
	Events::frame_drawn();
}

void Window::set_scene(Scene* scene) {
	scene->setup();
	current_scene = scene;
}

void Window::size_changed(GLFWwindow* window, int width, int height) {
    Window::size = ui::Size((float)width, (float)height);
    root_view->set_frame(ui::Rect((float)width, (float)height));
    root_frame_buffer->clear();
    Buffer::window_size_changed();
	Events::on_screen_size_change(size);
    update();
    GL(glfwSwapBuffers(Window::window));
}
