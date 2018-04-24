//
//  DebugInfoView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"

class DebugInfoView : public View _MEMORY_MANAGED(DebugInfoView) {
    
    Label *fpsLabel;
#if MEMORY_TRACKING
    Label *allocatedLabel;
    Label *deletedLabel;
    Label *existsLabel;
#endif
    Label *framesDrawnLabel;
    Label *touchLabel;

    vector<Label *> labels() const;
    
  
public:
        
    DebugInfoView();
    
    void setup() override;
    
    void update();
    void setTouchLabelText(const String &text);
    
    bool containsGlobalPoint(const Point &point) const override { return true; }
};
