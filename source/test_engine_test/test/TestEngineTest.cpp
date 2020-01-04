
#ifdef DESKTOP_BUILD

#include "System.hpp"
#include "Screen.hpp"
#include "TestView.hpp"
#include "TestScene.hpp"
#include "ExceptionCatch.hpp"

void test_engine_test() {

    try {
        te::Screen screen({ 800, 680 });

        screen.set_view(new TestView());
        screen.set_scene(new TestScene());
       // screen.set_level(new TestLevel());

        screen.start_main_loop();
    }
    catch (...) {
        cu::System::alert(what());
    }

};

#endif
