//
//  SelectionScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 03/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Grid.hpp"
#include "GlobalEvents.hpp"
#include "SelectionScene.hpp"

using namespace gm;
using namespace scene;

void SelectionScene::_setup() {

    instance = this;

    add_object(new Grid());
    add_object(box1 = new BoxModel(1));
    add_object(box2 = new BoxModel(1));

    box1->color = Color::light_blue.with_alpha(0.2f);
    box2->color = Color::light_blue.with_alpha(0.2f);

    add_object(test_manip = new PositionManipulator());

    test_manip->edit_position() = { 3, 3, 0 };

    box2->edit_position().y = 2;

}
