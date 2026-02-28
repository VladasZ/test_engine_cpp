//
//  Scalable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/20/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Rotatable.hpp"

namespace scene {

class Scalable : public Rotatable {

public:

    gm::Vector3 _scale = { 1.0f, 1.0f, 1.0f };
    gm::Matrix4 _scale_matrix;

    gm::Matrix4 _model_matrix;

public:

    const gm::Vector3& scale() const;

    void set_scale(float);
    void set_scale(const gm::Vector3&);

    const gm::Matrix4& model_matrix() const;

    void update_matrices() override;

};

}
