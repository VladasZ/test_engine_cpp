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

#define DEF_TYPES(Type)\
/*inline static decltype(std::make_shared<Type>) *makePtr = &std::make_shared<Type>;*/\
using Ptr = Type *;\
using Array = std::vector<Type>;\
using PtrArray = std::vector<Ptr>;

//template <class T>
//class TestObject MEMORY_MANAGED(T) {
//public:
//
//    inline static decltype(std::make_shared<T>) *makePtr = &std::make_shared<T>;
//    using Ptr = std::shared_ptr<T>;
//
//    using Array = std::vector<T>;
//    using PtrArray = std::vector<Ptr>;
//};
