//
//  Sprite.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Rect.hpp"
#include "Drawable.hpp"
#include "Array.hpp"
#include "DeprecatedImage.hpp"

class World;

class Sprite : public Drawable {
    
    friend World;
    
    virtual void draw() override;
//    virtual BufferData* getBufferData() override;
//    const BufferConfiguration bufferConfiguration() const override;
    
protected:
    
    bool _neeedsBufferUpdate = true;
    
    ui::Point _position;
	ui::Size _size;
    
    DeprecatedImage* _image;
    
    Array<ui::Rect>* _subsprites = nullptr;
    int _subspriteIndex = -1;
    
public:
        
    Sprite(DeprecatedImage* image);
    ~Sprite();
    
    void setPosition(const ui::Point &position);
	ui::Point position();
    
    void setSize(const ui::Size &size);
	ui::Size size();
    
    void setSubsprites(const std::initializer_list<ui::Rect> &subsprites);
    void setSubspriteIndex(int index);
    int getSubspriteIndex() const;
};
