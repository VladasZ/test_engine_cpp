//
//  Point.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

struct Point {
    
    var x: Double = 0
    var y: Double = 0
    
    var angle: Double { return .pi - atan2(x, y) }
    var isZero: Bool { return x == 0 && y == 0 }
    var length: Double { return sqrt(pow(abs(x), 2) + pow(abs(y), 2)) }
    
    static var one: Point { return Point(0, 1) }
    
    var normalized: Point {
        
        if self.isZero { return Point.one }
        return self * (1 / length)
    }
    
    init() { }
    
    init(_ x: Double, _ y: Double) {
    
        self.x = x
        self.y = y
    }
    
    static func +(left: Point, right: Point) -> Point {
    
        return Point(left.x + right.x, left.y + right.y)
    }
    
    static func += ( left: inout Point, right: Point) {
        
        left.x += right.x
        left.y += right.y
    }
    
    static func *(left: Point, right: Double) -> Point {
        
        return Point(left.x * right, left.y * right)
    }
}

extension Point : CustomStringConvertible {
    
    var description: String { return "Point: x - \(x), y - \(y)" }
}
