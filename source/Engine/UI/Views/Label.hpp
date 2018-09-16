//
//  Label.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Meta.hpp"
#include "Font.hpp"
#include "View.hpp"
#include "ImageView.hpp"

class Label : public View { TYPES(Label);
    
    std::string _text;
    
	Font* _font = Font::System;
	View* _contentView;
	Alignment _alignment = Alignment::Left;

    void _setGlyphs();
    
    bool _needsGlyphsUpdate = false;
    
    virtual void draw() override;
        
public:
    
    Label(const Rect &rect = Rect());

    std::string text() const;
    Label* setText(const std::string &text);
    
	const Font* const font() const { return _font; }
    Label* setFont(Font* font);
    
    Label* setFontSize(int size);

	const Alignment alignment() const { return _alignment; }
	Label* setAlignment(Alignment alignment);
};
