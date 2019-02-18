
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

    //auto sliders = new TestSlidersView();

    //TestEngine::screen.root_view()->add_subview(new TestSlidersView());


    auto view = new ui::ImageView({200, 500, 300, 300 }, new ui::Image(Paths::images_directory() + "cat.jpg"));
    view->color = Color::green;
    //view->add_layout(ui::Layout(ui::Anchor::BR));

    TestEngine::screen.root_view()->add_subview(view);

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

