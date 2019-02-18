
#include "Box.hpp"
#include "Grid.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "Paths.hpp"
#include "Model.hpp"
#include "ImageView.hpp"
#include "TestEngine.hpp"
#include "ModelImporter.hpp"
#include "TestSlidersView.hpp"

int main() {

    TestEngine::initialize({ 1000, 680 });

    auto root_view = TestEngine::screen.root_view();

    auto view = new ui::View({ 0, 600, 50, 50 });
    view->color = Color::turquoise;
    root_view->add_subview(view);

    auto image_view = new ui::ImageView({ 200, 500, 300, 300 }, new ui::Image(Paths::images_directory() + "cat.jpg"));
    image_view->color = Color::green;

    root_view->add_subview(image_view);

	auto scene = new scene::Scene();
	TestEngine::screen.set_scene(scene);

    scene->camera->set_target({ 0, 0, 0.5 });
    scene->camera->set_position({ 1, 1, 1.5 });

	scene->add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

    auto vector = new scene::Model(ModelImporter::import("Vector.blend"));

    scene->add_object(vector);


    Logvar(vector->pivot().to_string());


    TestEngine::start_main_loop([&]{

    });

    return 0;
}

