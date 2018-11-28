//
//  SwitchView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/28/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "SwitchView.hpp"

SwitchView::SwitchView(const Rect &rect) : View(rect) {
	enable_touch();
}

bool SwitchView::state() const {
	return _state;
}

SwitchView* SwitchView::set_state(bool state) {
	return this;
}

void SwitchView::_on_touch(const Touch& touch) {
	set_state(!_state);
	View::_on_touch(touch);
}
