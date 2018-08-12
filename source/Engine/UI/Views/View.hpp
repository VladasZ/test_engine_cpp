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
#include "Memory.hpp"
#include "Layout.hpp"
#include "Input.hpp"

#define DRAW_DEBUG_FRAMES true

class Buffer;
class Window;
class Input;
class FrameBuffer;

class View : public Drawable {

    friend Window;
    friend Layout::Base;

	void _checkFramebuffers(View* view, FrameBuffer* framebuffer);

protected:

    Rect _absoluteFrame;
    Rect _frameInFrameBuffer;

    Rect _frame;

    bool _needsDraw = true;
	bool _needsLayout = true;
	bool _ownsFramebuffer = false;

    Layout::Arr* _layout = nullptr;

    FrameBuffer* _frameBuffer = nullptr;

    void drawSubviews() const;

    virtual void draw() override;

	virtual void layout();
	virtual void layoutSubviews();

    Rect _calculateAbsoluteFrame() const;
    Rect _calculateFrameInFrameBuffer() const;

    virtual void setup() { }
    
    View* _addLayout(const std::initializer_list<Layout::Base*> &layout);

public:
    
    TouchID _touchID = -1;

    View* _setFramebuffer();

    View* superview = nullptr;

    Array<View*> subviews;

	static View* make(const Rect& rect = Rect()) { return new View(rect); }
    View(const Rect &rect = Rect());
    virtual ~View();
    
    Rect frame() const { return _frame; }
    View* setFrame(const Rect &frame);
    View* setSize(const Size &size);
    View* setOrigin(const Point &origin);
    View* setCenter(const Point &center);
    View* edit(std::function<void(View*)> edit);
    
    View* setX(float x);
    View* setY(float y);
    
    View* setWidth(float width);
    View* setHeight(float height);

    View* addSubview(View* view);
    void insertSubviewAt(int position, View* view);
    void removeAllSubviews();

    virtual View* setColor(const Color& color);

    Point localPointFrom(const Point &point) const;
    virtual bool containsGlobalPoint(const Point &point) const;

    template <class ...Args>
    View* addLayout(Args ...args) { return _addLayout({ args... }); }

	template <class ...Args>
	View* setLayout(Args ...args) { 
		for (auto layout : *_layout) delete layout;
		delete _layout;
		_layout = nullptr;
		return _addLayout({ args... }); 
	}

    View* clone() const;

    static View* dummy(float width = 50, float height = 50);
       
};
