//
//  main.m
//  obj-ios
//
//  Created by Vladas Zakrevskis on 03/06/2019.
//  Copyright © 2019 vz. All rights reserved.
//

#ifdef IOS_BUILD

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

#import "ios_main.h"

int ios_main() {
    @autoreleasepool {
        return UIApplicationMain(0, malloc(1), nil, NSStringFromClass([AppDelegate class]));
    }
}

#endif
