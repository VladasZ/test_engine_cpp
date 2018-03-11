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
    
    vector<function<void(Args...)>> subscribers;
    
public:
    
    Event(const String &id) : id(id) { }
    
    void subscribe(const function<void(Args...)> &action) {
        subscribers.push_back(action);
    }
    
    void operator()(Args... parameters) {
        for (auto action : subscribers) action(parameters...);
    }
};

