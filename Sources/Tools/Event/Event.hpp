//
//  Event.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

template<class ...Args>
class Event {
    
    String id;
    
    using FunctionType = function<void(Args...)>;
    using Subscribers = vector<FunctionType>;
 
    Subscribers subscribers;
    
public:
    
    Event(const String &id) : id(id) { }
    
    void subscribe(const FunctionType &action) {
        subscribers.push_back(action);
    }
    
    void operator()(Args... parameters) {
        for (auto action : subscribers) action(parameters...);
    }
};

