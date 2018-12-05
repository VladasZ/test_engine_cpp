//
//  View.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "OldView.hpp"
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

OldView::OldView(const ui::Rect &rect) : _frame { rect } { }

OldView::~OldView() {
	remove_all_subviews();
    if (_layout) delete _layout;
	if (_owns_framebuffer) delete _frame_buffer;
	disable_touch();
}

ui::Rect OldView::_calculate_absolute_frame() const {

    if (this->superview == nullptr) return _frame;

	ui::Rect result = _frame;
    OldView* superview = this->superview;

    while (superview) {
        result.origin += superview->_frame.origin;
        superview = superview->superview;
    }

    return result;
}

ui::Rect OldView::_calculate_frame_in_frame_buffer() const {

    if (this->superview == nullptr) return _frame;

    auto superview = this->superview;
	ui::Rect result = _frame;

    while (!superview->_owns_framebuffer) {
        result.origin += superview->_frame.origin;
		if (superview->superview == nullptr) break;
        superview = superview->superview;
    }

    return result;
}

OldView* OldView::_set_framebuffer() {
    _frame_buffer = new FrameBuffer(_frame.size);
	_owns_framebuffer = true;
	return this;
}

void OldView::draw_subviews() const {
    for (auto subview : subviews) subview->draw();
}

void OldView::draw() {

    if (_needs_layout) layout();

	if (_color.is_transparent() && !DRAW_DEBUG_FRAMES) _need_draw = false;

    if (_need_draw) {
        _frame_buffer->draw([&] {
            if (_owns_framebuffer) {
                GL::set_viewport(_frame.with_zero_origin());
            }
            else {
                GL::set_viewport(_frame_in_frame_buffer);
            }
            Shader::ui.use();
            Shader::ui.set_uniform_color(_color);
            Buffer::fullscreen->draw();
#if DRAW_DEBUG_FRAMES
            Shader::ui.set_uniform_color(ui::C::turquoise);
            Buffer::fullscreenOutline->draw();
#endif
        });
        _need_draw = false;
    }

    draw_subviews();
    
    
    if (_owns_framebuffer) {
        superview->_frame_buffer->draw([&]{
            GL::set_viewport(_frame_in_frame_buffer);
            Shader::ui_texture.use();
            _frame_buffer->get_image()->bind();
            Buffer::fullscreenImage->draw();
            GL::unbind_image();
        });
    }
}

void OldView::layout() {

    if (!_needs_layout) { UNEXPECTED; return; }

    if (_layout)
        for (auto& layout : *_layout)
            layout->_layout(this);

    _frame_in_frame_buffer = _calculate_frame_in_frame_buffer();
    _absolute_frame = _calculate_absolute_frame();
    _need_draw = true;
}

void OldView::layout_subviews() {
    for (auto subview : subviews) subview->layout();
}

void OldView::_check_framebuffers(OldView* view, FrameBuffer* framebuffer) {
	auto buffer = view->_owns_framebuffer ? view->_frame_buffer : framebuffer;

	view->_frame_buffer = buffer;

	for (auto subview : view->subviews)
		_check_framebuffers(subview, buffer);
}

OldView* OldView::set_frame(const ui::Rect &frame) {
    _frame = frame;
    _needs_layout = true;
    return this;
}

OldView* OldView::set_size(const ui::Size &size) {
    _frame.size = size;
    _needs_layout = true;
    return this;
}

OldView* OldView::set_origin(const ui::Point &origin) {
    _frame.origin = origin;
    superview->_need_draw = true;
    return this;
}

OldView* OldView::set_center(const ui::Point &center) {
	this->_frame.origin.x = center.x - _frame.size.width / 2;
	this->_frame.origin.y = center.y - _frame.size.height / 2;
    return this;
}

OldView* OldView::edit(std::function<void(OldView*)> edit) {
    edit(this);
    return this;
}

OldView* OldView::set_x(float x) {
    _frame.origin.x = x;
    _needs_layout = true;
    return this;
}

OldView* OldView::set_y(float y) {
    _frame.origin.y = y;
    _needs_layout = true;
    return this;
}

OldView* OldView::set_width(float width) {
    _frame.size.width = width;
    _needs_layout = true;
    return this;
}

OldView* OldView::set_height(float height) {
    _frame.size.height = height;
    _needs_layout = true;
    return this;
}

OldView* OldView::set_needs_layout() {
    _needs_layout = true;
    return this;
}

OldView* OldView::add_subview(OldView* view) {
    subviews.emplace_back(view);
    view->superview = this;
	if (_frame_buffer)
		_check_framebuffers(view, _frame_buffer);
	view->setup();
    return this;
}

void OldView::insert_subview_at(int position, OldView* view) {
	subviews.insert_at(position, view);
    view->superview = this;
	if (_frame_buffer)
		_check_framebuffers(view, _frame_buffer);
    view->setup();
}

void OldView::remove_all_subviews() {
    for (auto view : subviews) delete view;
    subviews.clear();
}

OldView* OldView::set_color(const ui::Color& color) {
    this->_color = color;
    return this;
}

OldView* OldView::_add_layout(const std::initializer_list<Layout::Base*> &layout) {
    if (_layout == nullptr) {
        _layout = new Layout::Arr(layout);
        return this;
    }

    _layout->append(layout);

    return this;
}

OldView* OldView::clone() const {
    OldView* view = new OldView(_frame);
    view->_color = _color;
    view->_layout = _layout;

    for (auto subView : subviews)
        view->add_subview(subView->clone());

    return view;
}

OldView* OldView::dummy(float width, float height) {
    OldView* view = new OldView({
        (float)System::random(100),
        (float)System::random(100),
        (float)System::random(100),
        (float)System::random(100)
        });

    view->_color = Random::color();
    return view;
}

ui::Point OldView::local_point_from(const ui::Point& point) const {
    return point - _absolute_frame.origin;
}

bool OldView::contains_global_point(const ui::Point& point) const {
    return _absolute_frame.contains(point);
}

void OldView::enable_touch() {
	Input::subscribeView(this);
}

void OldView::disable_touch() {
	Input::unsubscribeView(this);
}
