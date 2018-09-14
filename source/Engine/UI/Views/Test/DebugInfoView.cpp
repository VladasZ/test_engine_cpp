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
    
	setSize({ 500, 200 });
    addLayout(L::Top(5), L::Left(5));
    
	Events::frame_drawn.subscribe([&] {
        fpsLabel->setText("FPS: "_s + Window::FPS);
        framesDrawnLabel->setText("Frames drawn: "_s + Window::framesDrawn);
	});

    Events::touch.subscribe([&] (Point point) {
        touchLabel->setText("Touch: x - "_s + point.x + " y - " + point.y);
    });
    
    Debug::infoLabel = infoLabel;
    
	addSubview(fpsLabel);
	addSubview(framesDrawnLabel);
    addSubview(touchLabel);
    addSubview(infoLabel);
}
