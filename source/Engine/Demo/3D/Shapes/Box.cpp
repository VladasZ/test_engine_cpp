//
//  Box.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Box.hpp"


Box::Box() {
    vertices = {
    
        { -1.0, -1.0,  1.0 },
        { 1.0, -1.0,  1.0 },
        { 1.0,  1.0,  1.0 },
        { -1.0,  1.0,  1.0 },
    
        { -1.0, -1.0, -1.0 },
        { 1.0, -1.0, -1.0 },
        { 1.0,  1.0, -1.0 },
        { -1.0,  1.0, -1.0 }
    };
}
