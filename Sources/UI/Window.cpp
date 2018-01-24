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

Label *label;
Label *fpsLabel;
Label *allocatedLabel;
Label *deletedLabel;
Label *existsLabel;


void Window::setup() {
    rootView = new View(0, 0, Window::size.width, Window::size.height);
    
    fpsLabel       = new Label(0,  0, 0, 30);
    allocatedLabel = new Label(0, 40, 0, 30);
    deletedLabel   = new Label(0, 80, 0, 30);
    existsLabel    = new Label(0, 120, 0, 30);

    labelContentView->color = Color::green;
    
    label = new Label(400, 200);
    label->setText("");
    label->color = Color::blue;
    
    labelContentView->addSubview(label);
    
    rootView->addSubview(labelContentView);
    rootView->addSubview(fpsLabel);
    rootView->addSubview(allocatedLabel);
    rootView->addSubview(deletedLabel);
    rootView->addSubview(existsLabel);
    rootView->layout();
    
}

void Window::on30FramesDrawn() {
    fpsLabel->setText(string("FPS: ") + to_string(Window::FPS));
    allocatedLabel->setText(string("Objects allocated: ") + to_string(MemoryManager::totalObjectsAllocated));
    deletedLabel->setText(string("Objects deleted: ") + to_string(MemoryManager::totalObjectsDeleted));
    existsLabel->setText(string("Objects exist: " + to_string(MemoryManager::totalObjectsExist())));
}

void Window::update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rootView->drawSubviews();
    
    FPS = 1000000000 / Time::interval();
    
    
    Window::framesDrawn++;
    
    if (Window::framesDrawn % 5 == 0) on30FramesDrawn();
}

void Window::sizeChanged(GLFWwindow* window, int width, int height) {
    
    cout << "Window size changed to: " << width << " " << height << endl;
    
    Window::size.width  = width;
    Window::size.height = height;
    
    Shader::setupUiTranslation();
    rootView->frame = Rect(width, height);
    rootView->layout();
}

void Window::onCharacterInput(const char &ch) {
    label->setText(label->text() + ch);
}

void Window::onKeyPressed(const int &key) {
    if (key == 259//GLFW_KEY_BACKSPACE
        ) {
        auto string = label->text();
        string.pop_back();
        label->setText(string);
    }
}

void Window::touchBegan(const TestEngine::Point &position) {
    
    cout << position.toString() << endl;
    Window::didTouch(position.x, position.y);
}

void Window::touchMoved(const TestEngine::Point &position) {
    
}
