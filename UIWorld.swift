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
    var testUIViews: [TestUIView] = [TestUIView]()
    
    init(world: World, view: UIView) {
        
        self.world = world
        self.view = view
        world.delegate = self
    }
    
    func addEntity(_ entity: Entity) {
        
        let testView = TestUIView(entity: entity)
        testUIViews.append(testView)
        view.addSubview(testView)
    }
    
    func update() {
        
        world.update()
        testUIViews.forEach { $0.update() }
    }
}

extension UIWorld : WorldDelegate {
    
    func worldDidAddEntity(_ entity: Entity) {
        
        addEntity(entity)
    }
    
    func worldDidRemove(_ entity: Entity) {
        
        guard let view = (testUIViews.filter { $0.entity === entity }).first else { Log.error(); return }
        view.removeFromSuperview()
        testUIViews = testUIViews.filter { $0 !== view }
    }
}
