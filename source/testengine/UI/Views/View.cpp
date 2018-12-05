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
#include "Random.hpp"

View::View(const Rect &rect) : _frame { rect } { }

View::~View() {
	remove_all_subviews();
    if (_layout) delete _layout;
	if (_owns_framebuffer) delete _frame_buffer;
	disable_touch();
}

Rect View::_calculate_absolute_frame() const {

    if (this->superview == nullptr) return _frame;

    Rect result = _frame;
    View* superview = this->superview;

    while (superview) {
        result.origin += superview->_frame.origin;
        superview = superview->superview;
    }

    return result;
}

Rect View::_calculate_frame_in_frame_buffer() const {

    if (this->superview == nullptr) return _frame;

    auto superview = this->superview;
    Rect result = _frame;

    while (!superview->_owns_framebuffer) {
        result.origin += superview->_frame.origin;
		if (superview->superview == nullptr) break;
        superview = superview->superview;
    }

    return result;
}

View* View::_set_framebuffer() {
    _frame_buffer = new FrameBuffer(_frame.size);
	_owns_framebuffer = true;
	return this;
}

void View::draw_subviews() const {
    for (auto subview : subviews) subview->draw();
}

void View::draw() {

    if (_needs_layout) layout();

	if (_color.is_transparent() && !DRAW_DEBUG_FRAMES) _need_draw = false;

    if (_need_draw) {
        _frame_buffer->draw([&] {
            if (_owns_framebuffer) {
                GL::setViewport(_frame.with_zero_origin());
            }
            else {
                GL::setViewport(_frame_in_frame_buffer);
            }
            Shader::ui.use();
            Shader::ui.setUniformColor(_color);
            Buffer::fullscreen->draw();
#if DRAW_DEBUG_FRAMES
            Shader::ui.setUniformColor(C::turquoise);
            Buffer::fullscreenOutline->draw();
#endif
        });
        _need_draw = false;
    }

    draw_subviews();
    
    
    if (_owns_framebuffer) {
        superview->_frame_buffer->draw([&]{
            GL::setViewport(_frame_in_frame_buffer);
            Shader::uiTexture.use();
            _frame_buffer->getImage()->bind();
            Buffer::fullscreenImage->draw();
            GL::unbindImage();
        });
    }
}

void View::layout() {

    if (!_needs_layout) { UNEXPECTED; return; }

    if (_layout)
        for (auto& layout : *_layout)
            layout->_layout(this);

    _frame_in_frame_buffer = _calculate_frame_in_frame_buffer();
    _absolute_frame = _calculate_absolute_frame();
    _need_draw = true;
}

void View::layout_subviews() {
    for (auto subview : subviews) subview->layout();
}

void View::_check_framebuffers(View* view, FrameBuffer* framebuffer) {
	auto buffer = view->_owns_framebuffer ? view->_frame_buffer : framebuffer;

	view->_frame_buffer = buffer;

	for (auto subview : view->subviews)
		_check_framebuffers(subview, buffer);
}

View* View::set_frame(const Rect &frame) {
    _frame = frame;
    _needs_layout = true;
    return this;
}

View* View::set_size(const Size &size) {
    _frame.size = size;
    _needs_layout = true;
    return this;
}

View* View::set_origin(const Point &origin) {
    _frame.origin = origin;
    superview->_need_draw = true;
    return this;
}

View* View::set_center(const Point &center) {
	this->_frame.origin.x = center.x - _frame.size.width / 2;
	this->_frame.origin.y = center.y - _frame.size.height / 2;
    return this;
}

View* View::edit(std::function<void(View*)> edit) {
    edit(this);
    return this;
}

View* View::set_x(float x) {
    _frame.origin.x = x;
    _needs_layout = true;
    return this;
}

View* View::set_y(float y) {
    _frame.origin.y = y;
    _needs_layout = true;
    return this;
}

View* View::set_width(float width) {
    _frame.size.width = width;
    _needs_layout = true;
    return this;
}

View* View::set_height(float height) {
    _frame.size.height = height;
    _needs_layout = true;
    return this;
}

View* View::set_needs_layout() {
    _needs_layout = true;
    return this;
}

View* View::add_subview(View* view) {
    subviews.emplace_back(view);
    view->superview = this;
	if (_frame_buffer)
		_check_framebuffers(view, _frame_buffer);
	view->setup();
    return this;
}

void View::insert_subview_at(int position, View* view) {
	subviews.insert_at(position, view);
    view->superview = this;
	if (_frame_buffer)
		_check_framebuffers(view, _frame_buffer);
    view->setup();
}

void View::remove_all_subviews() {
    for (auto view : subviews) delete view;
    subviews.clear();
}

View* View::set_color(const Color& color) {
    this->_color = color;
    return this;
}

View* View::_add_layout(const std::initializer_list<Layout::Base*> &layout) {
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
        view->add_subview(subView->clone());

    return view;
}

View* View::dummy(float width, float height) {
    View* view = new View({
        (float)System::random(100),
        (float)System::random(100),
        (float)System::random(100),
        (float)System::random(100)
        });

    view->_color = Random::color();
    return view;
}

Point View::local_point_from(const Point &point) const {
    return point - _absolute_frame.origin;
}

bool View::contains_global_point(const Point &point) const {
    return _absolute_frame.contains(point);
}

void View::enable_touch() {
	Input::subscribeView(this);
}

void View::disable_touch() {
	Input::unsubscribeView(this);
}
