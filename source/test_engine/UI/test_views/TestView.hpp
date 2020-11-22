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

        ui::Label* fold_caption_label = nullptr;
        ui::StackView* folded_stack_view = nullptr;
        ui::FoldableView* foldableView = nullptr;

        ui::View* view = nullptr;
        ui::Label* label = nullptr;
        ui::Button* button = nullptr;
        ui::ImageView* image_view = nullptr;

        using ScrollView::ScrollView;

        void setup() override;
        void layout() override;

    };

}

