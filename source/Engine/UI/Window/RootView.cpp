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

ImageView* imageView;

void RootView::setup() {

	//addSubview(
	//	(new View({ 400, 400 }))
	//	->setColor(Color::green)
	//	->addLayout(L::CenterH(), L::CenterV())
	//	->edit([](View* view) {
	//	FOR(10) {
	//		view->addSubview(View::dummy());
	//	}
	//})
	//	->_setFramebuffer()
	//);

	addSubview(
		(new ImageView({100, 100 }))
		->setImage(Image::cat)
		->setColor(Color::green)
		->addLayout(L::Bottom(), L::Right())
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(Color::blue)
			->addLayout(L::CenterH(), L::CenterV())
		)
	);

	addSubview(
		(new View({ 50, 50 }))
		->setColor(Color::green)
		->addLayout(
			L::Bottom(5, subviews.back()), 
			L::CenterH(5, subviews.back())
		)
	);

	addSubview(
		(new Label({ 0, 100, 100, 20 }))
		->setText("hello2")
		->addLayout(L::Bottom(), L::Right())
	);

	createSticks();

#if DEBUG_VIEW
	debugInfoView = new DebugInfoView();
	addSubview(debugInfoView);
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
