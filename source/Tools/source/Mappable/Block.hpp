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
#include <type_traits>

#include "Meta.hpp"
#include "Array.hpp"
#include "String.hpp"
#include "Dictionary.hpp"
//
//class Block {
//
//    enum class Type : uint8_t {
//        Bool,
//        Integer,
//        Float,
//        String,
//        Array
//    };
//
//    static inline Dictionary<Type, String> _types_to_string = {
//         { Type::Bool,    "Bool"    },
//         { Type::Integer, "Integer" },
//         { Type::Float,   "Float"   },
//         { Type::String,  "String"  },
//         { Type::Array,   "Array"   }
//    };
//
//    const String _initialType;
//    Type _type;
//    std::any _value;
//
//    template <class T>
//    constexpr Type _getType() {
//        if (is_string_convertible<T>) return Type::String;
//        if (is_same_v<bool, T>)       return Type::Bool;
//        if (is_integral_v<T>)         return Type::Integer;
//        if (is_floating_point_v<T>)   return Type::Float;
//        throw String() + "Type: " + nameOf<T> +" is not supported by Block class.";
//    }
//
//public:
//
//    template <class T>
//    constexpr static inline bool is_supported =
//        is_same_v<bool, T>     ||
//        is_integral_v<T>       ||
//        is_floating_point_v<T> ||
//        is_string_convertible<T>
//        ;
//
//    template <class T>
//    Block(const T& value) : _initialType(nameOf<T>) {
//
//        if constexpr (!is_supported<T>) {
//            throw String() + "Type: " + nameOf<T> + " is not supported by Block class.";
//        }
//
//        if constexpr (is_string_convertible<T>) {
//            Log(String() + " convertovkoo: " + value);
//            _value = String(value);
//        }
//        else constexpr {
//            Log(String() + " nee: " + value);
//            _value = value;
//        }
//
//        _type = _getType<T>();
//    }
//
//    template <class T>
//    T get() {
//
//        //Log("getting: " + _initialType);
//
//        //if (_type != _getType<T>())
//        //    throw String() + "Block contains " + _type + " not " + nameOf<T>;
//        return std::any_cast<T>(_value);
//    }
//
//    String type() const {
//        return _types_to_string[_type];
//    }
//
//    Block * begin() {
//        return this;
//    }
//
//    Block * end() {
//        return this + 1;
//    }
//
//};
