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
#include "ScrollView.hpp"
#include "Log.hpp"
#include "GL.hpp"

View::View(const Rect &rect) : frame { rect } { }

View::~View() { if (buffer != nullptr) delete buffer; }

BufferData * View::getBufferData() {
    _absoluteFrame = calculateAbsoluteFrame();
    static const Rect default_rect = {-1, -1, 2, 2};
    return default_rect.getData();
}

Rect View::calculateAbsoluteFrame() const {

    if (this->superview == nullptr) return frame;

    Rect aFrame = frame;
    View *superview = this->superview;

    while (superview != nullptr) {

        if (superview->_isScrollView()) {
            ScrollView *scrollView = (ScrollView *)superview;
            aFrame.origin -= scrollView->_content_offset;
        }

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
    glViewport(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    buffer->draw();
    drawSubviews();
}

void View::layout() {

    if (autolayoutMask == Autolayout::None) {
        setupBuffer();
        layoutSubviews();
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
    layoutSubviews();
}

void View::layoutSubviews() {
    for (auto subview : subviews) subview->layout();
}

void View::setFrame(const Rect &frame) {
    this->frame = frame;
    layout();
}

void View::setFrame(float x, float y, float width, float height) {
    this->frame = { x, y, width, height };
    layout();
}

void View::setCenter(const Point &center) {
    setFrame(center.x - frame.size.width / 2,
             center.y - frame.size.height / 2,
             frame.size.width,
             frame.size.height);
}

void View::setCenter(float x, float y) {
    setCenter(Point(x, y));
}

int View::getTouchID() const {
    return _touchID;
}

void View::addSubview(View *view) {
    subviews.emplace_back(view);
    view->superview = this;
    view->setup();
}

void View::insertSubviewAt(int position, View *view) {
    subviews.emplace(subviews.begin() + position, view);
    view->superview = this;
    view->setup();
}

void View::removeAllSubviews() {
    for (auto view : subviews) {
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

    for (auto view : subviews) {
        view->addTestViews();
    }
}
#endif

Point View::localPointFrom(const Point &point) const {
    return point - _absoluteFrame.origin;
}

bool View::containsGlobalPoint(const Point &point) const {
    return _absoluteFrame.contains(point);
}
