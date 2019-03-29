//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TestView.hpp"


void TestView::_setup() {

    _drawing_view = new ui::DrawingView({ 300, 300 });

    //_drawing_view->color = gm::Color::turquoise;

    auto path = new gm::Path();

    path->add_point({ 10, 10 });
    path->add_point({ 20,  0 });
    path->add_point({  0, 30 });
    path->add_point({ 40,  0 });

    path->add_point({ 100,  100 });
    path->add_point({   0,  100 });
    path->add_point({   0,    0 });
    path->add_point({ 100,    0 });


    path->add_point({ 40,  0 });
    path->add_point({ 40,  0 });

    _drawing_view->add_path(path);

    add_subview(_drawing_view);

}
