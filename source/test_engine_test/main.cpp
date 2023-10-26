
#ifdef DESKTOP_BUILD

#include "TestScreen.hpp"
#include "ResearchScreen.hpp"

int main() {

    auto screen = new te::Screen({ 1000, 600 });
    screen->clear_color = gm::Color::gray;
    screen->set_scene(new WorldScene);
    screen->start_main_loop();

    return 0;
}

#endif
