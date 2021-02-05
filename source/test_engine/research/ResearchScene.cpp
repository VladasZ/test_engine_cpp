//
//  ResearchScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 05/02/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#include "Grid.hpp"
#include "ResearchView.hpp"
#include "ResearchScene.hpp"


using namespace te;
using namespace scene;


void ResearchScene::setup() {
    add_object(new Grid({ 200, 200 }, { 20, 20 }));
    
    add_object(vector_a = new VectorModel);
    add_object(vector_b = new VectorModel);
    add_object(vector_c = new VectorModel);

    vector_a->color = gm::Color::red;
    vector_b->color = gm::Color::blue;
}

void ResearchScene::update(float time) {
    Scene::update(time);
    vector_a->visualize_vector(ResearchView::vector_a->position * 10, 10);
    vector_b->visualize_vector(ResearchView::vector_b->position * 10, 10);
    vector_c->visualize_vector(ResearchView::vector_a->position.cross(ResearchView::vector_b->position) * 10, 10);
}
