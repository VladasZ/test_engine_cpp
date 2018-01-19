//
//  Font.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "STL.hpp"
#include "Tools.hpp"

class File;
class Image;
class Glyph;

struct FT_FaceRec_;
typedef struct FT_FaceRec_* FT_Face;

class Font : NonCopyable {
    
    vector<Glyph *> glyphs;
  
public:
    
    static Font *SF;
    static Font *OpenSans;
    
    static void initialize();

    Font(const string& fileName);
    
    Glyph *glyphForChar(char ch);
    
};
