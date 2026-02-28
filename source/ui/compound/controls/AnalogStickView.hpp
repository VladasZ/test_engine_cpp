//
//  AnalogStickView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Event.hpp"
#include "DrawingView.hpp"


namespace ui {

    class AnalogStickView : public DrawingView {

        DrawingView* direction_stick;

        void on_touch_moved(const gm::Point& touch);

    public:

        AnalogStickView();

        void set_direction(const gm::Point&);

        cu::Event<const gm::Point&> on_direction_change;
        
    private:

        void setup() override;
        
    };
}
