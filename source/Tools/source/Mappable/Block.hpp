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
#include "Dictionary.hpp"

class Block {

    enum class DataType : char {
        Pointer,
        Number,
        String,
        Array,
        Dictionary,
        Count
    };

    std::any _value;
    String _typeName;
    DataType _type = DataType::String;

    using Pair = std::pair<String, std::any>;

    template <class T>
    constexpr DataType _getType() {
        if (is_pointer_v<T>)    return DataType::Pointer;
        if (is_arithmetic_v<T>) return DataType::Number;
    }

public:
    
    template <class T> Block(const T &value) :
        _value(value),
        _typeName(nameOf<T>),
        _type(_getType<T>())
    { }

    template <class T> Block(const std::initializer_list<T> &list) { 

        //constexpr bool isDict = is_same_v<T, Pair>;

        //constexpr using ContainerType = is_same_v<T, Pair> ? Dictionary<String, Pair> : Array<T>;


        //if constexpr (is_same_v<T, Pair>) {
        //   // _typeName = typeid
        //    _type = DataType::Dictionary;
        //}
        //else constexpr {
        //    _typeName = typeid(Array<T>).name();
        //    _value = Array<T>(list);
        //    _type = DataType::Array;
        //}
    }

    template <class T> operator T() const {
        return std::any_cast<T>(_value);
    }

    template <class T> bool isTypeOf() const {
        return typeid(T).name() == _typeName;
    }

    bool isArray() const {
        return _type == DataType::Array;
    }

    bool isDictionary() const {
        return _type == DataType::Dictionary;;
    }

    template <class T> Array<T> array() const {
        if (!isArray()) return Array<T>();
        return *this;
    }

    template <class T> void foreach(const std::function<void(const T &)> &each) const {
        for (const auto& object : array<T>())
            each(object);
    }
};