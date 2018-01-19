//
//  Glyph.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/18/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

class Image;

class Glyph {
    
    
public:
    
    Image *image;
    
    const int advance;
    const int bearing;
    
    Glyph(Image *image, int advance, int bearing);
    ~Glyph();
    
};