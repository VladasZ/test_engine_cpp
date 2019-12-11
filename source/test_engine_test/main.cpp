
#ifdef DESKTOP_BUILD

#include "System.hpp"
#include "Screen.hpp"
#include "TestView.hpp"
#include "TestLevel.hpp"
#include "EffectsScene.hpp"
#include "ExceptionCatch.hpp"

int main() {

	cu::System::alert("koo");


	try {
		te::Screen screen({ 1000, 680 });

        screen.set_view(new TestView());
        screen.set_scene(new EffectsScene());
		screen.set_level(new TestLevel());

		screen.start_main_loop();
	}
	catch (...) {
		cu::System::alert(what());
	}
 
	return 0;

}

#endif
