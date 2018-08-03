//
//  Size.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"

namespace Geometry {
    
    class Size {
        
    public:
        
        float width = 0, height = 0;
        
        Size() = default;
        Size(float width, float height);
                
        Point center() const;
                
        template<class T>
        Size operator /(const T &value) {
            return Size(this->width / (float)value, this->height / (float)value);
        }

        bool operator ==(const Size& size) const { return width == size.width && height == size.height; };
        bool operator !=(const Size& size) const { return width != size.width || height != size.height; };
    };
}

using namespace Geometry;
