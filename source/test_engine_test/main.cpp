
#ifdef DESKTOP_BUILD

#include "GMMapping.hpp"
#include "UIMapping.hpp"



#include "Screen.hpp"
#include "TestView.hpp"
#include "JsonMapper.hpp"
#include "JsonUnpacker.hpp"
#include "TestEngineTest.hpp"
#include "TestMappingModels.hpp"

using namespace ui;
using namespace mapping;

#ifndef WINDOWS_BUILD

MAKE_CLASS_INFO(Simple,
                MAKE_PROPERTY("a", &Simple::a)
);

class TestPackView : public View {

public:

    using View::View;

    View*  some_view  = new View ({  10,  11,  12,  13 });
    Label* some_label = new Label({ 100, 200, 300, 400 });

};

MAKE_CLASS_INFO(TestPackView,
                MAKE_PROPERTY("some_view",  &TestPackView::some_view),
                MAKE_PROPERTY("some_label", &TestPackView::some_label)
        );

MAKE_MAPPER(te_mapper,

            InfoOfSimple,

            gm::InfoOfColor,
            gm::InfoOfPoint,
            gm::InfoOfSize,
            gm::InfoOfRect,

            InfoOfImage,

            ui::InfoOfView,
            ui::InfoOfLabel,
            ui::InfoOfFont,
            ui::InfoOfImageView,

            InfoOfTestPackView

);

constexpr auto json_mapper = mapping::JSONMapper<te_mapper>();

constexpr auto json_unpacker = mapping::JsonUnpacker<ui::View, json_mapper>();

auto view  = new View();
auto label = new Label();

auto pack_view = new TestPackView();

TestClass test;


ImageView* image_view = new ImageView({ 1, 2, 3, 4 });

#endif

int main() {

    auto screen = new te::Screen({1000, 1000});
    screen->clear_color = gm::Color::gray;
    screen->set_view(new TestView());
    screen->start_main_loop();


    return 0;
}

#endif
