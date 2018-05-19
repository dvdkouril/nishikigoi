//
//  Scene.hpp
//  nishikigoi
//
//  Created by David Kouril on 19/05/2018.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class Scene {
public:
    void init();
    void draw();
    void update();
    
    void mouseDown(MouseEvent event);
};

#endif /* Scene_hpp */
