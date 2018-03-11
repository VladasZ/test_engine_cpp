//
//  View.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "View.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"
#include "Window.hpp"

View::View(float x, float y, float width, float height) : frame(Rect(x, y, width, height)) { }
View::View(float width, float height) : View(0, 0, width, height) { }
View::View(const Size &size) : View(0, 0, size.width, size.height) { }
View::View(const Rect &rect) : frame(rect) { }
View::~View() { if (buffer != nullptr) delete buffer; }

BufferData * View::getBufferData() {
    return absoluteFrame().getData();
}

Rect View::absoluteFrame() const {
    Rect aFrame = frame;
    View *superview = this->superview;
    while (superview != nullptr) {
        aFrame.origin += superview->frame.origin;
        superview = superview->superview;
    }
    return aFrame;
}

void View::drawSubviews() const {
    if (subviews.empty()) return;
    for (auto subview : subviews) subview->draw();
}

void View::draw() {
    Shader::ui.use();
    Shader::ui.setUniformColor(color);
    buffer->draw();
    drawSubviews();
}

void View::layout() {
        
    if (autolayoutMask == Autolayout::None) {
        setupBuffer();
        for (auto subview : subviews) subview->layout();
        return;
    }
    
    Rect parentFrame;
    Rect layoutFrame = frame;
    
    if (superview == nullptr) parentFrame = Rect(Window::size.width, Window::size.height);
    else parentFrame = superview->frame;
    
    if (autolayoutMask & Autolayout::StickToLeft)
        layoutFrame.origin.x = 0;
    
    if (autolayoutMask & Autolayout::StickToRight)
        layoutFrame.origin.x = parentFrame.size.width - frame.size.width;
    
    if (autolayoutMask & Autolayout::StickToTop)
        layoutFrame.origin.y = 0;
    
    if (autolayoutMask & Autolayout::StickToBottom)
        layoutFrame.origin.y = parentFrame.size.height - frame.size.height;

    if (autolayoutMask & Autolayout::Center) {
        layoutFrame.origin.x = parentFrame.size.width / 2 - frame.size.width / 2;
        layoutFrame.origin.y = parentFrame.size.height / 2 - frame.size.height / 2;
    }
    
    if (autolayoutMask & Autolayout::CenterHorizontally)
        layoutFrame.origin.x = parentFrame.size.width / 2 - frame.size.width / 2;

    if (autolayoutMask & Autolayout::CenterVertically)
        layoutFrame.origin.y = parentFrame.size.height / 2 - frame.size.height / 2;
    
    if (autolayoutMask & Autolayout::Background)
        layoutFrame = parentFrame.withZeroOrigin();

    this->frame = layoutFrame;
    
    setupBuffer();
    
    for (auto subview : subviews) subview->layout();
}

void View::setFrame(const Rect &frame) {
    this->frame = frame;
    layout();
}

void View::setCenter(const Point &center) {
    setFrame(Rect(center.x - frame.size.width / 2,
                  center.y - frame.size.height / 2,
                  frame.size.width,
                  frame.size.height));
}

void View::addSubview(View *view) {
    subviews.push_back(view);
    view->superview = this;
    view->setup();
}

void View::insertSubviewAt(int position, View *view) {
    subviews.insert(subviews.begin() + position, view);
    view->superview = this;
    view->setup();
}

void View::removeAllSubviews() {
    for(auto view : subviews) {
        view->removeAllSubviews();
        delete view;
    }
    subviews.clear();
}

#if MEMORY_BENCHMARK
void View::addTestViews() {
    
    if (subviews.empty()) {
        
        Size size = frame.size / 2.05;
        Color color = Color::random();
        
        auto view1 = new View(size);
        auto view2 = new View(size);
        auto view3 = new View(size);
        auto view4 = new View(size);
        
        view1->autolayoutMask = StickToTop | StickToLeft;
        view2->autolayoutMask = StickToTop | StickToRight;
        view3->autolayoutMask = StickToBottom | StickToLeft;
        view4->autolayoutMask = StickToBottom | StickToRight;
        
        view1->color = color;
        view2->color = color;
        view3->color = color;
        view4->color = color;
        
        addSubview(view1);
        addSubview(view2);
        addSubview(view3);
        addSubview(view4);
        return;
    }
    
    for(auto view : subviews) {
        view->addTestViews();
    }
}
#endif
