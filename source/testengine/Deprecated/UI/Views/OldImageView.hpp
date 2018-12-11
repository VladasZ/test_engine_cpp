//
//  ImageView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"
#include "TestEngineImage.hpp"

class Window;

class OldImageView : public OldView {
      
    void draw() override;

    Image* _image = nullptr;
    
public:
        
    Image* image() const;
    OldImageView* set_image(Image* image);
    
	OldView* set_color(const ui::Color& color) override { return this; }

    using OldView::OldView;
    ~OldImageView() override;
};
