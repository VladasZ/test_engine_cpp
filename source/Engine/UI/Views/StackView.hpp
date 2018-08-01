//
//  StackView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/01/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"

class StackView : public View {

	View::Alignment _alignment = View::Alignment::center;

public:

	using View::View;

	void layout() override;

	StackView* setAlignment(View::Alignment alignment) { _alignment = alignment; return this; }

};