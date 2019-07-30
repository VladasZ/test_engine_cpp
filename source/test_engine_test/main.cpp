
#ifndef IOS_BUILD

#include "Screen.hpp"
#include "TestLevel.hpp"
#include "TestScene.hpp"

int main() {
	te::Screen screen({ 800, 800 });

	screen.set_scene(new TestScene());
	screen.set_level(new TestLevel());
#ifdef DESKTOP_BUILD
	screen.start_main_loop();
#endif
    return 0;
}

#endif
