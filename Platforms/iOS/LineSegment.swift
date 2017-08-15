//
//  LineSegment.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/8/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

class LineSegment {
    
    var a: Point
    var b: Point
    
    var vector: Point { return a - b }
    
    init(a: Point, b: Point) {
        
        self.a = a
        self.b = b
    }
    
    func distanceTo(_ point: Point) -> Double {
        
        return distance(to: point, fromLineSegmentBetween: a, and: b)
    }
}

private func distance(to p: Point, fromLineSegmentBetween l1: Point, and l2: Point) -> Double {
    
    let A: Double = p.x - l1.x
    let B: Double = p.y - l1.y
    let C: Double = l2.x - l1.x
    let D: Double = l2.y - l1.y
    let dot: Double = A * C + B * D
    let len_sq: Double = C * C + D * D
    let param: Double = dot / len_sq
    var xx: Double
    var yy: Double
    if param < 0 || (l1.x == l2.x && l1.y == l2.y) {
        xx = l1.x
        yy = l1.y
    }
    else if param > 1 {
        xx = l2.x
        yy = l2.y
    }
    else {
        xx = l1.x + param * C
        yy = l1.y + param * D
    }
    
    let dx: Double = p.x - xx
    let dy: Double = p.y - yy
    return sqrt(dx * dx + dy * dy)
}
