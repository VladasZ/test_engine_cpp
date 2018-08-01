//
//  Label.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Font.hpp"
#include "View.hpp"
#include "ImageView.hpp"

class Label : public View {
    
    std::string _text;
    Font* _font = Font::System;
    
    void _setGlyphs();
    
    bool _needsGlyphsUpdate = false;
    
    virtual void draw() override;
        
public:
    
    Label(const Rect &rect = Rect());

    std::string text() const;
    Label* setText(const std::string &text);
    
    const Font* const font() const;
    Label* setFont(Font* font);
    
};
