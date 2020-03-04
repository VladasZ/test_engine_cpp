
#ifdef DESKTOP_BUILD

#include "Paths.hpp"
#include "Screen.hpp"
#include "System.hpp"
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

    try {
        Paths::dump();
        auto screen = new te::Screen({ 1000, 800 });
        screen->clear_color = gm::Color::gray;
        screen->scene_selection_view->add_scene<WorldScene>();
        screen->scene_selection_view->add_scene<PhysicsScene>();
        screen->scene_selection_view->add_scene<SelectionScene>();
        screen->scene_selection_view->add_scene<RotationTestScene>();
        screen->set_scene(new WorldScene());
        screen->start_main_loop();
    }
    catch(...) {
        cu::System::alert(what());
    }

    return 0;
}

#endif
