//
//  Array.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 6/07/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <vector>
#include <experimental/optional>
#include <functional>
#include <memory>

#include "System.hpp"

template <class T>
class Array : public std::vector<T> {
    using __array = std::vector<T>;
public:
    using __array::__array;

    using Ptr       = std::shared_ptr<T>;
   // using Optional  = std::optional<T>;
    using Predicate = std::function<bool(const T&)>;
    using Callback  = std::function<void(const Array<T>&)>;

//    Optional where(const Predicate &predicate) const {
//        for (const auto& object : *this)
//            if (predicate(object))
//                return object;
//        return std::nullopt;
//    }

    void removeIf(const Predicate &predicate) {
        erase(std::remove_if(this->begin(), this->end(),  predicate, this->end()));
    }

    template <class ...Args>
    void append(Args ...args) {
        this->insert(this->end(), std::initializer_list<T> { args... });
    }

	void insertAt(size_t index, const T& object) {
        this->emplace(this->begin() + index, object);
	}

    T random() const {
        return this->at(System::random((int)this->size()));
    }
};
