//
//  Label.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma mark

#include "STL.hpp"
#include "Font.hpp"
#include "View.hpp"
#include "ImageView.hpp"

class Label : public View {
    
    string _text;
    Font *_font = Font::System;
    
    void setGlyphs();
        
public:
    
    using View::View;
        
    string text() const;
    void setText(const string &text);
    
    Font *font() const;
    void setFont(Font *font);
    
};
