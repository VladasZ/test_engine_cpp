//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "Input.hpp"
#include "AnalogStickView.hpp"
#include "ScrollView.hpp"
#include "Macro.hpp"
#include "Label.hpp"
#include "System.hpp"
#include "ImageView.hpp"
#include "Glyph.hpp"
#include "DrawingView.hpp"
#include "FrameBuffer.hpp"
#include "StackView.hpp"
#include "TestView.hpp"

ImageView* imageView;

void RootView::setup() {

	addSubview(
		(new TestView({300, 300}))
		->addLayout(L::CenterH(), L::CenterV())
	);

	//addSubview(
	//	View::make({ 100, 100 })
	//	->addLayout(L::Right(), L::Top())
	//	->setColor(Color::blue)
	//);

	//addSubview(
	//	View::make({ 100, 100 })
	//	->addLayout(L::Right(), L::Bottom())
	//	->setColor(Color::blue)
	//);

	//addSubview(
	//	View::make({ 100, 100 })
	//	->addLayout(L::Left(), L::Bottom())
	//	->setColor(Color::blue)
	//);

	createSticks();

#if DEBUG_VIEW
	addSubview(
		(new DebugInfoView({500, 100}))
		->addLayout(L::Top(), L::Left())
	);
#endif
}

void RootView::createSticks() {

	directionStick = new AnalogStickView();
	rotationStick = new AnalogStickView();

	directionStick->addLayout(L::Bottom(15), L::Right(15));
	rotationStick->addLayout(L::Bottom(15), L::Left(15));

	//addSubview(directionStick);
	//addSubview(rotationStick);
}
