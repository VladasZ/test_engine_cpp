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
    
    Label* fpsLabel         = new Label({ 500, 34 });
	Label* framesDrawnLabel = new Label({ 500, 34 });
	Label* touchLabel       = new Label({ 500, 34 });

public:

	using StackView::StackView;

	void setup() override;
};
