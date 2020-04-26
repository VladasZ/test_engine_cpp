//
//  WorldView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "TestView.hpp"
#include "FileManagerView.hpp"


namespace te {

    class WorldView : public ui::View {
    public:

        TestView* test_view;
        FileManagerView* file_manager;

        using View::View;

    protected:

        void setup() override;
        void layout_subviews() override;

    };

}
