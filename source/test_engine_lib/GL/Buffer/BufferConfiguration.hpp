//
//  BufferConfiguration.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <cstdint>

class Buffer;

class BufferConfiguration {
    
    uint8_t configuration[3];
    uint8_t size = 1;
    
    uint8_t vertex_size = 0;
    
    uint8_t stride_for_index(uint8_t index) const;
    
    void set_pointers() const;

    friend Buffer;

    BufferConfiguration(uint8_t, uint8_t, uint8_t);
    
public:

    static const BufferConfiguration _2;
    static const BufferConfiguration _2_2;
    static const BufferConfiguration _3;
    static const BufferConfiguration _3_2;
    static const BufferConfiguration _3_3;
    static const BufferConfiguration _3_4;
};
