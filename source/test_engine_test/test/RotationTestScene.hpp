//
//  RotationTestScene.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 17/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Scene.hpp"
#include "VectorModel.hpp"

namespace te {

    class RotationTestScene : public scene::Scene {

    protected:

        scene::VectorModel* vector;

        void _setup() override;
    };

}
