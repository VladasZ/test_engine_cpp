//
//  PositionManipulator.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "PositionManipulator.hpp"

using namespace gm;
using namespace scene;

PositionManipulator::PositionManipulator() : BoxModel(0.1f) {

    for (auto& arrow : arrows) {
        add_submodel(arrow = new VectorModel());
    }

    static constexpr float plane_size = 0.32f;
    static constexpr float plane_height = 0.01f;

    planes.x = new BoxModel({ plane_height, plane_size, plane_size });
    planes.y = new BoxModel({ plane_size, plane_height, plane_size });
    planes.z = new BoxModel({ plane_size, plane_size, plane_height });

    planes.x->edit_position() = { 0, plane_size / 2, plane_size / 2 };
    planes.y->edit_position() = { plane_size / 2, 0, plane_size / 2 };
    planes.z->edit_position() = { plane_size / 2, plane_size / 2, 0 };

    for (auto& plane : planes) {
        plane->color = gm::Color::yellow.with_alpha(0.28f);
        add_submodel(plane);
    }

    arrows.x->color = Color::red;
    arrows.y->color = Color::green;
    arrows.z->color = Color::blue;

    arrows.x->look_at({ 1, 0, 0 });
    arrows.y->look_at({ 0, 1, 0 });
    arrows.z->look_at({ 0, 0, 1 });

    box = new BoxModel(0.1f);
    box->color = Color::turquoise;
    add_submodel(box);

    color = Color::clear;

    respects_depth_buffer = false;

}

gm::Axis PositionManipulator::get_axis(Model* vector) const {
    if (vector == arrows.x) return Axis::X;
    if (vector == arrows.y) return Axis::Y;
    if (vector == arrows.z) return Axis::Z;
    Fatal("Invalid model in PositionManipulator::get_position");
}

gm::Axis PositionManipulator::get_plane(Model* plane) const {
    if (plane == planes.x) return Axis::X;
    if (plane == planes.y) return Axis::Y;
    if (plane == planes.z) return Axis::Z;
    Fatal("Invalid model in PositionManipulator::get_plane");
}
