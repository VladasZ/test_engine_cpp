
#include <math.h>

#include "Box.hpp"
#include "Grid.hpp"
#include "Mesh.hpp"
#include "Math.hpp"
#include "Plane.hpp"
#include "Scene.hpp"
#include "Paths.hpp"
#include "Model.hpp"
#include "ImageView.hpp"
#include "TestEngine.hpp"
#include "TexturedModel.hpp"
#include "ModelImporter.hpp"
#include "TestSlidersView.hpp"

static scene::Scene* _scene = nullptr;

static scene::Model* up                  = nullptr;
static scene::Model* side                = nullptr;

static scene::Model* indicator           = nullptr;
static scene::Model* direction_vector    = nullptr;
static scene::Model* plane_normal_vector = nullptr;
static scene::Model* up_vector           = nullptr;
static scene::Model* monkey_model        = nullptr;
static scene::Model* cube_model          = nullptr;

void create_scene() {

    _scene = new scene::Scene();
    TestEngine::screen.set_scene(_scene);

    auto x_box = new scene::Box(0.1f); x_box->set_position({ 1.0f, 0, 0 }); _scene->add_object(x_box);
    auto y_box = new scene::Box(0.1f); y_box->set_position({ 0, 1.2f, 0 }); _scene->add_object(y_box);
    auto z_box = new scene::Box(0.1f); z_box->set_position({ 0, 0, 1.0f }); _scene->add_object(z_box);

    _scene->camera->resolution = TestEngine::screen.size;
    _scene->camera->set_target({ 0, 0, 0 });
    _scene->camera->set_position({ 0.5, 0, 1 });

    _scene->add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

    cube_model = ModelImporter::import("textured_cube.blend", new Image(Paths::images_directory() + "cube_texture.png"));
    _scene->add_object(cube_model);
    cube_model->set_scale(0.1f);

    direction_vector = ModelImporter::import("Vector.blend");
    _scene->add_object(direction_vector);

    plane_normal_vector = ModelImporter::import("Vector.blend");
    _scene->add_object(plane_normal_vector);

    up_vector = ModelImporter::import("Vector.blend");
    _scene->add_object(up_vector);

    indicator = new scene::Box(0.05f);
    _scene->add_object(indicator);

    auto plane = new scene::Plane({ 50, 50 });
    plane->set_position({ 0, 0, -0.1f});
    //_scene->add_object(plane);

}

void create_ui() {

    auto root_view = TestEngine::screen.root_view();

    auto vec4_view = new Vec4SlidersView();
    vec4_view->add_layout({ ui::Anchor::Width,  240 });
    vec4_view->add_layout({ ui::Anchor::Height, 400 });
    vec4_view->add_layout({ ui::Anchor::TR          });

    vec4_view->on_change.subscribe([&](const Vector4& vector) {

        auto angle = vector.w;
        Logvar(angle);
        angle -= math::half_pi<float>;
        Logvar(vector.to_string());

        const Vector3 up_vector_point { 0, 1, 0 };
        Vector3 direction_vector_point { cos(angle), 0, sin(angle) };
        auto plane_normal = up_vector_point.cross(direction_vector_point);


        up_vector->look_at({ 0, 1, 0 });
        direction_vector->look_at(direction_vector_point);
        plane_normal_vector->look_at(plane_normal);

        cube_model->look_at(vector.vector3());

        direction_vector   ->add_rotation(cube_model->rotation_matrix());
        up_vector          ->add_rotation(cube_model->rotation_matrix());
        plane_normal_vector->add_rotation(cube_model->rotation_matrix());

        indicator->set_position(vector.vector3());

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

