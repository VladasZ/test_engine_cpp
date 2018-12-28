////
////  Label.cpp
////  TestEngine
////
////  Created by Vladas Zakrevskis on 1/19/18.
////  Copyright © 2018 VladasZ. All rights reserved.
////

//#include "OldLabel.hpp"
//#include "Font.hpp"
//#include "Glyph.hpp"
//#include "TEImageDrawer.hpp"
//#include "Rect.hpp"
//#include "Lifehack.hpp"

//OldLabel::OldLabel(const ui::Rect &rect) : OldView(rect) {
//	_contentView =
//		OldView::make(rect.with_zero_origin())
//		->add_layout(L::fromAlignment(_alignment), L::CenterV())
//	;

//	add_subview(_contentView);

//    _color = ui::Color::gray;
//}

//void OldLabel::draw() {
//    if (_needsGlyphsUpdate) _setGlyphs();
//    OldView::draw();
//}

//void OldLabel::_setGlyphs() {
//    _contentView->remove_all_subviews();
//    if (_text.empty()) return;
    
//    int advance = 0;
//	float contentWidth = 0;
//	auto& contentSize = UNPRIVATE(_contentView)->_frame.size;

//	contentSize.height = _font->height();

//    for (const auto letter : _text) {
//        auto glyph = _font->glyphForChar(letter);

//		auto glyphView = UNPRIVATE(
//			(new OldImageView(glyph->size()))
//			->set_image(glyph->image)
//		);

//		auto& glyphViewFrame = glyphView->_frame;

//		glyphViewFrame.origin = {
//            advance + glyph->bearing.x,
//			contentSize.height / 2 - glyph->bearing.y + _font->baselineShift()
//        };

//		_contentView->add_subview(glyphView);
//        advance += glyph->advance;
//		contentWidth = glyphViewFrame.max_x();
//    }

//	contentSize.width = contentWidth;
        
//    _needsGlyphsUpdate = false;
//    _needs_draw = true;
//	UNPRIVATE(_contentView)->_needs_layout = true;
//}

//std::string OldLabel::text() const { return _text; }

//OldLabel* OldLabel::setText(const std::string& text) {
//	if (text == _text) return this;
//    _text = text;
//    _needsGlyphsUpdate = true;
//    return this;
//}

//OldLabel* OldLabel::setFont(Font* font) {
//    _font = font;
//    _needsGlyphsUpdate = true;
//    return this;
//}

//OldLabel* OldLabel::setFontSize(int size) {
//    setFont(this->_font->withSize(size));
//    return this;
//}

//OldLabel* OldLabel::setAlignment(Alignment alignment) {
//	_alignment = alignment;
//	_contentView->set_layout(L::fromAlignment(alignment), L::CenterV());
//	return this;
//}
