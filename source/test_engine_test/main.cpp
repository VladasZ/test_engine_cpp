
#include <math.h>

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

#include "Box.hpp"
#include "Grid.hpp"
#include "Mesh.hpp"
#include "Math.hpp"
#include "Plane.hpp"
#include "Paths.hpp"
#include "Model.hpp"
#include "LogData.hpp"
#include "TestScene.hpp"
#include "ImageView.hpp"
#include "TestEngine.hpp"
#include "TexturedModel.hpp"
#include "ModelImporter.hpp"
#include "TestSlidersView.hpp"

static TestScene* _scene;

void create_ui() {

    auto root_view = TestEngine::screen.root_view();

    auto vec4_view = new Vec4SlidersView();
    vec4_view->add_layout({ ui::Anchor::Width,  240 });
    vec4_view->add_layout({ ui::Anchor::Height, 400 });
    vec4_view->add_layout({ ui::Anchor::TR          });

    vec4_view->on_change.subscribe([&](const Vector4& vector) {
        _scene->set_vector(vector);
    });

    root_view->add_subview(vec4_view);
}

void test_geometry() {
    glm::mat4 g_transform = glm::translate(glm::mat4 { }, { 5, 5, 5 });
    Matrix4   transform   = Matrix4::transform::translation({ 5, 5, 5 });

    Logvar(data_to_string<float>(g_transform));
    Logvar(data_to_string<float>(transform));


    glm::vec4 g_vec = { 1, 1, 1, 1 };
    Vector3     vec = { 1, 1, 1 };

    Logvar(data_to_string<float>(g_vec));
    Logvar(data_to_string<float>(vec));

    g_vec = g_transform * g_vec;
      vec =   transform *   vec;

    Logvar(data_to_string<float>(g_vec));
    Logvar(data_to_string<float>(vec));

}

int main() {

    test_geometry();

   // return 0;

    TestEngine::initialize({ 1000, 680 });

    TestEngine::screen.set_scene(_scene = new TestScene());

    create_ui();

    TestEngine::start_main_loop([&]{

    });

    return 0;
}

