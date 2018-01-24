//
//  Font.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

class File;
class Image;
class Glyph;

struct FT_FaceRec_;
typedef struct FT_FaceRec_* FT_Face;

class Font : NonCopyable {
    
    float _height;
    float _baselineShift;
    
    vector<Glyph *> glyphs;
  
public:
    
    static Font *System;
    static Font *SF;
    static Font *OpenSans;
    
    static void initialize();

    Font(const string& fileName);
    
    float baselineShift() const;
    float height() const;
    
    Glyph *glyphForChar(char ch);
    
};
