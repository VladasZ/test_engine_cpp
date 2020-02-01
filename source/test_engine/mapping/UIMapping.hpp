//
//  UIMapping.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 18/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#ifdef USING_MAPPING

#ifdef UI_MAPPING_HEADER
static_assert(false, "Mapping headers must be included only once.");
#endif
#define UI_MAPPING_HEADER

#define protected public
#define private public

#include "Label.hpp"
#include "Button.hpp"
#include "Switch.hpp"
#include "ImageView.hpp"

#undef protected
#undef private

#include "Mapper.hpp"



MAKE_CLASS_INFO(Image,
                MAKE_PROPERTY("path", &Image::_path));

namespace ui {

    MAKE_CLASS_INFO(View,
                    MAKE_PROPERTY("frame",                    &View::_frame),
                    MAKE_PROPERTY("subviews",                 &View::_subviews),
                    MAKE_PROPERTY("color",                    &View::background_color),
                    MAKE_PROPERTY("user_interaction_enabled", &View::_user_interaction_enabled)
    );

    MAKE_CLASS_INFO(Font,
                    MAKE_PROPERTY("size", &Font::_size),
                    MAKE_PROPERTY("file", &Font::_file)
    );

    MAKE_CLASS_INFO(Label,
                    MAKE_PROPERTY("font", &Label::_font),
                    MAKE_PROPERTY("text", &Label::_text)
    );

    MAKE_CLASS_INFO(Button,
                    MAKE_PROPERTY("caption_label", &Button::_caption_label)
    );

    MAKE_CLASS_INFO(Switch,
                    MAKE_PROPERTY("is_selected", &Switch::_is_selected)
    );

    MAKE_CLASS_INFO(ImageView,
                    MAKE_PROPERTY("content_mode", &ImageView::_content_mode),
                    MAKE_PROPERTY("image",        &ImageView::_image)
    );

}

#endif
