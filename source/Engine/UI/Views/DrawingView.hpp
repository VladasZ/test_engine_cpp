//
//  DrawingView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Path.hpp"
#include "View.hpp"
#include "Array.hpp"

class DrawingView : public View {
    
    Array<Path*> paths;
    
    void draw() override;

public:
    
    using View::View;
 
    void addPath(Path* path);
    
};
