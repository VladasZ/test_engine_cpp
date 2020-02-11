//
//  ObjectInfoView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"
#include "StackView.hpp"
#include "CaptionLabel.hpp"

class ObjectInfoView : public ui::StackView {

protected:

    ui::CaptionLabel* _id_label;
    ui::CaptionLabel* _position_label;
    ui::CaptionLabel* _bounding_box_label;

public:

    using StackView::StackView;

    void set_object(scene::Model*);

    void clear();

protected:

    void _setup() override;
    void _layout() override;

};
