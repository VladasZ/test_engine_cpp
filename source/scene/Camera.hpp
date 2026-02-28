//
//  Camera.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Ray.hpp"
#include "Size.hpp"
#include "Flyable.hpp"


namespace scene {

    class Camera : public Flyable {

        gm::Matrix4            _view_matrix;
        gm::Matrix4      _projection_matrix;
        gm::Matrix4 _view_projection_matrix;

        gm::Vector3 _target        ;
        gm::Vector3 _up { 0, 0, 1 };

    public:

        float fov    =    1.0f;
        float z_near =    0.1f;
        float z_far  = 5000.0f;

        explicit Camera(Scene*);

        gm::Size resolution { 100, 100 };

        const gm::Matrix4&            view_matrix() const;
        const gm::Matrix4&      projection_matrix() const;
        const gm::Matrix4& view_projection_matrix() const;

        void set_target(const gm::Vector3&);
        const gm::Vector3& target() const;

        void move_orbit(const gm::Point&);

        void zoom(float);

        const gm::Vector3& direction() const override;

        gm::Ray cast_ray(const gm::Point&);

    public:

        void update_matrices() override;
        void update() override;

        std::string to_string() const;
    };

}
