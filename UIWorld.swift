//
//  UIWorld.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit
import SwiftyTools

class UIWorld {
    
    var view: UIView
    var world: World
    var testViews: [TestView] = [TestView]()
    
    init(world: World, view: UIView) {
        
        self.world = world
        self.view = view
        world.delegate = self
    }
    
    func addEntity(_ entity: Entity) {
        
        var testView: TestView
        
        if let entity = entity as? Polygon {
            
            testView = TestPolygonView(polygon: entity)
        }
        else {
         
            testView = TestUIImageView(entity: entity)
        }
                
        testViews.append(testView)
        view.addSubview(testView as! UIView)
    }
    
    func update() {
        
        world.update()
        testViews.forEach { $0.update() }
    }
}

extension UIWorld : WorldDelegate {
    
    func worldDidAddEntity(_ entity: Entity) {
        
        addEntity(entity)
    }
    
    func worldDidRemove(_ entity: Entity) {
        
        guard let view = (testViews.filter { $0.entity === entity }).first else { Log.error(); return }
        view.kill()
        testViews = testViews.filter { $0 !== view }
    }
}
