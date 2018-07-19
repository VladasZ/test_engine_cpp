//
//  ScrollView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/11/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"

class ScrollView : public View {

    friend View;

    Point _content_offset;
    Size _content_size;

public:

    ScrollView();
    ScrollView(const Rect &rect);

    void setContentOffset(const Point &offset);

};