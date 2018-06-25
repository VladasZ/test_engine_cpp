//
//  Block.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 6/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <any>
#include <functional>

#include "Meta.hpp"
#include "Array.hpp"
#include "String.hpp"

class Block {

    std::any value;
    std::string typeName;

public:
    
    template <class T> Block(const T &value) : value(value), typeName(typeid(T).name()) { }

    template <class T> Block(const std::initializer_list<T> &list) : value(Array<T>(list)), typeName(typeid(Array<T>).name()) { 
    
        STATIC_GET_TYPE(list);
    
    }

    template <class T> operator T() {
        return std::any_cast<T>(value);
    }

    template <class T> bool isTypeOf() {
        return typeid(T).name() == typeName;
    }

    template <class T> Array<T> array() {
        return *this;
    }

    template <class T> void foreach(const std::function<void(const T &)> &each) {
        for (const auto& object : array<T>())
            each(object);
    }
};