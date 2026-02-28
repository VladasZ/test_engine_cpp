//
//  Rotatable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Translatable.hpp"

namespace scene {

class Rotatable : public Translatable {

protected:

    bool _ignore_quat = false;
    gm::Vector4 _rotation;
    gm::Matrix4 _rotation_matrix;

public:

    void look_at(const gm::Vector3&);

    const gm::Vector4& rotation() const;
    void set_rotation(const gm::Vector4&);

    void update_matrices() override;

};

}
