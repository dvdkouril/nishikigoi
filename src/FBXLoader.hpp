//
//  FBXLoader.hpp
//  nishikigoi
//
//  Created by David Kouril on 13/01/2018.
//

#ifndef FBXLoader_hpp
#define FBXLoader_hpp

#include <stdio.h>

#include "fbxsdk.h"
#include "MeshObject.hpp"
#include "JointObject.hpp"
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;

class FBXLoader
{
public:
    static std::vector<MeshObject*> loadObjectFromFile(std::string fileName);
    static MeshObject* loadMeshObject(FbxNode* rootNote);
    static JointObject* loadSkeleton(FbxNode* rootNode);
};

#endif /* FBXLoader_hpp */
