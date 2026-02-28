//
//  Glyph.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 1/18/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Glyph.hpp"
#include "Image.hpp"
#include "LogUtils.hpp"

using namespace ui;
using namespace gm;


Glyph::Glyph(char ch, Image* image, int advance, const Point& bearing)
        : ch(ch), image(image), advance(advance / 2), bearing(bearing.x / 2, bearing.y / 2) { }

Glyph::~Glyph() {
    delete image;
}

Size Glyph::size() const {
    return Size { image->width(), image->height() } / 2;
}

float Glyph::y_max() const {
    return bearing.y;
}

float Glyph::y_min() const {
    return bearing.y - image->height();
}

std::string Glyph::to_string() const {
    return VarString(ch) +
           VarString(image) +
           VarString(advance) +
           VarString(bearing);
}
