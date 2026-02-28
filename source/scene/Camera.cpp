//
//  Camera.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Log.hpp"
#include "Scene.hpp"
#include "Camera.hpp"

using namespace gm;
using namespace scene;


Camera::Camera(Scene* scene) : Flyable(Vector3() + 10.0f) {
    _scene = scene;
}

const Matrix4& Camera::view_matrix() const {
    return _view_matrix;
}

const Matrix4& Camera::projection_matrix() const {
    return _projection_matrix;
}

const Matrix4& Camera::view_projection_matrix() const {
    return _view_projection_matrix;
}

void Camera::set_target(const Vector3& target) {
    _target = target;
    _need_matrices_update = true;
}

const Vector3& Camera::target() const {
    return _target;
}

void Camera::move_orbit(const Point& shift) {
    if (shift.is_zero()) return;
    _position -= _target;
    _position.orbit_shift(shift);
    _position += _target;
    _need_matrices_update = true;
}

void Camera::zoom(float value) {
    _position = _position - _target;
    float length = _position.length();
    _position.set_length(length + (length * 0.1f * -value));
    _position += _target;
    _need_matrices_update = true;
}

const Vector3& Camera::direction() const {
    static Vector3 direction;
    direction = _target - _position;
    return direction;
}

Ray Camera::cast_ray(const gm::Point& location) {

    Vector4 start {
        (location.x / resolution.width - 0.5f) * 2.0f,
        ((resolution.height - location.y) / resolution.height - 0.5f) * 2.0f,
        -1,
        1
    };

    Vector4 end {
        (location.x / resolution.width - 0.5f) * 2.0f,
        ((resolution.height - location.y) / resolution.height - 0.5f) * 2.0f,
        0,
        1
    };

    const auto inversed_transform = view_projection_matrix().inversed();

    start = inversed_transform * start; start /= start.w;
    end   = inversed_transform *   end;   end /=   end.w;

    Ray ray { start.vector3(), end.vector3() };

    ray.end = (ray.direction_vector() * 1000) + ray.begin;

    return ray;
}

void Camera::update_matrices() {

    if (!_need_matrices_update) return;

    _view_matrix            = Matrix4::transform::look_at(_position, _target, _up);
    _projection_matrix      = Matrix4::transform::perspective(fov, resolution.width / resolution.height, z_near, z_far);
    _view_projection_matrix = _projection_matrix * _view_matrix;

    for (auto obj : _scene->_objects) {
        obj->set_needs_matrices_update();
    }

    _scene->position_manipulator->set_needs_matrices_update();

    _need_matrices_update = false;
}

void Camera::update() {
    _target += velocity;
    Movable::update();
}

std::string Camera::to_string() const {
    return VarString(_position) + " " + VarString(_target);
}
