
#ifdef DESKTOP_BUILD

#include "Screen.hpp"
#include "TestView.hpp"
#include "TestScene.hpp"
#include "TestLevel.hpp"
#include "WorldScene.hpp"
#include "PhysicsScene.hpp"
#include "SelectionScene.hpp"
#include "ExceptionCatch.hpp"
#include "RotationTestScene.hpp"
#include "SceneSelectionView.hpp"

using namespace ui;
using namespace te;


int main() {

    Log << "Hello";

    auto screen = new te::Screen({ 1000, 800 });
    screen->clear_color = gm::Color::gray;
    screen->set_view(new TestView);
    //screen->set_scene(new TestScene);
    screen->set_level(new TestLevel);
    screen->start_main_loop();

    return 0;
}

#endif
