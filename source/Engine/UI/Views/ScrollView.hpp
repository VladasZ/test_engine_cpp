//
//  ScrollView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/11/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"

class Buffer;

class ScrollView : public View {

    friend View;

    Point _content_offset;
    Size _content_size;
    
    void draw() override;

    Buffer* _getBuffer() const;
    ScrollView* _setFramebuffer(const Size& size);

    
public:

    ScrollView();
    ScrollView(const Rect &rect);
    
    void setup() override;

    const Point& contentOffset() const { return _content_offset; }
    void setContentOffset(const Point &offset);

};
