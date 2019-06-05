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

#import "GLWrapper.hpp"
#import "TestEngine.hpp"
#import "TestScene.hpp"

@interface Controller : GLKViewController @end @implementation Controller

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setup];    
}

- (void)update {
    //TestEngine::screen.update();
    GL::clear();
    GL::set_clear_color(gm::Color::random());
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
    
//    TestEngine::initialize({ static_cast<float>(view.frame.size.width),
//        static_cast<float>(view.frame.size.height) });
    
    //TestEngine::screen.set_scene(new TestScene());
}

@end

#import "AppDelegate.h"
@interface AppDelegate () @end @implementation AppDelegate
-(void)applicationDidFinishLaunching:(UIApplication *)application {
_w = [UIWindow new]; _w.rootViewController = [Controller new]; [_w makeKeyAndVisible]; }
@end

#endif
