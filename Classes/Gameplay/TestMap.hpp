/*
 * TestMap.hpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#ifndef TESTMAP_HPP_
#define TESTMAP_HPP_

#include <cocos2d.h>

class Player;
class HUD;
class Camera;


USING_NS_CC;

class TestMap : public CCLayer
{

public:
	TestMap();
	~TestMap();
	static CCScene* scene();
	bool init();

	void update();

private:
	void loadMap();
	void loadHUD();
	void setCameraOn(CCPoint position);

	//
	// Attributes
	//
	CCNode* _mapNode;
	CCTMXTiledMap* _tileMap;
	Player* _player;
	HUD* _hud;
	Camera* _camera;
};

#endif /* TESTMAP_HPP_ */
