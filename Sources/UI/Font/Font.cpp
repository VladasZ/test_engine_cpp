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
                             200 * 64));
    
    int glyphIndex = FT_Get_Char_Index(face, 'G');
    
    Check(FT_Load_Glyph(face,
                        glyphIndex,
                        FT_LOAD_RENDER));
    
    FT_BitmapGlyph bitmapGlyhp;
    Check(FT_Get_Glyph(face->glyph, (FT_Glyph*)&bitmapGlyhp));
    
    cout << endl;
    cout << face->glyph->advance.x / 64 << " advance.x" << endl;
    cout << face->glyph->advance.y / 64 << " advance.y" << endl;
    cout << endl;
    cout << face->glyph->metrics.height / 64 << " metrics.height" << endl;
    cout << face->glyph->metrics.width / 64 << " metrics.width" << endl;
    cout << endl;
    cout << face->glyph->metrics.horiAdvance / 64 << " metrics.horiAdvance" << endl;
    cout << endl;
    cout << face->glyph->metrics.horiBearingX / 64 << " metrics.horiBearingX" << endl;
    cout << face->glyph->metrics.horiBearingY / 64 << " metrics.horiBearingY" << endl;
    cout << endl;
    cout << face->glyph->metrics.vertBearingX / 64 << " metrics.vertBearingX" << endl;
    cout << face->glyph->metrics.vertBearingY / 64 << " metrics.vertBearingY" << endl;
    cout << endl;
    cout << face->glyph->linearHoriAdvance / 64 << " linearHoriAdvance" << endl;
    cout << face->glyph->linearVertAdvance / 64 <<  " linearVertAdvance" << endl;
    cout << endl;
    cout << bitmapGlyhp->bitmap.width << " bitmap.width" << endl;
    cout << bitmapGlyhp->bitmap.rows << " bitmap.rows" << endl;
    cout << endl;


    image = new Image(bitmapGlyhp->bitmap.width,
                      bitmapGlyhp->bitmap.rows,
                      bitmapGlyhp->bitmap.buffer,
                      1);

}
