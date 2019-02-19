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

    enum Filter {
        Nearest,
        Linear,
        Bilinear,
        Trilinear,
        Default = Linear
    };

public:

    TEImageBinder(Image*);
    ~TEImageBinder() override;

    void bind  () const override;
    void unbind() const override;

private:

    void _set_filter(Filter filter);

};
