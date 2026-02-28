//
//  Font.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#ifdef _WIN32
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#endif

#include <cmath>
#include <FreeTypeInclude.hpp>


#include "ui.hpp"
#include "Log.hpp"
#include "File.hpp"
#include "Font.hpp"
#include "Glyph.hpp"
#include "Image.hpp"

using namespace cu;
using namespace ui;

#ifdef USING_FREETYPE

static FT_Library ft_library() {
    static FT_Library _library = nullptr;
    if (_library == nullptr) {
        FT_Init_FreeType(&_library);
    }
    return _library;
}

static Glyph* render_glyph(FT_Face face, char symbol) {

    FT_UInt glyphIndex = FT_Get_Char_Index(face, static_cast<FT_ULong>(symbol));

    FT_Load_Glyph(face, glyphIndex, FT_LOAD_RENDER);

	FT_Glyph ft_glyph;
    FT_Get_Glyph(face->glyph, &ft_glyph);

	auto bitmap_glyph = reinterpret_cast<FT_BitmapGlyph>(ft_glyph);

	Size size = { bitmap_glyph->bitmap.width, bitmap_glyph->bitmap.rows };

    Point bearing = { face->glyph->metrics.horiBearingX / 64,
                      face->glyph->metrics.horiBearingY / 64 };

	auto glyph = new Glyph(symbol,
                           new Image(bitmap_glyph->bitmap.buffer, size.width, size.height, 1),
                           static_cast<int>(face->glyph->metrics.horiAdvance / 64),
                           bearing);
	
	FT_Done_Glyph(ft_glyph);

    return glyph;
}
#endif


Font::Font(const std::string& file_name, unsigned size) : _file(file_name), _size(size) {
#ifdef USING_FREETYPE

    File* file = new File(file_name);

    FT_Face face;

    FT_New_Memory_Face(ft_library(),
                       reinterpret_cast<FT_Byte*>(file->data()),
                       static_cast<FT_Long>(file->size()),
                       0,
                       &face);

    FT_Set_Pixel_Sizes(face, 0, size);

    float y_max = 0;
    float y_min = 0;

    for (char symbol = 0; symbol < 127; symbol++) {
      auto glyph = render_glyph(face, symbol);

      if (y_max < glyph->y_max()) {
          y_max = glyph->y_max();
      }

      if (y_min > glyph->y_min()) {
          y_min = glyph->y_min();
      }

      _glyphs[symbol] = glyph;
    }

    _height = y_max - y_min;

    float baseline_position = std::fabs(y_min);

    _baseline_shift = _height / 2 - baseline_position;
    
    delete file;
    
#endif
}

Font::~Font() {
    for (auto glyph : _glyphs) {
        delete glyph;
    }
}

float Font::height() const {
    return _height / 2;
}

float Font::baseline_shift() const {
    return _baseline_shift;
}

Glyph* Font::glyph_for_char(char ch) const {
    if (ch < 0) return _glyphs['?'];
    return _glyphs[ch];
}

Font* Font::with_size(unsigned int size) const {
    return new Font(_file, size);
}
