//
//  DrawingView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "DrawingView.hpp"
#include "Shader.hpp"
#include "Buffer.hpp"


void DrawingView::draw() {
    Shader::ui.use();
    Shader::ui.setUniformColor(color);
    _absoluteFrame.setViewport();
//    buffer->draw();
    Shader::uiPath.use();
    Shader::uiPath.setViewportTranslation(_frame.size);
    for (auto path : paths) path->draw();

    drawSubviews();
}

void DrawingView::layout() {
    View::layout();
}

void DrawingView::addPath(Path *path) {
    paths.push_back(path);
}
