//
//  Meta.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/08/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <tuple>
#include <vector>
#include <utility>
#include <type_traits>

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

template <class ArayType, class VectorType>
void vector_to_c_array(ArayType& to_init, const VectorType& initializer) {
	int index = 0;
	for (const auto element : initializer)
		to_init[index++] = element;
}

template <class ArayType>
auto c_array_to_vector(ArayType& array) {
	using ElementType = std::remove_const<std::remove_reference<decltype(*array)>::type>::type;
	auto array_size = sizeof(array) / sizeof(ElementType);
	std::vector<ElementType> vector;

	for (int i = 0; i < array_size; i++)
		vector.emplace_back(array[i]);

	return vector;
}
