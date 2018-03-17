//
//  String.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

template <class T>
string toString(const T &value) {
         if constexpr (is_same_v<T, char>)  return string(1, value);
    else if constexpr (is_fundamental_v<T>) return to_string(value);
    else                                    return value;
}

class TestString {
    
    long _size = 0;
    char *data = new char('\0');
    
    TestString(long size, char *data);
    void initWithString(const string &string);
  
public:
    
    TestString() = default;
    
    template<class T>
    TestString(const T &value) { initWithString(toString(value)); }
    
    operator string()       const;
    operator const char *() const;
    
    const char *c_str() const;
    string stdString()  const;
    
    TestString operator +(const TestString &str) const;
    void operator +=(const TestString &str);

    template<class T>
    TestString operator +(const T &in) const { return *this + TestString(in); }
    
    template<class T>
    void operator +=(const T &in) { *this += TestString(in); }
    
    char *begin() const;
    char *end()   const;
    
    bool empty() const;
    long size()  const;
    void print() const;
    
    TestString drop(int size) const;
};

ostream &operator<<(ostream &os, TestString const &str);

TestString operator "" _s(const char *in, size_t size);
TestString operator "" _s(unsigned long long in);
