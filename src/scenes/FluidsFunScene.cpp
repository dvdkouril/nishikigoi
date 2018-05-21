//
//  FluidsFunScene.cpp
//  nishikigoi
//
//  Created by David Kouril on 19/05/2018.
//

#include "FluidsFunScene.hpp"

#include "MeshObject.hpp"
#include "FBXLoader.hpp"

void FluidsFunScene::init()
{
    //~ Load object geometries, skeletons, and animations from FBX file
    std::vector<MeshObject*> objects = FBXLoader::loadObjectFromFile("weird-arm-test-skeleton2.fbx");
    MeshObject * weirdArmTest = objects[0];
    //mWeirdArmTest = weirdArmTest;
    //mAllRenderables.push_back(weirdArmTest);
    
    //~ Upload geometry data to GPU
    gl::VboMesh::Layout layout;
    layout.usage(GL_STATIC_DRAW).attrib(geom::POSITION, 3);
    mIndexBuffer = gl::Vbo::create(GL_ELEMENT_ARRAY_BUFFER, weirdArmTest->getIndices());
    mVertexBuffer = gl::VboMesh::create(weirdArmTest->getVertices().size(),
                                        GL_TRIANGLES,
                                        { layout },
                                        weirdArmTest->getIndices().size(),
                                        GL_UNSIGNED_INT,
                                        mIndexBuffer);
    mVertexBuffer->bufferAttrib(geom::POSITION, weirdArmTest->getVertices().size() * sizeof(vec3), weirdArmTest->getVertices().data());
}

void FluidsFunScene::draw()
{
    //gl::setModelMatrix(mWeirdArmTest->getModelMatrix());
    //gl::clear( Color( 0, 0, 0 ) );
    //gl::draw(mVertexBuffer);
}
