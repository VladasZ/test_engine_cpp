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

void Label::draw() {
    if (needsGlyphsUpdate) setGlyphs();
    View::draw();
}

void Label::setGlyphs() {
    
    removeAllSubviews();
    if (_text.empty()) return;
    
    int advance = 0;
    
    vector<ImageView *> views;
    
    for (auto letter : _text) {
        auto glyph = _font->glyphForChar(letter);
        auto imageView = new ImageView(glyph->size());
        imageView->frame.origin = Point(advance + glyph->bearing.x,
                                        frame.size.height / 2 - glyph->bearing.y + _font->baselineShift());
        imageView->image = glyph->image;
        views.push_back(imageView);
        addSubview(imageView);
        advance += glyph->advance;
    }

    frame.size.width = views.back()->frame.maxX();
    
    needsGlyphsUpdate = false;
    
    layout();
}

String Label::text() const { return _text; }

void Label::setText(const String &text) {
    _text = text;
    needsGlyphsUpdate = true;
}

Font * Label::font() const { return _font; }

void Label::setFont(Font *font) {
    _font = font;
    needsGlyphsUpdate = true;
}
