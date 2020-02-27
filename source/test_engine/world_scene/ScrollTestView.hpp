//
//  ScrollTestView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "TestView.hpp"
#include "StackView.hpp"
#include "FoldableView.hpp"
#include "FileManagerView.hpp"

namespace te {

    class ScrollTestView : public ui::View {
    public:

        TestView* test_view;
        FileManagerView* file_manager;

        using View::View;

    protected:

        void _setup() override;
        void _layout() override;

    };

}
