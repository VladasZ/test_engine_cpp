//
//  TestView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "Label.hpp"
#include "ImageView.hpp"

namespace te {

    class TestView : public ui::View {

    public:

        ui::View* view;
        ui::Label* label;
        ui::ImageView* image_view;

        using View::View;

        void _setup() override;
        void _layout() override;

    };

}

