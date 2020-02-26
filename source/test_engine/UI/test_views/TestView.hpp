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
#include "ScrollView.hpp"


namespace te {

    class TestView : public ui::ScrollView {

    public:

        ui::View* view;
        ui::Label* label;
        ui::ImageView* image_view;

        using ScrollView::ScrollView;

        void _setup() override;
        void _layout() override;

    };

}

