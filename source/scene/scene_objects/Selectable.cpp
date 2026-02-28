//
//  Selectable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Mesh.hpp"
#include "Selectable.hpp"

using namespace gm;
using namespace scene;


static Box box_for_mesh(Mesh* mesh) {

    Vector3 min { std::numeric_limits<float>::max() };
    Vector3 max { std::numeric_limits<float>::min() };

    for (auto vertex : mesh->vertices()) {
        if (vertex.position.x < min.x) min.x = vertex.position.x;
        if (vertex.position.y < min.y) min.y = vertex.position.y;
        if (vertex.position.z < min.z) min.z = vertex.position.z;

        if (vertex.position.x > max.x) max.x = vertex.position.x;
        if (vertex.position.y > max.y) max.y = vertex.position.y;
        if (vertex.position.z > max.z) max.z = vertex.position.z;
    }

    return Box { min, max };
}

Selectable::Selectable(Mesh* mesh) : bounding_box(box_for_mesh(mesh)) {

}

bool Selectable::intersects_ray(const gm::Ray& ray) const {
    if (!selectable) return false;
    const auto inversed_model = _model_matrix.inversed();
    const auto transformed_orig = inversed_model * ray.begin;
    const auto transformed_dir  = inversed_model * ray.end;
    return bounding_box.intersects_ray({ transformed_orig, transformed_dir });
}
