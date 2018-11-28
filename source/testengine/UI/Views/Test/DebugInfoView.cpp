//
//  DebugInfoView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "DebugInfoView.hpp"
#include "GlobalEvents.hpp"
#include "Window.hpp"
#include "Input.hpp"

void DebugInfoView::setup() {
    
	set_size({ 500, 200 });
    add_layout(L::Top(5), L::Left(5));
    
	Events::frame_drawn.subscribe([&] {
        fpsLabel->setText("FPS: "_s + Window::FPS);
        framesDrawnLabel->setText("Frames drawn: "_s + Window::framesDrawn);
	});

    Events::touch.subscribe([&] (Point point) {
        touchLabel->setText("Touch: x - "_s + point.x + " y - " + point.y);
    });
    
    Debug::infoLabel = infoLabel;
    
	add_subview(fpsLabel);
	add_subview(framesDrawnLabel);
    add_subview(touchLabel);
    add_subview(infoLabel);
}
