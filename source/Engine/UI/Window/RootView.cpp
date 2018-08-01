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

ImageView* imageView;

void RootView::setup() {

	addSubview(
		(new StackView({300, 800}))
		->addLayout(L::Bottom(), L::Right())
		->addSubview(
			(new View({50, 50}))
			->setColor(C::green)
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->addSubview(
		(new Label({50, 10}))
			->setText("gelllo")
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(C::green)
		)
		->setColor(C::blue)
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
