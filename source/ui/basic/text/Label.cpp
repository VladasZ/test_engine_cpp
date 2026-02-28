//
//  Label.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/29/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "Label.hpp"
#include "Glyph.hpp"
#include "ImageView.hpp"

using namespace ui;


Label::Label(const Rect& frame) : View(frame) {
    _font = config::default_font;
    init_view(_content_view);
    _content_view->draw_debug_frame = false;
}

const std::string& Label::text() const {
    return _text;
}

void Label::set_text(const std::string& text) {
    if (text == _current_text) {
        _text = text;
        _needs_redraw = false;
        return;
    }
    if (_text == text) return;
    _text = text;
    _needs_redraw = true;
}

void Label::set_alignment(Edge alignment) {
    if (_alignment == alignment) return;
    _alignment = alignment;
    _set_needs_layout();
}

void Label::resize_to_text() {
    edit_frame().size = _content_view->frame().size;
}

void Label::_set_glyphs() {

    _content_view->remove_all_subviews();

    if (_text.empty()) return;

    float advance = 0;
    auto& _content_size = _content_view->edit_frame().size;

    _content_size.height = _font->height();

    for (auto letter : _text) {
        auto glyph = _font->glyph_for_char(secure ? '*' : letter);

        auto glyph_view = new ImageView(glyph->size(), glyph->image);
        glyph_view->tint_color = text_color;
        glyph_view->draw_debug_frame = false;

        glyph_view->edit_frame().origin = {
            advance + glyph->bearing.x,
            _content_size.height - glyph->bearing.y + _font->baseline_shift()
        };

        _content_view->add_subview(glyph_view);
        advance += glyph->advance;
    }

    _content_size.width = _content_view->subviews().back()->frame().max_x();

    _set_needs_layout();

}

void Label::_draw() {
    if (_needs_redraw) {
        _set_glyphs();
        _needs_redraw = false;
        _current_text = _text;
    }
    View::_draw();
}

void Label::backspace() {
    if (_text.empty()) return;
    _text.pop_back();
    _content_view->remove_last_subview();
    if (_text.empty()) {
        _content_view->edit_frame().size.width = 0;
    }
    else {
        _content_view->edit_frame().size.width = _content_view->subviews().back()->frame().max_x();
    }
}

void Label::layout() {

    if (_alignment == Edge::Center) {
        _content_view->place.at_center();
        return;
    }

    _content_view->place.center_ver();
    if (_alignment == Edge::Left) {
        _content_view->place.l(10);
    }
    else {
        _content_view->place.r(10);
    }

}
