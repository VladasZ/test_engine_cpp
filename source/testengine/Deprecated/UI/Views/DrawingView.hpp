//
//  DrawingView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Path.hpp"
#include "OldView.hpp"
#include "Array.hpp"

class DrawingView : public OldView {
    
    Array<Path*> paths;
    
    void draw() override;

public:
    
    using OldView::OldView;
 
    void addPath(Path* path);
    
};
