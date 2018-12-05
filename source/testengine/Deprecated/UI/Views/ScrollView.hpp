//
//  ScrollView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/11/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"

class Buffer;

class ScrollView : public OldView {

    friend OldView;

	ui::Point _content_offset;
	ui::Size _content_size;
    
    void draw() override;

    Buffer* _getBuffer() const;
    ScrollView* _setFramebuffer(const ui::Size& size);

    
public:

    ScrollView();
    ScrollView(const ui::Rect &rect);
    
    void setup() override;

    const ui::Point& contentOffset() const { return _content_offset; }
    void setContentOffset(const ui::Point &offset);

};
