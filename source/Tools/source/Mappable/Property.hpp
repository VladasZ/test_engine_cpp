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


template<class _ClassType, class _MemberType, class _DefaultType, class _ConverterType = void>
class Property
{
public:
	using ClassType = _ClassType;
	using MemberType = _MemberType;
	using Pointer = MemberType ClassType::*;
	using ConverterType = _ConverterType;
	using DefaultType = _DefaultType;
	const std::string name;
	const std::string class_name = typeid(_ClassType).name();
	const Pointer pointer;
	const DefaultType default_value;
	Property(const std::string &name, Pointer pointer, const DefaultType& default_value)
		: name(name), pointer(pointer), default_value(default_value)
	{ }
};

template<class ClassType, class MemberType, class DefaultType, class ConverterType = void>
static const auto make_property(const std::string& name, MemberType ClassType::* pointer, const DefaultType& default_value)
{
	return Property<ClassType, MemberType, DefaultType, ConverterType>(name, pointer, default_value);
}


//template<class ClassType, class MemberType>
//std::ostream& operator<<(std::ostream& os, const Property<ClassType, MemberType, MemberType>& obj)
//{
//    return os << "Property: " << obj.name << " of: " << typeid(ClassType).name();
//}

#define PROPERTY(name, default_value) make_property(#name,  &_This::name, default_value)
#define CONVERTIBLE(name, converter) make_property<_This, decltype(name), decltype(name), converter>(#name,  &_This::name, decltype(name)())
#define CONVERT_ARRAY(name, converter) make_property<_This, decltype(name), c_array_element_type<decltype(name)>, converter>(#name,  &_This::name, c_array_element_type<decltype(name)>())
