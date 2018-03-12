//
//  DrawingView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "DrawingView.hpp"


void DrawingView::draw() {
    View::draw();
    for (auto path : paths) path->draw();
}

void DrawingView::layout() {
    View::layout();
    for (auto path : paths) path->setOrigin(frame.origin);
}

void DrawingView::addPath(Path *path) {
    paths.push_back(path);
}
