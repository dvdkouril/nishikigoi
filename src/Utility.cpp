//
//  Utility.cpp
//  nishikigoi
//
//  Created by David Kouril on 13/01/2018.
//

#include "Utility.hpp"
#include "glm/gtc/type_ptr.hpp"

mat4 Utility::mayaToCinderMatrix(FbxAMatrix mat)
{    
    mat4 resultMat;
    resultMat[0][0] = mat.Get(0, 0);
    resultMat[1][0] = mat.Get(1, 0);
    resultMat[2][0] = mat.Get(2, 0);
    resultMat[3][0] = mat.Get(3, 0);
    
    resultMat[0][1] = mat.Get(0, 1);
    resultMat[1][1] = mat.Get(1, 1);
    resultMat[2][1] = mat.Get(2, 1);
    resultMat[3][1] = mat.Get(3, 1);
    
    resultMat[0][2] = mat.Get(0, 2);
    resultMat[1][2] = mat.Get(1, 2);
    resultMat[2][2] = mat.Get(2, 2);
    resultMat[3][2] = mat.Get(3, 2);
    
    resultMat[0][3] = mat.Get(0, 3);
    resultMat[1][3] = mat.Get(1, 3);
    resultMat[2][3] = mat.Get(2, 3);
    resultMat[3][3] = mat.Get(3, 3);
    return resultMat;
}
