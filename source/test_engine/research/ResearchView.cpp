//
//  ResearchView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 05/02/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//
#include "ResearchView.hpp"


using namespace te;
using namespace ui;


void ResearchView::setup() {
    init_view(vector_a, { 200, 280 })->set_range(-2, 2);
    init_view(vector_b, { 200, 280 })->set_range(-2, 2);
}

void ResearchView::layout() {
    vector_a->place.bl();
    vector_b->place.br();
}

