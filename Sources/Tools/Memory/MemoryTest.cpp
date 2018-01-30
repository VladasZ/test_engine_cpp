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
    
    String uuuu = "lalalaRgluk!";
    String uuuu2 = string("lalalalal2");
    
    uuuu.print();
    uuuu2.print();
    
    (uuuu + uuuu2).print();
    
    
    uuuu += uuuu2;
    
    uuuu.print();
    
    
    
    string test = String("std string uuu");
    const char *test1 = String("c string");
    
    String sps = "heeellooo";
    
    cout << sps << endl;
    
    
    cout << test << endl;
    cout << test1 << endl;

}
