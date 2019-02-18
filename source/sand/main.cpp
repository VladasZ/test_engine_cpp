
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
static scene::Scene* _scene        = nullptr;

void create_scene() {

    _scene = new scene::Scene();
    TestEngine::screen.set_scene(_scene);

    auto x_box = new scene::Box(0.1); x_box->set_position({ 1.0f, 0, 0 }); _scene->add_object(x_box);
    auto y_box = new scene::Box(0.1); y_box->set_position({ 0, 1.2f, 0 }); _scene->add_object(y_box);
    auto z_box = new scene::Box(0.1); z_box->set_position({ 0, 0, 1.0f }); _scene->add_object(z_box);



    _scene->camera->resolution = TestEngine::screen.size;
    _scene->camera->set_target({ 0, 0, 0.5 });
    _scene->camera->set_position({ 1, 0, 0.5 });

    _scene->add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

    //vector_model = new scene::Model(ModelImporter::import("Vector.blend"));
    vector_model = new scene::Box(0.5);

    _scene->add_object(vector_model);

    Logvar(vector_model->pivot().to_string());

    //vector_model->set_pivot(vector_model->pivot());

}

void create_ui() {

    auto root_view = TestEngine::screen.root_view();

    auto vec4_view = new Vec4SlidersView();
    vec4_view->add_layout({ ui::Anchor::Width,  240 });
    vec4_view->add_layout({ ui::Anchor::Height, 400 });
    vec4_view->add_layout({ ui::Anchor::TR          });

    vec4_view->on_change.subscribe([&](const Vector4& vector){
        auto target = vector.vector3() * vector.w;
        Info(target.to_string());
        vector_model->look_at(target);
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

