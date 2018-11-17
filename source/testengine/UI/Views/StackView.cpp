//
//  StackView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/01/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "StackView.hpp"

void StackView::layout() {
	View::layout();

	auto count = subviews.size();
	float interval = _frame.size.height / count;

	for (int i = 0; i < count; i++) {
		auto view = subviews[i];
        view->setX(0);
        view->setY(interval * i);
		//view->setCenter({ _frame.size.width / 2, interval * i + interval / 2 });
	}
}
