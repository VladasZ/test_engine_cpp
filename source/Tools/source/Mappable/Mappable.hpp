//
//  Mappable.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/08/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <type_traits>
#include <iostream>

#include "Meta.hpp"
#include "Property.hpp"
#include "Json.hpp"


template <class T>
using if_array = typename std::enable_if<std::is_array<T>::value>::type;

template <class T>
using if_not_array = typename std::enable_if<!std::is_array<T>::value>::type;

template <class Property>
constexpr bool is_convertible_property = !std::is_same<Property::ConverterType, void>::value;

template <class Property>
using if_convertible_property = typename std::enable_if<is_convertible_property<Property>>::type;

template <class Property>
using if_not_convertible_property = typename std::enable_if<!is_convertible_property<Property>>::type;

template <class T>
constexpr bool is_mappable = std::is_base_of<Mappable<T>, T>::value;

template <class T>
using if_mappable = typename std::enable_if<is_mappable<T> && !is_vector<T> && !std::is_array<T>::value>::type;

template <class T>
using if_not_mappable = typename std::enable_if<!is_mappable<T> && !is_vector<T> && !std::is_array<T>::value>::type;


template<class T>
class Mappable
{
public:
	using _This = T;

private:

	//Extraction

	template <class Member, class Property>
	static if_convertible_property<Property> dispatch_extraction(Member& member, const Property& property, const nlohmann::json& json_to_parse) {
		extract_convertible(member, property, json_to_parse);
	}

	template <class Member, class Property>
	static if_not_convertible_property<Property> dispatch_extraction(Member& member, const Property& property, const nlohmann::json& json_to_parse) {
		extract(member, property, json_to_parse);
	}

	template <class Member, class Property>
	static void extract_convertible(Member& member, const Property& property, const nlohmann::json& json_to_parse) {
		member = Property::ConverterType::parse(json_to_parse[property.name]);
	}

	template <class Member, class Property>
	static if_mappable<Member> extract(Member& member, const Property& property, const nlohmann::json& json_to_parse) {
		if (json_to_parse.find(property.name) == json_to_parse.end()) {
			for_each(Member::properties(), [&](auto member_property) {
				member.*member_property.pointer = member_property.default_value;
			});
			return;
		}
		member = Member::parse(json_to_parse[property.name]);
	}

	template <class Member, class Property>
	static if_not_mappable<Member> extract(Member& member, const Property& property, const nlohmann::json& json_to_parse) {
		member = json_to_parse.value<Member>(property.name, property.default_value);
	}

	template <class Member, class Property>
	static if_vector<Member> extract(Member& member, const Property& property, const nlohmann::json& json_to_parse) {
		extract_vector(member, property, json_to_parse);
	}

	template <class VectorType, class Property>
	static if_mappable<VectorType> extract_vector(std::vector<VectorType>& vector, const Property& property, const nlohmann::json& json_to_parse) {
		if (!json_to_parse.is_array()) {
			vector = property.default_value;
			return;
		}
		vector.clear();
		for (const auto& object_json : json_to_parse)
			vector.emplace_back(VectorType::parse(object_json));
	}

	template <class VectorType, class Property>
	static if_not_mappable<VectorType> extract_vector(std::vector<VectorType>& vector, const Property& property, const nlohmann::json& json_to_parse) {
		vector = json_to_parse.value<std::vector<VectorType>>(property.name, property.default_value);
	}


	//Packing

	template <class Member, class Property>
	static if_convertible_property<Property> dispatch_packing(const Member& member, const Property& property, nlohmann::json& json_to_parse) {
		pack_convertible(member, property, json_to_parse);
	}

	template <class Member, class Property>
	static if_not_convertible_property<Property> dispatch_packing(const Member& member, const Property& property, nlohmann::json& json_to_parse) {
		pack(member, property, json_to_parse);
	}

	template <class Member, class Property>
	static void pack_convertible(const Member& member, const Property& property, nlohmann::json& json_to_pack) {
		using Converter = Property::ConverterType;
		json_to_pack[property.name] = Converter::static_to_json(*static_cast<const Converter *>(&member));
	}

	template <class Member, class Property>
	static if_array<Member> pack(const Member& member, const Property& property, nlohmann::json& json_to_pack) {
		json_to_pack[property.name] = c_array_to_vector(member);
	}

	template <class Member, class Property>
	static if_not_mappable<Member> pack(const Member& member, const Property& property, nlohmann::json& json_to_pack) {
		json_to_pack[property.name] = member;
	}

	template <class Member, class Property>
	static if_mappable<Member> pack(const Member& member, const Property& property, nlohmann::json& json_to_pack) {
		json_to_pack[property.name] = member.to_json();
	}

	template <class Member, class Property>
	static if_vector<Member> pack(const Member& member, const Property& property, nlohmann::json& json_to_pack) {
		pack_vector(member, property, json_to_pack);
	}

	template <class VectorType, class Property>
	static if_not_mappable<VectorType> pack_vector(const std::vector<VectorType>& vector, const Property& property, nlohmann::json& json_to_pack) {
		json_to_pack[property.name] = nlohmann::json::array();
		for (const auto& object : vector)
			json_to_pack[property.name].emplace_back(object);
	}

	template <class VectorType, class Property>
	static if_mappable<VectorType> pack_vector(const std::vector<VectorType>& vector, const Property& property, nlohmann::json& json_to_pack) {
		json_to_pack[property.name] = nlohmann::json::array();
		for (const auto& object : vector)
			json_to_pack[property.name].emplace_back(object.to_json());
	}

public:

	template <class T>
	static nlohmann::json static_to_json(const T& object) {
		nlohmann::json json;
		for_each(T::properties(), [&](auto property) {
			dispatch_packing(object.*property.pointer, property, json);
		});
		return json;
	}

	template <class T>
	static std::string static_to_json_string(const T& object) {
		return static_to_json(object).dump();
	}

	static T parse(const nlohmann::json& json_to_parse) {
		T object;
		for_each(T::properties(), [&](auto property) {
			dispatch_extraction(object.*property.pointer, property, json_to_parse);
		});
		return object;
	}

	nlohmann::json to_json() {
		return Mappable<T>::static_to_json(*static_cast<T*>(this));
	}

	static T parse_string(const std::string& json_string) {
		const nlohmann::json parsed_json = nlohmann::json::parse(json_string, nullptr, false);
		return parse(parsed_json);
	}

	std::string to_json_string() {
		return Mappable<T>::static_to_json_string(*static_cast<T*>(this));
	}

	static void printProperties() {
		for_each(T::properties(), [](auto property) {
			std::cout << property << std::endl;
		});
	}
};

template <class TargetType, class _ConverterType>
struct Converter : public TargetType, public Mappable<_ConverterType> { };

#define CONVERT(__class_name_) struct JSON##__class_name_ : public Converter<__class_name_, JSON##__class_name_>
