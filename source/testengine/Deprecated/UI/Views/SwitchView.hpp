//
//  SwitchView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/28/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"
#include "DeprecatedImage.hpp"

class SwitchView : public OldView {

	bool _state = false;

public:

	ui::Color active_color = ui::C::green;
	ui::Color inactive_color = ui::C::gray;

	SwitchView(const ui::Rect& rect = { });

	bool state() const;
	SwitchView* set_state(bool state);

	void _on_touch(const Touch& touch) override;
};
