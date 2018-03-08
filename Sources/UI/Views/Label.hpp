//
//  Label.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma mark

#include "Font.hpp"
#include "View.hpp"
#include "ImageView.hpp"

class Label : public View _MEMORY_MANAGED(Label) {
    
    String _text;
    Font *_font = Font::System;
    
    void setGlyphs();
        
public:
    
    using View::View;
        
    String text() const;
    void setText(const String &text);
    
    Font *font() const;
    void setFont(Font *font);
    
};
