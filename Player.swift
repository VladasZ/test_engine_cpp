//
//  Player.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

class Player : Movable {
    
    var world: World?
    let radius = 20.0
    
    override func update() {
        
        let nextPosition = position + velocity
        
        if nextPosition.x - radius < 0 || nextPosition.x + radius > 600 { velocity.x = 0 }
        if nextPosition.y - radius < 0 || nextPosition.y + radius > 300 { velocity.y = 0 }
        
        position += velocity
    }
}
