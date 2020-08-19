//
//  ModelImporter.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#ifdef USING_ASSIMP

#include <unordered_map>

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "Log.hpp"
#include "Mesh.hpp"
#include "Model.hpp"
#include "StringUtils.hpp"
#include "ModelImporter.hpp"

using namespace cu;
using namespace gm;
using namespace scene;

static Assimp::Importer _importer;


scene::Model* ModelImporter::import(const std::string& file, Image* image) {

    Log << "Loading model:" << file;

    const aiScene* scene = _importer.ReadFile(file,
                                              aiProcess_CalcTangentSpace       |
                                              aiProcess_Triangulate            |
                                              aiProcess_JoinIdenticalVertices  |
                                              aiProcess_SortByPType             );

    if (!scene) {
        Fatal(_importer.GetErrorString());
    }

    Logvar(scene->mNumMeshes);

    auto meshes = std::vector<aiMesh*> { scene->mMeshes, scene->mMeshes + scene->mNumMeshes };

    auto mesh                    = scene->mMeshes[0];
    auto has_texture_coordinates = mesh->HasTextureCoords(0);

    Vertex::Indices indices;

    Logvar(file);
    Logvar(scene->mNumMaterials);
    Logvar(mesh->HasTextureCoords(0));
    Logvar(scene->HasMaterials());
    Logvar(scene->HasTextures());

    Logvar(mesh->mMaterialIndex);


    auto material = scene->mMaterials[mesh->mMaterialIndex];

    Logvar(material->GetTextureCount(aiTextureType_DIFFUSE));

    aiString texturePath;

    auto result = material->GetTexture(aiTextureType_DIFFUSE, 0, &texturePath);

    std::string texture_path = texturePath.C_Str();

    //Logvar(texture_path);


    //cu::String::drop_first(texture_path);

//    auto tex_index = std::stoi(texture_path);
//
//    auto texture = scene->mTextures[tex_index];
//
//    Logvar(texture->mWidth);
//    Logvar(texture->mHeight);
//
//    Logvar(tex_index);


    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        const auto& face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(static_cast<Vertex::Index>(face.mIndices[j]));
        }
    }

    if (image && has_texture_coordinates) {
        Vertex::Array vertices;

        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
            vertices.emplace_back(Vector3::force_create(mesh->mVertices[i]),
                                  Vector3::force_create(mesh->mNormals[i]),
                                  Point { mesh->mTextureCoords[0][i].x, 1 - mesh->mTextureCoords[0][i].y });
        }

        return new Model(new Mesh(std::move(vertices),
                                  std::move(indices)),
                         image);
    }

    Vertex::Array vertices;


    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        vertices.emplace_back(Vector3::force_create(mesh->mVertices[i]),
                              Vector3::force_create(mesh->mNormals[i]));
    }

    Log << mesh->mNumVertices;

    auto parsed_mesh = new scene::Mesh(std::move(vertices),
                                       std::move(indices));

    return new scene::Model(parsed_mesh);
}

#endif
