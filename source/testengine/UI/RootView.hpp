//
//  RootView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/8/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"

namespace te {

class RootView : public ui::View {

public:

    using View::View;

    void _setup() override;
    void _draw() override;

public:

    void _layout() override;

};

}
