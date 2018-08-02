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

template<class _ClassType, class _MemberType>
class Property {
public:
	using ClassType = _ClassType;
	using MemberType = _MemberType;
    using Pointer = MemberType ClassType::*;
    const String name;
    const Pointer pointer;
	const _MemberType default_value;
    Property(const String &name, Pointer pointer, const _MemberType& default_value) : name(name), pointer(pointer), default_value(default_value) { }
};

template<class _ClassType, class _MemberType, class _DefaultType>
static const auto make_property(const String& name, _MemberType _ClassType::* pointer, const _DefaultType& default_value) {
    return Property<_ClassType, _MemberType>(name, pointer, default_value);
}

template<class ClassType, class MemberType>
auto operator<<(std::ostream& os, const Property<ClassType, MemberType>& obj) {
    return os << "Property: " << obj.name << " of: " << nameOf<ClassType>;
}

#define PROPERTY(name, type, default_value) make_property(#name,  &type::name, default_value)
