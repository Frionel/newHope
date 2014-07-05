/*
 * TestMap.cpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#include "TestMap.hpp"

#define kTilesHorizontal 20
#define kTilesVertical 12
#define kTilesSize 32
#define kMapWidth (kTilesHorizontal*kTilesSize)
#define kMapHeight (kTilesVertical*kTilesSize)
#define kMarginHorizontalPercent 0.85
#define kMarginVerticalPercent 0.85


TestMap::~TestMap()
{
	unschedule(schedule_selector(TestMap::update));
//TODO: Probar que realmente se borran:
	CC_SAFE_RELEASE_NULL(_hud);
	CC_SAFE_RELEASE_NULL(_mapNode);
}

CCScene* TestMap::scene()
{
    // 'scene' is an autorelease object
    CCScene* newScene = CCScene::create();
    TestMap* testMapLayer = cc::create<TestMap>();

    // add layer as a child to scene
    newScene->addChild(testMapLayer);

    // return the scene
    return newScene;
}

bool TestMap::init()
{
	if(!CCLayer::init())
		return false;

	// Load Map
	loadMap();

	// HUD
	_hud = cc::create<HUD>();
	_player->setJoystick(_hud->getJoystick());
	addChild(_hud);

	// loop
	schedule(schedule_selector(TestMap::update));

	return true;
}

void TestMap::loadMap()
{
	// Initialize node
	_mapNode = CCNode::create();
	CCSize screenSize = CCEGLView::sharedOpenGLView()->getDesignResolutionSize();
	_mapNode->setScaleX(screenSize.width/kMapWidth);
	_mapNode->setScaleY(screenSize.height/kMapHeight);
	addChild(_mapNode);

	// Map
	_tileMap = new CCTMXTiledMap();
	_tileMap->initWithTMXFile("testMap.tmx");
	_mapNode->addChild(_tileMap);

	// Load Layers
	CCTMXObjectGroup* objectGroup = _tileMap->objectGroupNamed("events");

	// Player
	CCDictionary* spawnPoint = objectGroup->objectNamed("spawn");
	int x = ((CCString)*spawnPoint->valueForKey("x")).intValue();
	int y = ((CCString)*spawnPoint->valueForKey("y")).intValue();

	_player = cc::create<Player>();
	_player->setPosition(CCPoint(x, y));
	_mapNode->addChild(_player);
}

void TestMap::setCameraOn(CCPoint position)
{
	/*
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize designRes = CCEGLView::sharedOpenGLView()->getDesignResolutionSize();

    int x = MAX(position.x, winSize.width/2);
    int y = MAX(position.y, winSize.height/2);
    x = MIN(x, (kTilesSize*kTilesHorizontal) - winSize.width / 2);
    y = MIN(y, (kTilesSize*kTilesVertical) - winSize.height/2);
    CCPoint actualPosition = ccp(x, y);

    CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2);
    CCPoint viewPoint = ccpSub(centerOfView, actualPosition);

    setPosition(viewPoint);
    */
	CCPoint mapPos = _mapNode->getPosition();

	// Horizontal
	float marginRight = kMapWidth*kMarginHorizontalPercent;
	float marginLeft = kMapWidth*(1 - kMarginHorizontalPercent);
	float horizontalMove = 0.0f;

	if(position.x > mapPos.x + marginRight)
		horizontalMove = position.x - marginRight;
	else if(position.x < mapPos.x + marginLeft)
		horizontalMove = position.x - marginLeft;

	// Vertical
	float marginUpper = kMapHeight*kMarginVerticalPercent;
	float marginBottom = kMapHeight*(1 - kMarginVerticalPercent);
	float verticalMove = 0.0f;

	if(position.y > mapPos.y + marginUpper)
		verticalMove = position.y - marginUpper;
	else if(position.y < mapPos.y + marginBottom)
		verticalMove = position.y - marginBottom;

	_mapNode->setPositionX(mapPos.x + horizontalMove);
	_mapNode->setPositionY(mapPos.y + verticalMove);
}

void TestMap::update()
{
	_player->update();

	setCameraOn(_player->getPosition());
}


















