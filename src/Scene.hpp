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
    virtual void init();
    virtual void draw();
    virtual void update();
    
    virtual void mouseDown(MouseEvent event);
    virtual void mouseUp(MouseEvent event);
    virtual void mouseDrag(MouseEvent event);
};

#endif /* Scene_hpp */
