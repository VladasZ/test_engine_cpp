//
//  TEModelDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"

class Buffer;

class TEModelDrawer : public scene::Model::Drawer {

    Buffer* _buffer;

private:
    ~TEModelDrawer() override;
    void _draw() const override;
public:
    TEModelDrawer(scene::Model*);
};
