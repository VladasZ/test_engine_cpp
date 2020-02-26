//
//  WorldScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Grid.hpp"
#include "Paths.hpp"
#include "System.hpp"
#include "WorldView.hpp"
#include "WorldScene.hpp"
#include "ModelImporter.hpp"

using namespace cu;
using namespace te;
using namespace scene;


void WorldScene::_setup() {

    view = new WorldView();

    add_object(new Grid());

    auto mountain_dir = Paths::downloads();

    Logvar(System::pwd());
    Logvar(Paths::downloads());
    Logvar(Paths::downloads().ls());
    
//    auto mountain_file = mountain_dir / "Terrain_001.obj";
//
//    Logvar(Paths::downloads().ls());
//    Logvar(mountain_file);
//    Logvar(mountain_dir.ls());
//
//    auto mon_model = ModelImporter::import(mountain_file);
//
//    add_object(mon_model);
//
//    Logvar(mountain_file.ls());

}

