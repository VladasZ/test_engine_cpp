//
//  Font.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>
#include <array>


namespace ui {

    class Glyph;

    class Font {

        std::string _file;

        unsigned _size;

        float _height;
        float _baseline_shift;

        std::array<Glyph*, 128> _glyphs;

    public:

        Font() = default;
        explicit Font(const std::string& file_name, unsigned size = 40);
        ~Font();

        float height() const;
        float baseline_shift() const;

        Glyph* glyph_for_char(char ch) const;

        Font* with_size(unsigned int) const;
    };

}
