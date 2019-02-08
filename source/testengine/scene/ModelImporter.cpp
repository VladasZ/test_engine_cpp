//
//  ModelImporter.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "Log.hpp"
#include "Paths.hpp"
#include "ColoredMesh.hpp"
#include "ModelImporter.hpp"

static Assimp::Importer _importer;

scene::Mesh* ModelImporter::import(const std::string& file) {

    const aiScene* scene = _importer.ReadFile(Paths::models_directory() + file,
                                              aiProcess_CalcTangentSpace       |
                                              aiProcess_Triangulate            |
                                              aiProcess_JoinIdenticalVertices  |
                                              aiProcess_SortByPType);

    if (!scene) {
        Error(_importer.GetErrorString());
        //assert(scene == nullptr);
        return nullptr;
    }

    auto mesh = scene->mMeshes[0];

    std::vector<Vector3> vertices;
    std::vector<unsigned short> indices;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        auto& vert = mesh->mVertices[i];
        vertices.emplace_back(vert.x, vert.y, vert.z);
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        auto& face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(static_cast<unsigned short>(face.mIndices[j]));
    }

    return new scene::ColoredMesh(vertices, indices);
}
