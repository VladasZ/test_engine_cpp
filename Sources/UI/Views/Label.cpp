//
//  Label.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Label.hpp"
#include "Font.hpp"
#include "Glyph.hpp"
#include "Image.hpp"
#include "Primitives.hpp"

void Label::setGlyphs() {
    
    removeAllSubviews();
    
    int advance = 0;
    
    for (auto letter : _text) {
        auto glyph = _font->glyphForChar(letter);
        auto imageView = new ImageView(glyph->image->size);
        imageView->frame.origin = Point(advance + glyph->bearing.x, 40 - glyph->bearing.y);
        imageView->setImage(glyph->image);
        addSubview(imageView);
        advance += glyph->advance;
        cout << glyph->advance << endl;
    }
    
    layout();
}

string Label::text() const { return _text; }

void Label::setText(const string &text) {
    _text = text;
    setGlyphs();
}

Font * Label::font() const { return _font; }

void Label::setFont(Font *font) {
    _font = font;
    setGlyphs();
}
