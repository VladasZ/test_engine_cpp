
#include "Box.hpp"
#include "Grid.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "Paths.hpp"
#include "Model.hpp"
#include "ImageView.hpp"
#include "TestEngine.hpp"
#include "TexturedModel.hpp"
#include "ModelImporter.hpp"
#include "TestSlidersView.hpp"

static scene::Scene* _scene = nullptr;

static scene::Model* up                 = nullptr;
static scene::Model* side               = nullptr;

static scene::Model* indicator          = nullptr;
static scene::Model* vector_model       = nullptr;
static scene::Model* monkey_model       = nullptr;
static scene::TexturedModel* cube_model = nullptr;

void create_scene() {

    _scene = new scene::Scene();
    TestEngine::screen.set_scene(_scene);

    auto x_box = new scene::Box(0.1f); x_box->set_position({ 1.0f, 0, 0 }); _scene->add_object(x_box);
    auto y_box = new scene::Box(0.1f); y_box->set_position({ 0, 1.2f, 0 }); _scene->add_object(y_box);
    auto z_box = new scene::Box(0.1f); z_box->set_position({ 0, 0, 1.0f }); _scene->add_object(z_box);

    _scene->camera->resolution = TestEngine::screen.size;
    _scene->camera->set_target({ 0, 0, 0 });
    _scene->camera->set_position({ 3, 0, 4 });

    _scene->add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

    vector_model = new scene::Model(ModelImporter::import("Vector.blend"));
    vector_model->set_position({ 5, 5, -1 });
    _scene->add_object(vector_model);

    Logvar(vector_model->pivot().to_string());

    cube_model = new scene::TexturedModel(new Image(Paths::images_directory() + "cube_texture.png"), ModelImporter::import("textured_cube.blend"));
    cube_model->set_position({ 10, 10, 0 });
    _scene->add_object(cube_model);

    monkey_model = new scene::Model(ModelImporter::import("monkey.blend"));
    monkey_model->set_position({ -10, -10, 0 });
    _scene->add_object(monkey_model);


    indicator = new scene::Box(0.2);
    _scene->add_object(indicator);

}

void create_ui() {

    auto root_view = TestEngine::screen.root_view();

    auto vec4_view = new Vec4SlidersView();
    vec4_view->add_layout({ ui::Anchor::Width,  240 });
    vec4_view->add_layout({ ui::Anchor::Height, 400 });
    vec4_view->add_layout({ ui::Anchor::TR          });

    vec4_view->on_change.subscribe([&](const Vector4& vector){
        auto target = vector.vector3();
        Info(target.to_string());
        vector_model->look_at(target);
        indicator->set_position(target * vector.w + vector_model->position());
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

