//
//  XYZSlidersView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"
#include "XYZPack.hpp"
#include "RangeConversion.hpp"
#include "LabeledSliderView.hpp"


namespace te {

    class XYZSlidersView : public ui::View {

    public:

        cu::XYZPack<ui::LabeledSliderView*> sliders = nullptr;

        using View::View;

        ~XYZSlidersView() override;

        gm::Vector3 position;

        cu::Event<gm::Vector3> on_change;

    private:

        void setup() override;
        void layout_subviews() override;

    };

}
