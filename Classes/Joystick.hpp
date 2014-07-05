/*
 * Joystick.hpp
 *
 *  Created on: 29/06/2014
 *      Author: FrioneL
 */

#ifndef JOYSTICK_HPP_
#define JOYSTICK_HPP_

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace gui;

class Joystick : public Widget
{
public:
	bool init(Widget* widget);

	void touchBegan(CCTouch* pTouch);
	void touchMoved(CCTouch* pTouch);
	void touchEnded(CCTouch* pTouch);

	bool isActive();
	CCPoint getDirection();

private:

	//
	// Attributes
	//
	UIImageView* _joystickMargin;
	UIImageView* _joystickController;

	CCPoint _direction;

};

#endif /* JOYSTICK_HPP_ */
