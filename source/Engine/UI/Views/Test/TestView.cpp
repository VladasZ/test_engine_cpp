//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/04/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "TestView.hpp"
#include "Label.hpp"

void TestView::setup() {

	addSubview(
		View::make({ 50, 50 })
		->setColor(C::random())
		->addLayout(L::Top(), L::Right())
	);

	addSubview(
		View::make({ 20, 20 })
		->setColor(C::random())
		->addLayout(L::Top(10, subviews.back()), L::CenterH(subviews.back()))
	);

	addSubview(
		View::make({ 10, 10 })
		->setColor(C::random())
		->addLayout(L::Right(5, subviews.back()), L::CenterV(subviews.back()))
	);

	addSubview(
		(new Label({100, 42}))
		->setText("Hellob")
		->setColor(C::random())
		->addLayout(L::Top(), L::Left())
	);

	addSubview(
		(new ImageView({ 100, 100 }))
		->setImage(I::text)
		->addLayout(L::CenterH(), L::CenterV())
	);
}
