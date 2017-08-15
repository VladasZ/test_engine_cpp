//
//  Shooter.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/7/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation
import SwiftyTools

class Shooter : Player {
    
    var isShooting = false
    
    func startShooting() {
        
        if isShooting { Log.error(); return }
        
        isShooting = true
        
        Timer.every(0.5) { stop in
            
            if !self.isShooting { stop = true; return }
                        
            let bullet = Bullet(player: self)
            
            self.world?.addEntity(bullet)
        }
    }
    
    func stopShooting() {
        
        isShooting = false
    }
}
