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
#include "Types.h"
#include "STL.hpp"

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

class View {
        
    friend Window;
    
protected:
    
    Buffer *buffer;
    
    void drawSubviews() const;
    virtual void draw() const;
    void layout();
    
    virtual BufferData getBufferData();
    virtual void setupBuffer();
    
public:
    
    View *superview = nullptr;
    
    Rect frame;
    Color color;
    int autolayoutMask = None;
    vector<View *> subviews;
    
    View() = default;
    View(Float x, Float y, Float width, Float height);
    View(Float width, Float height);
    
    void setFrame(const Rect &frame);
    void addSubview(View *view);
};
