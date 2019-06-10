//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "TestView.hpp"


void TestView::_setup() {
    
    button = new ui::Button();
    add_subview(button);
    
    button->on_press.subscribe([]{
        Info("SOPOK");
    });
}

void TestView::_layout() {
    View::_layout();
    
    button->set_frame({
        0,
        _frame.size.height - 100,
        100,
        100
    });
}
