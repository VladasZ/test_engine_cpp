//
//  UIView.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit
import SwiftyTools

extension UIView {
    
    var superviewCenter: CGPoint {
        guard let superview = superview else { Log.error(); return CGPoint.zero }
        return CGPoint(superview.width / 2, superview.height / 2)
    }
    
    var fromCenter: CGPoint {
        
        get {
            guard let superview = superview else { Log.error(); return CGPoint.zero }
            return CGPoint(superview.width / 2 - center.x, superview.height / 2 - center.y)
        }
        set {
            center = newValue + superviewCenter
        }
    }
}

