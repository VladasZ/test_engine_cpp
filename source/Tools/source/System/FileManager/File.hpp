//
//  File.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "String.hpp"
#include "Memory.hpp"

#if APPLE
using byte = unsigned char;
#else
using byte = std::byte;
//using byte = unsigned char;
#endif

class File MEMORY_MANAGED(File) {

    size_t _size;
    byte *_data;

public:

    size_t getSize() const;
    byte *getData() const;

    File() = default; //FIX
    File(const String &path);
    ~File();
};
