
#include "Box.hpp"
#include "Grid.hpp"
#include "Scene.hpp"
#include "TestEngine.hpp"

int main() {

    TestEngine::initialize({ 1000, 1000 });

	auto scene = new scene::Scene();
	TestEngine::screen.set_scene(scene);


	scene->add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

	scene->camera->set_position({ 5, 5, 5 });

    TestEngine::start_main_loop([&]{

    });

    return 0;
}
