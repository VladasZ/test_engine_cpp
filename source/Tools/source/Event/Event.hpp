//
//  Event.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <functional>

#include "Array.hpp"

template<class ...Params>
class Event {
    
public:
    using EventCallbackType = std::function<void(Params...)>;

private:
    Array<EventCallbackType> subscribers;
        
public:
    
    Event() = default;

    void subscribe(EventCallbackType action) {
        subscribers.emplace_back(action);
    }
    
    void operator()(Params... parameters) const {
        for (const auto& subscriber : subscribers)
                subscriber(std::forward<Params ...>(parameters...));
    }
};
