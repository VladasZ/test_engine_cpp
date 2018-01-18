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
    
    BufferData *getBufferData() override;
    void setupBuffer() override;
    void draw() override;
    
    Image *image = nullptr;
    
public:
    
    using View::View;
    
    void setImage(Image *image);
    
};
