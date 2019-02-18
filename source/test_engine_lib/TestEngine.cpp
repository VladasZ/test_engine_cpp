//
//  TestEngine.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/13/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "GL.hpp"
#include "Mouse.hpp"
#include "Camera.hpp"
#include "Keyboard.hpp"
#include "TestEngine.hpp"
#include "GlobalEvents.hpp"

#if GLFW

static void size_changed(GLFWwindow* window, int width, int height);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double x, double y);
static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif

Screen TestEngine::screen;

void TestEngine::initialize(const Size& window_size) {

    std::srand(static_cast<unsigned int>(time(nullptr)));

    screen.initialize(window_size);

    glfwSetKeyCallback        (screen.glfw_window, key_callback            );
    glfwSetScrollCallback     (screen.glfw_window, scroll_callback         );
    glfwSetCursorPosCallback  (screen.glfw_window, cursor_position_callback);
    glfwSetWindowSizeCallback (screen.glfw_window, size_changed            );
    glfwSetMouseButtonCallback(screen.glfw_window, mouse_button_callback   );

}

void TestEngine::start_main_loop(std::function<void()> on_frame_drawn) {
    do {
        GL(glfwPollEvents());
        screen.update();
        if (on_frame_drawn)
            on_frame_drawn();
        GL(glfwSwapBuffers(screen.glfw_window));
    } while (
        glfwGetKey(screen.glfw_window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(screen.glfw_window) == 0
    );
}

#ifdef GLFW

static void size_changed(GLFWwindow* window, int width, int height) {
    Logvar(Point(width, height).to_string());
    TestEngine::screen.set_size({ static_cast<float>(width), static_cast<float>(height) });
    GL(glfwSwapBuffers(window));
}

static void mouse_button_callback([[maybe_unused]] GLFWwindow* window,
int glfw_button,
int action,
[[maybe_unused]] int mods) {
    auto button = ui::Mouse::Button::Left;

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
    TestEngine::screen.scene()->camera->move_orbit({ static_cast<float>(xoffset) / 50, static_cast<float>(yoffset) / 50 });
}

static void key_callback([[maybe_unused]] GLFWwindow* window,
int key,
int scancode,
int action,
int mods) {
    mods = scancode;
    ui::Keyboard::add_key_event(static_cast<ui::Keyboard::Key  >(key),
                                static_cast<ui::Keyboard::Event>(action));
}

#endif
