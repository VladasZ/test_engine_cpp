//
//  PlaneModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/21/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Mesh.hpp"
#include "PlaneModel.hpp"

using namespace gm;
using namespace scene;

static Mesh* create_mesh(const Size& size) {
    return new Mesh(Vertex::Array {
                     {{ 0, -size.width / 2,  size.height / 2 }, { 1, 0, 0 }},
                     {{ 0,  size.width / 2,  size.height / 2 }, { 1, 0, 0 }},
                     {{ 0,  size.width / 2, -size.height / 2 }, { 1, 0, 0 }},
                     {{ 0, -size.width / 2, -size.height / 2 }, { 1, 0, 0 }}}, { 0, 1, 2, 0, 2, 3 });
}


static Mesh* create_mesh(const std::array<gm::Vector3, 4>& points) {
    return new Mesh(Vertex::Array {
                     { points[0], { 0, 0, 1 }},
                     { points[1], { 0, 0, 1 }},
                     { points[2], { 0, 0, 1 }},
                     { points[3], { 0, 0, 1 }}}, { 0, 1, 2, 0, 2, 3 });
}

PlaneModel::PlaneModel(const Size& size) : Model(create_mesh(size)), size(size) {
    look_at({ 0, 0, 1 });
}

PlaneModel::PlaneModel(const std::array<gm::Vector3, 4>& points) : Model(create_mesh(points)) {

}
