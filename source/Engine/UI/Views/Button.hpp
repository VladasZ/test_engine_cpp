//
//  Button.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"
#include <functional>

class Button : public View _MEMORY_MANAGED(Button) {
            
    std::function<void()> touchAction;
    std::function<void()> releaseAction;

    ImageView* imageView = nullptr;
    Label* label = nullptr;
    
    void setup() override;
    
public:
    
    using View::View;
    
    void setText(const std::string &text);
    void setImage(Image* image);
        
    void onTouch(std::function<void()> action);
    void onRelease(std::function<void()> action);
};
