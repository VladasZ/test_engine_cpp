//
//  Array.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/07/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

template <class T>
class Array : public std::vector<T> {
    using __vector = std::vector<T>;
public:
    using __vector::__vector;
};