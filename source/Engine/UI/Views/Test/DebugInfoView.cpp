//
//  DebugInfoView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "DebugInfoView.hpp"

void DebugInfoView::setup() {


	setColor(C::gray);

	fpsLabel->setText("Hello");


	addSubview(fpsLabel);
	addSubview(framesDrawnLabel);
	addSubview(touchLabel);
}
