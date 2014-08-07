/*
 * HUD.hpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#ifndef HUD_HPP_
#define HUD_HPP_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Joystick.hpp"

using namespace cocos2d;
using namespace gui;


class HUD : public CCLayer
{
public:
	HUD();
	~HUD();
	bool init();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	Joystick* getJoystick();

private:
	void loadWidgets();


	//
	// Atributes
	//
	Joystick* _joystick;
	UIButton* _menuButton;

};



#endif /* HUD_HPP_ */
