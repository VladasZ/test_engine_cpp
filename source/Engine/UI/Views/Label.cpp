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
#include "Rect.hpp"
#include "Lifehack.hpp"

Label::Label(const Rect &rect) : View(rect) {
	_contentView =
		View::make(rect.withZeroOrigin())
		->addLayout(L::fromAlignment(_alignment), L::CenterV())
	;

	addSubview(_contentView);

    _color = Color::gray;
}

void Label::draw() {
    if (_needsGlyphsUpdate) _setGlyphs();
    View::draw();
}

void Label::_setGlyphs() {
    _contentView->removeAllSubviews();
    if (_text.empty()) return;
    
    int advance = 0;
	float contentWidth = 0;
	auto& contentSize = UNPRIVATE(_contentView)->_frame.size;

	contentSize.height = _font->height();

    for (const auto letter : _text) {
        auto glyph = _font->glyphForChar(letter);

		auto glyphView = UNPRIVATE(
			(new ImageView(glyph->size()))
			->setImage(glyph->image)
		);

		auto& glyphViewFrame = glyphView->_frame;

		glyphViewFrame.origin = {
            advance + glyph->bearing.x,
			contentSize.height / 2 - glyph->bearing.y + _font->baselineShift()
        };

		_contentView->addSubview(glyphView);
        advance += glyph->advance;
		contentWidth = glyphViewFrame.maxX();
    }

	contentSize.width = contentWidth;
        
    _needsGlyphsUpdate = false;
    _needsDraw = true;
	UNPRIVATE(_contentView)->_needsLayout = true;
}

std::string Label::text() const { return _text; }

Label* Label::setText(const std::string &text) {
	if (text == _text) return this;
    _text = text;
    _needsGlyphsUpdate = true;
    return this;
}

Label* Label::setFont(Font* font) {
    _font = font;
    _needsGlyphsUpdate = true;
    return this;
}

Label* Label::setFontSize(int size) {
    setFont(this->_font->withSize(size));
    return this;
}

Label* Label::setAlignment(Alignment alignment) {
	_alignment = alignment;
	_contentView->setLayout(L::fromAlignment(alignment), L::CenterV());
	return this;
}
