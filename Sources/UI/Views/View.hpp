//
//  View.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Primitives.hpp"
#include "Color.hpp"
#include "Drawable.hpp"

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
    TopRight           = StickToTop | StickToRight
};

class Buffer;
class Window;

class View : public Drawable _MEMORY_MANAGED(View) {
        
    friend Window;
    
protected:
    
    void drawSubviews() const;
    void layout();
    
    virtual void draw() override;
    virtual BufferData *getBufferData() override;
    
    Rect absoluteFrame();
    
    virtual void setup() { }
    
public:
    
    View *superview = nullptr;
    
    Rect frame;
    int autolayoutMask = None;
    vector<View *> subviews;
    
    View() = default;
    View(float x, float y, float width, float height);
    View(float width, float height);
    View(const Size &size);
    View(const Rect &rect);

    virtual ~View();
    
    void setFrame(const Rect &frame);
    void setCenter(const Point &center);
    
    void addSubview(View *view);
    void insertSubviewAt(int position, View *view);
    void removeAllSubviews();
    
#if MEMORY_BENCHMARK
    void addTestViews();
#endif
};
