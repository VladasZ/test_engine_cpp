//
//  Meta.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/08/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <string>
#include <tuple>
#include <vector>
#include <memory>
#include <utility>
#include <type_traits>

#define TYPES(ClassName)\
public:\
using This   = ClassName;\
using Ptr    = std::shared_ptr<This>;\
using Arr    = Array<This>;\
using PtrArr = Array<Ptr>;\
private:

#define UNPRIVATE(var) reinterpret_cast<This*>(var)

template <class T>
using remove_everything = std::remove_all_extents_t<std::remove_reference_t<std::remove_const_t<std::remove_pointer_t<std::remove_reference_t<T>>>>>;

template <class T, class T2>
constexpr inline bool contains = std::is_same_v<remove_everything<T>, remove_everything<T2>>;

template <class T> class StaticClassInfo;
#define STATIC_GET_TYPE(Type) StaticClassInfo<Type> _foo;

template <typename Tuple, typename F, std::size_t ...Indices>
void __for_each_impl(Tuple&& tuple, F&& f, std::index_sequence<Indices...>) {
	using swallow = int[]; (void)swallow { 1, (f(std::get<Indices>(std::forward<Tuple>(tuple))), void(), int{})... };
}

template <typename Tuple, typename F>
void for_each(Tuple&& tuple, F&& f) {
	constexpr std::size_t N = std::tuple_size_v<std::remove_reference_t<Tuple>>;
	__for_each_impl(std::forward<Tuple>(tuple), std::forward<F>(f), std::make_index_sequence<N>{});
}

template<typename>
struct _is_vector : std::false_type {};

template<typename T, typename A>
struct _is_vector<std::vector<T, A>> : std::true_type {};

template<class T>
constexpr bool is_vector = _is_vector<T>::value;

template <class T>
using if_vector = typename std::enable_if<is_vector<T>>::type;

template <class T>
constexpr bool is_char = std::is_same<char, T>::value;

template <class T>
using if_char = typename std::enable_if<is_char<T>>::type;

template <class T>
using if_integer = typename std::enable_if<std::numeric_limits<T>::is_integer && !is_char<T>>::type;

template <bool _value>
using if_ = typename std::enable_if<_value>::type;

template <class T>
struct _c_array_struct {
	static T array;
	using _element_type = decltype(*(_c_array_struct<T>::array));
};

template <class T>
using c_array_element_type = typename std::remove_const<typename std::remove_reference<typename _c_array_struct<T>::_element_type>::type>::type;

template <class T>
constexpr auto c_array_size(const T& array) {
	return sizeof(array) / sizeof(*array);
}

template <class ArayType, class VectorType>
void vector_to_c_array(ArayType& to_init, const VectorType& initializer) {
	int index = 0;
	for (const auto element : initializer)
		to_init[index++] = element;
}

template <class ArayType>
auto c_array_to_vector(ArayType& array) {
	using ElementType = c_array_element_type<ArayType>;
	auto array_size = c_array_size(array);
	std::vector<ElementType> vector;

	for (int i = 0; i < array_size; i++)
		vector.emplace_back(array[i]);

	return vector;
}

template <class ArrayType>
std::string c_array_to_string(const ArrayType& array, if_char<c_array_element_type<ArrayType>>* = nullptr) {
	auto size = c_array_size(array);
	std::string result;

	for (int i = 0; i < size; i++)
	{
		if (array[i] == '\0')
			return result;
		result.push_back(array[i]);
	}

	return result;
}

template <class ArrayType>
std::string c_array_to_string(const ArrayType& array, if_integer<c_array_element_type<ArrayType>>* = nullptr) {
	auto size = c_array_size(array);
	std::string result;

	for (int i = 0; i < size; i++)
		result.push_back(array[i] + '0');

	return result;
}


template <class ArrayType>
if_char<c_array_element_type<ArrayType>> string_to_c_array(ArrayType& array, const std::string string)
{
	auto size = c_array_size(array);

	for (int i = 0; i < size; i++)
		array[i] = '\0';

	int i = 0;
	int string_index = 0;

	while (string_index < string.length() && i < size)
	{
		if (string.at(string_index) == '\"')
		{
			string_index++;
			continue;
		}

		array[i] = string.at(string_index);
		i++;
		string_index++;
	}
}

template <class ArrayType>
if_integer<c_array_element_type<ArrayType>> string_to_c_array(ArrayType& array, const std::string string)
{
	auto size = c_array_size(array);

	for (int i = 0; i < size; i++)
		array[i] = 0;

	int i = 0;
	int string_index = 0;

	while (string_index < string.length() && i < size)
	{
		if (string.at(string_index) == '\"')
		{
			string_index++;
			continue;
		}

		array[i] = string.at(string_index) - '0';
		i++;
		string_index++;
	}
}
