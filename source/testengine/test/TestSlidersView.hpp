//
//  TestSlidersView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "XYZSlidersView.hpp"

class TestSlidersView : public ui::View {

    using View::View;

public:

    XYZSlidersView* _box_position_view = nullptr;

    ui::LabeledSliderView* _fov_view = nullptr;

    static TestSlidersView view;

private:

    void _setup() override;
};
