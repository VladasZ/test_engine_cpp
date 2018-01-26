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

enum Autolayout {
    
   None               = 0,
   StickToLeft        = 1 << 0,
   StickToRight       = 1 << 1,
   StickToTop         = 1 << 2,
   StickToBottom      = 1 << 3,
   Center             = 1 << 4,
   CenterHorizontally = 1 << 5,
   CenterVertically   = 1 << 6
};

class Buffer;
class Window;

class View : public NonCopyable _MEMORY_MANAGED(View) {
        
    friend Window;
    
protected:
    
    Buffer *buffer = nullptr;
        
    void drawSubviews() const;
    virtual void draw();
    void layout();
    
    virtual BufferData *getBufferData();
    virtual void setupBuffer();
    
    Rect absoluteFrame();
    
public:
    
    View *superview = nullptr;
    
    Rect frame;
    Color color;
    int autolayoutMask = None;
    vector<View *> subviews;
    
    View() = default;
    View(float x, float y, float width, float height);
    View(float width, float height);
    View(const Size &size);
    
    virtual ~View();
    
    void setFrame(const Rect &frame);
    void setCenter(const Point &center);
    
    void addSubview(View *view);
    void removeAllSubviews();
    
#if MEMORY_BENCHMARK
    void addTestViews();
#endif
};
