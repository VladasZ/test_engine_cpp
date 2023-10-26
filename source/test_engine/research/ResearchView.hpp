//
//  ResearchView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 05/02/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#pragma once

#include "XYZSlidersView.hpp"


namespace te {

	class ResearchView : public ui::View {

	public:

		using View::View;

	protected:

		void setup() override;
		void layout() override;

	public:

		static inline XYZSlidersView* vector_a = nullptr;
		static inline XYZSlidersView* vector_b = nullptr;

	};

}
