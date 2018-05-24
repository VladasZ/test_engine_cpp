//
//  Alert.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/6/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Alert.hpp"
#include "CallObj.h"

void Alert::show(const String &message) {
    objCShowAlert(message.c_str());
}
