//
//  RegistryWriter.cpp
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
#include "RegistryWriter.hpp"

using namespace std;

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
#define KEY RegistryKey::_current_writing_key

HKEY _get_hkey(const string& path) {
    HKEY hkey;

    auto error_code = RegOpenKey(HKEY_LOCAL_MACHINE, path.c_str(), &hkey);

    if (error_code != ERROR_SUCCESS) {
        char error[MAX_KEY_LENGTH];
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, error_code, 0, error, MAX_KEY_LENGTH, 0);
        throw "Unable to open registry key: " + path + ". Error: " + error;
    }
    return hkey;
}

bool _setRegistryKey(const char* keyPath, const char* keyName, const char* keyData) {

    HKEY  key;
    long  error;
    DWORD disposition;

    error = RegCreateKeyEx(
        HKEY_LOCAL_MACHINE, keyPath, 0, NULL, REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS, NULL, &key, &disposition
    );
    if (error) return FALSE;

    error = RegSetValueEx(
        key, keyName, 0, REG_SZ, (BYTE*)keyData, lstrlen(keyData) + 1
    );
    RegCloseKey(key);
    if (error) return FALSE;

    return TRUE;
}

void _try_open_hkey(const string& path) {
    RegCloseKey(_get_hkey(path));
}

RegistryWriter::RegistryWriter(const RegistryKey &key) : _reg_key(&key) { }

RegistryWriter& RegistryWriter::operator=(const char *value) {
    _setRegistryKey(_reg_key->_path.c_str(), KEY.c_str(), value);
    return *this;
}

void RegistryWriter::_get_value() {

    auto hkey = _get_hkey(_reg_key->_path);

    TCHAR result[MAX_VALUE_NAME];
    DWORD resultLength = sizeof(result);

    if (RegQueryValueEx(
        hkey,
        KEY.c_str(),
        NULL,
        NULL,
        reinterpret_cast<LPBYTE>(&result),
        &resultLength)
        != ERROR_SUCCESS)
    {
        throw "Unable to read registry key: " + KEY + " for path: " + _reg_key->_path;
    }

    _value = result;

    RegCloseKey(hkey);
}

RegistryWriter::operator string() {
    return _value;
}

#endif
