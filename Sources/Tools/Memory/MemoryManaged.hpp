//
//  MemoryManaged.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#define  MEMORY_MANAGED(class) : public MemoryManaged<class>
#define _MEMORY_MANAGED(class) , public MemoryManaged<class>

class Hello {
    
    
};

template <class T>
class MemoryManaged {
public:
    
    static string className;
    static int allocated;
    static int deleted;
    
    static int leaked() {
        return allocated - deleted;
    }
    
    MemoryManaged() {
        cout << "Created: " << className << endl;
        allocated++;
        
    }
    
    ~MemoryManaged() {
        cout << "Deletet: " << className << endl;
        deleted++;
    }
    
};

template <class T>
string MemoryManaged<T>::className = []() {
    cout << "Initialized class: " << typeid(T).name() << endl;
    return typeid(T).name();
}();

template <class T>
int MemoryManaged<T>::allocated = 0;

template <class T>
int MemoryManaged<T>::deleted = 0;
