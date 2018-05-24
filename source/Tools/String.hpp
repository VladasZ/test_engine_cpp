#include <string>

////
////  std::string.hpp
////  TestEngine
////
////  Created by Vladas Zakrevskis on 1/30/18.
////  Copyright © 2018 VladasZ. All rights reserved.
////
//
//#pragma once
//
//#include "HasMember.h"
//#include "STL.hpp"
//
//GENERATE_HAS_MEMBER(toString);
//
//template <class T>
//auto __toString(const T &value) {
//    if constexpr (is_array<T>::value)                   return string(value);
//    else if constexpr (is_same<T, const char *>::value) return string(value);
//    else if constexpr (is_same<T, string>::value)       return value;
//    else if constexpr (is_fundamental<T>::value)        return to_string(value);
//    else if constexpr (has_member_toString<T>::value)   return value.toString();
//    else if constexpr (is_same<T, char>::value)         return string(1, value);
//    else { STATIC_GET_TYPE(value); }
//}
//
//class std::string {
//    
//    long _size;
//    char *data = nullptr;
//    
//    std::string(long size, char *data);
//    void initWithstd::string(const string &string);
//    void initWithstd::string(const std::string &string);
//
//public:
//    
//    std::string();
//    
//    template<class T>
//    std::string(const T &value) { initWithstd::string(__toString(value)); }
//    
//    std::string(const std::string &string);
//    std::string &operator =(const std::string &str);
//    
//    ~std::string();
//    
//    operator string()       const;
//    operator const char *() const;
//    
//    const char *c_str() const;
//    string stdstd::string()  const;
//    
//    std::string operator +(const std::string &str) const;
//    void operator +=(const std::string &str);
//
//    template<class T>
//    std::string operator +(const T &in) const { return *this + std::string(in); }
//    
//    template<class T>
//    void operator +=(const T &in) { *this += std::string(in); }
//    
//    char *begin() const;
//    char *end()   const;
//    
//    bool empty() const;
//    long size()  const;
//    void print() const;
//    
//    std::string drop(int size) const;
//};
//
//std::ostream &operator<<(std::ostream &os, std::string const &str);
//
std::string operator "" _s(const char *in, size_t size);
std::string operator "" _s(unsigned long long in);
