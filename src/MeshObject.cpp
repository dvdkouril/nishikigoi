//
//  MeshObject.cpp
//  nishikigoi
//
//  Created by David Kouril on 07/01/2018.
//

#include "MeshObject.hpp"

MeshObject::MeshObject()
{
    
}

MeshObject::MeshObject(std::vector<vec3> vertices, std::vector<uint> indices)
{
    this->vertices = vertices;
    this->indices = indices;
}

std::vector<vec3> MeshObject::getVertices()
{
    return this->vertices;
}

std::vector<uint> MeshObject::getIndices()
{
    return this->indices;
}

void MeshObject::setVertices(std::vector<vec3> vertices)
{
    this->vertices = vertices;
}

void MeshObject::setIndices(std::vector<uint> indices)
{
    this->indices = indices;
}

void MeshObject::setModelMatrix(mat4 matrix)
{
    this->modelMatrix = matrix;
}

mat4 MeshObject::getModelMatrix()
{
    return this->modelMatrix;
}
