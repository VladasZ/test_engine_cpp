//
//  TestView.swift
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/8/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

import UIKit

protocol TestView : class {
    
    var entity: Entity { get set }
    
    func update()
    func kill()
}
