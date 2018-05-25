//
//  String.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <string>
#include <type_traits>

#include "HasMember.hpp"
#include "Macro.hpp"

#ifndef WINDOWS
GENERATE_HAS_MEMBER(toString);
#endif

template <class T>
auto __toString(const T &value) {
    if constexpr      (std::is_array<T>::value)         return std::string(value);
    else if constexpr (std::is_same_v<T, const char *>) return std::string(value);
    else if constexpr (std::is_same_v<T, std::string>)  return value;
    else if constexpr (std::is_fundamental<T>::value)   return std::to_string(value);
    else if constexpr (has_member_toString<T>::value)   return value.toString();
    else if constexpr (std::is_same<T, char>::value)    return std::string(1, value);
    else { STATIC_GET_TYPE(value); }
}

class String {
    
    size_t _size;
    char *_data = nullptr;
    
    String(size_t size, char *data);
    void initWithString(const std::string &string);
    void initWithString(const String &string);

public:
    
    String();
    
    template<class T>
    String(const T &value) { initWithString(__toString(value)); }
    
    String(const String &string);
    String &operator =(const String &str);
    
    ~String();
    
    operator std::string() const;
    operator const char *() const;
    
    const char *c_str() const;
    std::string stdString()  const;
    
    String operator +(const String &str) const;
    void operator +=(const String &str);

    template<class T>
    String operator +(const T &in) const { return *this + String(in); }
    
    template<class T>
    void operator +=(const T &in) { *this += String(in); }
    
    char *begin() const;
    char *end()   const;
    
    bool empty() const;
    size_t size()  const;
    void print() const;
    
    String drop(int size) const;
};

std::ostream &operator<<(std::ostream &os, String const &str);

String operator "" _s(const char *in, size_t size);
String operator "" _s(unsigned long long in);
