//
//  ViewController.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit
import SwiftyTools

var world: World!
let player = Shooter()

class ViewController: UIViewController {
    
    
    @IBOutlet var leftStick: AnalogStick!
    @IBOutlet var rightStick: AnalogStick!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        leftStick.delegate = self
        rightStick.delegate = self
        setupWorld()
    }
    
    func setupWorld() {
        
        
        world = World()
                
        player.position = Point(100, 100)
        player.world = world
        
        let uiWorld = UIWorld(world: world, view: view)
        
        world.addEntity(player)

        Timer.every(0.01) { _ in uiWorld.update() }
    }
}


