//
//  Property.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 6/09/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <iostream>
#include <map>

#include "Meta.hpp"
#include "String.hpp"

template<class ClassType, class MemberType>
class Property {
public:
    using Pointer = MemberType ClassType::*;
    const String name;
    const Pointer pointer;
    Property(const String &name, Pointer pointer) : name(name), pointer(pointer) { }
};

template<class _ClassType, class _MemberType>
static constexpr auto make_property(const String &name, _MemberType _ClassType::* pointer) {
    return Property<_ClassType, _MemberType>(name, pointer);
}

template<class ClassType, class MemberType>
std::ostream& operator<<(std::ostream& os, const Property<ClassType, MemberType>& obj) {
    return os << "Property: " << obj.name << " of: " << typeid(ClassType).name();
}

#define PROPERTY(name, type) make_property(#name,  &type::name)
