//
//  World.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import Foundation

protocol WorldDelegate : class {
    
    func worldDidAddEntity(_ entity: Entity)
    func worldDidRemove(_ entity: Entity)
}

class World {
    
    private var entities: [Entity] = [Entity]()
    
    var delegate: WorldDelegate?
    
    func addEntity(_ entity: Entity) {
        
        entities.append(entity)
        delegate?.worldDidAddEntity(entity)
    }
    
    func removeEntity(_ entity: Entity) {
        
        entities = entities.filter { $0 !== entity }
        delegate?.worldDidRemove(entity)
    }
    
    func update() {
        
        entities.forEach {
            
            if let movable = $0 as? Movable { movable.update() }
        }
    }
}
