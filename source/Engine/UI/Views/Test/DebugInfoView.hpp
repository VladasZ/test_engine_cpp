//
//  DebugInfoView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "StackView.hpp"
#include "Label.hpp"

class DebugInfoView : public StackView {
    
	Label* fpsLabel         = new Label();
	Label* framesDrawnLabel = new Label();
	Label* touchLabel       = new Label();

public:

	using StackView::StackView;

	void setup() override;
};
