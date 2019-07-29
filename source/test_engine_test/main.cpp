
#ifndef IOS_BUILD

#include "Screen.hpp"
#include "TestScene.hpp"

int main() {
	te::Screen screen({ 800, 800 });

	auto scene = new TestScene();
	screen.set_scene(scene);

	screen.start_main_loop();
    return 0;
}

#endif
