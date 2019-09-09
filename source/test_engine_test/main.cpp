
#ifndef IOS_BUILD

#include "Screen.hpp"
#include "TestView.hpp"
#include "TestLevel.hpp"
#include "TestScene.hpp"

int main() {
    te::Screen screen({ 1000, 680 });

	screen.set_scene(new TestScene());
	screen.set_level(new TestLevel());
	screen.set_view(new TestView());
	
#ifdef DESKTOP_BUILD
	screen.start_main_loop();
#endif
    return 0;
}

#endif
