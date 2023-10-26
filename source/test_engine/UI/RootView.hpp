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

        static inline bool _draw_touches;
        static inline Array _touch_views;

    public:

        using View::View;

        void setup() override;

        static void set_draw_touches(bool);

    };

}
