
#ifndef IOS_BUILD

#include "Screen.hpp"
#include "TestView.hpp"
#include "TestLevel.hpp"
#include "TestScene.hpp"

int main() {
    te::Screen screen({ 1000, 680 });

	screen.set_scene(new TestScene());
	screen.set_level(new TestLevel());

	auto test_view = new TestView();
	test_view->add_layout(ui::Anchor::Background);
	screen.root_view()->add_subview(test_view);

#ifdef DESKTOP_BUILD
	screen.start_main_loop();
#endif
    return 0;
}

#endif
