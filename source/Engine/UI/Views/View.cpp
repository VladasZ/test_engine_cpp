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
#include "Layout.hpp"

View::View(const Rect &rect) : _frame{ rect } { }

View::~View() {
    if (buffer != nullptr) delete buffer;
    if (_layout != nullptr) delete _layout;
}

BufferData * View::getBufferData() {
    _absoluteFrame = calculateAbsoluteFrame();
    static const Rect default_rect{ -1, -1,  2,  2 };
    return default_rect.getData();
}

Rect View::calculateAbsoluteFrame() const {

    if (this->superview == nullptr) return _frame;

    Rect aFrame = _frame;
    View *superview = this->superview;

    while (superview != nullptr) {

        if (superview->_isScrollView()) {
            ScrollView *scrollView = (ScrollView *)superview;
            aFrame.origin -= scrollView->_content_offset;
        }

        aFrame.origin += superview->_frame.origin;
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
    _absoluteFrame.setViewport();
    buffer->draw();
    drawSubviews();
}

void View::layout() {
    if (_layout != nullptr)
        for (auto& layout : *_layout)
            layout->_layout(this);

    setupBuffer();
    layoutSubviews();
}

void View::layoutSubviews() {
    for (auto subview : subviews) subview->layout();
}

View * View::setFrame(const Rect &frame) {
    _frame = frame;
    layout();
    return this;
}

View * View::setSize(const Size &size) {
    _frame.size = size;
    layout();
    return this;
}

View * View::setOrigin(const Point &origin) {
    _frame.origin = origin;
    layout();
    return this;
}

View * View::setCenter(const Point &center) {
    this->_frame = {
        center.x - _frame.size.width / 2,
        center.y - _frame.size.height / 2,
        _frame.size.width,
        _frame.size.height
    };
    layout();
    return this;
}

int View::getTouchID() const {
    return _touchID;
}

View * View::addSubview(View *view) {
    subviews.emplace_back(view);
    view->superview = this;
    view->setup();
    return this;
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

View * View::setColor(const Color& color) {
    this->color = color;
    return this;
}

View * View::_addLayout(const std::initializer_list<Layout::Base *> &layout) {
    if (_layout == nullptr) {
        _layout = new Layout::Array(layout);
        return this;
    }

    _layout->append(layout);

    return this;
}

View * View::dummy(float width, float height) {
    View *view = new View({ width, height });
    view->color = Color::random();
    return view;
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
