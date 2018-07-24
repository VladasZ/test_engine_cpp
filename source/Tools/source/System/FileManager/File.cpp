//
//  File.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "FileManager.hpp"
#include "File.hpp"
#include "Log.hpp"

using namespace std;

File::File(const String &path) {

    FILE* file = fopen(FileManager::assetsPathWithFileName(path).c_str(), "rb");

    if (file == 0) {
//        Error("Failed to open file: " << path);
        return;
    }
    fseek(file, 0, SEEK_END);
    _size = ftell(file);
    fseek(file, 0, SEEK_SET);
    _data = new byte[_size];
    fread(_data, sizeof(byte), _size, file);
    fclose(file);
}

File::~File() {
    delete[] _data;
}

size_t File::getSize() const {
    return _size;
}

byte * File::getData() const {
    return _data;
}
