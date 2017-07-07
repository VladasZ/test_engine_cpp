//
//  TestUIView.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit
import iOSTools
import SwiftyTools

class TestUIView : UIImageView {
    
    var entity: Entity!
    
    init(entity: Entity) {
        
        super.init(frame: CGRect.zero)
        
        self.entity = entity
        
        if entity is Shooter {
            
            image = #imageLiteral(resourceName: "smile")
            frame = CGRect(width: 50, height: 50)
        }
        else if entity is Bullet {
            
            image = #imageLiteral(resourceName: "bullet")
            frame = CGRect(width: 10, height: 50)
        }
        else {
            
            image = #imageLiteral(resourceName: "smile")
            frame = CGRect(width: 100, height: 100)
            Log.warning()
        }
        
        update()
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func update() {
        
        if !entity.direction.isZero {
            transform = CGAffineTransform(rotationAngle: CGFloat(entity.direction.angle))
        }
        
        center.x = CGFloat(entity.position.x)
        center.y = CGFloat(entity.position.y)
    }
}
