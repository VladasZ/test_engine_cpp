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

class Buffer;
class Window;
class Input;

enum Autolayout {
    None               = 0,
    StickToLeft        = 1 << 0,
    StickToRight       = 1 << 1,
    StickToTop         = 1 << 2,
    StickToBottom      = 1 << 3,
    Center             = 1 << 4,
    CenterHorizontally = 1 << 5,
    CenterVertically   = 1 << 6,
    Background         = 1 << 7,
    TopRight           = StickToTop    | StickToRight,
    TopLeft            = StickToTop    | StickToLeft,
    BotRight           = StickToBottom | StickToRight,
    BotLeft            = StickToBottom | StickToLeft
};

class View : public Drawable {
        
    friend Window;
    
protected:
    
    void drawSubviews() const;
    
    virtual void draw() override;
    virtual BufferData *getBufferData() override;
    
    Rect calculateAbsoluteFrame() const;
    Rect _absoluteFrame;
    
    int _touchID = -1;
    
    virtual void setup() { }
    virtual bool _isScrollView() const { return false; }
    
public:
    
    View *superview = nullptr;
    
    Rect frame;
    int autolayoutMask = None;
    Array<View *> subviews;
    
    View() = default;
    View(const Rect &rect);

    virtual ~View();
    
    virtual void layout();
    virtual void layoutSubviews();
    
    View * setFrame(const Rect &frame);
    View * setCenter(const Point &center);

    int getTouchID() const;
    
    View * addSubview(View *view);
    void insertSubviewAt(int position, View *view);
    void removeAllSubviews();

    View * setColor(const Color& color);
    View * setAutolayoutMask(Autolayout mask);

    Point localPointFrom(const Point &point) const;
    virtual bool containsGlobalPoint(const Point &point) const;

    static View * dummy(float width = 50, float height = 50);
        
#if MEMORY_BENCHMARK
    void addTestViews();
#endif
};
