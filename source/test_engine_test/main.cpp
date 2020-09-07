
#ifdef DESKTOP_BUILD

#include "Screen.hpp"
#include "TestScene.hpp"
#include "WorldScene.hpp"
#include "PhysicsScene.hpp"
#include "SelectionScene.hpp"
#include "ExceptionCatch.hpp"
#include "RotationTestScene.hpp"
#include "SceneSelectionView.hpp"

using namespace ui;
using namespace te;


int main() {

    auto screen = new te::Screen({ 1000, 600 });
    screen->clear_color = gm::Color::gray;
    screen->set_scene(new WorldScene);
    screen->start_main_loop();

    return 0;
}

#endif
