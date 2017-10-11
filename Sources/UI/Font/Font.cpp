//
//  Font.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Font.hpp"
#include "File.hpp"
#include "Log.hpp"
#include "Types.h"
#include "Window.hpp"
#include "Image.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

static FT_Library library = nullptr;

FT_Library ftLibrary() {
    if (library == nullptr) {
        Check(FT_Init_FreeType(&library));
    }
    return library;
}

Font::Font(const string& fileName) {
    
    file = new File(fileName);
    
    Check(FT_New_Memory_Face(ftLibrary(),
                             file->getData(),
                             file->getSize(),
                             0,
                             &face));
    
    Check(FT_Set_Pixel_Sizes(face,
                             0,
                             300));
    
    Int glyphIndex = FT_Get_Char_Index(face, 'a');
    
    Check(FT_Load_Glyph(face,
                        glyphIndex,
                        FT_LOAD_RENDER));
    
    FT_BitmapGlyph bitmapGlyhp;
    Check(FT_Get_Glyph(face->glyph, (FT_Glyph*)&bitmapGlyhp));
    
    image = new Image(bitmapGlyhp->bitmap.width,
                      bitmapGlyhp->bitmap.rows,
                      bitmapGlyhp->bitmap.buffer,
                      1);

}
