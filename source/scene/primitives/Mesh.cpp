//
//  Mesh.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Mesh.hpp"

using namespace scene;

Mesh::Mesh(const gm::Vertex::Array& vertices, const gm::Vertex::Indices& indices)
: _vertices(vertices), _indices(indices) { }

bool Mesh::has_indices() const {
    return _indices.size();
}

const gm::Vertex::Indices& Mesh::indices() const {
    return _indices;
}

const gm::Vertex::Array& Mesh::vertices() const {
    return _vertices;
}
