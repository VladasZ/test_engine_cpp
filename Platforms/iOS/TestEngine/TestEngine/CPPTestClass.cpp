//
//  CPPTestClass.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "CPPTestClass.hpp"
#include "STL.hpp"
#include "Log.hpp"

void CPPTestClass::hello() {
    
    cout << "Hello" << endl;
    Info("hello");
    Warning("warning");
    Error("Error");
}
