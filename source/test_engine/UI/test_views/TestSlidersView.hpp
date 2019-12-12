//
//  TestSlidersView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vec4SlidersView.hpp"

class TestSlidersView : public ui::View {

    using View::View;

public:

    Vec4SlidersView* _rotation_view = nullptr;

    static TestSlidersView view;

private:

    void _setup() override;
};
