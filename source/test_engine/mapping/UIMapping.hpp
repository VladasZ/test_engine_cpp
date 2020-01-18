//
//  UIMapping.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 18/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "Mapper.hpp"

namespace ui {

    MAKE_CLASS_INFO(View,
              MAKE_PROPERTY("frame",                    &View::_frame)
            , MAKE_PROPERTY("subviews",                 &View::_subviews)
      ,       MAKE_PROPERTY("color",                    &View::background_color)
            , MAKE_PROPERTY("user_interaction_enabled", &View::_user_interaction_enabled)
    );

}
