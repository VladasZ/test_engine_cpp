//
//  ModelImporter.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <string>

#include "Image.hpp"

namespace scene {
    class Model;
}

class ModelImporter {
public:
    static scene::Model* import(const std::string&, Image* = nullptr);
};
