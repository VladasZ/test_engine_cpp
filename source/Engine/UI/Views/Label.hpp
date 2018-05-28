//
//  Label.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "TestObject.hpp"
#include "Font.hpp"
#include "View.hpp"
#include "ImageView.hpp"

class Label : public View {
    
    std::string _text;
    Font *_font = Font::System;
    
    void setGlyphs();
    
    bool needsGlyphsUpdate = false;
    
    virtual void draw() override;
        
public:
    
    using View::View;
        
    std::string text() const;
    void setText(const std::string &text);
    
    Font *font() const;
    void setFont(Font *font);
    
};
