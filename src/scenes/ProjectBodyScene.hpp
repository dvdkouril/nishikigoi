//
//  ProjectBodyScene.hpp
//  nishikigoi
//
//  Created by David Kouril on 19/05/2018.
//

#ifndef ProjectBodyScene_hpp
#define ProjectBodyScene_hpp

#include <stdio.h>
#include "../Scene.hpp"
//#include "cinder/CameraUi.h"
#include "boost/date_time/date.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"

struct TrackedData {
    bool sex;
    bool masturbation;
    bool exercise;
    int attractive;
    int good_life;
};

struct DayData {
    time_t date;
    TrackedData metrics;
};

class ProjectBodyScene : Scene {
public:
    void prepareRenderingData();
    void loadDataFromFile();
    
    void init() override;
    void draw() override;
    void mouseDrag(MouseEvent event) override;
    void mouseDown(MouseEvent event) override;
    void mouseUp(MouseEvent event) override;
    
private:
    std::vector<DayData> mTrackedDays;
    int                 mNumToRender;
    
    gl::VboRef          mDayPositionsVbo;
    gl::GlslProgRef     mSimpleBillboardShader;
    
    CameraPersp         mCamera;
//    CameraUi            mCameraUi;
    
    ivec2               mLastMousePos;
};

#endif /* ProjectBodyScene_hpp */
