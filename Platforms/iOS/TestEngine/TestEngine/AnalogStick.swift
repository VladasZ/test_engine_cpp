//
//  AnalogStick.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit
import iOSTools
import SwiftyTools

protocol AnalogStickDelegate : class {
    
    func analogStickDidBeginDragging(_ stick: AnalogStick)
    func analogStickDidEndDragging(_ stick: AnalogStick)
    func analogStickDidChangePosition(_ stick: AnalogStick)
}

class AnalogStick : IBDesignableView {
    
    //MARK: - Static Properties
    
    static let identifier = "AnalogStick"
    
    //MARK: - Outlets
    
    @IBOutlet var stickImageView: UIImageView!
    
    //MARK: - Properties
    
    var stickCenter: CGPoint!
    var radius: CGFloat { return height / 2 }
    var position: CGPoint = CGPoint.zero
    var delegate: AnalogStickDelegate?
    
    //MARK: - Setup
    
    override func setup() {
        
        layer.cornerRadius = height / 2
        layer.borderWidth = 2
        layer.borderColor = UIColor.black.cgColor
        
        stickImageView.circle()
        stickImageView.layer.borderWidth = 1
        stickImageView.layer.borderColor = UIColor.black.cgColor
        
        stickCenter = stickImageView.center
    }
    
    //MARK: - Actions
    
    @IBAction func didPan(_ sender: UIPanGestureRecognizer) {
        
        if sender.state == .began {
            delegate?.analogStickDidBeginDragging(self)
        }
        
        if sender.state == .ended {
            stickImageView.center = stickCenter
            position = CGPoint.zero
            delegate?.analogStickDidChangePosition(self)
            delegate?.analogStickDidEndDragging(self)
            return
        }
        
        position = sender.location(in: self) - stickCenter
        
        if position.length > radius {
            position = position * (radius / position.length)
        }
        
        stickImageView.fromCenter = position
        delegate?.analogStickDidChangePosition(self)
    }
}
