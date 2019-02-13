//
//  ModelImporter.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <string>

namespace scene {
class Mesh;
}

class ModelImporter {
public:
    static scene::Mesh* import(const std::string&);
};
