//
//  Font.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Font.hpp"
#include "File.hpp"
#include "Image.hpp"
#include "Glyph.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

static FT_Library library = nullptr;

Font * Font::SF;
Font * Font::OpenSans;
Font * Font::System;

FT_Library ftLibrary() {
    if (library == nullptr) {
        FT_Init_FreeType(&library);
    }
    return library;
}

Glyph *renderGlyph(const FT_Face &face, char ch) {
    
    int glyphIndex = FT_Get_Char_Index(face, ch);
    
    FT_Load_Glyph(face,
                  glyphIndex,
                  FT_LOAD_RENDER);
    
    FT_BitmapGlyph bitmapGlyhp;
    FT_Get_Glyph(face->glyph, (FT_Glyph*)&bitmapGlyhp);
    
    auto image = new Image(Size(bitmapGlyhp->bitmap.width,
                                bitmapGlyhp->bitmap.rows),
                           bitmapGlyhp->bitmap.buffer,
                           1);
    
    return new Glyph(ch,
                     image,
                     (int)face->glyph->metrics.horiAdvance / 64,
                     Point(face->glyph->metrics.horiBearingX / 64,
                           face->glyph->metrics.horiBearingY / 64));
}

Font::Font(const string& fileName) {
    
    auto file = new File(fileName);
    FT_Face face;
    
    FT_New_Memory_Face(ftLibrary(),
                       file->getData(),
                       file->getSize(),
                       0,
                       &face);
    
    FT_Set_Pixel_Sizes(face,
                       0,
                       20);
    
    int yMax = 0;
    int yMin = 0;
    
    Glyph *maxGlyph = nullptr;
    Glyph *minGlyph = nullptr;
    
    FOR(128) {
        
        auto glyph = renderGlyph(face, i);
        
        if (yMax < glyph->yMax()) {
            yMax = glyph->yMax();
            maxGlyph = glyph;
        }
        
        if (yMin > glyph->yMin()) {
            yMin = glyph->yMin();
            minGlyph = glyph;
        }
        
        glyphs.push_back(glyph);
    }
    
    _height = yMax - yMin;
    
    float baselinePosition = abs(minGlyph->yMin());
    
    _baselineShift = _height / 2 - baselinePosition;
}

float Font::baselineShift() const {
    return _baselineShift;
}

float Font::height() const {
    return _height;
}

Glyph * Font::glyphForChar(char ch) {
    return glyphs[ch];
}

void Font::initialize() {
    SF       = new Font("Fonts/SF.otf");
    OpenSans = new Font("Fonts/OpenSans.ttf");
    System   = SF;
}



