//
//  Assimp.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//


#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include "Array.hpp"
#include "Vector3.hpp"
#include "Log.hpp"
#include "Buffer.hpp"
#include "Mesh.hpp"
#include "Assimp.hpp"
#include "Random.hpp"


Mesh* import_model(const std::string& pFile)
{
    // Create an instance of the Importer class
    Assimp::Importer importer;
    // And have it read the given file with some example postprocessing
    // Usually - if speed is not the most important aspect for you - you'll
    // propably to request more postprocessing than we do in this example.
    const aiScene* scene = importer.ReadFile( pFile,
                                             aiProcess_CalcTangentSpace       |
                                             aiProcess_Triangulate            |
                                             aiProcess_JoinIdenticalVertices  |
                                             aiProcess_SortByPType);
    
    // If the import failed, report it
    if(!scene)
    {
        Error(importer.GetErrorString());
        return nullptr;
    }
    
    auto mesh = scene->mMeshes[0];
    
    auto result = new Mesh();

#if USE_COLORED_MESH
    auto& vertices = result->colored_vertices;
#else
    auto& vertices = result->vertices;
#endif
    auto& indices = result->indices;
    
    vertices.resize(mesh->mNumVertices);
    
    //memcpy(&vertices[0], mesh->mVertices, mesh->mNumVertices * sizeof(Point3));
    

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        auto& vert = mesh->mVertices[i];
        
        ColoredVertex cVert;
        
        cVert.position.x = vert.x;
        cVert.position.y = vert.y;
        cVert.position.z = vert.z;
        
        
        cVert.color = Random::color();
        
        
        vertices[i] = cVert;
    }
    
    
   // mesh->vertices = colored_vertices;

    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        auto& face = mesh->mFaces[i];
        
        for (unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    return result;//new Buffer((GLfloat*)&vertices[0], vertices.bytes_size(), (GLushort*)&indices[0], indices.bytes_size(), BufferConfiguration::_3);
}

