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

class OldView : public Drawable {

    friend Window;
	friend Input;
    friend Layout::Base;

	void _check_framebuffers(OldView* view, FrameBuffer* framebuffer);

protected:

	TouchID _touch_id = -1;

	ui::Rect _absolute_frame;
	ui::Rect _frame_in_frame_buffer;

	ui::Rect _frame;

    bool _needs_draw = true;
	bool _needs_layout = true;
	bool _owns_framebuffer = false;

    Layout::Arr* _layout = nullptr;

    FrameBuffer* _frame_buffer = nullptr;

    void draw_subviews() const;

    virtual void draw() override;

	virtual void layout();
	virtual void layout_subviews();

	ui::Rect _calculate_absolute_frame() const;
	ui::Rect _calculate_frame_in_frame_buffer() const;

    virtual void setup() { }
    
    OldView* _add_layout(const std::initializer_list<Layout::Base*>& layout);

	virtual void _on_touch(const Touch& touch) { on_touch(touch); }

public:
    
	Event<Touch> on_touch;

    OldView* superview = nullptr;

    Array<OldView*> subviews;

	OldView* _set_framebuffer();

	static OldView* make(const ui::Rect& rect = ui::Rect()) { return new OldView(rect); }
    OldView(const ui::Rect &rect = ui::Rect());
    virtual ~OldView();
    
	ui::Rect frame() const { return _frame; }
    OldView* set_frame(const ui::Rect& frame);
    OldView* set_size(const ui::Size& size);
    OldView* set_origin(const ui::Point& origin);
    OldView* set_center(const ui::Point& center);
    OldView* edit(std::function<void(OldView*)> edit);
    
    OldView* set_x(float x);
    OldView* set_y(float y);
    
    OldView* set_width(float width);
    OldView* set_height(float height);

    OldView* set_needs_layout();
    
    OldView* add_subview(OldView* view);
    void insert_subview_at(int position, OldView* view);
    void remove_all_subviews();

    virtual OldView* set_color(const ui::Color& color);

	ui::Point local_point_from(const ui::Point& point) const;
    virtual bool contains_global_point(const ui::Point& point) const;

    template <class ...Args>
    OldView* add_layout(Args ...args) { return _add_layout({ args... }); }

	template <class ...Args>
	OldView* set_layout(Args ...args) { 
		for (auto layout : *_layout) delete layout;
		delete _layout;
		_layout = nullptr;
		return _add_layout({ args... }); 
	}

	void enable_touch();
	void disable_touch();

    OldView* clone() const;

    static OldView* dummy(float width = 50, float height = 50);
       
};
