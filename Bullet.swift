//
//  Bullet.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/7/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation
import SwiftyTools
import AudioToolbox

class Bullet : Movable {
    
    static let speed = 3.0
    
    var isDead = false
    
    init(player: Player) {
        
        super.init()
        
        velocity  = player.direction.normalized * Bullet.speed
        position  = player.position + velocity.normalized * (player.radius + 30)
        direction = player.direction
        
        after(6) { self.die() }
    }
    
    func die() {
        
        if isDead { return }
        world.removeEntity(self)
        isDead = true
    }
    
    override func update() {
        
        let nextPosition = position + velocity
        
        if  nextPosition.x < player.position.x + player.radius &&
            nextPosition.x > player.position.x - player.radius &&
            nextPosition.y < player.position.y + player.radius &&
            nextPosition.y > player.position.y - player.radius {
            
            AudioServicesPlayAlertSound(kSystemSoundID_Vibrate)
            self.die()
            return
        }
        
        super.update()
    }
}
