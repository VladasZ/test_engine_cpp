//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/04/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "TestView.hpp"
#include "Label.hpp"
#include "Random.hpp"

void TestView::setup() {

    addSubview(
        (new ImageView({_frame.size.width, _frame.size.height}))
        ->setImage(I::square)
    );
    
	addSubview(
		View::make({ 50, 50 })
		->setColor(Random::color())
		->addLayout(L::Top(), L::Right())
	);

	addSubview(
		View::make({ 20, 20 })
		->setColor(Random::color())
		->addLayout(L::Top(10, subviews.back()), L::CenterH(subviews.back()))
	);

	addSubview(
		View::make({ 10, 10 })
		->setColor(Random::color())
		->addLayout(L::Right(5, subviews.back()), L::CenterV(subviews.back()))
	);

	addSubview(
		(new Label({100, 42}))
		->setText("Hellob")
		->setColor(Random::color())
		->addLayout(L::Top(), L::Left())
	);

	addSubview(
		(new ImageView({ 100, 100 }))
		->setImage(I::text)
		->addLayout(L::CenterH(), L::CenterV())
	);
}
