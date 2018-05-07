//
//  Utility.hpp
//  nishikigoi
//
//  Created by David Kouril on 13/01/2018.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <stdio.h>
#include "cinder/gl/gl.h"
#include "fbxsdk.h"

using namespace ci;

class Utility
{
public:
    static mat4 mayaToCinderMatrix(FbxAMatrix mat);
};

#endif /* Utility_hpp */
