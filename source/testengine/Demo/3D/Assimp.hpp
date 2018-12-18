//
//  Assimp.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>

class Mesh;

Mesh* import_model(const std::string& pFile);
