//
//  CGPoint.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit

extension CGPoint {

    //MARK: - Operators
    
    static func +(left: CGPoint, right: CGPoint) -> CGPoint {
        
        return CGPoint(left.x + right.x, left.y + right.y)
    }
    
    static func -(left: CGPoint, right: CGPoint) -> CGPoint {
        
        return CGPoint(left.x - right.x, left.y - right.y)
    }
    
    static func *(left: CGPoint, right: CGFloat) -> CGPoint {
        
        return CGPoint(left.x * right, left.y * right)
    }
    
    //MARK: - Properties
    
    var length: CGFloat {
        
        return sqrt(pow(abs(x), 2) + pow(abs(y), 2))
    }
    
    //MARK: - Functions
    
    func distanceTo(_ point: CGPoint) -> CGFloat {
        
        let xDist = x - point.x
        let yDist = y - point.y
        return CGFloat(sqrt((xDist * xDist) + (yDist * yDist)))
    }
}
