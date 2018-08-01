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
#include "Array.hpp"
#include "Image.hpp"

class World;

class Sprite : public Drawable {
    
    friend World;
    
    virtual void draw() override;
//    virtual BufferData* getBufferData() override;
//    const BufferConfiguration bufferConfiguration() const override;
    
protected:
    
    bool _neeedsBufferUpdate = true;
    
    Point _position;
    Size _size;
    
    Image* _image;
    
    Array<Rect>* _subsprites = nullptr;
    int _subspriteIndex = -1;
    
public:
        
    Sprite(Image* image);
    ~Sprite();
    
    void setPosition(const Point &position);
    Point position();
    
    void setSize(const Size &size);
    Size size();
    
    void setSubsprites(const std::initializer_list<Rect> &subsprites);
    void setSubspriteIndex(int index);
    int getSubspriteIndex() const;
};
