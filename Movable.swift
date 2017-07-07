//
//  Movable.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

class Movable : Entity {
    
    var velocity:  Point = Point()
    
    func update() {
        
        let nextPosition = position + velocity
        
        if nextPosition.x < 0 || nextPosition.x > 600 {
            velocity.x = -velocity.x
            direction.x = -direction.x
        }
        if nextPosition.y < 0 || nextPosition.y > 300 {
            velocity.y = -velocity.y
            direction.y = -direction.y
        }
        
        position += velocity
    }
}
