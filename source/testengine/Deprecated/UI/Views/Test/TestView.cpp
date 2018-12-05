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

    add_subview(
        (new ImageView({_frame.size.width, _frame.size.height}))
        ->setImage(I::square)
    );
    
	add_subview(
		OldView::make({ 50, 50 })
		->set_color(Random::color())
		->add_layout(L::Top(), L::Right())
	);

	add_subview(
		OldView::make({ 20, 20 })
		->set_color(Random::color())
		->add_layout(L::Top(10, subviews.back()), L::CenterH(subviews.back()))
	);

	add_subview(
		OldView::make({ 10, 10 })
		->set_color(Random::color())
		->add_layout(L::Right(5, subviews.back()), L::CenterV(subviews.back()))
	);

	add_subview(
		(new Label({100, 42}))
		->setText("Hellob")
		->set_color(Random::color())
		->add_layout(L::Top(), L::Left())
	);

	add_subview(
		(new ImageView({ 100, 100 }))
		->setImage(I::text)
		->add_layout(L::CenterH(), L::CenterV())
	);
}
