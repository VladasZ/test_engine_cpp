//
//  Player.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation
import SwiftyTools

class Player : Movable {
    
    var world: World?
    let radius = 20.0
    
    var circle: Circle { return Circle(origin: position, radius: radius) }
    
    override func update() {
        
        var nextPosition = position + velocity
        
        if nextPosition.x - radius < 0 || nextPosition.x + radius > 600 { velocity.x = 0 }
        if nextPosition.y - radius < 0 || nextPosition.y + radius > 400 { velocity.y = 0 }
        
        if let collisionEdges = polygon.intersectsCircle(Circle(origin: nextPosition, radius: radius)) {
            
            if collisionEdges.count > 1 {
            
                let edgeVector = collisionEdges.first!.vector
                let projection = velocity.projectionTo(edgeVector)
                velocity = edgeVector.withLength(projection * 0.75)
                nextPosition = position + velocity
                
                if polygon.intersectsCircle(Circle(origin: nextPosition, radius: radius)) != nil {
                    return
                }
            
            }
            else {
                
                let edgeVector = collisionEdges.first!.vector
                let projection = velocity.projectionTo(edgeVector)
                velocity = edgeVector.withLength(projection * 0.75)
            }
        }
        
        position += velocity
    }
}
