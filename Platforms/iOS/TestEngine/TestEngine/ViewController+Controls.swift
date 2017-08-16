//
//  ViewController+Controls.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/7/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit
import SwiftyTools

extension ViewController {
    
    
}

extension ViewController : AnalogStickDelegate {
    
    func analogStickDidBeginDragging(_ stick: AnalogStick) {
        
        if stick !== rightStick { return }
        after(0.1) { player.startShooting() }
    }

    func analogStickDidEndDragging(_ stick: AnalogStick) {
        
        if stick !== rightStick { return }
        player.stopShooting()
    }
    
    func analogStickDidChangePosition(_ stick: AnalogStick) {
                
        if stick === leftStick {
            
            player.velocity = (stick.position * 0.03).point
        }
        else {
            player.direction = stick.position.point
        }
    }
}
