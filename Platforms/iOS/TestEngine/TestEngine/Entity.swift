//
//  Entity.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

class Entity {
    
    var position: Point = Point()
    var direction: Point = Point()
    
    init() { }
    
    init(position: Point) {
        
        self.position = position
    }
}
