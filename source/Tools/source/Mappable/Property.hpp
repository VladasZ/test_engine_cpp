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

template<class _ClassType, class _MemberType>
class Property {
public:
	using ClassType = _ClassType;
	using MemberType = _MemberType;
	using Pointer = MemberType ClassType::*;
	const std::string name;
	const std::string class_name = typeid(_ClassType).name();
	const Pointer pointer;
	const MemberType default_value;
	Property(const std::string &name, Pointer pointer, const MemberType& default_value) : name(name), pointer(pointer), default_value(default_value) { }
};

template<class ClassType, class MemberType, class DefaultType>
static const auto make_property(const std::string& name, MemberType ClassType::* pointer, const DefaultType& default_value) {
	return Property<ClassType, MemberType>(name, pointer, default_value);
}

template<class ClassType, class MemberType>
std::ostream& operator<<(std::ostream& os, const Property<ClassType, MemberType>& obj) {
	return os << "Property: " << obj.name << " of: " << typeid(ClassType).name();
}

#define PROPERTY(name, default_value) make_property(#name,  &__ClassType::name, default_value)

#define DECL_PROPERTIES(__classType, __properties) using __ClassType = __classType;\
   static const auto properties() {\
return std::make_tuple\
(\
__properties\
);\
}
