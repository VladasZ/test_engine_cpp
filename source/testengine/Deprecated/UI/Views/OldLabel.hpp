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
#include "OldImageView.hpp"

class OldLabel : public OldView {
    
    std::string _text;
    
	Font* _font = Font::System;
	OldView* _contentView;
	Alignment _alignment = Alignment::Left;

    void _setGlyphs();
    
    bool _needsGlyphsUpdate = false;
    
    virtual void draw() override;
        
public:
    
    OldLabel(const ui::Rect& rect = { });

    std::string text() const;
    OldLabel* setText(const std::string& text);
    
    const Font* font() const { return _font; }
    OldLabel* setFont(Font* font);
    
    OldLabel* setFontSize(int size);

    Alignment alignment() const { return _alignment; }
    OldLabel* setAlignment(Alignment alignment);
};
