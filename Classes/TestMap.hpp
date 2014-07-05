/*
 * TestMap.hpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#ifndef TESTMAP_HPP_
#define TESTMAP_HPP_

#include "cocos2d.h"
#include "Player.hpp"
#include "HUD.hpp"

using namespace cocos2d;

class TestMap : public CCLayer
{

public:

	~TestMap();
	static CCScene* scene();
	bool init();

	void update();

private:
	void loadMap();
	void setCameraOn(CCPoint position);

	//
	// Attributes
	//
	CCNode* _mapNode;
	CCTMXTiledMap* _tileMap;
	Player* _player;
	HUD* _hud;
};

#endif /* TESTMAP_HPP_ */
