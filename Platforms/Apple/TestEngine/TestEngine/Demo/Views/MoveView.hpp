//
//  MoveView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "UI.hpp"

class MoveView : public View {
protected:
    void setup() override;
    void layout() override;
    
public:
    using View::View;
};
