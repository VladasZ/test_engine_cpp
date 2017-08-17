//
//  Point.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma mark

class Point {
    
public:
    
#pragma mark - Properties
    
    double x = 0, y = 0;
    
#pragma mark - Initialization
    
    Point() = default;
    Point(double x, double y);

#pragma mark - Getters
    
    double angle() const;
    bool isZero() const;
    double length() const;
    
    Point normalized() const;
    double distanceTo(const Point &point) const;
    Point withLength(double length) const;
    double angleWith(const Point &point) const;
    double projectionTo(const Point &point) const;
    
#pragma mark - Static properties
    
    static const Point one;
};
