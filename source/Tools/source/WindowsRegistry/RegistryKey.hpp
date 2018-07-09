//
//  RegistryKey.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/06/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#ifdef _WIN32

#include <string>
#include <vector>

#include "RegistryWriter.hpp"

class RegistryKey 
{
    friend RegistryWriter;

    static std::string _current_writing_key;
    std::string _path;

    RegistryWriter _writer;

public:

    using Array = std::vector<RegistryKey>;

    RegistryKey(const std::string &path);
    RegistryKey(const RegistryKey& key);

    bool subkey_exists(const std::string& key);
    void create_subkey(const std::string& key);

    Array get_subkeys() const;
    std::string get_path() const;

    RegistryWriter & operator[] (const std::string &key);
};

#endif
