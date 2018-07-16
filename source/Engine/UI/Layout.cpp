//
//  Layout.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/15/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Layout.hpp"
#include "View.hpp"
#include "Rect.hpp"
#include "String.hpp"

using namespace std;

void Layout::Base::_layout(View *view) const {
    if (anchor == nullptr) _layoutWithoutAnchor(view);
    _layoutWithAnchor(view);
}

void Layout::Base::_layoutWithoutAnchor(View *view) const {

    const Rect &superFrame = view->superview->_frame;
    Rect &frame = view->_frame;

    auto type = this->type();

    if (isTop()) {
        frame.origin.y = value;
        return;
    }

    if (isBottom()) {
        frame.origin.y = superFrame.size.height - frame.size.height - value;
        return;
    }

    if (isLeft()) {
        frame.origin.x = value;
        return;
    }

    if (isRight()) {
        frame.origin.x = superFrame.size.width - frame.size.width - value;
    }

    if (isCenter()) {
        frame.origin.x = superFrame.size.width / 2 - frame.size.width / 2;
        frame.origin.y = superFrame.size.height / 2 - frame.size.height / 2;
        return;
    }
}


void Layout::Base::_layoutWithAnchor(View *view) const {

    const Rect &anchorFrame = anchor->_frame;
    Rect &frame = view->_frame;

}