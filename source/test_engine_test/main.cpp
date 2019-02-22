
#include <math.h>

#include "Box.hpp"
#include "Grid.hpp"
#include "Mesh.hpp"
#include "Math.hpp"
#include "Plane.hpp"
#include "Paths.hpp"
#include "Model.hpp"
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

int main() {

    TestEngine::initialize({ 1000, 680 });

    TestEngine::screen.set_scene(_scene = new TestScene());

    create_ui();

    TestEngine::start_main_loop([&]{

    });

    return 0;
}

