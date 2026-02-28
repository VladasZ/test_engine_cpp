//
//  Grid.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Mesh.hpp"
#include "Grid.hpp"

using namespace gm;
using namespace scene;

static Mesh* create_mesh(Size size, Size resolution) {

    Vertex::Array vertices;

    const auto width_min = - size.width / 2;
    const auto width_step = size.width / resolution.width;

    const auto height_min = - size.height / 2;
    const auto height_step = size.height / resolution.height;

    for (int i = 0; i <= resolution.width; i++) {
        vertices.emplace_back( Vector3 { width_min + width_step * i, height_min }             );
        vertices.emplace_back( Vector3 { width_min + width_step * i, height_min + size.height});
    }

    for (int i = 0; i <= resolution.height; i++) {
        vertices.emplace_back( Vector3 { width_min,              height_min + height_step * i });
        vertices.emplace_back( Vector3 { width_min + size.width, height_min + height_step * i });
    }

    Vertex::Indices indices;
    Vertex::Index index = 0;

    for ([[maybe_unused]] auto vert : vertices) {
        indices.push_back(index++);
    }

    return new Mesh(std::move(vertices), std::move(indices));
}

Grid::Grid(const Size& size, const Size& resolution)
    :
    Model(create_mesh(size, resolution), Model::DrawMode::Lines),
    size(size),
    resolution(resolution)
{
    color = Color::black.with_alpha(0.2f);
    selectable = false;
}
