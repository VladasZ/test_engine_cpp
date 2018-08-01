//
//  ImageView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once
#include "View.hpp"

class Image;
class Window;

class ImageView : public View _MEMORY_MANAGED(ImageView) {
      
    void draw() override;

    Image* _image = nullptr;
    
public:
    
    Image* getImage() const;
    ImageView* setImage(Image* image);
    
    using View::View;
    ~ImageView() override;
};
