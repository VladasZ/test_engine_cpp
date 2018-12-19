//
//  RootView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"
#include "Debug.hpp"
#include "SettingsView.hpp"
#include "DebugInfoView.hpp"

inline SettingsView* settingsView = nullptr;

class RootView : public OldView {
    
    friend Screen;
    
    void setup() override;

    void create_sticks();
    
public:
    
    using OldView::OldView;

#if DEBUG_VIEW
    DebugInfoView* debugInfoView;
#endif

};
