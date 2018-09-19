//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"

void RootView::setup() {
    
#if DEBUG_VIEW
    addSubview(new DebugInfoView());
#endif
    
    settingsView = new SettingsView( { 420, 400 });
    settingsView->addLayout(L::Right(), L::Bottom(60));
    addSubview(settingsView);
 
    
    settingsView->onX.subscribe([](float valueX) {
        Logvar(valueX);
    });
    
    settingsView->onY.subscribe([](float valueY) {
        Logvar(valueY);
    });
    
    settingsView->onZ.subscribe([](float valueZ) {
        Logvar(valueZ);
    });
    
    settingsView->onFov.subscribe([](float valueFov) {
        Logvar(valueFov);
    });
}

