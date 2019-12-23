
#ifdef DESKTOP_BUILD

#include "GLTest.hpp"
#include "System.hpp"
#include "Screen.hpp"
#include "TestView.hpp"
#include "GLWrapper.hpp"
#include "TestLevel.hpp"
#include "TestScene.hpp"
#include "EffectsScene.hpp"
#include "OpenGLHeaders.hpp"
#include "ExceptionCatch.hpp"
#include "TestEngineTest.hpp"

void test_engine_test() {

    try {
        te::Screen screen({ 1200, 800 });

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
