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
let polygon = Polygon(vertices: [
    
    Point(0, 100),
    Point(10, 80),
    Point(50, 115),
    Point(60, 75),
    Point(100, 80),
    Point(150, 15),
    Point(160, 125),
    Point(100, 150),
    Point(80, 125),
    Point(60, 150),
])

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
        
     
        
        polygon.position = Point(200, 200)
        
        let uiWorld = UIWorld(world: world, view: view)
        
        world.addEntity(player)
        world.addEntity(polygon)

        Timer.every(0.01) { _ in uiWorld.update() }
    }
}


