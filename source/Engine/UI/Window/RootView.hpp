//
//  RootView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "Debug.hpp"
#include "SettingsView.hpp"
#include "DebugInfoView.hpp"

inline SettingsView* settingsView = nullptr;

class RootView : public View {
    
    friend Window;
    
    void setup() override;

    void createSticks();
    
public:
    
    using View::View;

#if DEBUG_VIEW
    DebugInfoView* debugInfoView;
#endif

};
