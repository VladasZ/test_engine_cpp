//
//  String.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "TestString.hpp"

#define STRING_DEBUG true
#define BUFFER_SIZE _size + 1

TestString::TestString(long size, char *data) : _size(size), data(data) { }

TestString::TestString(int number) : TestString(to_string(number)) {  }

TestString::TestString(const char ch) : _size(1), data((char *)malloc(BUFFER_SIZE)) {
    memcpy(data, &ch, 1);
    memcpy(data + 1, &"\0", 1);
}

TestString::TestString(const char *str) : _size(strlen(str)), data((char *)malloc(BUFFER_SIZE)) {
    memcpy(data, str, BUFFER_SIZE);
}

TestString::TestString(const string &str) : _size(str.size()), data((char *)malloc(BUFFER_SIZE)) {
    memcpy(data, &str[0], BUFFER_SIZE);
}

TestString::TestString(const TestString &str) : _size(str._size), data((char *)malloc(BUFFER_SIZE)) {
    memcpy(data, str.data, BUFFER_SIZE);
}

TestString::operator string() const {
    return string(data);
}

TestString::operator const char*() const {
    char *data = (char *)malloc(BUFFER_SIZE);
    memcpy(data, this->data, BUFFER_SIZE);
    return data;
}

const char * TestString::c_str() const { return *this; }
string TestString::stdString() const { return *this; }

bool TestString::empty() const {
    return _size == 0;
}

long TestString::size() const {
    return _size;
}

void TestString::print() const {
    Log(data);
}

TestString TestString::operator +(const TestString &str) const {
#if STRING_DEBUG
    Log("operator +=");

    Log(endl << "STR in: " << *this);
    Log("STR in2: " << str);
#endif
    
    long size = this->BUFFER_SIZE + str._size - 1;
    char *data = (char *)malloc(size);
    memcpy(data, this->data, this->_size);
    memcpy(data + this->_size, str.data, str.BUFFER_SIZE);
#if STRING_DEBUG
    Log("STR out: " << TestString(size, data));
#endif
    return TestString(size, data);
}

void TestString::operator +=(const TestString &str) {
#if STRING_DEBUG
    Log("operator +=");
    Log(endl << "STR in: " << *this);
    Log("STR in2: " << str);
#endif
    this->data = (char *)realloc(this->data, this->_size + str._size + 1);
    memcpy(this->data + this->_size, str.data, str.BUFFER_SIZE);
    this->_size += str._size;
#if STRING_DEBUG
    Log("STR out: " << *this);
#endif
}

ostream &operator<<(ostream &os, TestString const &str) {
    return os << str.c_str();
}

char * TestString::begin() const {
    return data;
}

char * TestString::end() const {
    return data + _size;
}

TestString TestString::drop(int size) const {
    TestString newString = *this;
    newString._size -= size;
    newString.data = (char *)realloc(newString.data, newString.BUFFER_SIZE);
    newString.data[newString._size] = '\0';
    return newString;
}
