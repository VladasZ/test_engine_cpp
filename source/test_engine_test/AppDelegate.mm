//
//  AppDelegate.m
//  obj-ios
//
//  Created by Vladas Zakrevskis on 03/06/2019.
//  Copyright © 2019 vz. All rights reserved.
//

#ifdef IOS_BUILD

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

#import "Input.hpp"
#import "GLWrapper.hpp"
#import "TestEngine.hpp"
#import "TestScene.hpp"

@interface Controller : GLKViewController @end @implementation Controller

- (void)viewDidLoad {
    [super viewDidLoad];    
    [self setup];
}

- (void)update {
    TestEngine::screen.update();
}

- (void)setup {
    
    self.preferredFramesPerSecond = 60;
    
    EAGLContext* context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    
    NSLog(@"%@", context);
    [EAGLContext setCurrentContext:context];
    GLKView* view = (GLKView*)self.view;
    view.context = context;
    view.drawableColorFormat = GLKViewDrawableColorFormatRGBA8888;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat16;
    view.drawableStencilFormat = GLKViewDrawableStencilFormat8;
    
    TestEngine::initialize({ static_cast<float>(view.frame.size.width),
        static_cast<float>(view.frame.size.height) });
    
    TestEngine::screen.set_scene(new TestScene());
    
    GL::on_window_size_change(gm::Size { static_cast<float>(self.view.frame.size.width),
                                         static_cast<float>(self.view.frame.size.height)
    });
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
    
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
    GL::on_window_size_change(gm::Size { static_cast<float>(self.view.frame.size.width),
        static_cast<float>(self.view.frame.size.height)
    });
}

- (ui::Touch*)te_touch_with_touch:(UITouch*)touch event:(ui::Touch::Event)event {
    const auto touch_id = reinterpret_cast<ui::Touch::ID>(touch);
    const auto ns_location = [touch locationInView:self.view];
    const auto location = gm::Point { static_cast<float>(ns_location.x),
                                      static_cast<float>(ns_location.y) };
    return new ui::Touch(touch_id, location, event);
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches)
        ui::Input::process_touch_event([self te_touch_with_touch:touch event:ui::Touch::Began]);
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches)
        ui::Input::process_touch_event([self te_touch_with_touch:touch event:ui::Touch::Moved]);
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    for (UITouch* touch in touches)
        ui::Input::process_touch_event([self te_touch_with_touch:touch event:ui::Touch::Ended]);
}

@end

#import "AppDelegate.h"
@interface AppDelegate () @end @implementation AppDelegate
-(void)applicationDidFinishLaunching:(UIApplication *)application {
_w = [UIWindow new]; _w.rootViewController = [Controller new]; [_w makeKeyAndVisible]; }
@end

#endif
