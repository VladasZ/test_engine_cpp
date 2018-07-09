//
//  RegistryKey.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/06/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#ifdef _WIN32

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

#include <iostream>

#include "RegistryKey.hpp"

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

using namespace std;

string RegistryKey::_current_writing_key;

HKEY _get_hkey(const string& path);
void _try_open_hkey(const string& path);
bool _setRegistryKey(const char* keyPath, const char* keyName, const char* keyData);

static void get_subdirs(HKEY key, vector<string>& result)
{
    TCHAR    achKey[MAX_KEY_LENGTH];
    DWORD    cbName;
    TCHAR    achClass[MAX_PATH] = TEXT("");
    DWORD    cchClassName = MAX_PATH;
    DWORD    cSubKeys = 0;
    DWORD    cbMaxSubKey;
    DWORD    cchMaxClass;
    DWORD    cValues;
    DWORD    cchMaxValue;
    DWORD    cbMaxValueData;
    DWORD    cbSecurityDescriptor;
    FILETIME ftLastWriteTime;

    DWORD i, retCode;

    TCHAR  achValue[MAX_VALUE_NAME];
    DWORD cchValue = MAX_VALUE_NAME;

    retCode = RegQueryInfoKey(
        key,
        achClass,
        &cchClassName,
        NULL,
        &cSubKeys,
        &cbMaxSubKey,
        &cchMaxClass,
        &cValues,
        &cchMaxValue,
        &cbMaxValueData,
        &cbSecurityDescriptor,
        &ftLastWriteTime);

    if (cSubKeys)
    {
        for (i = 0; i<cSubKeys; i++)
        {
            cbName = MAX_KEY_LENGTH;
            retCode = RegEnumKeyEx(key, i,
                achKey,
                &cbName,
                NULL,
                NULL,
                NULL,
                &ftLastWriteTime);
            if (retCode == ERROR_SUCCESS)
            {
                result.push_back(achKey);
            }
        }
    }

    if (cValues)
    {
        for (i = 0, retCode = ERROR_SUCCESS; i<cValues; i++)
        {
            cchValue = MAX_VALUE_NAME;
            achValue[0] = '\0';
            retCode = RegEnumValue(key, i,
                achValue,
                &cchValue,
                NULL,
                NULL,
                NULL,
                NULL);

            if (retCode == ERROR_SUCCESS)
            {
                result.push_back(achValue);
            }
        }
    }
}

RegistryKey::RegistryKey(const string &path) : _path(path), _writer(*this) { 
    _try_open_hkey(path);
}

RegistryKey::RegistryKey(const RegistryKey& key) : _path(key._path), _writer(*this) {

}

bool RegistryKey::subkey_exists(const string& key) {
    try {
        this->operator[](key);
    }
    catch (...) { return false; }
    return true;
}

void RegistryKey::create_subkey(const std::string& key) {
    if (subkey_exists(key))
        return;
    _setRegistryKey(_path.c_str(), key.c_str(), "");
}

RegistryKey::Array RegistryKey::get_subkeys() const {

    Array result;

    vector<string> keys;

    get_subdirs(_get_hkey(_path), keys);

    for (auto key : keys)
    {
        try {
            _try_open_hkey(_path + "\\" + key);
        }
        catch (...) { continue; }

        result.emplace_back(_path + "\\" + key);
    }

    return result;
}

string RegistryKey::get_path() const {
    return _path;
}

RegistryWriter & RegistryKey::operator[] (const std::string &key) {
    _current_writing_key = key;
    _writer._get_value();
    return _writer;
}

#endif
