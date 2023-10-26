//
//  TestScene.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Scene.hpp"
#include "Model.hpp"
#include "XYZPack.hpp"
#include "PointLight.hpp"


namespace te {

	class TestScene : public scene::Scene {

		scene::PointLight *light;

		scene::Model *cube;

		cu::XYZPack<scene::Model *> walls;

		scene::BoxModel *marker_box;

		void setup() override;

	};

}