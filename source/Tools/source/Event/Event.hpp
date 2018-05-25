//
//  Event.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <functional>
#include <type_traits>

template<class SubscriberType, class ...Params>
class Event {
    
public:
    using EventCallbackType = std::function<void(Params...)>;
    using EventConditionType = std::function<bool(SubscriberType *, Params...)>;

private:

    struct Subscriber {
        SubscriberType *object = nullptr;
        EventCallbackType action;

        Subscriber(EventCallbackType action)
            :
            action(action)
        { }

        Subscriber(SubscriberType* object, EventCallbackType action)
            :
            object(object),
            action(action)
        { }
    };
    
    std::vector<Subscriber> subscribers;
    
    EventConditionType _condition = [](SubscriberType *, Params...){ return true; };
    
public:
    
    Event() = default;

    template<class Void = SubscriberType>
    Event(typename std::enable_if_t<std::is_same_v<Void, void> == false, EventConditionType> condition)
        :
        _condition(condition) 
    { }
    
    template<class Void = SubscriberType>
    void subscribe(typename std::enable_if_t<std::is_same_v<Void, void>, EventCallbackType> action)
    {
        subscribers.emplace_back(action);
    }

    void subscribe(SubscriberType *subscriber, EventCallbackType action) {
        subscribers.emplace_back(subscriber, action);
    }
    
    void unsubscribe(SubscriberType *subscriber) {
        subscribers.erase(
        std::remove_if(subscribers.begin(), subscribers.end(),
                       [subscriber](SubscriberType *_sub) { return _sub == subscriber; }),
                          subscribers.end());
    }
    
    void operator()(Params... parameters) const {
        for (auto subscriber : subscribers) {
            if (_condition(subscriber.object, parameters...))
                subscriber.action(parameters...);
        }
    }
    
    void condition(const EventConditionType &condition) {
        _condition = condition;
    }
};

