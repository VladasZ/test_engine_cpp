//
//  String.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

class String {
    
    long _size = 0;
    char *data = new char('\n');
    
    String(long size, char *data);
  
public:
    
    String() = default;
    String(const char *str);
    String(const string &str);
    
    operator string() const;
    operator const char*() const;
    
    long size() const;
    void print() const;
    
    const char *cStr() const;
    string stdString() const;
    
    String operator +(const String &str) const;
    void operator +=(const String &str);
};

ostream &operator<<(ostream &os, String const &str);

