//
//  Rect.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/8/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

class Rect {
    
    var x: Double { get { return origin.x } set { origin.x = newValue } }
    var y: Double { get { return origin.y } set { origin.y = newValue } }
    var width:  Double { get { return size.width }  set { size.width = newValue } }
    var height: Double { get { return size.height } set { size.height = newValue } }
    
    var origin: Point = Point()
    var size:   Size  = Size()
    
    init() { }
    
    init(size: Size) {
        
        self.size = size
    }
    
    init(origin: Point, size: Size) {
        
        self.origin = origin
        self.size   = size
    }
    
    init(_ x: Double, _ y: Double, _ width: Double, _ height: Double) {
        
        origin = Point(x, y)
        size   = Size(width, height)
    }
}
