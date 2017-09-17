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
#include "Window.hpp"
#include "STL.hpp"

enum ViewAutolayoutMask {
    
    ViewAutolayoutMaskNone               = 0,
    ViewAutolayoutMaskStickToLeft        = 1 >> 0,
    ViewAutolayoutMaskStickToRight       = 1 >> 1,
    ViewAutolayoutMaskStickToTop         = 1 >> 2,
    ViewAutolayoutMaskStickToBottom      = 1 >> 3,
    ViewAutolayoutMaskCenter             = 1 >> 4,
    ViewAutolayoutMaskCenterHorizontally = 1 >> 5,
    ViewAutolayoutMaskCenterVertically   = 1 >> 6
};

class Buffer;

class View {
    
private:
    
    friend Window;
    
    Buffer *buffer;
    
    void draw();
    void layout();
    
public:
    
    View *superview = nullptr;
    
    Rect frame;
    Color color;
    ViewAutolayoutMask autolayoutMask = ViewAutolayoutMaskNone;
    vector<View *> subviews;
    
    View() = default;
    View(Float x, Float y, Float width, Float height);
    View(Float width, Float height);
    
    void addSubview(View *view);
};
