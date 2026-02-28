//
//  RotationTestView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 17/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "XYZSlidersView.hpp"


namespace te {

    class RotationTestView : public ui::View {

    public:

        static inline XYZSlidersView* sliders;

    protected:

        void setup() override;

    };

}
