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
#include "Property.hpp"

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

