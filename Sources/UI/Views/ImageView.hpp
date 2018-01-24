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
  
    friend Window;
    
    BufferData *getBufferData() override;
    void setupBuffer() override;
    void draw() override;
    
    Image *image = nullptr;
    
public:
    
    using View::View;
    
    ~ImageView() override;
    
    void setImage(Image *image);
    
};
