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

String::String() : _size(0), data(new char('\0')) { }

String::String(long size, char *data) : _size(size), data(data) { }

void String::initWithString(const string &str) {
    if (data != nullptr) free(data);
    _size = str.size();
    data = (char *)malloc(BUFFER_SIZE);
    memcpy(data, &str[0], BUFFER_SIZE);
}

void String::initWithString(const String &string) {
    if (data != nullptr) free(data);
    _size = string._size;
    data = (char *)malloc(BUFFER_SIZE);
    memcpy(data, string.data, BUFFER_SIZE);
}

String::String(const String &string) {
    initWithString(string);
}

String & String::operator =(const String &str) {
    initWithString(str);
    return *this;
}

String::~String() {
    free(data);
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
    
    String result;
    free(result.data);
    result._size = this->_size + str._size;
    result.data = (char *)malloc(result.BUFFER_SIZE);
    
    memcpy(result.data, this->data, this->_size);
    memcpy(result.data + this->_size, str.data, str.BUFFER_SIZE);
    
#if STRING_DEBUG
    Log("STR out: " << result);
#endif
    
    return result;
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
