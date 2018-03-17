//
//  HasMember.h
//  TestEngine
//
//  Created by Vladas Zakrevskis on 17/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

//  https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Member_Detector

#pragma once

#include <type_traits> // To use 'std::integral_constant'.
#include <iostream>    // To use 'std::cout'.
#include <iomanip>     // To use 'std::boolalpha'.

#define GENERATE_HAS_MEMBER(member)                                               \
\
template < class T >                                                              \
class HasMember_##member                                                          \
{                                                                                 \
private:                                                                          \
using Yes = char[2];                                                          \
using  No = char[1];                                                          \
\
struct Fallback { int member; };                                              \
struct Derived : T, Fallback { };                                             \
\
template < class U >                                                          \
static No& test ( decltype(U::member)* );                                     \
template < typename U >                                                       \
static Yes& test ( U* );                                                      \
\
public:                                                                           \
static constexpr bool RESULT = sizeof(test<Derived>(nullptr)) == sizeof(Yes); \
};                                                                                \
\
template < class T >                                                              \
struct has_member_##member                                                        \
: public std::integral_constant<bool, HasMember_##member<T>::RESULT>              \
{                                                                                 \
};

