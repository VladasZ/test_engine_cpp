//
//  Label.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Font.hpp"
#include "OldView.hpp"
#include "ImageView.hpp"

class Label : public OldView {
    
    std::string _text;
    
	Font* _font = Font::System;
	OldView* _contentView;
	Alignment _alignment = Alignment::Left;

    void _setGlyphs();
    
    bool _needsGlyphsUpdate = false;
    
    virtual void draw() override;
        
public:
    
	Label(const ui::Rect& rect = { });

    std::string text() const;
    Label* setText(const std::string &text);
    
	const Font* const font() const { return _font; }
    Label* setFont(Font* font);
    
    Label* setFontSize(int size);

	const Alignment alignment() const { return _alignment; }
	Label* setAlignment(Alignment alignment);
};
