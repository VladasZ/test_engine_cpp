//
//  Glyph.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/18/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Glyph.hpp"
#include "Image.hpp"

Glyph::Glyph(char ch, Image* image, int advance, const Point &bearing)
: ch(ch), image(image), advance(advance), bearing(bearing)
{ }

Glyph::~Glyph() {
    delete image;
}

Size Glyph::size() const {
    return image->size;
}

float Glyph::yMax() const {
    return bearing.y;
}

float Glyph::yMin() const {
    return bearing.y - image->size.height;
}
