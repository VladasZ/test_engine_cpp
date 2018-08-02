//
//  Mappable.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/08/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <iostream>
#include <map>

#include "Meta.hpp"
#include "String.hpp"
#include "Property.hpp"
#include "json.hpp"

template <class T>
constexpr bool is_mappable = std::is_base_of<Mappable<T>, T>::value;

template<class T>
class Mappable {

	template <class _MemberType, class _PropertyType>
	static void extract(_MemberType& member, const _PropertyType& property, const nlohmann::json& json_to_parse) {
		if constexpr (is_mappable<_MemberType>) {
			member = _MemberType::parse(json_to_parse[property.name]);
		}
		else {
			member = json_to_parse.value<_MemberType>(property.name, property.default_value);
		}
	}

public:
	static T parse(const nlohmann::json& json_to_parse) {
		T object;
		for_each(T::properties(), [&](auto property) {
			using MemberType = decltype(property)::MemberType;
			MemberType& member = object.*property.pointer;
			extract(member, property, json_to_parse);
		});
		return object;
	}

    static T parse_string(const std::string& json_string) {
		const nlohmann::json parsed_json = nlohmann::json::parse(json_string, nullptr, false);
        return parse(parsed_json);
    }

    static void printProperties() {
        for_each(T::properties(), [](auto property) {
            std::cout << property << std::endl;
        });
    }
};

