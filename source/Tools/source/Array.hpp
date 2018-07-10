//
//  Array.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 6/07/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <vector>
#include <optional>
#include <functional>
#include <memory>

template <class T>
class Array : public std::vector<T> {
    using __array = std::vector<T>;
public:
    using __array::__array;

    using Ptr       = std::shared_ptr<T>;
    using Optional  = std::optional<T>;
    using Predicate = std::function<bool(const T&)>;
    using Callback  = std::function<void(const Array<T>&)>;

    Optional where(const Predicate &predicate) {
        for (const auto& object : *this)
            if (predicate(object))
                return object;
        return std::nullopt;
    }

};