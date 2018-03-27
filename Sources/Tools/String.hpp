//
//  String.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

GENERATE_HAS_MEMBER(toString);

template <class T>
auto __toString(const T &value) {
    if constexpr (is_array<T>::value)                 return string(value);
    else if constexpr (is_same<T, const char *>::value)    return string(value);
    else if constexpr (is_same<T, string>::value)          return value;
    else if constexpr (is_fundamental<T>::value)           return to_string(value);
    else if constexpr (has_member_toString<T>::value) return value.toString();
    else if constexpr (is_same<T, char>::value)            return string(1, value);
    else { STATIC_GET_TYPE(value); }
}

class String {
    
    long _size;
    char *data = nullptr;
    
    String(long size, char *data);
    void initWithString(const string &string);
    void initWithString(const String &string);

public:
    
    String();
    
    template<class T>
    String(const T &value) { initWithString(__toString(value)); }
    
    String(const String &string);
    String &operator =(const String &str);
    
    ~String();
    
    operator string()       const;
    operator const char *() const;
    
    const char *c_str() const;
    string stdString()  const;
    
    String operator +(const String &str) const;
    void operator +=(const String &str);

    template<class T>
    String operator +(const T &in) const { return *this + String(in); }
    
    template<class T>
    void operator +=(const T &in) { *this += String(in); }
    
    char *begin() const;
    char *end()   const;
    
    bool empty() const;
    long size()  const;
    void print() const;
    
    String drop(int size) const;
};

ostream &operator<<(ostream &os, String const &str);

String operator "" _s(const char *in, size_t size);
String operator "" _s(unsigned long long in);
