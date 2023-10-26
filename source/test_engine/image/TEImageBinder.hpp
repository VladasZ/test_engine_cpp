//
//  TEImageBinder.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "ImageBinder.hpp"

class Image;

class TEImageBinder : public image::ImageBinder {

    unsigned int _id = 0;

public:

    TEImageBinder(Image*);
    ~TEImageBinder() override;

    int id() const override;

    void bind () const override;

};
