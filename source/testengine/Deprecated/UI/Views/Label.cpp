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
#include "DeprecatedImage.hpp"
#include "Rect.hpp"
#include "Lifehack.hpp"

Label::Label(const ui::Rect &rect) : OldView(rect) {
	_contentView =
		OldView::make(rect.with_zero_origin())
		->add_layout(L::fromAlignment(_alignment), L::CenterV())
	;

	add_subview(_contentView);

    _color = ui::Color::gray;
}

void Label::draw() {
    if (_needsGlyphsUpdate) _setGlyphs();
    OldView::draw();
}

void Label::_setGlyphs() {
    _contentView->remove_all_subviews();
    if (_text.empty()) return;
    
    int advance = 0;
	float contentWidth = 0;
	auto& contentSize = UNPRIVATE(_contentView)->_frame.size;

	contentSize.height = _font->height();

    for (const auto letter : _text) {
        auto glyph = _font->glyphForChar(letter);

		auto glyphView = UNPRIVATE(
			(new ImageView(glyph->size()))
			->set_image(glyph->image)
		);

		auto& glyphViewFrame = glyphView->_frame;

		glyphViewFrame.origin = {
            advance + glyph->bearing.x,
			contentSize.height / 2 - glyph->bearing.y + _font->baselineShift()
        };

		_contentView->add_subview(glyphView);
        advance += glyph->advance;
		contentWidth = glyphViewFrame.max_x();
    }

	contentSize.width = contentWidth;
        
    _needsGlyphsUpdate = false;
    _need_draw = true;
	UNPRIVATE(_contentView)->_needs_layout = true;
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
	_contentView->set_layout(L::fromAlignment(alignment), L::CenterV());
	return this;
}
