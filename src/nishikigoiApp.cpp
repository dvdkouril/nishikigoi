#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CameraUi.h"

#include "SceneManager.hpp"

#include "Scene.hpp"
#include "scenes/UbahnScene.hpp"
#include "scenes/FluidsFunScene.hpp"
#include "scenes/ProjectBodyScene.hpp"
#include "scenes/MoleculeRendererScene.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class nishikigoiApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
    void mouseUp( MouseEvent event ) override;
    void mouseDrag( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
private:
    Scene * currentScene;
};

void nishikigoiApp::setup()
{
    currentScene = (Scene*)new ProjectBodyScene;
    currentScene->init();
}

void nishikigoiApp::mouseDown( MouseEvent event )
{
    currentScene->mouseDown(event);
}

void nishikigoiApp::mouseUp( MouseEvent event )
{
    currentScene->mouseUp(event);
}

void nishikigoiApp::mouseDrag( MouseEvent event )
{
    currentScene->mouseDrag(event);
}

void nishikigoiApp::update()
{
    currentScene->update();
}

void nishikigoiApp::draw()
{
    currentScene->draw();
    
    //gl::setMatrices(mCamera);
    //for(auto meshObj : allRenderables)
    //{
        // this will probably be done differently based on rendering optimization (instancing etc.)
        // render(meshObj);
    //}
    
    
}

CINDER_APP( nishikigoiApp, RendererGl )
