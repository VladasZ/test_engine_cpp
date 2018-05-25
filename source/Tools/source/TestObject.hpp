//
//  TestObject.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 25/05/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "MemoryManaged.hpp"

template <class T>
class TestObject MEMORY_MANAGED(T) {
public:

    using Ptr = std::shared_ptr<T>;
    using Array = std::vector<T>;
    using PtrArray = std::vector<Ptr>;
};
