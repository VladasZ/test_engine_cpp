//
//  String.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "String.hpp"
#include "Log.hpp"

using namespace std;

#define STRING_DEBUG false
#define BUFFER_SIZE _size + 1

String::String() : _size(0), _data(new char('\0')) { }

String::String(size_t size, char *data) : _size(size), _data(data) { }

void String::initWithString(const string &str) {
    if (_data != nullptr) free(_data);
    _size = str.size();
    _data = (char *)malloc(BUFFER_SIZE);
    memcpy(_data, &str[0], BUFFER_SIZE);
}

void String::initWithString(const String &string) {
    if (_data != nullptr) free(_data);
    _size = string._size;
    _data = (char *)malloc(BUFFER_SIZE);
    memcpy(_data, string._data, BUFFER_SIZE);
}

String::String(const String &string) {
    initWithString(string);
}

String & String::operator =(const String &str) {
    initWithString(str);
    return *this;
}

String::~String() {
    free(_data);
}

String::operator string() const { return string(_data); }

String::operator const char*() const {
    char *data = (char *)malloc(BUFFER_SIZE);
    memcpy(data, this->_data, BUFFER_SIZE);
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
    
    String result(this->_size + str._size, (char *)malloc(this->_size + str._size + 1));
    memcpy(result._data, this->_data, this->_size);
    memcpy(result._data + this->_size, str._data, str.BUFFER_SIZE);
    
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
    this->_data = (char *)realloc(this->_data, this->_size + str._size + 1);
    memcpy(this->_data + this->_size, str._data, str.BUFFER_SIZE);
    this->_size += str._size;
#if STRING_DEBUG
    Log("STR out: " << *this);
#endif
}

char * String::begin() const { return _data; }
char * String::end()   const { return _data + _size; }

bool String::empty() const { return _size == 0; }
size_t String::size()  const { return _size; }
void String::print() const { Log(_data); }

String String::drop(int size) const {
    String newString = *this;
    newString._size -= size;
    newString._data = (char *)realloc(newString._data, newString.BUFFER_SIZE);
    newString._data[newString._size] = '\0';
    return newString;
}

std::ostream &operator<<(std::ostream &os, String const &str) {
    return os << str.stdString();
}

String operator "" _s(const char *in, size_t size) { return String(in); }
String operator "" _s(unsigned long long in) { return String("5"); }
