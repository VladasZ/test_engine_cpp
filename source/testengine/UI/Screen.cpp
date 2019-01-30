//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace std;

#include "ui.hpp"
#include "GL.hpp"
#include "Log.hpp"
#include "Box.hpp"
#include "Time.hpp"
#include "Mesh.hpp"
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
#include "RootView.hpp"
#include "TEDrawer.hpp"
#include "ColoredMesh.hpp"
#include "GlobalEvents.hpp"
#include "DebugInfoView.hpp"
#include "TestSlidersView.hpp"
#include "BufferConfiguration.hpp"

#if GLFW

static void size_changed(GLFWwindow* window, int width, int height);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double x, double y);

#endif

static scene::Scene* _scene;
static scene::Box*   box;
static Buffer*       box_buffer;


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
    //display_resolution *= 2;
    
    Log("Screen resolution: " << display_resolution.to_string());


    int width;
    int height;
    glfwGetFramebufferSize(glfw_window, &width, &height);
    
    Logvar(width);
    Logvar(height);
    
#endif

    //GL(glEnable(GL_DEPTH_TEST));
    GL(glEnable(GL_BLEND));
    //GL(glEnable(GL_ALPHA_TEST));
    GL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    GL(glDisable(GL_DEPTH_TEST));
   // GL(glLineWidth(1000));


    ui::config::set_drawer(new te::Drawer());
    ui::config::default_font = new ui::Font(Paths::fonts_directory() + "SF.otf");

    ui::Input::on_touch_event([](ui::Touch* touch) {
        Events::touch(touch);
    });

    Shader::initialize();
    Buffer::initialize(display_resolution, size);
    Events::on_screen_size_change(display_resolution);

    setup();

    _scene = new scene::Scene();
    _scene->camera->fov = 1;

    box = new scene::Box(0.2f);
    _scene->add_object(box);
    box->refresh_mesh();
    box->calculate_mvp_matrix();


    box_buffer = new Buffer(box->mesh());

    static const float fov_multiplier = 10.0f;

    TestSlidersView::view._box_position_view->multiplier = 1.0f;

    TestSlidersView::view._box_position_view->on_change.subscribe([&](Vector3 position) {
        box->position = position;
        box->calculate_mvp_matrix();
        cout << log_data<float>(16, box->mvp_matrix()) << endl;
        cout << log_data<float>(16, box->model_matrix()) << endl;
        cout << box->position.to_string() << endl;
    });

    TestSlidersView::view._fov_view->on_value_changed.subscribe([&](float value) {
        _scene->camera->fov = value * fov_multiplier;
        box->calculate_mvp_matrix();
        cout << log_data<float>(16, box->mvp_matrix()) << endl;
        cout << log_data<float>(16, box->model_matrix()) << endl;

    });

    TestSlidersView::view._box_rotation_view->on_change.subscribe([&](Vector3 rotation) {
        box->rotation.x = rotation.x;
        box->rotation.y = rotation.y;
        box->rotation.z = rotation.z;
        box->calculate_mvp_matrix();
        cout << log_data<float>(16, box->mvp_matrix()) << endl;
        cout << log_data<float>(16, box->model_matrix()) << endl;
        cout << box->rotation.to_string() << endl;
        cout << rotation.to_string() << endl;
    });

    TestSlidersView::view._box_angle_view->on_value_changed.subscribe([&](float angle) {
        box->rotation.w = angle;
        box->calculate_mvp_matrix();
        cout << log_data<float>(16, box->mvp_matrix()) << endl;
        cout << log_data<float>(16, box->model_matrix()) << endl;
    });


    Info(box->mesh()->to_string());
    Endl;
    Info(box_buffer->to_string());

    glm::mat4 mat;

    Info(log_data<float>(16, mat));


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
    GL::set_viewport({ size });
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

#ifdef DEBUG_VIEW
    debug_view->_draw();
#endif



    scene::Box* box = static_cast<scene::Box*>(_scene->_objects[0]);

    Shader::colored3D.use();
    Shader::colored3D.set_mvp_matrix(box->mvp_matrix());
    box_buffer->draw();

    GL::set_viewport({ size });

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
