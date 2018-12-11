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
        (new OldImageView({_frame.size.width, _frame.size.height}))
        ->set_image(Image::square)
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
		(new OldImageView({ 100, 100 }))
		->set_image(Image::text)
		->add_layout(L::CenterH(), L::CenterV())
	);
}
