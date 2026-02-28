//
//  TextField.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 03/06/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"


namespace ui {

    class TextField : public Label {

    private:

        bool _is_focused = false;
        View* _cursor;

    public:

        using Label::Label;

    protected:

        void setup() override;
        void layout() override;

    };

}
