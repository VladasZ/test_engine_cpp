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
        
		float width  = 0;
		float height = 0;
        
        Size() = default;
        Size(float width, float height);
                
        Point center() const;
		float ratio()  const;
                
		Size operator / (float value) const;
		Size operator * (float value) const;
        
		bool operator == (const Size& size) const;
    };
}

using namespace Geometry;
