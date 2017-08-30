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

class View {
    
private:
    
    friend Window;
    
    void draw();
    void layout();
    
public:
    
    View *superview = nullptr;
    
    Rect frame;
    Color color;
    ViewAutolayoutMask autolayoutMask = ViewAutolayoutMaskNone;
    
    View() = default;
    View(Float width, Float height);
};
