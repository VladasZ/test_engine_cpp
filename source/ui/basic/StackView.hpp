//
//  StackView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/29/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"


namespace ui {

    class StackView : public View {

        float _margin = 0;

    public:

        using View::View;

        void set_margin(float);

    protected:

        void layout() override;

    };

}
