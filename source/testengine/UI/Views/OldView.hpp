//
//  View.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Array.hpp"
#include "Drawable.hpp"
#include "Color.hpp"
#include "Rect.hpp"
#include "Layout.hpp"
#include "Input.hpp"
#include "Touch.hpp"
#include "Event.hpp"

class Buffer;
class Window;
class FrameBuffer;

class View : public Drawable {

    friend Window;
	friend Input;
    friend Layout::Base;

	void _check_framebuffers(View* view, FrameBuffer* framebuffer);

protected:

	TouchID _touch_id = -1;

    Rect _absolute_frame;
    Rect _frame_in_frame_buffer;

    Rect _frame;

    bool _need_draw = true;
	bool _needs_layout = true;
	bool _owns_framebuffer = false;

    Layout::Arr* _layout = nullptr;

    FrameBuffer* _frame_buffer = nullptr;

    void draw_subviews() const;

    virtual void draw() override;

	virtual void layout();
	virtual void layout_subviews();

    Rect _calculate_absolute_frame() const;
    Rect _calculate_frame_in_frame_buffer() const;

    virtual void setup() { }
    
    View* _add_layout(const std::initializer_list<Layout::Base*>& layout);

	virtual void _on_touch(const Touch& touch) { on_touch(touch); }

public:
    
	Event<Touch> on_touch;

    View* superview = nullptr;

    Array<View*> subviews;

	View* _set_framebuffer();

	static View* make(const Rect& rect = Rect()) { return new View(rect); }
    View(const Rect &rect = Rect());
    virtual ~View();
    
    Rect frame() const { return _frame; }
    View* set_frame(const Rect& frame);
    View* set_size(const Size& size);
    View* set_origin(const Point& origin);
    View* set_center(const Point& center);
    View* edit(std::function<void(View*)> edit);
    
    View* set_x(float x);
    View* set_y(float y);
    
    View* set_width(float width);
    View* set_height(float height);

    View* set_needs_layout();
    
    View* add_subview(View* view);
    void insert_subview_at(int position, View* view);
    void remove_all_subviews();

    virtual View* set_color(const Color& color);

    Point local_point_from(const Point &point) const;
    virtual bool contains_global_point(const Point &point) const;

    template <class ...Args>
    View* add_layout(Args ...args) { return _add_layout({ args... }); }

	template <class ...Args>
	View* set_layout(Args ...args) { 
		for (auto layout : *_layout) delete layout;
		delete _layout;
		_layout = nullptr;
		return _add_layout({ args... }); 
	}

	void enable_touch();
	void disable_touch();

    View* clone() const;

    static View* dummy(float width = 50, float height = 50);
       
};
