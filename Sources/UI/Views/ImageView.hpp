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

class ImageView : public View {
  
    friend Window;
    
    virtual BufferData getBufferData();
    virtual void setupBuffer();
    virtual void draw() const;
    
    Image *image;
    
public:
    
    ImageView() = default;
    ImageView(Float x, Float y, Float width, Float height);
    ImageView(Float width, Float height);
    
    void setImage(Image *image);
    
};
