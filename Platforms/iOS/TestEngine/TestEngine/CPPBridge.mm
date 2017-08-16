//
//  CPPBridge.m
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#import "CPPBridge.h"
#import "CPPTestClass.hpp"

@implementation CPPBridge

+ (void)run {
    
    
    CPPTestClass::hello();
}

@end
