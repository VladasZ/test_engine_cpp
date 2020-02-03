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

    box1->color = Color::light_blue;
    box2->color = Color::light_blue;

    box2->edit_position().y = 2;

    add_box(box1->bounding_box);

}
