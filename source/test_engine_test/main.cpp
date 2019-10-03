
#ifndef IOS_BUILD

#include "Screen.hpp"
#include "TestView.hpp"
#include "TestLevel.hpp"
#include "EffectsScene.hpp"

int main() {
    te::Screen screen({ 1000, 680 });

	screen.set_scene(new EffectsScene());
	screen.set_view(new TestView());

#ifdef DESKTOP_BUILD
	screen.start_main_loop();
#endif
    return 0;
}

#endif
