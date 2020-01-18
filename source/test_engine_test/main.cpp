
#ifdef DESKTOP_BUILD

#include "GMMapping.hpp"
#include "UIMapping.hpp"


#include "Screen.hpp"
#include "TestView.hpp"
#include "JsonMapper.hpp"
#include "TestMappingModels.hpp"
#include "TestEngineTest.hpp"

using namespace ui;
using namespace mapping;

MAKE_CLASS_INFO(Simple,
                MAKE_PROPERTY("a", &Simple::a)
);


MAKE_MAPPER(te_mapper,

            InfoOfSimple,

            gm::InfoOfColor,
            gm::InfoOfPoint,
            gm::InfoOfSize,
            gm::InfoOfRect,

            ui::InfoOfView,
            ui::InfoOfLabel

);

constexpr auto json_mapper = mapping::JSONMapper<te_mapper>();

auto view = new View();
auto label = new Label();

int main() {


    json_mapper.print(view);
    json_mapper.print(label);

    return 0;


    auto screen = new te::Screen({1000, 1000});
    screen->clear_color = gm::Color::gray;
    screen->set_view(new TestView());
    screen->start_main_loop();


    return 0;
}

#endif
