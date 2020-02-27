//
//  ScrollTestView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include <source/ui/BasicViews/StackView.hpp>
#include "View.hpp"
#include "TestView.hpp"
#include "FoldableView.hpp"

namespace te {

    class ScrollTestView : public ui::View {
    public:

        TestView* testView;

        using View::View;

        void _setup() override;
        void _layout() override;

    };

}
