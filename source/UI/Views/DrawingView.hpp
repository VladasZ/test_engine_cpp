//
//  DrawingView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"
#include <vector>

class DrawingView : public View {
    
    std::vector<Path *> paths;
    
    void draw() override;
    void layout() override;
    
public:
    
    using View::View;
 
    void addPath(Path *path);
    
};
