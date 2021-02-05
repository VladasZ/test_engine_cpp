//
//  ResearchScene.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 05/02/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#pragma once

#include "Scene.hpp"
#include "VectorModel.hpp"


namespace te {

	class ResearchScene : public scene::Scene {

	protected:

        void setup() override;
        void update(float) override;

	protected:

		scene::VectorModel* vector_a = nullptr;
		scene::VectorModel* vector_b = nullptr;
        scene::VectorModel* vector_c = nullptr;
	};

}
