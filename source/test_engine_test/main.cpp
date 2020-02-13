
#ifdef DESKTOP_BUILD

#include "GMMapping.hpp"
#include "UIMapping.hpp"

#include "Screen.hpp"
#include "System.hpp"
#include "TestView.hpp"
#include "TestScene.hpp"
#include "PhysicsScene.hpp"
#include "SelectionScene.hpp"
#include "TestEngineTest.hpp"
#include "ExceptionCatch.hpp"

using namespace ui;


int main() {

    try {
        auto screen = new te::Screen({ 1000, 680 });
        screen->clear_color = gm::Color::gray;
        screen->set_view(new TestView());
        screen->set_scene(new SelectionScene());
        screen->start_main_loop();
    }
    catch(...) {
        cu::System::alert(what());
    }

    return 0;
}

#endif
