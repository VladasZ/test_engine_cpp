//
//  Sprite.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Primitives.hpp"
#include "Drawable.hpp"

class World;
class Image;

class Sprite : public Drawable {
    
    friend World;
    
    virtual void draw() override;
    virtual BufferData *getBufferData() override;
    const BufferConfiguration bufferConfiguration() const override;
    
protected:
    
    bool neeedsBufferUpdate = true;
    
    Point _position;
    Size _size;
    
    Image *image;
    
public:
        
    Sprite(Image *image);
    
    void setPosition(const Point &position);
    Point position();
    
    void setSize(const Size &size);
    Size size();
};
