//
//  Label.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/29/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "ui.hpp"
#include "Log.hpp"
#include "View.hpp"
#include "Font.hpp"


namespace ui {

    class Label : public View {

    protected:

        bool _needs_redraw = false;

        Edge _alignment = Edge::Center;

        std::string _current_text;
        std::string _text;
        View* _content_view;
        Font* _font;

    public:

		bool secure = false;

        gm::Color text_color = config::default_font_color;

        Label(const Rect& frame = { });

    public:

        const std::string& text() const;
        void set_text(const std::string&);

        void set_alignment(Edge);

        template <class T>
        void set_text(const T& value) {
            set_text(cu::log::to_string(value));
        }

        void resize_to_text();

    private:

        void _set_glyphs();

        void _draw() override;

    protected:

        void backspace();

        void setup() override { }
        void layout() override;

    };

}
