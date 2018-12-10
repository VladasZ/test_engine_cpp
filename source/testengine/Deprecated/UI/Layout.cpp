//
//  Layout.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/15/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Layout.hpp"
#include "OldView.hpp"
#include "Rect.hpp"
#include "Dictionary.hpp"

using namespace std;

void Layout::Base::_layout(OldView* view) const {
    if (anchor == nullptr) _layoutWithoutAnchor(view);
    else                   _layoutWithAnchor(view);
}

void Layout::Base::_layoutWithoutAnchor(OldView* view) const {

    const ui::Rect &superFrame = view->superview->_frame;
	ui::Rect &frame = view->_frame;

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
        return;
    }

    if (isCenterH()) {
        frame.origin.x = superFrame.size.width / 2 - frame.size.width / 2;
        return;
    }

    if (isCenterV()) {
        frame.origin.y = superFrame.size.height / 2 - frame.size.height / 2;
        return;
    }
}

void Layout::Base::_layoutWithAnchor(OldView* view) const {

    const ui::Rect &anchorFrame = anchor->_frame;
	ui::Rect &frame = view->_frame;

    if (isTop()) {
        frame.origin.y = anchorFrame.max_y() + value;
        return;
    }

    if (isBottom()) {
        frame.origin.y = anchorFrame.origin.y - frame.size.height - value;
        return;
    }

    if (isLeft()) {
        frame.origin.x = anchorFrame.max_x() + value;
        return;
    }

    if (isRight()) {
        frame.origin.x = anchorFrame.origin.x - frame.size.width - value;
        return;
    }

    if (isCenterH()) {
        frame.origin.x = anchorFrame.origin.x + anchorFrame.size.width / 2 - frame.size.width / 2 + value;
        return;
    }

    if (isCenterV()) {
        frame.origin.y = anchorFrame.origin.y + anchorFrame.size.height / 2 - frame.size.height / 2 + value;
        return;
    }
}

Layout::Base* Layout::fromAlignment(Alignment alignment) {
	switch (alignment) {
		case Alignment::Left:   return L::Left();
		case Alignment::Right:  return L::Right();
		case Alignment::Center: return L::CenterH();
	}
	return L::CenterH();
}