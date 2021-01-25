//
//  TestScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Grid.hpp"
#include "Mesh.hpp"
#include "Image.hpp"
#include "Screen.hpp"
#include "PlaneModel.hpp"
#include "VectorModel.hpp"
#include "EffectsScene.hpp"

using namespace gm;
using namespace te;


void EffectsScene::setup() {
    
    Screen::clear_color = Color::light_gray;
    
    position_manipulator->is_hidden = false;
    
    camera->set_target({ 0, 0, 0 });
    camera->edit_position() = {1, 1, 1 };
    camera->flying_speed = 0.2f;

    floor = new scene::Grid();
    add_object(floor);
    
    //    floor = new scene::Plane(Size { 200, 200 });
    //    floor->color = Color::light_gray;
    //    add_object(floor);
    
    cube = new scene::BoxModel(Box { 0.1f });
    cube->edit_position() = { 3, 3, 1 };
    add_object(cube);
    
    
    vector_model = new scene::VectorModel();
    vector_model->set_scale({ 10, 1, 1 });
    add_object(vector_model);
    
}
