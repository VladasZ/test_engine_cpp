//
//  View.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "TestObject.hpp"
#include "Drawable.hpp"
#include "Color.hpp"
#include "Primitives.hpp"

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

class Buffer;
class Window;
class Input;

class View :  public Drawable _MEMORY_MANAGED(View) {
        
    friend Window;
    
protected:

    DEF_TYPES(View);
    
    void drawSubviews() const;
    
    virtual void draw() override;
    virtual BufferData *getBufferData() override;
    
    Rect calculateAbsoluteFrame() const;
    Rect _absoluteFrame;
    
    int _touchID = -1;
    
    virtual void setup() { }
    
public:
    
    View::Ptr superview = nullptr;
    
    Rect frame;
    int autolayoutMask = None;
    View::PtrArray subviews;
    
    View() = default;
    View(float x, float y, float width, float height);
    View(float width, float height);
    View(const Size &size);
    View(const Rect &rect);

    virtual ~View();
    
    virtual void layout();
    
    void setFrame(const Rect &frame);
    void setCenter(const Point &center);
    
    int getTouchID() const;
    
    void addSubview(View::Ptr view);
    void insertSubviewAt(int position, View::Ptr view);
    void removeAllSubviews();
        
    Point localPointFrom(const Point &point) const;
    virtual bool containsGlobalPoint(const Point &point) const;
        
#if MEMORY_BENCHMARK
    void addTestViews();
#endif
};
