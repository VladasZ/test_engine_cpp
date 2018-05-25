//
//  File.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "MemoryManaged.hpp"
#include "String.hpp"

typedef unsigned char Byte;

class File MEMORY_MANAGED(File) {
    
    size_t size;
    Byte *data;
    
public:
    
    size_t getSize() const;
    Byte *getData() const;

    File(const std::string &path);
    ~File();
};

