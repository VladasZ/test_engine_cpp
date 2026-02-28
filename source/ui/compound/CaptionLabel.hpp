//
//  CaptionLabel.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 11/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"


namespace ui {

    class CaptionLabel : public View {

    protected:

        Label* _caption_label;
        Label* _text_label;

    public:

        using View::View;

        void set_caption(const std::string&);
        void set_text(const std::string&);

    protected:

        void setup() override;
        void layout() override;

    };

}
