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
#include "FrameBuffer.hpp"
#include "Image.hpp"

View::View(const Rect &rect) : _frame { rect } { }

View::~View() {
    if (_layout != nullptr) delete _layout;
}

FrameBuffer * View::_getFrameBuffer() const {
    
    if (_frameBuffer != nullptr) return _frameBuffer;

    View * superview = this->superview;
    FrameBuffer *frameBuffer = nullptr;

    while (superview != nullptr && frameBuffer == nullptr) {
        frameBuffer = superview->_frameBuffer;
        superview = superview->superview;
    }

    return frameBuffer;
}

Rect View::_calculateAbsoluteFrame() const {

    if (this->superview == nullptr) return _frame;

    Rect result = _frame;
    View *superview = this->superview;

    while (superview != nullptr) {
        result.origin += superview->_frame.origin;
        superview = superview->superview;
    }

    return result;
}

Rect View::_calculateFrameInFrameBuffer() const {

    if (_frameBuffer != nullptr || this->superview == nullptr) return _frame;

    auto superview = this->superview;
    Rect result = _frame;

    while (superview != nullptr && superview->_frameBuffer == nullptr) {
        result.origin += superview->_frame.origin;
        superview = superview->superview;
    }

    return result;
}

void View::_setFramebuffer() {
    _frameBuffer = new FrameBuffer(_frame.size);
}

void View::drawSubviews() const {
    if (subviews.empty()) return;
    for (auto subview : subviews) subview->draw();
}

void View::draw() {

    if (_needsLayout) layout();

    if (_needsDraw) {
        _getFrameBuffer()->draw([&] {
            _frameInFrameBuffer.setViewport();
            Shader::ui.use();
            Shader::ui.setUniformColor(color);
            Buffer::fullscreen->draw();
        });
        _needsDraw = false;
    }

    drawSubviews();
}

void View::layout() {

  //  PING;

    if (!_needsLayout) {
        Warning("Layout called");
        return;
    }

    if (_layout != nullptr)
        for (auto& layout : *_layout)
            layout->_layout(this);

    _frameInFrameBuffer = _calculateFrameInFrameBuffer();

    if (_needsSubviewsLayout) {
        layoutSubviews();
        _needsSubviewsLayout = false;
    }
    _needsDraw = true;
}

void View::layoutSubviews() {
    for (auto subview : subviews) subview->layout();
}

View * View::setFrame(const Rect &frame) {
    _frame = frame;
    _needsLayout = true;
    _needsSubviewsLayout = _frame.size != frame.size;
    return this;
}

View * View::setSize(const Size &size) {
    _frame.size = size;
    _needsLayout = true;
    _needsSubviewsLayout = _frame.size != size;
    return this;
}

View * View::setOrigin(const Point &origin) {
    _frame.origin = origin;
    _needsLayout = true;
    return this;
}

View * View::setCenter(const Point &center) {
    this->_frame = {
        center.x - _frame.size.width / 2,
        center.y - _frame.size.height / 2,
        _frame.size.width,
        _frame.size.height
    };
    _needsLayout = true;
    return this;
}

View * View::edit(std::function<void(View *)> edit) {
    edit(this);
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
//        _layout = new Layout::Array(layout);
        return this;
    }

  //  _layout->append(layout);

    return this;
}

View * View::clone() const {
    View *view = new View(_frame);
    view->color = color;
    view->_layout = _layout;

    for (auto subView : subviews)
        view->addSubview(subView->clone());

    return view;
}

View * View::dummy(float width, float height) {
    View *view = new View({
        (float)System::random(100),
        (float)System::random(100),
        (float)System::random(100),
        (float)System::random(100)
        });

    view->color = Color::random();
    return view;
}

Point View::localPointFrom(const Point &point) const {
    return point - _absoluteFrame.origin;
}

bool View::containsGlobalPoint(const Point &point) const {
    return _absoluteFrame.contains(point);
}
