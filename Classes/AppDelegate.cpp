#include "AppDelegate.h"
//#include "HelloWorldScene.h"
#include "TestMap.hpp"

USING_NS_CC;

AppDelegate::AppDelegate()
{
//	sleep(10);
}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector* director = CCDirector::sharedDirector();
    CCEGLView* glView = CCEGLView::sharedOpenGLView();
    director->setOpenGLView(glView);
    director->setProjection(kCCDirectorProjection2D);

	// Initialize Screen region
	CCSize screenSize = glView->getFrameSize();
	CCSize designSize = CCSize(1280, 720);
	glView->setDesignResolutionSize(designSize.width, designSize.height, kResolutionExactFit);

	//TODO: set hd/sd depending on the screenSize
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = TestMap::scene();//HelloWorld::scene();

    // run
    director->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
