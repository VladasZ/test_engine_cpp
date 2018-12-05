//
//  StackView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/01/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"

class StackView : public OldView {

	Alignment _alignment = Alignment::Center;

public:

	using OldView::OldView;

	void layout() override;

	StackView* setAlignment(Alignment alignment) { _alignment = alignment; return this; }

};