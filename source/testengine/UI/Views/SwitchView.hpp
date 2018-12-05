//
//  SwitchView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/28/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"
#include "Image.hpp"

class SwitchView : public View {

	bool _state = false;

public:

	Color active_color = C::green;
	Color inactive_color = C::gray;

	SwitchView(const Rect &rect = Rect());

	bool state() const;
	SwitchView* set_state(bool state);

	void _on_touch(const Touch& touch) override;
};
