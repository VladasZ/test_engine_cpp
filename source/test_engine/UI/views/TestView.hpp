//
//  TestView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Button.hpp"
#include "Switch.hpp"
#include "ImageView.hpp"
#include "DrawingView.hpp"
#include "SelectionScene.hpp"
#include "AnalogStickView.hpp"
#include "Vec4SlidersView.hpp"

class TestView : public ui::View {

public:
   
    using ui::View::View;

    ui::View* revolving_view;

    ui::Button* button;
    ui::Switch* switcher;
    ui::ImageView* image;

#ifndef DESKTOP_BUILD
    static inline Event<gm::Point> on_left_stick_move;
    static inline Event<gm::Point> on_right_stick_move;

    ui::AnalogStickView* left_stick;
    ui::AnalogStickView* right_stick;
#endif

    static inline Vec4SlidersView* sliders = nullptr;

    void _setup() override;
    void _layout() override;

};
