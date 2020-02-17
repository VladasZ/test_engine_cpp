
#ifdef DESKTOP_BUILD

#include "Screen.hpp"
#include "System.hpp"
#include "TestScene.hpp"
#include "PhysicsScene.hpp"
#include "SelectionScene.hpp"
#include "ExceptionCatch.hpp"
#include "RotationTestScene.hpp"

using namespace ui;


int main() {

    try {
        auto screen = new te::Screen({ 1000, 680 });
        screen->clear_color = gm::Color::gray;
        screen->set_scene(new te::RotationTestScene());
        screen->start_main_loop();
    }
    catch(...) {
        cu::System::alert(what());
    }

    return 0;
}

#endif
