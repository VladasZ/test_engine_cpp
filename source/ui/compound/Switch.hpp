//
//  Switch.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 17/12/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"


namespace ui {

    class Switch : public View {

    private:

        ui::Label* _label;

    protected:

        bool _is_selected = false;

        View* _switch;

    public:

        using View::View;

        bool is_selected() const;

        void set_value(bool);

        void set_caption(const std::string&);

        cu::Event<bool> on_value_changed;

    protected:

        void setup() override;
        void layout() override;

    };

}
