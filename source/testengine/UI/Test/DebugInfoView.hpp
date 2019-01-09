//
//  DebugInfoView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/9/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"
#include "StackView.hpp"

class DebugInfoView : public ui::View {

private:

    ui::StackView* _stack_view;

    ui::Label* _fps_label;
    ui::Label* _frames_drawn_label;
    ui::Label* _cursor_position_label;

public:

    ui::Label* info_label;

public:

    using View::View;

public:

    void _setup() override;
    void _draw() override;

protected:

    void _layout() override;

};
