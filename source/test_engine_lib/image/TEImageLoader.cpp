//
//  TEImageLoader.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TEImageBinder.hpp"
#include "TEImageLoader.hpp"

TEImageLoader::~TEImageLoader() {

}

image::ImageBinder* TEImageLoader::create_binder_for(Image* image) {
    return new TEImageBinder(image);
}
