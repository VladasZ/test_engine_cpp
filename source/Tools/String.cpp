////
////  std::string.cpp
////  TestEngine
////
////  Created by Vladas Zakrevskis on 1/30/18.
////  Copyright © 2018 VladasZ. All rights reserved.
////
//
#include "String.hpp"
//#include "Log.hpp"
//
//#define STRING_DEBUG false
//#define BUFFER_SIZE _size + 1
//
//std::string::std::string() : _size(0), data(new char('\0')) { }
//
//std::string::std::string(long size, char *data) : _size(size), data(data) { }
//
//void std::string::initWithstd::string(const string &str) {
//    if (data != nullptr) free(data);
//    _size = str.size();
//    data = (char *)malloc(BUFFER_SIZE);
//    memcpy(data, &str[0], BUFFER_SIZE);
//}
//
//void std::string::initWithstd::string(const std::string &string) {
//    if (data != nullptr) free(data);
//    _size = string._size;
//    data = (char *)malloc(BUFFER_SIZE);
//    memcpy(data, string.data, BUFFER_SIZE);
//}
//
//std::string::std::string(const std::string &string) {
//    initWithstd::string(string);
//}
//
//std::string & std::string::operator =(const std::string &str) {
//    initWithstd::string(str);
//    return *this;
//}
//
//std::string::~std::string() {
//    free(data);
//}
//
//std::string::operator string() const { return string(data); }
//
//std::string::operator const char*() const {
//    char *data = (char *)malloc(BUFFER_SIZE);
//    memcpy(data, this->data, BUFFER_SIZE);
//    return data;
//}
//
//const char * std::string::c_str() const { return *this; }
//string std::string::stdstd::string()   const { return *this; }
//
//std::string std::string::operator +(const std::string &str) const {
//#if STRING_DEBUG
//    Log("operator +");
//    Log("STR in: " << *this);
//    Log("STR in2: " << str);
//#endif
//    
//    std::string result(this->_size + str._size, (char *)malloc(this->_size + str._size + 1));
//    memcpy(result.data, this->data, this->_size);
//    memcpy(result.data + this->_size, str.data, str.BUFFER_SIZE);
//    
//#if STRING_DEBUG
//    Log("STR out: " << result);
//#endif
//    
//    return result;
//}
//
//void std::string::operator +=(const std::string &str) {
//#if STRING_DEBUG
//    Log("operator +=");
//    Log("STR in: " << *this);
//    Log("STR in2: " << str);
//#endif
//    this->data = (char *)realloc(this->data, this->_size + str._size + 1);
//    memcpy(this->data + this->_size, str.data, str.BUFFER_SIZE);
//    this->_size += str._size;
//#if STRING_DEBUG
//    Log("STR out: " << *this);
//#endif
//}
//
//char * std::string::begin() const { return data; }
//char * std::string::end()   const { return data + _size; }
//
//bool std::string::empty() const { return _size == 0; }
//long std::string::size()  const { return _size; }
//void std::string::print() const { Log(data); }
//
//std::string std::string::drop(int size) const {
//    std::string newstd::string = *this;
//    newstd::string._size -= size;
//    newstd::string.data = (char *)realloc(newstd::string.data, newstd::string.BUFFER_SIZE);
//    newstd::string.data[newstd::string._size] = '\0';
//    return newstd::string;
//}
//
//std::ostream &operator<<(std::ostream &os, std::string const &str) {
//    return os << str.stdstd::string();
//}
//
std::string operator "" _s(const char *in, size_t size) { return std::string(in); }
std::string operator "" _s(unsigned long long in) { return std::string("5"); }
