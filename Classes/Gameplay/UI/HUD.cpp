/*
 * HUD.cpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#include "HUD.hpp"
#include "cocos-ext.h"

HUD::HUD() :
	_joystick(nullptr),
	_menuButton(nullptr)
{
}

HUD::~HUD()
{
	CC_SAFE_DELETE(_joystick);

	CC_SAFE_RELEASE_NULL(_menuButton);
}

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
	Widget* widget = extension::GUIReader::shareReader()->widgetFromJsonFile("ui/hud/hud.json");

    // Set size of the screen
    CCSize designSize = CCEGLView::sharedOpenGLView()->getDesignResolutionSize();
    CCSize widgetSize = widget->getContentSize();

    widget->setScaleX(designSize.width/widgetSize.width);
    widget->setScaleY(designSize.height/widgetSize.height);

	_joystick = new Joystick(widget->getChildByName("joystick"));
	_menuButton = static_cast<UIButton*>(widget->getChildByName("menuButton"));

	addChild(widget);
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
