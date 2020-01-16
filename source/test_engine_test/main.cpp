
#ifdef DESKTOP_BUILD

#include "View.hpp"
#include "JsonMapper.hpp"
#include "TestEngineTest.hpp"

using namespace ui;


namespace gm {

    MAKE_CLASS_INFO(Color, std::tuple(
            MAKE_PROPERTY("r", &Color::r),
            MAKE_PROPERTY("g", &Color::g),
            MAKE_PROPERTY("b", &Color::b),
            MAKE_PROPERTY("a", &Color::a)
    ));

    MAKE_CLASS_INFO(Point, std::tuple(
            MAKE_PROPERTY("x", &Point::x),
            MAKE_PROPERTY("y", &Point::y)
    ));

    MAKE_CLASS_INFO(Size, std::tuple(
            MAKE_PROPERTY("width", &Size::width),
            MAKE_PROPERTY("height", &Size::height)
    ));

    MAKE_CLASS_INFO(Rect, std::tuple(
            MAKE_PROPERTY("origin", &Rect::origin),
            MAKE_PROPERTY("size", &Rect::size)
    ));

}

namespace ui {

    MAKE_CLASS_INFO(View, std::tuple(
            MAKE_PROPERTY("color", &View::background_color),
            MAKE_PROPERTY("frame", &View::_frame)
    ));

}

MAKE_MAPPER(

        gm::InfoOfColor,
        gm::InfoOfPoint,
        gm::InfoOfSize,
        gm::InfoOfRect,

        ui::InfoOfView

        );

constexpr auto json_mapper = mapping::JSONMapper<mapper>();


constexpr gm::Color test { 1, 2, 3 };
constexpr gm::Color test2 { 1, 2, 3 };

static_assert(mapper.is_equals(test, test2));

int main() {
    //test_engine_test();

    View view;

    view.background_color = gm::Color::gray;
    view._frame = { 1, 2, 3, 4 };


    json_mapper.test(view);


    return 0;
}

#endif
