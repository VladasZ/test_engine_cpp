//
//  Matrix4.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Matrix4.hpp"


Matrix4::Matrix4() : Matrix4 {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
} { }

Matrix4::Matrix4(const std::initializer_list<float>& list) {
    if (list.size() != Matrix4::size)
        throw "Matrix4 invalid initializer";
    std::copy(list.begin(), list.end(), &data[0][0]);
}

 
