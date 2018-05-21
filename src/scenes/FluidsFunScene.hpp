//
//  FluidsFunScene.hpp
//  nishikigoi
//
//  Created by David Kouril on 19/05/2018.
//

#ifndef FluidsFunScene_hpp
#define FluidsFunScene_hpp

#include <stdio.h>
#include "../Scene.hpp"

class FluidsFunScene : Scene {
    void init() override;
    void draw() override;
    
private:
    gl::VboMeshRef mVertexBuffer;
    gl::VboRef mIndexBuffer;
};

#endif /* FluidsFunScene_hpp */
