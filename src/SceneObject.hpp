//
//  SceneObject.hpp
//  nishikigoi
//
//  Created by David Kouril on 07/01/2018.
//

#ifndef SceneObject_hpp
#define SceneObject_hpp

#include <stdio.h>
#include <vector>
#include "glm/glm.hpp"

using namespace cinder;

class SceneObject
{
    
private:
    SceneObject *                   parentObj;
    std::vector<SceneObject*>       childrenObjs;
    
    vec3            worldPosition;
    quat            worldRotation;
};

#endif /* SceneObject_hpp */
