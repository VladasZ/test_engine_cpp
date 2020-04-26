//
//  WorldView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "FileManagerView.hpp"


namespace te {

    class WorldView : public ui::View {
    public:

        FileManagerView* file_manager;

        using View::View;

    protected:

        void _setup() override;
        void _layout() override;

    };

}
