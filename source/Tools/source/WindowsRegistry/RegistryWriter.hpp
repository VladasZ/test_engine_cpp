//
//  RegistryWriter.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/06/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#ifdef _WIN32

#include <string>

class RegistryKey;

class RegistryWriter
{
    friend RegistryKey;
    
    std::string _value;

    const RegistryKey* const _reg_key;
    
    RegistryWriter(const RegistryKey &key);

    void _get_value();

public:

    RegistryWriter& operator = (const char* value);

    operator std::string();
};

#endif
