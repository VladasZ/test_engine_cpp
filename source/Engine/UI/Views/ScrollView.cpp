//
//  ScrollView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/11/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ScrollView.hpp"

ScrollView::ScrollView() : ScrollView({ 0, 0, 0, 0 }) {}

ScrollView::ScrollView(const Rect &rect) : View(rect) {
    _content_size = rect.size;
}

void ScrollView::setContentOffset(const Point &offset) {
    _content_offset = offset;
}
