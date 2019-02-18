
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

static scene::Model* vector_model = nullptr;

void create_scene() {

    auto scene = new scene::Scene();
    TestEngine::screen.set_scene(scene);

    scene->camera->resolution = TestEngine::screen.size;
    scene->camera->set_target({ 0, 0, 0.5 });
    scene->camera->set_position({ 1, 0, 0.5 });

    scene->add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

    vector_model = new scene::Model(ModelImporter::import("Vector.blend"));

    scene->add_object(vector_model);

    vector_model->set_pivot({ 0, 0, 0.5 });


    Logvar(vector_model->pivot().to_string());
}

void create_ui() {

    auto root_view = TestEngine::screen.root_view();

    auto vec4_view = new Vec4SlidersView();
    vec4_view->add_layout({ ui::Anchor::Width,  240 });
    vec4_view->add_layout({ ui::Anchor::Height, 400 });
    vec4_view->add_layout({ ui::Anchor::TR          });

    vec4_view->on_change.subscribe([&](const Vector4& vector){
        Logvar(vector.to_string());
        Logvar(vector.vector3().length());
        vector_model->set_rotation(vector);
    });

    root_view->add_subview(vec4_view);

}

int main() {

    TestEngine::initialize({ 1000, 680 });

    create_scene();
    create_ui();

    TestEngine::start_main_loop([&]{

    });

    return 0;
}

