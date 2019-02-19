//
//  TEImageLoader.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "ImageLoader.hpp"

class TEImageLoader : public image::ImageLoader {
public:
    ~TEImageLoader() override;
    image::ImageBinder* create_binder_for(Image*) override;
};
