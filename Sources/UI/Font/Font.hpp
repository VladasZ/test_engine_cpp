//
//  Font.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "STL.hpp"

class File;
class Image;
class Glyph;

struct FT_FaceRec_;
typedef struct FT_FaceRec_* FT_Face;

class Font {
    
    vector<Glyph *> glyphs;
  
public:
    
    Font(const string& fileName);
    
    Glyph *glyphForChar(char ch);
    
};
