//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "TestView.hpp"

TestView* testView = nullptr;

void RootView::setup() {
    
#if DEBUG_VIEW
    add_subview(new DebugInfoView());
#endif
    


  
}

