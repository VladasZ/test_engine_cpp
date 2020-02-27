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
#include "Button.hpp"
#include "StackView.hpp"
#include "ImageView.hpp"
#include "ScrollView.hpp"
#include "FoldableView.hpp"


namespace te {

    class TestView : public ui::ScrollView {

    public:

        ui::Label* fold_caption_label;
        ui::StackView* folded_stack_view;
        ui::FoldableView* foldableView;

        ui::View* view;
        ui::Label* label;
        ui::Button* button;
        ui::ImageView* image_view;

        using ScrollView::ScrollView;

        void _setup() override;
        void _layout() override;

    };

}

