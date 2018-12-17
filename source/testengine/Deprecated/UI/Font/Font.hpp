//
//  Font.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>

#include "Array.hpp"
#include "NonCopyable.hpp"

class Glyph;

class Font : public NonCopyable {
    
    float _height;
    float _baselineShift;
    std::string _fileName;
    
    Array<Glyph*> _glyphs;
  
public:
    
    Font(const std::string& fileName, int size = 28);
	~Font();
    
	float  baselineShift()       const { return _baselineShift; }
	float  height()              const { return _height;        }
	Glyph* glyphForChar(char ch) const { return _glyphs[ch];    }
    
    Font* withSize(int size);

	static Font* System;
	static Font* SF;
	static Font* OpenSans;

	static void initialize();
};
