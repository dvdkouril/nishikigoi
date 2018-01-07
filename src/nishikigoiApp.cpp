#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class nishikigoiApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void nishikigoiApp::setup()
{
}

void nishikigoiApp::mouseDown( MouseEvent event )
{
}

void nishikigoiApp::update()
{
}

void nishikigoiApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( nishikigoiApp, RendererGl )
