//
//  ImageView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "Image.hpp"

class Window;

class ImageView : public View {
      
    void draw() override;

    Image* _image = nullptr;
    
public:
        
    Image* getImage() const;
    ImageView* setImage(Image* image);
    
	View* setColor(const Color& color) override { return this; }

    using View::View;
    ~ImageView() override;
};