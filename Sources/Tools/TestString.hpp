//
//  String.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

class TestString {
    
    long _size = 0;
    char *data = new char('\0');
    
    TestString(long size, char *data);
  
public:
    
    TestString() = default;
    TestString(int number);
    TestString(const char ch);
    TestString(const char *str);
    TestString(const string &str);
    TestString(const TestString &str);
    
    operator string() const;
    operator const char *() const;
    
    bool empty() const;
    long size() const;
    void print() const;
    
    const char *c_str() const;
    string stdString() const;
    
    TestString operator +(const TestString &str) const;
    void operator +=(const TestString &str);
    
    char *begin() const;
    char *end() const;
    
    TestString drop(int size) const;
};

ostream &operator<<(ostream &os, TestString const &str);

