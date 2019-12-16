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

#import "AppDelegate.h"

#import "Input.hpp"
#import "Screen.hpp"
#import "TestView.hpp"
#import "GLWrapper.hpp"
#import "TestScene.hpp"
#import "TestLevel.hpp"

using namespace gm;

te::Screen* _screen;

@interface Controller : GLKViewController @end @implementation Controller

- (void)viewDidLoad {
    [super viewDidLoad];    
    [self setup];
    
    _screen = new te::Screen({ self.view.frame.size.width,
                               self.view.frame.size.height });
    
   // _screen->set_scene(new TestScene());
#ifndef NO_BOX2D
   // _screen->set_level(new TestLevel());
#endif
    _screen->set_view(new TestView());
}

- (void)update {
    
    //GL::set_clear_color(Color::turquoise);
   // GL::clear();
    
    _screen->update();
}

- (void)setup {
    
    self.preferredFramesPerSecond = 60;
    
    EAGLContext* context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    
    if (context == nil) {
        context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        Log("kEAGLRenderingAPIOpenGLES2");
    }
    else {
        Log("kEAGLRenderingAPIOpenGLES3");
    }

    NSLog(@"%@", context);
    [EAGLContext setCurrentContext:context];
    GLKView* view = (GLKView*)self.view;
    view.context = context;
    view.drawableColorFormat = GLKViewDrawableColorFormatRGBA8888;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat16;
    view.drawableStencilFormat = GLKViewDrawableStencilFormat8;
    view.multipleTouchEnabled = true;
    
    GL::on_window_size_change({ self.view.frame.size.width,
                                self.view.frame.size.height });
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
    GL::on_window_size_change({ self.view.frame.size.width,
                                self.view.frame.size.height });
}

- (ui::Touch*)te_touch_with_touch:(UITouch*)touch event:(ui::Touch::Event)event {
    const auto touch_id = reinterpret_cast<ui::Touch::ID>(touch);
    const auto ns_location = [touch locationInView:self.view];
    const auto location = gm::Point { ns_location.x, ns_location.y };
    return new ui::Touch(touch_id, location, event);
}

- (void)touchesBegan:(NSSet<UITouch*>*)touches
           withEvent:(UIEvent*)event {
    Log("began");
    for (UITouch* touch in touches)
        ui::Input::process_touch_event([self te_touch_with_touch:touch event:ui::Touch::Began]);
}

- (void)touchesMoved:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event {
    Log("moved");
    for (UITouch* touch in touches)
        ui::Input::process_touch_event([self te_touch_with_touch:touch event:ui::Touch::Moved]);
}

- (void)touchesEnded:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event {
    Log("ended");
    for (UITouch* touch in touches)
        ui::Input::process_touch_event([self te_touch_with_touch:touch event:ui::Touch::Ended]);
}

@end

@interface AppDelegate()

@end

@implementation AppDelegate
- (void)applicationDidFinishLaunching:(UIApplication*)application {
    _window = [UIWindow new];
    _window.rootViewController = [Controller new];
    [_window makeKeyAndVisible];
}
@end

#endif
