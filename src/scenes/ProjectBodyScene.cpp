//
//  ProjectBodyScene.cpp
//  nishikigoi
//
//  Created by David Kouril on 19/05/2018.
//

#include "ProjectBodyScene.hpp"

using namespace boost::gregorian;

void ProjectBodyScene::init()
{
    int xShift = 30;
    mCamera.lookAt(vec3(xShift, 0, 100), vec3(xShift, 0, 0));
    //mCameraUi = CameraUi(&mCamera, getWindow(), -1);
    
    prepareRenderingData();
}

void ProjectBodyScene::loadDataFromFile()
{
    DayData day;
    TrackedData data;
    data.attractive = 0;
    data.sex = true;
    data.masturbation = false;
    data.good_life = true;
    data.attractive = true;
    day.metrics = data;
    day.date = 123;
    
    mTrackedDays.push_back(day);
}

void ProjectBodyScene::prepareRenderingData()
{
    loadDataFromFile();
    
    std::vector<vec3> dayPositions;
    
    date today(day_clock::local_day());
    auto dayInWeek = today.day_of_week();
    auto weekInYear = today.week_number();
    std::cout << today.day().as_number() << " " << today.month().as_number() << std::endl;
    std::cout << "dayInWeek: " << dayInWeek.as_number() << std::endl;
    std::cout << "weekInYear " << weekInYear << std::endl;
    
    int x = dayInWeek.as_number();
    int y = weekInYear;
    
    //TODO: from tracked days, make position of those days on a "month grid"
    // this will actually also have to include days where nothing has been tracked
//    for (auto day : mTrackedDays)
//    {
//
//    }
    
    for (int i = 0; i < 7; i++)
    {
        //for (int j = 0; j < 4; j++)
        for (int j = 0; j < 20; j++)
        {
            dayPositions.push_back(vec3(i, j, 0));
        }
    }
    
    mNumToRender = dayPositions.size();
    //mDayPositionsVbo = gl::Vbo::create(GL_ARRAY_BUFFER, mTrackedDays.size() * sizeof(vec3), dayPositions.data(), GL_STATIC_DRAW);
    mDayPositionsVbo = gl::Vbo::create(GL_ARRAY_BUFFER, dayPositions.size() * sizeof(vec3), dayPositions.data(), GL_STATIC_DRAW);
    mDayPositionsVbo->bind();
    gl::enableVertexAttribArray(0);
    gl::vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    //~ Shaders setup
    mSimpleBillboardShader = gl::GlslProg::create(loadAsset("shaders/simple-billboards.vs"),
                                                  loadAsset("shaders/simple-billboards.fs"),
                                                  loadAsset("shaders/simple-billboards.gs"));
}

void ProjectBodyScene::draw()
{
    gl::clear(Color(1, 1, 1));
    
    {
        gl::ScopedGlslProg billboard(mSimpleBillboardShader);
        mSimpleBillboardShader->uniform("Scale", 1.0f);
        mSimpleBillboardShader->uniform("modelViewMatrix", mCamera.getViewMatrix());
        mSimpleBillboardShader->uniform("projectionMatrix", mCamera.getProjectionMatrix());
        gl::drawArrays(GL_POINTS, 0, mNumToRender);
    }
    
    //gl::drawString("test", vec2(0, 0));
}


void ProjectBodyScene::mouseDrag(MouseEvent event)
{
    auto incr = mLastMousePos - event.getPos();
    mLastMousePos = event.getPos();
    auto currentCamPos = mCamera.getEyePoint();
    mCamera.setEyePoint(currentCamPos + vec3(0, 0.1 * incr.y * 1, 0));
    std::cout << "mouseDrag" << std::endl;
}

void ProjectBodyScene::mouseDown(MouseEvent event)
{
    mLastMousePos = event.getPos();
    std::cout << "mouseDown" << std::endl;
}

void ProjectBodyScene::mouseUp(MouseEvent event)
{
    std::cout << "mouseUp" << std::endl;
}
