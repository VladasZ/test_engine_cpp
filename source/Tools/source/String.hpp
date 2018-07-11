//
//  String.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <string>

#include "HasMember.hpp"

GENERATE_HAS_MEMBER(toString, String, void);

template <class T>
decltype(auto) __toString(const T &value) {
         if constexpr (std::is_same_v<T, char>)         return std::string(1, value);
    else if constexpr (std::is_same_v<T, const char *>) return std::string(value);
    else if constexpr (std::is_same_v<T, std::string>)  return value;
    else if constexpr (has_toString<T>)                 return value.toString();
    else if constexpr (std::is_array_v<T>)              return std::string(value);
    else if constexpr (std::is_fundamental_v<T>)        return std::to_string(value);
    else { STATIC_GET_TYPE(value); }
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
