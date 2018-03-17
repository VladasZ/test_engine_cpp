//
//  String.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "String.hpp"

#define STRING_DEBUG false
#define BUFFER_SIZE _size + 1

String::String(long size, char *data) : _size(size), data(data) { }

void String::initWithString(const string &str) {
    _size = str.size();
    data = (char *)malloc(_size + 1);
    memcpy(data, &str[0], _size + 1);
}

void String::initWithString(const String &string) {
    _size = string._size;
    data = (char *)malloc(_size + 1);
    memcpy(data, string.data, _size + 1);
}

String::operator string() const { return string(data); }

String::operator const char*() const {
    char *data = (char *)malloc(BUFFER_SIZE);
    memcpy(data, this->data, BUFFER_SIZE);
    return data;
}

const char * String::c_str() const { return *this; }
string String::stdString()   const { return *this; }

String String::operator +(const String &str) const {
#if STRING_DEBUG
    Log("operator +");

    Log("STR in: " << *this);
    Log("STR in2: " << str);
#endif
    
    long size = this->_size + str._size + 1;
    char *data = (char *)malloc(size);
    memcpy(data, this->data, this->_size);
    memcpy(data + this->_size, str.data, str._size + 1);
#if STRING_DEBUG
    Log("STR out: " << String(size, data));
#endif
    return String(size - 1, data);
}

void String::operator +=(const String &str) {
#if STRING_DEBUG
    Log("operator +=");
    Log("STR in: " << *this);
    Log("STR in2: " << str);
#endif
    this->data = (char *)realloc(this->data, this->_size + str._size + 1);
    memcpy(this->data + this->_size, str.data, str.BUFFER_SIZE);
    this->_size += str._size;
#if STRING_DEBUG
    Log("STR out: " << *this);
#endif
}

char * String::begin() const { return data; }
char * String::end()   const { return data + _size; }

bool String::empty() const { return _size == 0; }
long String::size()  const { return _size; }
void String::print() const { Log(data); }

String String::drop(int size) const {
    String newString = *this;
    newString._size -= size;
    newString.data = (char *)realloc(newString.data, newString.BUFFER_SIZE);
    newString.data[newString._size] = '\0';
    return newString;
}

ostream &operator<<(ostream &os, String const &str) {
    return os << str.stdString();
}

String operator "" _s(const char *in, size_t size) { return String(in); }
String operator "" _s(unsigned long long in) { return String(in); }
