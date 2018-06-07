//
//  String.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <string>

template <class T>
decltype(auto) __toString(const T &value) {
    if constexpr      (std::is_array<T>::value)         return std::string(value);
    else if constexpr (std::is_same_v<T, const char *>) return std::string(value);
    else if constexpr (std::is_same_v<T, std::string>)  return value;
    else if constexpr (std::is_fundamental<T>::value)   return std::to_string(value);
    else if constexpr (has_member_toString<T>::value)   return value.toString();
    else if constexpr (std::is_same<T, char>::value)    return std::string(1, value);
    else { STATIC_GET_TYPE(value); }
}

class String : public std::string {
    
    using str = std::string;
    
public:

    using str::str;

    template<class T>
    String(const T &value) : str(__toString(value)) { }
    
    template<class T>
    String operator +(const T &in) const { return str(*this) + str(String(in)); }
    
    template<class T>
    void operator +=(const T &in) { str(*this) += str(String(in)); }
};

String operator "" _s(const char *in, size_t size);
String operator "" _s(unsigned long long in);
