#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CameraUi.h"

#include "SceneManager.hpp"
#include "MeshObject.hpp"
#include "FBXLoader.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class nishikigoiApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
private:
    SceneManager *                  mSceneManager;
    std::vector<MeshObject*>        mAllRenderables;
    
    std::vector<vec3>               mSpheresPositions;
    
    //~ debug: should be moved elsewhere
    gl::VboRef          mIndexBuffer;
    gl::VboMeshRef      mVertexBuffer;
    MeshObject *        mWeirdArmTest;
    
    gl::VboRef          mSpheresBuffer;
    
    gl::GlslProgRef     mSimpleBillboardShader;
    
    CameraPersp         mCamera;
    CameraUi            mCameraUi;
};

void nishikigoiApp::setup()
{
    mSceneManager = new SceneManager;
    
    //~ Load scene from file
    mSceneManager->loadSceneFromFile("test");
    
    //~ Shaders setup
    mSimpleBillboardShader = gl::GlslProg::create(loadAsset("shaders/simple-billboards.vs"),
                                                  loadAsset("shaders/simple-billboards.fs"),
                                                  loadAsset("shaders/simple-billboards.gs"));
    
    mSpheresBuffer = gl::Vbo::create(GL_VERTEX_ARRAY);
    mSpheresBuffer->bufferData(mSpheresPositions.size() * sizeof(vec3), mSpheresPositions.data(), GL_STATIC_DRAW);
    
    //~ Load object geometries, skeletons, and animations from FBX file
    std::vector<MeshObject*> objects = FBXLoader::loadObjectFromFile("weird-arm-test-skeleton2.fbx");
    MeshObject * weirdArmTest = objects[0];
    mWeirdArmTest = weirdArmTest;
    mAllRenderables.push_back(weirdArmTest);
    
    //~ Upload geometry data to GPU
    gl::VboMesh::Layout layout;
    layout.usage(GL_STATIC_DRAW).attrib(geom::POSITION, 3);
    mIndexBuffer = gl::Vbo::create(GL_ELEMENT_ARRAY_BUFFER, weirdArmTest->getIndices());
    mVertexBuffer = gl::VboMesh::create(weirdArmTest->getVertices().size(),
                                        GL_TRIANGLES,
                                        { layout },
                                        weirdArmTest->getIndices().size(),
                                        GL_UNSIGNED_INT,
                                        mIndexBuffer);
    mVertexBuffer->bufferAttrib(geom::POSITION, weirdArmTest->getVertices().size() * sizeof(vec3), weirdArmTest->getVertices().data());
    
    mCamera.lookAt(vec3(10, 10, 10), vec3(0));
    mCameraUi = CameraUi(&mCamera, getWindow(), -1);
}

void nishikigoiApp::mouseDown( MouseEvent event )
{
}

void nishikigoiApp::update()
{
}

void nishikigoiApp::draw()
{
    gl::setMatrices(mCamera);
    //for(auto meshObj : allRenderables)
    //{
        // this will probably be done differently based on rendering optimization (instancing etc.)
        // render(meshObj);
    //}
    gl::setModelMatrix(mWeirdArmTest->getModelMatrix());
	gl::clear( Color( 0, 0, 0 ) );
    //gl::drawCube(vec3(0), vec3(1));
    gl::draw(mVertexBuffer);
}

CINDER_APP( nishikigoiApp, RendererGl )
