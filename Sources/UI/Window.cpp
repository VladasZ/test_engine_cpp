//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Window.hpp"
#include "UI.hpp"
#include "GL.hpp"

void sizeChanged(GLFWwindow* window, int width, int height);

#if GLFW
GLFWwindow * Window::window;
#endif

Size Window::size;
View * Window::rootView;
int Window::FPS = 0;
int Window::framesDrawn = 0;

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    Window::didTouch(xpos, ypos);
}

void Window::initialize(int width, int height) {
    
    size = Size(width, height);
    
#if GLFW
    
    glfwInit();
    
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
    
#if MAC_OS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
#endif
    
    window = glfwCreateWindow(width, height, "Test Engine", NULL, NULL);
    
    if (window == nullptr) { Error("GLFW window creation failed"); return; }
    
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, sizeChanged);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    
    glewExperimental = GL_TRUE;
    if (glewInit()) { Error("Glew initialization failed"); }
    
#endif
    
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    //glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    Input::initialize();
    Shader::initialize();
    Image::initialize();
    Font::initialize();
    
    glClearColor(0.5, 0.5, 0.5, 1);
    
    setup();
}

auto labelContentView = new View(10, 100, 600, 400);

void Window::didTouch(const int &x, const int &y) {    
    //greenView->setCenter(Point(x, y));
}

#if DEBUG_OUTPUT
DebugInfoView *debugInfoView;
#endif

void Window::setup() {
    rootView = new View(0, 0, Window::size.width, Window::size.height);
    
#if DEBUG_OUTPUT
    debugInfoView = new DebugInfoView();
    debugInfoView->layout();
#endif

    rootView->layout();
}

void Window::onDebugTick() {
    
#if MEMORY_BENCHMARK
    static int counter = 0;
    if (counter % 6 == 0) rootView->removeAllSubviews();    
    rootView->addTestViews();
    rootView->layout();
    counter++;
#endif
    
#if DEBUG_OUTPUT
    debugInfoView->update();
#endif

}

void Window::update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rootView->drawSubviews();
    
#if DEBUG_OUTPUT
    debugInfoView->draw();
#endif

    FPS = 1000000000 / Time::interval();
    
    Window::framesDrawn++;
    
    if (Window::framesDrawn % 1 == 0) onDebugTick();
}

void Window::sizeChanged(GLFWwindow* window, int width, int height) {
    Window::size = Size(width, height);
    Shader::setupUiTranslation();
    rootView->frame = Rect(Window::size);
    rootView->layout();
}

void Window::onCharacterInput(const char &ch) {
}

void Window::onKeyPressed(const int &key) {
    if (key == 259//GLFW_KEY_BACKSPACE
        ) {

    }
}

void Window::touchBegan(const TestEngine::Point &position) {
    cout << position.toString() << endl;
    Window::didTouch(position.x, position.y);
}

void Window::touchMoved(const TestEngine::Point &position) {
    
}
