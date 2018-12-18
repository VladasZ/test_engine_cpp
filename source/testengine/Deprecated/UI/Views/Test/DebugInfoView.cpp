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
#include "OldInput.hpp"

void DebugInfoView::setup() {
    
	set_size({ 500, 200 });
    add_layout(L::Top(5), L::Left(5));
    
	Events::frame_drawn.subscribe([&] {
        fpsLabel->setText(std::string() + "FPS: " + std::to_string(Window::FPS));
        framesDrawnLabel->setText(std::string() + "Frames drawn: " + std::to_string(Window::frames_drawn));
	});

    Events::touch.subscribe([&] (ui::Point point) {
        touchLabel->setText(std::string() + "Touch: x - " + std::to_string(point.x) + " y - " + std::to_string(point.y));
    });
    
    Debug::info_label = infoLabel;
    
	add_subview(fpsLabel);
	add_subview(framesDrawnLabel);
    add_subview(touchLabel);
    add_subview(infoLabel);
}
