//
//  Font.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include <cmath>

#include "Log.hpp"
#include "Font.hpp"
#include "Image.hpp"
#include "Glyph.hpp"
#include "File.hpp"

using namespace std;


Font* Font::SF;
Font* Font::OpenSans;
Font* Font::System;

static FT_Library ftLibrary() {
  static FT_Library _library = nullptr;
  if (_library == nullptr)
	FT_Init_FreeType(&_library);
  return _library;
}

Glyph* renderGlyph(const FT_Face &face, char ch) {
    
  int glyphIndex = FT_Get_Char_Index(face, ch);
    
  FT_Load_Glyph(face,
				glyphIndex,
				FT_LOAD_RENDER);
    
  FT_BitmapGlyph bitmapGlyhp;
  FT_Get_Glyph(face->glyph, (FT_Glyph*)&bitmapGlyhp);
    
  auto image = new Image(Size((float)bitmapGlyhp->bitmap.width,
							  (float)bitmapGlyhp->bitmap.rows),
						 bitmapGlyhp->bitmap.buffer,
						 1);
    
  return new Glyph(ch,
				   image,
				   (int)face->glyph->metrics.horiAdvance / 64,
				   Point((float)face->glyph->metrics.horiBearingX / 64,
						 (float)face->glyph->metrics.horiBearingY / 64));
}

Font::Font(const String& fileName, int size) : _fileName(fileName) {
    
  auto file = new File(fileName.c_str());
  FT_Face face;
    
  FT_New_Memory_Face(ftLibrary(),
					 (FT_Byte*)file->getData(),
					 (FT_Long)file->getSize(),
					 0,
					 &face);
    
  FT_Set_Pixel_Sizes(face,
					 0,
					 size);
    
  float yMax = 0;
  float yMin = 0;
        
  for (int i = 0; i < 128; i++) {
	auto glyph = renderGlyph(face, i);
        
	if (yMax < glyph->yMax()) yMax = glyph->yMax();        
	if (yMin > glyph->yMin()) yMin = glyph->yMin();
        
	_glyphs.push_back(glyph);
  }
    
  _height = yMax - yMin;
    
  float baselinePosition = std::fabs((float)yMin);
    
  _baselineShift = _height / 2 - baselinePosition;
}

Font::~Font() {
  for (auto glyph : _glyphs) delete glyph;
}

Font* Font::withSize(int size) {
  return new Font(_fileName, size);
}

void Font::initialize() {
  SF       = new Font("Fonts/SF.otf");
  OpenSans = new Font("Fonts/OpenSans.ttf");
  System   = SF;
}



