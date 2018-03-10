//
//  Drawable.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 10/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Drawable.hpp"
#include "Buffer.hpp"
#include "BufferConfiguration.hpp"


void Drawable::setupBuffer() {
    if (buffer != nullptr) delete buffer;
    buffer = new Buffer(getBufferData(), bufferConfiguration());
}

const BufferConfiguration Drawable::bufferConfiguration() const {
    return BufferConfiguration(2);
}

