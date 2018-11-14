//
//  File.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <cstddef>

#include "String.hpp"

using byte = std::byte;

class File {

    size_t _size;
    byte* _data;

public:

    size_t getSize() const;
    byte* getData() const;

    File() = default; //FIX
    File(const String &path);
    ~File();
};
