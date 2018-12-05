//
//  ImageView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"
#include "Image.hpp"

class Window;

class ImageView : public OldView {
      
    void draw() override;

    Image* _image = nullptr;
    
public:
        
    Image* get_image() const;
    ImageView* set_image(Image* image);
    
	OldView* set_color(const ui::Color& color) override { return this; }

    using OldView::OldView;
    ~ImageView() override;
};
