//
//  String.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <string>

#include "Meta.hpp"
#include "HasMember.hpp"

GENERATE_HAS_MEMBER(toString, String(void));

template <class T>
constexpr inline bool is_string_convertible =
    contains<T, char>               ||
    std::is_same_v<T, std::string>  ||
    std::is_same_v<T, String>       ||
    has_toString<T>                 ||
    std::is_fundamental_v<T>
    ;

template <class T>
auto __toString(const T &value) {
         if constexpr (std::is_same_v<T, std::string>)  return value;
    else if constexpr (std::is_same_v<T, void>)         return std::string();
    else if constexpr (has_toString<T>)                 return value.toString();
    else if constexpr (contains<T, char>)               return std::string(value);
    else if constexpr (std::is_fundamental_v<T>)        return std::to_string(value);
    else { return String() + "Failed string conversion from type: " + nameOf<T>; }
}

class String : public std::string {
    using __str = std::string;
public:

    using __str::__str;

    String() = default;
    template<class T> String(const T &value) : __str(__toString(value)) { }
    template<class T> String operator + (const T &in) const { return (__str)*this + String(in); }
    template<class T> void   operator +=(const T &in) { this->append(in); }
};

String operator "" _s(const char *in, size_t size);
String operator "" _s(unsigned long long       in);

template <class T>
inline const String nameOf = typeid(T).name();
