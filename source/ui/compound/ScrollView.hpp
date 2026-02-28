//
//  ScrollView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "Slider.hpp"
#include "RangeConversion.hpp"


namespace ui {

    class ScrollView : public View {

    protected:

        cu::RangeConversion _conversion;

        Slider* _vertical_slider;

    public:

        using View::View;

    protected:

        void setup() override;
        void layout() override;

    };

}
