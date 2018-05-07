//
//  MeshObject.hpp
//  nishikigoi
//
//  Created by David Kouril on 07/01/2018.
//

#ifndef MeshObject_hpp
#define MeshObject_hpp

#include <stdio.h>
#include "SceneObject.hpp"

class MeshObject : SceneObject
{
public:
    MeshObject();
    MeshObject(std::vector<vec3> vertices, std::vector<uint> indices);
    
    void setModelMatrix(mat4 matrix);
    mat4 getModelMatrix();
    
    std::vector<vec3> getVertices();
    std::vector<uint> getIndices();
    void setVertices(std::vector<vec3> vertices);
    void setIndices(std::vector<uint> indices);
    
private:
    std::vector<vec3> vertices;
    std::vector<uint> indices;
    
    mat4                modelMatrix;
};

#endif /* MeshObject_hpp */
