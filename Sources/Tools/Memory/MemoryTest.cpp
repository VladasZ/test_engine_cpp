//
//  MemoryTest.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "MemoryTest.hpp"

#include "UI.hpp"

void memoryTest() {

    MemoryManager::printsEveryOperation = true;
    
    Color uu = Color::green;
    
    cout << uu.toString()  << endl;
    
}
