//
//  View.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <functional>
#include "Array.hpp"
#include "Drawable.hpp"
#include "Color.hpp"
#include "Primitives.hpp"
#include "Memory.hpp"
#include "Layout.hpp"

class Buffer;
class Window;
class Input;
class FrameBuffer;


class View : public Drawable {

    friend Window;
    friend Layout::Base;

    virtual void layout();
    virtual void layoutSubviews();

protected:

    Rect _absoluteFrame;
    Rect _frameInFrameBuffer;

    Rect _frame;
    int _touchID = -1;

    bool _needsDraw = true;
    bool _needsLayout = true;

    Layout::Arr* _layout = nullptr;

    FrameBuffer* _frameBuffer = nullptr;

    FrameBuffer* _getFrameBuffer() const;

    void drawSubviews() const;

    virtual void draw() override;

    Rect _calculateAbsoluteFrame() const;
    Rect _calculateFrameInFrameBuffer() const;

    virtual void setup() { }
    
    View* _addLayout(const std::initializer_list<Layout::Base*> &layout);


public:
    
    void _setFramebuffer();

    View* superview = nullptr;

    Array<View*> subviews;

    View(const Rect &rect = Rect());

    virtual ~View();
    
    Rect frame() const { return _frame; }
    View* setFrame(const Rect &frame);
    View* setSize(const Size &size);
    View* setOrigin(const Point &origin);
    View* setCenter(const Point &center);
    View* edit(std::function<void(View*)> edit);

    int getTouchID() const;

    View* addSubview(View* view);
    void insertSubviewAt(int position, View* view);
    void removeAllSubviews();

    virtual View* setColor(const Color& color);

    Point localPointFrom(const Point &point) const;
    virtual bool containsGlobalPoint(const Point &point) const;

    template <class ...Args>
    View* addLayout(Args ...args) { return _addLayout({ args... }); }

    View* clone() const;

    static View* dummy(float width = 50, float height = 50);
       
};
