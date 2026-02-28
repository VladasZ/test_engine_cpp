//
//  LabeledSliderView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 1/29/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"
#include "Slider.hpp"


namespace ui {

    class Button;

    class LabeledSliderView : public View {

        Label*  _caption_label = nullptr;
        Label*  _value_label   = nullptr;
        Button* _reset_button  = nullptr;

    public:

        using View::View;

        Slider* slider_view = nullptr;

        void set_caption(const std::string&);
        void set_slider_color(const gm::Color&);

    private:

        void setup() override;
        void layout() override;

    };

}
