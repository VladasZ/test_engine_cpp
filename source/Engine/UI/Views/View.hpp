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
#include "Primitives.hpp"
#include "Memory.hpp"
#include "Layout.hpp"

class Buffer;
class Window;
class Input;



class View : public Drawable {
        
    friend Window;
    friend Layout::Base;

protected:
    
    void drawSubviews() const;
    
    virtual void draw() override;
    virtual BufferData *getBufferData() override;
    
    Rect calculateAbsoluteFrame() const;
    Rect _absoluteFrame;
    
    Rect _frame;

    int _touchID = -1;
    
    virtual void setup() { }
    virtual bool _isScrollView() const { return false; }

    Layout::Array *_layout = nullptr;
    
public:
    
    View *superview = nullptr;
    
    Array<View *> subviews;
    
    View() = default;
    View(const Rect &rect);

    virtual ~View();
    
    virtual void layout();
    virtual void layoutSubviews();
    
    Rect frame() const { return _frame; }
    View * setFrame(const Rect &frame);
    View * setSize(const Size &size);
    View * setOrigin(const Point &origin);
    View * setCenter(const Point &center);

    int getTouchID() const;
    
    View * addSubview(View *view);
    void insertSubviewAt(int position, View *view);
    void removeAllSubviews();

    View * setColor(const Color& color);

    Point localPointFrom(const Point &point) const;
    virtual bool containsGlobalPoint(const Point &point) const;

    View * addLayout(const std::initializer_list<Layout::Base *> &layout);

    static View * dummy(float width = 50, float height = 50);
        
#if MEMORY_BENCHMARK
    void addTestViews();
#endif
};
