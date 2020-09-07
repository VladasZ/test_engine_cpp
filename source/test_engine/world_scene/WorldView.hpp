//
//  WorldView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"
#include "TestView.hpp"
#include "Button.hpp"

namespace te {

    class WorldView : public ui::View {
    public:

        TestView* test_view;
        ui::View* square;
        ui::Button* change_color_button;

        using View::View;

    protected:

        void setup() override;
        void layout_subviews() override;

    };

}
