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
    if (_text.empty()) return;
    
    int advance = 0;
    
    vector<ImageView *> views;
    
    for (auto letter : _text) {
        auto glyph = _font->glyphForChar(letter);
        auto imageView = new ImageView(glyph->image->size);
        imageView->frame.origin = Point(advance + glyph->bearing.x, frame.size.height - glyph->bearing.y);
        imageView->setImage(glyph->image);
        imageView->color = Color::purple.withAlpha(0.5);
        views.push_back(imageView);
        addSubview(imageView);
        advance += glyph->advance;
    }
    
    auto minTopGlyph = MIN(views, [] (ImageView * v1, ImageView * v2) {
        return v1 ->frame.y < v2 ->frame.y;
    });
    
    auto maxBotGlyph = MAX(views, [] (ImageView *v1, ImageView *v2) {
        return v1->frame.maxY() < v2->frame.maxY();
    });

    frame.height = abs(minTopGlyph->frame.y - maxBotGlyph->frame.maxY());
    frame.width = views.back()->frame.maxX();
    
    auto shift = -minTopGlyph->frame.y;
    
    //Error("HEEELOOOOOOOOOO");
    for (auto view : views) view->frame.y += shift;
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
