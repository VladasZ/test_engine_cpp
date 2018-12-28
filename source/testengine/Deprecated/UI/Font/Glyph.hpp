//
//  Glyph.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/18/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Rect.hpp"
#include "NonCopyable.hpp"
#include "TEImageDrawer.hpp"

class Glyph : public NonCopyable {
        
public:
    
    const char ch;
    ui::Image* const image;
    const int advance;
    const ui::Point bearing;
    
    Glyph(char ch, ui::Image* image, int advance, const ui::Point& bearing);
    ~Glyph();
    
	ui::Size size() const;
    float y_max() const;
    float y_min() const;
};
