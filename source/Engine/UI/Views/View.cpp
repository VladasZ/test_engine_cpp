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
	removeAllSubviews();
    if (_layout != nullptr) delete _layout;
	if (_ownsFramebuffer) delete _frameBuffer;
}

Rect View::_calculateAbsoluteFrame() const {

    if (this->superview == nullptr) return _frame;

    Rect result = _frame;
    View* superview = this->superview;

    while (superview != nullptr) {
        result.origin += superview->_frame.origin;
        superview = superview->superview;
    }

    return result;
}

Rect View::_calculateFrameInFrameBuffer() const {

    if (this->superview == nullptr) return _frame;

    auto superview = this->superview;
    Rect result = _frame;

    while (!superview->_ownsFramebuffer) {
        result.origin += superview->_frame.origin;
		if (superview->superview == nullptr) break;
        superview = superview->superview;
    }

    return result;
}

View* View::_setFramebuffer() {
    _frameBuffer = new FrameBuffer(_frame.size);
	_ownsFramebuffer = true;
	return this;
}

void View::drawSubviews() const {
    for (auto subview : subviews) subview->draw();
}

void View::draw() {

    if (_needsLayout) layout();

	if (_color.isTransparent() && !DRAW_DEBUG_FRAMES) _needsDraw = false;

    if (_needsDraw) {
        _frameBuffer->draw([&] {
            if (_ownsFramebuffer) {
                GL::setViewport(_frame.withZeroOrigin());
            }
            else {
                GL::setViewport(_frameInFrameBuffer);
            }
            Shader::ui.use();
            Shader::ui.setUniformColor(_color);
            Buffer::fullscreen->draw();
#if DRAW_DEBUG_FRAMES
            Shader::ui.setUniformColor(C::turquoise);
            Buffer::fullscreenOutline->draw();
#endif
        });
        _needsDraw = false;
    }

    drawSubviews();
    
    
    if (_ownsFramebuffer) {
        superview->_frameBuffer->draw([&]{
            GL::setViewport(_frameInFrameBuffer);
            Shader::uiTexture.use();
            _frameBuffer->getImage()->bind();
            Buffer::fullscreenImage->draw();
            GL::unbindImage();
        });
    }
}

void View::layout() {

    if (!_needsLayout) { UNEXPECTED; return; }

    if (_layout != nullptr)
        for (auto& layout : *_layout)
            layout->_layout(this);

    _frameInFrameBuffer = _calculateFrameInFrameBuffer();
    _absoluteFrame = _calculateAbsoluteFrame();
    _needsDraw = true;
}

void View::layoutSubviews() {
    for (auto subview : subviews) subview->layout();
}

void View::_checkFramebuffers(View* view, FrameBuffer* framebuffer) {
	auto buffer = view->_ownsFramebuffer ? view->_frameBuffer : framebuffer;

	view->_frameBuffer = buffer;

	for (auto subview : view->subviews)
		_checkFramebuffers(subview, buffer);
}

View* View::setFrame(const Rect &frame) {
    _frame = frame;
    _needsLayout = true;
    return this;
}

View* View::setSize(const Size &size) {
    _frame.size = size;
    _needsLayout = true;
    return this;
}

View* View::setOrigin(const Point &origin) {
    _frame.origin = origin;
    superview->_needsDraw = true;
    return this;
}

View* View::setCenter(const Point &center) {
    this->_frame = {
        center.x - _frame.size.width / 2,
        center.y - _frame.size.height / 2,
        _frame.size.width,
        _frame.size.height
    };
    return this;
}

View* View::edit(std::function<void(View*)> edit) {
    edit(this);
    return this;
}

View* View::setX(float x) {
    _frame.origin.x = x;
    _needsLayout = true;
    return this;
}

View* View::setY(float y) {
    _frame.origin.y = y;
    _needsLayout = true;
    return this;
}

View* View::setWidth(float width) {
    _frame.size.width = width;
    _needsLayout = true;
    return this;
}

View* View::setHeight(float height) {
    _frame.size.height = height;
    _needsLayout = true;
    return this;
}

View* View::addSubview(View* view) {
    subviews.emplace_back(view);
    view->superview = this;
	if (_frameBuffer != nullptr)
		_checkFramebuffers(view, _frameBuffer);
	view->setup();
    return this;
}

void View::insertSubviewAt(int position, View* view) {
	subviews.insertAt(position, view);
    view->superview = this;
	if (_frameBuffer != nullptr)
		_checkFramebuffers(view, _frameBuffer);
    view->setup();
}

void View::removeAllSubviews() {
    for (auto view : subviews) delete view;
    subviews.clear();
}

View* View::setColor(const Color& color) {
    this->_color = color;
    return this;
}

View* View::_addLayout(const std::initializer_list<Layout::Base*> &layout) {
    if (_layout == nullptr) {
        _layout = new Layout::Arr(layout);
        return this;
    }

    _layout->append(layout);

    return this;
}

View* View::clone() const {
    View* view = new View(_frame);
    view->_color = _color;
    view->_layout = _layout;

    for (auto subView : subviews)
        view->addSubview(subView->clone());

    return view;
}

View* View::dummy(float width, float height) {
    View* view = new View({
        (float)System::random(100),
        (float)System::random(100),
        (float)System::random(100),
        (float)System::random(100)
        });

    view->_color = Color::random();
    return view;
}

Point View::localPointFrom(const Point &point) const {
    return point - _absoluteFrame.origin;
}

bool View::containsGlobalPoint(const Point &point) const {
    return _absoluteFrame.contains(point);
}
