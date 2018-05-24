//
//  File.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

typedef unsigned char Byte;

#include "STL.hpp"

class File MEMORY_MANAGED(File) {
    
    size_t size;
    Byte *data;
    
public:
    
    size_t getSize() const;
    Byte *getData() const;

    File(const String &path);
    ~File();
};

