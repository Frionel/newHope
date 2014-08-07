/*
 * TestMap.cpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#include "TestMap.hpp"
#include "Player.hpp"
#include "Camera.hpp"
#include "HUD.hpp"


#define kTilesHorizontal 20
#define kTilesVertical 12
#define kTilesSize 32
#define kMapWidth (kTilesHorizontal*kTilesSize)
#define kMapHeight (kTilesVertical*kTilesSize)

TestMap::TestMap() :
	_mapNode(nullptr),
	_tileMap(nullptr),
	_player(nullptr),
	_hud(nullptr),
	_camera(nullptr)
{
}

TestMap::~TestMap()
{
	unschedule(schedule_selector(TestMap::update));
//TODO: Probar que realmente se borran:
	_hud->removeAllChildrenWithCleanup(true);
	CC_SAFE_RELEASE_NULL(_hud);

	_mapNode->removeAllChildrenWithCleanup(true);
	CC_SAFE_RELEASE_NULL(_mapNode);

	CC_SAFE_DELETE(_camera);
}

CCScene* TestMap::scene()
{
    // 'scene' is an autorelease object
    CCScene* scene = CCScene::create();
    TestMap* mapLayer = cc::create<TestMap>();

    // add layer as a child to scene
    scene->addChild(mapLayer);

    // return the scene
    return scene;
}

bool TestMap::init()
{
	if(!CCLayer::init())
		return false;

	loadMap();
	loadHUD();

	// loop
	schedule(schedule_selector(TestMap::update));

	return true;
}

void TestMap::loadMap()
{
	// Initialize node
	_mapNode = CCNode::create();
	CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
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
	_tileMap->addChild(_player, 99);

	// Camera
	_camera = new Camera(_tileMap, CCSize(kMapWidth, kMapHeight));
}

void TestMap::loadHUD()
{
	_hud = cc::create<HUD>();
	_player->setJoystick(_hud->getJoystick());

	addChild(_hud);
}

void TestMap::update()
{
	_player->update();
	//TODO just call camera if player is moving
	_camera->setOn(_player->getPosition());
}


















