//
//  FoldableView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 27/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "Button.hpp"


namespace ui {

    class FoldableView : public View {

    public:

        cu::Event<bool> on_folded;

        FoldableView(View* main, View* folded);

        void set_folded(bool);

    protected:

        View* _main_view;
        View* _hidden_view;

        Button* _unfold_button;

        bool _folded = true;

        void setup() override;
        void layout() override;

    };

}
