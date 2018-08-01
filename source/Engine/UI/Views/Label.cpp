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

Label::Label(const Rect &rect) : View(rect) {
    color = Color::gray;
}

void Label::draw() {
    if (_needsGlyphsUpdate) _setGlyphs();
    View::draw();
}

void Label::_setGlyphs() {
    
    removeAllSubviews();
    if (_text.empty()) return;
    
    int advance = 0;
    
    Array<ImageView*> views;
    
    for (auto letter : _text) {
        auto glyph = _font->glyphForChar(letter);
        auto imageView = new ImageView(glyph->size());
        auto view = (Label*)imageView; // Lifehack

        view->_frame.origin = { 
            advance + glyph->bearing.x,
            _frame.size.height / 2 - glyph->bearing.y + _font->baselineShift() 
        };

        imageView->setImage(glyph->image);
        views.push_back(imageView);
        addSubview(imageView);
        advance += glyph->advance;
    }

    _frame.size.width = views.back()->frame().maxX();
    
    _needsGlyphsUpdate = false;
    _needsDraw = true;
}

std::string Label::text() const { return _text; }

Label* Label::setText(const std::string &text) {
    _text = text;
    _needsGlyphsUpdate = true;
    return this;
}

const Font* const Label::font() const { return _font; }

Label* Label::setFont(Font* font) {
    _font = font;
    _needsGlyphsUpdate = true;
    return this;
}
