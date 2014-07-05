/*
 * HUD.cpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#include "HUD.hpp"
#include "cocos-ext.h"


bool HUD::init()
{
	if(!CCLayer::init())
		return false;

	loadWidgets();

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);

	return true;
}

void HUD::loadWidgets()
{
	Widget* widget = extension::GUIReader::shareReader()->widgetFromJsonFile("ui/hud.json");
	_joystick = cc::create<Joystick>(widget->getChildByName("joystick"));
	addChild(_joystick);
}

bool HUD::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	_joystick->touchBegan(pTouch);
	return true;
}

void HUD::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	_joystick->touchMoved(pTouch);
}

void HUD::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	_joystick->touchEnded(pTouch);
}

Joystick* HUD::getJoystick()
{
	return _joystick;
}
