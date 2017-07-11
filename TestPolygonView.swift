//
//  TestUIView.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/8/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit
import CoreGraphics
import QuartzCore
import iOSTools
import SwiftyTools

class TestPolygonView : UIView, TestView {
    
    var _entity: Entity
    var entity: Entity { get { return _entity } set { _entity = newValue } }
    
    init(polygon: Polygon) {
        
        _entity = polygon
        super.init(frame: CGRect.zero)
        
        let sizeToFit = polygon.sizeToFit.cgSize
        
        frame = CGRect(width: sizeToFit.width, height: sizeToFit.height)
        backgroundColor = UIColor.clear
        
        update()
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func kill() {
        
        removeFromSuperview()
    }
    
    func update() {
        
        if !entity.direction.isZero {
            transform = CGAffineTransform(rotationAngle: CGFloat(entity.direction.angle))
        }
        
        var frame = self.frame
        frame.x = CGFloat(entity.position.x)
        frame.y = CGFloat(entity.position.y)
        self.frame = frame
    }
    
    override func draw(_ rect: CGRect) {
        super.draw(rect)
        
        guard let vertices = (entity as? Polygon)?.vertices else { return }
        
        let ctx = UIGraphicsGetCurrentContext()!
        
        ctx.beginPath()
        ctx.setFillColor(UIColor.gray.cgColor)
        
        ctx.move(to: vertices.first!.cgPoint)
        
        for i in 1..<vertices.count {
            
            ctx.addLine(to: vertices[i].cgPoint)
        }
        
        ctx.addLine(to: vertices[0].cgPoint)
        
        ctx.fillPath()
    }
}
