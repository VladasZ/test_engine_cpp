//
//  String.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "String.hpp"

#define BUFFER_SIZE _size + 1

String::String(long size, char *data) : _size(size), data(data) { }

String::String(const char *str) : _size(strlen(str)), data((char *)malloc(BUFFER_SIZE)) {
    memcpy(data, str, BUFFER_SIZE);
}

String::String(const string &str) : _size(str.size()), data((char *)malloc(BUFFER_SIZE)) {
    memcpy(data, &str[0], BUFFER_SIZE);
}

String::operator string() const {
    return string(data);
}

String::operator const char*() const {
    char *data = (char *)malloc(BUFFER_SIZE);
    memcpy(data, this->data, BUFFER_SIZE);
    return data;
}

const char * String::cStr() const { return *this; }
string String::stdString() const { return *this; }

void String::print() const {
    cout << data << endl;
}

String String::operator +(const String &str) const {
    long size = this->_size + str._size - 1;
    char *data = (char *)malloc(size);
    memcpy(data, this->data, this->_size);
    memcpy(data + this->_size, str.data, str.BUFFER_SIZE);
    return String(size, data);
}

void String::operator +=(const String &str) {
    this->data = (char *)realloc(this->data, this->_size + str._size + 1);
    memcpy(this->data + this->_size, str.data, str.BUFFER_SIZE);
    this->_size += str._size;
}

ostream &operator<<(ostream &os, String const &str) {
    return os << str.cStr();
}

