//
//  Button.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 28/01/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "Event.hpp"
#include "Label.hpp"


namespace ui {

    class Button : public View {

    protected:

        Label* _caption_label;

    public:

        cu::Event<> on_press;

        Button(const gm::Rect& = { });

        Button* set_caption(const std::string&);
        Button* set_alignment(Edge);

    protected:

        void layout() override;

    };

}
