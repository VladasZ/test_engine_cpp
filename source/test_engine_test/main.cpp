
#include <math.h>

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

#include "Box.hpp"
#include "Grid.hpp"
#include "Mesh.hpp"
#include "Plane.hpp"
#include "Paths.hpp"
#include "Model.hpp"
#include "GmMath.hpp"
#include "LogData.hpp"
#include "TestView.hpp"
#include "TestScene.hpp"
#include "TestEngine.hpp"
#include "ModelImporter.hpp"
#include "XYZSlidersView.hpp"
#include "TestSlidersView.hpp"

using namespace gm;

int main() {

    TestEngine::initialize({ 1000, 680 });

    TestEngine::screen.root_view()->add_subview(new TestView({ 200, 200, 300, 300 }));
    TestEngine::screen.set_scene(new TestScene());

    TestEngine::start_main_loop([&]{

    });

    return 0;
}

