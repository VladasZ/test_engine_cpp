//
//  Mappable.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/08/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <iostream>

#include "Meta.hpp"
#include "String.hpp"


template<class ClassType, class MemberType>
class Property {
public:
    using Pointer = MemberType ClassType::*;
    String name;
    Pointer pointer;
    Property(const String &name, Pointer pointer) : name(name), pointer(pointer) { }
};

template<class _ClassType, class _MemberType>
static Property<_ClassType, _MemberType> make_property(const String &name, _MemberType _ClassType::* pointer) {
    return Property<_ClassType, _MemberType>(name, pointer);
}

template<class ClassType, class MemberType>
std::ostream& operator<<(std::ostream& os, const Property<ClassType, MemberType>& obj) {
    return os << "Property: " << obj.name << " of: " << typeid(ClassType).name();
}

template<class T>
class Mappable {
public:
    //static T parse(const map<String, String>& container) {
    //    T object;
    //    for_each(T::properties(), [&](auto property) {
    //        object.*property.pointer = container.at(property.name);
    //    });
    //    return object;
    //}

    static void printProperties() {
        for_each(T::properties(), [](auto property) {
            std::cout << property << std::endl;
        });
    }

    template<class TypeToPrint>
    static void print(const TypeToPrint& val) {
        std::cout << typeid(TypeToPrint).name() << ":" << std::endl;
        for_each(T::properties(), [&](auto property) {
            std::cout << property.name << ": " << val.*property.pointer << std::endl;
        });
        return result;
    }

    template<class TypeToString>
    static String toString(const TypeToString& val) {
        String result;
        for_each(T::properties(), [&](auto property) {
            result += property.name + ": " + val.*property.pointer + "\n";
        });
        return result;
    }
};

