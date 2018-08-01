//
//  Font.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Array.hpp"
#include "String.hpp"
#include "NonCopyable.hpp"
#include "Memory.hpp"
#include "Image.hpp"

class File;
class Glyph;

struct FT_FaceRec_;
typedef struct FT_FaceRec_* FT_Face;

class Font : public NonCopyable _MEMORY_MANAGED(Font) {
    
    float _height;
    float _baselineShift;
    String _fileName;
    
    Array<Glyph*> glyphs;
  
public:
    
    static Font* System;
    static Font* SF;
    static Font* OpenSans;
    
    static void initialize();

    Font(const String& fileName, int size = 20);
    
    float baselineShift() const;
    float height() const;
    
    Glyph* glyphForChar(char ch);
    
    Font* withSize(int size);
};
