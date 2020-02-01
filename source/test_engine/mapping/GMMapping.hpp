//
//  GMMapping.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 18/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#ifdef USING_MAPPING

#include "Rect.hpp"
#include "Color.hpp"
#include "Mapper.hpp"


namespace gm {


    MAKE_CLASS_INFO(Color,
            MAKE_PROPERTY("r", &Color::r),
            MAKE_PROPERTY("g", &Color::g),
            MAKE_PROPERTY("b", &Color::b),
            MAKE_PROPERTY("a", &Color::a)
    );

    MAKE_CLASS_INFO(Point,
            MAKE_PROPERTY("x", &Point::x),
            MAKE_PROPERTY("y", &Point::y)
    );

    MAKE_CLASS_INFO(Size,
            MAKE_PROPERTY("width",  &Size::width),
            MAKE_PROPERTY("height", &Size::height)
    );

    MAKE_CLASS_INFO(Rect,
            MAKE_PROPERTY("origin", &Rect::origin),
            MAKE_PROPERTY("size",   &Rect::size)
    );


}

#endif
