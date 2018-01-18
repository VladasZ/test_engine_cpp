//
//  Glyph.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/18/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Glyph.hpp"
#include "Image.hpp"

Glyph::Glyph(Image *image, int advance, int bearing)
: image(image), advance(advance), bearing(bearing)
{ }

Glyph::~Glyph() {
    delete image;
}
