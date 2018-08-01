//
//  Block.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 6/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <any>
#include <type_traits>

#include "Dictionary.hpp"
#include "String.hpp"

#define __CHECK_BLOCK_COMP static_assert(isCompatible<T>, "Type is not compatible with Block class.")

class Block {

public:

	enum class Type {
		Bool,
		Int,
		Float,
		String
	};

private:

	static const Dictionary<Type, std::string> _typeToString;

	std::any _value;
	const Type _type;

	template <class T>
	constexpr Type _getType() {
		__CHECK_BLOCK_COMP;
		if constexpr (std::is_same_v<bool,   T>) return Type::Bool;
		if constexpr (std::is_same_v<int,    T>) return Type::Int;
		if constexpr (std::is_same_v<float,  T>) return Type::Float;
		if constexpr (std::is_same_v<String, T>) return Type::String;
	}

public:

	template <class T>
	static constexpr bool isCompatible =
		std::is_same_v<bool,   T> ||
		std::is_same_v<int,    T> ||
		std::is_same_v<float,  T> ||
		std::is_same_v<String, T>
		;

	template <class T>
	Block(const T&& value) : _value(value), _type(_getType<T>()) {
		__CHECK_BLOCK_COMP;
	}

	template <class T>
	T value() {
		__CHECK_BLOCK_COMP;
		return std::any_cast<T>(_value);
	}

	String getType() { return Block::_typeToString.at(_type); }
};

const Dictionary<Block::Type, std::string> Block::_typeToString = {
	{ Block::Type::Bool,   "bool"   },
    { Block::Type::Int,    "int"    },
    { Block::Type::Float,  "float"  },
    { Block::Type::String, "String" }
};
