//
//  Size.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

namespace TestEngine {
    
    class Size //MEMORY_MANAGED(Size)
    {
        
    public:
        
        float width = 0, height = 0;
        
        Size() = default;
        Size(float width, float height);
                
        template<class T>
        Size operator /(const T &value) {
            return Size(this->width / value, this->height / value);
        }
    };
}

using namespace TestEngine;
