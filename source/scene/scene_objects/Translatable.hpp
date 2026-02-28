//
//  Movable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Movable.hpp"

namespace scene {

class Translatable : public Movable {

protected:

    gm::Matrix4 _translation_matrix;

public:

    const gm::Matrix4& translation_matrix() const;

    void update_matrices() override;

};

}
