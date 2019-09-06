//
//  TestView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Button.hpp"
#include "DrawingView.hpp"
#include "AnalogStickView.hpp"

class TestView : public ui::View {

public:

    using ui::View::View;
    
    ui::Button* button;
    ui::AnalogStickView* stick;

    void _setup() override;
    void _layout() override;

};
