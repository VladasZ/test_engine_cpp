//
//  TestScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "math.h"

#include "Grid.hpp"
#include "Mesh.hpp"
#include "Image.hpp"
#include "Plane.hpp"
#include "Paths.hpp"
#include "Screen.hpp"
#include "GLWrapper.hpp"
#include "EffectsScene.hpp"
#include "VectorModel.hpp"
#include "GlobalEvents.hpp"
#include "ModelImporter.hpp"

using namespace gm;
using namespace te;

void EffectsScene::setup() {

    Screen::clear_color = Color::light_gray;

    position_manipulator->is_hidden = false;

    camera->set_target({ 0, 0, 0 });
    camera->set_position({ 1, 1, 1 });
    camera->flying_speed = 0.2f;

    floor = new scene::Plane(Size { 200, 200 });
    floor->color = Color::light_gray;
    add_object(floor);

    cube = new scene::BoxModel(Box { 1 });
    cube->set_position({ 3, 3, 1 });
    add_object(cube);



}

void EffectsScene::each_frame() {

}
