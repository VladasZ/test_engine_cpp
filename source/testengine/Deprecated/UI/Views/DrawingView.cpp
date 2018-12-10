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
    Shader::ui.set_uniform_color(_color);
	GL::set_viewport(_absolute_frame);
//    buffer->draw();
    Shader::ui_path.use();
 //   Shader::uiPath.setViewportTranslation(_frame.size);
    for (auto path : paths) path->draw();

    draw_subviews();
}

void DrawingView::add_path(Path* path) {
    paths.push_back(path);
}
