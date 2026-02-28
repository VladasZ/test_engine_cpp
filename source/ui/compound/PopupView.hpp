//
//  PopupView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 19/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Button.hpp"
#include "StackView.hpp"


namespace ui {

    class PopupView : public View {

    private:

        ui::Button* _main_button = new ui::Button();

        std::vector<ui::Button*> _buttons;
        ui::StackView* _stack_view;

    public:

        using View::View;

        ~PopupView();

        void set_caption(const std::string&);
        void add_action(const std::string& caption, std::function<void()> action);

    protected:


        void setup() override;
        void layout() override;

    };

}
