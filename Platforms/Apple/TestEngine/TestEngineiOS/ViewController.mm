//
//  ViewController.m
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#import "ViewController.h"
#include "Window.hpp"
#include "Input.hpp"
#include "STL.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
        
    [self setup];
    
    Window::initialize(self.view.frame.size.width, self.view.frame.size.height);
}

- (void)update {
    
    Window::update();
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    
    Window::sizeChanged(0, self.view.frame.size.width, self.view.frame.size.height);
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
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
  
    UITouch *touch = [touches anyObject];
    CGPoint position = [touch locationInView:self.view];
    Input::touchBegan(position.x, position.y);
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {

}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    
    UITouch *touch = [touches anyObject];
    CGPoint position = [touch locationInView:self.view];
    Input::touchMoved(position.x, position.y);
}

@end
