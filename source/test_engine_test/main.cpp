
#ifndef IOS_BUILD

#include "TestView.hpp"
#include "TestScene.hpp"
#include "TestEngine.hpp"

int main() {
    
 
    TestEngine::initialize({ 1000, 680 });
    
    TestEngine::screen.root_view()->add_subview(new TestView({ 200, 200, 300, 300 }));
    TestEngine::screen.set_scene(new TestScene());
    
    TestEngine::start_main_loop([&]{
        
    });
    return 0;
}

#endif
