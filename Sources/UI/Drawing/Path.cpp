//
//  Path.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 09/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Path.hpp"


Path::Path(const Rect &rect) {
    points = {
              rect.origin,
        Point(rect.x,               rect.y + rect.width),
        Point(rect.x + rect.height, rect.y + rect.width),
        Point(rect.x + rect.height, rect.y)
    };
}

void Path::addPoint(const Point &point) {
    points.push_back(point);
}
