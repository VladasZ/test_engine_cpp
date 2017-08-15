//
//  Point.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

infix operator •: AdditionPrecedence

func •(left: Point, right: Point) -> Double {
    
    return left.x * right.x + left.y * right.y
}

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
    
    static func -(left: Point, right: Point) -> Point {
        
        return Point(left.x - right.x, left.y - right.y)
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
    
    func distanceTo(_ point: Point) -> Double {
        
        let xDist = x - point.x
        let yDist = y - point.y
        return sqrt((xDist * xDist) + (yDist * yDist))
    }
    
    func withLength(_ length: Double) -> Point {
        
        return normalized * length
    }
    
    func angleWith(_ point: Point) -> Double {
        
        return (self • point) / self.length / point.length
    }
    
    func projectionTo(_ point: Point) -> Double {
        
        return self.length * angleWith(point)
    }
}

extension Point : CustomStringConvertible {
    
    var description: String { return "Point: x - \(x), y - \(y)" }
}
