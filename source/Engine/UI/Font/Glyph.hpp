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
#include "Memory.hpp"
#include "Image.hpp"

class Glyph : public NonCopyable _MEMORY_MANAGED(Glyph) {
        
public:
    
    const char ch;
    const int advance;
    const Point bearing;
    Image* const image;
    
    Glyph(char ch, Image* image, int advance, const Point &bearing);
    ~Glyph();
    
    Size size() const;
    float yMax() const;
    float yMin() const;
};
