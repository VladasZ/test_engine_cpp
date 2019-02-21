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
#include "Model.hpp"
#include "ColoredMesh.hpp"
#include "TexturedMesh.hpp"
#include "TexturedModel.hpp"
#include "ModelImporter.hpp"

static Assimp::Importer _importer;

scene::Model* ModelImporter::import(const std::string& file, Image* image) {

    Info(std::string() + "Loading model: " + file);

    const aiScene* scene = _importer.ReadFile(Paths::models_directory() + file,
                                              aiProcess_CalcTangentSpace       |
                                              aiProcess_Triangulate            |
                                              aiProcess_JoinIdenticalVertices  |
                                              aiProcess_SortByPType);

    if (!scene) {
        Error(_importer.GetErrorString());
        return nullptr;
    }

    auto mesh = scene->mMeshes[0];
    auto has_texture_coordinates = mesh->HasTextureCoords(0);

    std::vector<Vector3> vertices;
    std::vector<unsigned short> indices;
    std::vector<Point> texture_coordinates;

    Info(file);
    Info(mesh->HasTextureCoords(0));
    Logvar(scene->HasMaterials());

    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        auto& vert = mesh->mVertices[i];
        vertices.emplace_back(vert.x, vert.y, vert.z);
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        auto& face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(static_cast<unsigned short>(face.mIndices[j]));
    }

    if (image && has_texture_coordinates) {
        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
            auto& coord = mesh->mTextureCoords[0][i];
            texture_coordinates.emplace_back(coord.x, 1 - coord.y);
        }

        return new scene::TexturedModel(image, new scene::TexturedMesh(vertices, indices, texture_coordinates));
    }

    return new scene::Model(new scene::ColoredMesh(vertices, indices));
}
