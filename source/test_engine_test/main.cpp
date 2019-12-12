
#ifdef DESKTOP_BUILD

#include "GLTest.hpp"
#include "System.hpp"
#include "Screen.hpp"
#include "TestView.hpp"
#include "GLWrapper.hpp"
#include "TestLevel.hpp"
#include "EffectsScene.hpp"
#include "OpenGLHeaders.hpp"
#include "ExceptionCatch.hpp"

int main() {

	try {
		te::Screen screen({ 1000, 680 });

        screen.set_view(new TestView());
        screen.set_scene(new EffectsScene());
		screen.set_level(new TestLevel());


//        glViewport(0, 0, 100, 100);
//
//		GL::start_main_loop([]{
//            te::Test::drawTriangle();
//        });

		screen.start_main_loop();
	}
	catch (...) {
		cu::System::alert(what());
	}
 
	return 0;

}

#endif
