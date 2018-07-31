//
//  HasMember.h
//  TestEngine
//
//  Created by Vladas Zakrevskis on 17/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

//https://stackoverflow.com/questions/87372/check-if-a-class-has-a-member-function-of-a-given-signature

#include <type_traits>

class String;

#define GENERATE_HAS_MEMBER(memberName__, functionSignature__)\
template<typename, typename T>\
struct __has_##memberName__ {\
    static_assert(std::integral_constant<T, false>::value, "Second template parameter needs to be of function type.");\
};\
\
template<typename Class, typename Ret, typename... Args>\
struct __has_##memberName__<Class, Ret(Args...)> {\
private:\
    template<typename T>\
    static constexpr auto check(T*) -> typename std::is_same <decltype(std::declval<T>().##memberName__(std::declval<Args>()...)), Ret>::type;\
    template<typename>\
    static constexpr std::false_type check(...);\
    typedef decltype(check<Class>(0)) type;\
public:\
    static constexpr bool value = type::value;\
};\
\
template <class T> \
constexpr bool has_##memberName__ = __has_toString<T, functionSignature__>::value;




template<typename, typename T>
struct __has_toString {
    static_assert(std::integral_constant<T, false>::value, "Second template parameter needs to be of function type.");
};

template<typename Class, typename Ret, typename... Args>
struct __has_toString<Class, Ret(Args...)> {
private:
    template<typename T>
    static constexpr auto check(T*) -> typename std::is_same <decltype(std::declval<T>().toString(std::declval<Args>()...)), Ret>::type;
    template<typename>
    static constexpr std::false_type check(...);
    typedef decltype(check<Class>(0)) type;
public:
    static constexpr bool value = type::value;
};

template <class T> 
constexpr bool has_toString = __has_toString<T, String(void)>::value;
