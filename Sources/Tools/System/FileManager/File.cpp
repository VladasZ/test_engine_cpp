//
//  File.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/26/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "File.hpp"
#include "Log.hpp"
#include "FileManager.hpp"

File::File(const string &path) {
    
    FILE* file = fopen(FileManager::assetsPathWithFileName(path).c_str(), "rb");
    
    if (file == 0) {
       // Error("Failed to open a file");
        return;
    }
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    data = new Byte[size];
    fread(data, sizeof(Byte), size, file);
    fclose(file);
}

File::~File() {
    
    delete[] data;
}

size_t File::getSize() const {
    return size;
}

Byte * File::getData() const {
    return data;
}
