//
//  UIMapping.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 18/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#ifdef UI_MAPPING_HEADER
static_assert("Mapping headers must be included only once.");
#endif
#define UI_MAPPING_HEADER

#define UNPRIVATE_HEADER "View.hpp"
#include "MappingUnprivate.hpp"

#define UNPRIVATE_HEADER "Label.hpp"
#include "MappingUnprivate.hpp"


#include "Mapper.hpp"

namespace ui {

    MAKE_CLASS_INFO(View,
      MAKE_PROPERTY("frame",                    &View::_frame)
    , MAKE_PROPERTY("subviews",                 &View::_subviews)
    , MAKE_PROPERTY("color",                    &View::background_color)
    , MAKE_PROPERTY("user_interaction_enabled", &View::_user_interaction_enabled)
    );


    MAKE_CLASS_INFO(Label,
      MAKE_PROPERTY("frame",                    &Label::_frame)
    , MAKE_PROPERTY("subviews",                 &Label::_subviews)
    , MAKE_PROPERTY("color",                    &Label::background_color)
    , MAKE_PROPERTY("user_interaction_enabled", &Label::_user_interaction_enabled)
    , MAKE_PROPERTY("text",                     &Label::_text)
    );

}
