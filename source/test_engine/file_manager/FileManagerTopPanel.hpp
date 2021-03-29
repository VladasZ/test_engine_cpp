//
//  FileManagerTopPanel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 29/04/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Event.hpp"
#include "Label.hpp"
#include "ImageButton.hpp"


namespace te {

    class FileManagerTopPanel : public ui::View {

    private:

        ui::ImageButton* _up_button;
        ui::Label* _path_label;

    public:

        using View::View;

        cu::Event<> on_press_up_button;

        void set_path(const cu::Path&) const;

    private:

        void setup() override;
        void layout() override;

    };

}
