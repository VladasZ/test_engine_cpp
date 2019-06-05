
#ifdef IOS_BUILD

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

#else

#include "TestView.hpp"
#include "TestScene.hpp"
#include "TestEngine.hpp"

#endif

int main() {
    
#ifdef IOS_BUILD
    
    char * argv[0];
    
    @autoreleasepool {
        return UIApplicationMain(0, argv, nil, NSStringFromClass([AppDelegate class]));
    }
    
#else
    TestEngine::initialize({ 1000, 680 });
    
    TestEngine::screen.root_view()->add_subview(new TestView({ 200, 200, 300, 300 }));
    TestEngine::screen.set_scene(new TestScene());
    
    TestEngine::start_main_loop([&]{
        
    });
    return 0;
#endif
}


