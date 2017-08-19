//
//  OBJBridge.m
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/19/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#import "OBJBridge.h"

@implementation OBJBridge

+ (const char *) workDirectoryPath {
    
    NSString *path = [[NSBundle mainBundle] bundlePath];
    return [path UTF8String];
}

@end
