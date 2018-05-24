//
//  Event.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#define _EVENT_FUNCTION_TYPE function<void(Params...)>
#define _EVENT_CONDITION_FUNCTION_TYPE function<bool(SubscriberType *, Params...)>

template<class SubscriberType, class ...Params>
class Event {
    
    struct Subscriber {
        SubscriberType *object;
        _EVENT_FUNCTION_TYPE action;
    };
    
    vector<Subscriber> subscribers;
    
    _EVENT_CONDITION_FUNCTION_TYPE _condition = [](SubscriberType *, Params...){ return true; };
    
public:
    
    Event() = default;
    Event(_EVENT_CONDITION_FUNCTION_TYPE condition) : _condition(condition) { }
    
    void subscribe(SubscriberType *subscriber, const _EVENT_FUNCTION_TYPE &action) {
        subscribers.push_back((Subscriber) { subscriber, action } );
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
    
    void condition(const _EVENT_CONDITION_FUNCTION_TYPE &condition) {
        _condition = condition;
    }
};

