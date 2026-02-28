//
//  Mesh.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vertex.hpp"

namespace scene {

class Mesh {

private:

    const gm::Vertex::Array _vertices;
    const gm::Vertex::Indices _indices;

public:

    Mesh(const gm::Vertex::Array&, const gm::Vertex::Indices& = { });

    bool has_indices() const;

    const gm::Vertex::Indices& indices() const;
    const gm::Vertex::Array& vertices() const;
};

}
