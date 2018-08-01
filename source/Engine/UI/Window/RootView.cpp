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

	_frameBuffer = Window::rootFrameBuffer;

	//FOR(10000) {
	//	addSubview(View::dummy());
	//}

	addSubview(
		(new Label({ 100, 20 }))
		->setText("hello")
		->addLayout(L::Bottom(), L::Left())
	);

	addSubview(
		(new View({ 20, 20, 100, 100 }))
		->setColor(Color::green)
	);

	addSubview(
		(new ImageView({ 100, 100 }))
		->setImage(Image::cat)
		->addLayout(L::CenterH(), L::CenterV())
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(Color::blue)
			->addLayout(L::CenterH(), L::CenterV())
		)
	);

	addSubview(
		(new View({ 200, 200, 100, 100 }))
		->setColor(Color::green)
		->addLayout(L::Bottom(), L::Right())
		->addSubview(
		(new View({ 50, 50 }))
			->setColor(Color::blue)
			->addLayout(L::CenterH(), L::CenterV())
		)
	);

	createSticks();

#if DEBUG_VIEW
	debugInfoView = new DebugInfoView();
	addSubview(debugInfoView);
#endif
}

void RootView::draw() {
	_frameBuffer->draw([&] {
		View::draw();
		for (auto subview : subviews)
			static_cast<RootView*>(subview)->draw();
	});
	Window::resetViewport();
}

void RootView::createSticks() {

	directionStick = new AnalogStickView();
	rotationStick = new AnalogStickView();

	directionStick->addLayout(Layout::Bottom(15), Layout::Right(15));
	rotationStick->addLayout(Layout::Bottom(15), Layout::Left(15));

	//addSubview(directionStick);
	//addSubview(rotationStick);
}
