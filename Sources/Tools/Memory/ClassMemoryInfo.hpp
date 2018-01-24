//
//  ClassMemoryInfo.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 25/01/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

class ClassMemoryInfo {
    
public:
    
    int allocated = 0;
    int deleted = 0;
    
    const string className;
    
    ClassMemoryInfo(const string &name);
    
    void print() const;
};
