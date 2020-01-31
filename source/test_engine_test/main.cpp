
#ifdef DESKTOP_BUILD

#include "GMMapping.hpp"
#include "UIMapping.hpp"

#include "Screen.hpp"
#include "TestView.hpp"
#include "TestEngineTest.hpp"

using namespace ui;


int main() {

    auto screen = new te::Screen({1000, 1000});
    screen->clear_color = gm::Color::gray;
    screen->set_view(new TestView());
    screen->start_main_loop();


    return 0;
}

#endif
