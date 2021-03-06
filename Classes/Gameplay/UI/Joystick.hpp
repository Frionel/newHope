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

USING_NS_CC;
using namespace gui;


class Joystick
{
public:
	Joystick(Widget* widget);
	~Joystick();

	void touchBegan(CCTouch* pTouch);
	void touchMoved(CCTouch* pTouch);
	void touchEnded(CCTouch* pTouch);

	bool isActive();
	const CCPoint& getDirection();
	bool inMargin();

private:
	void init(Widget* widget);

	//
	// Attributes
	//
	Layout* _joystickNode;
	ImageView* _margin;
	ImageView* _controller;

	int _touchId;
	CCPoint _direction;
	bool _insideMargin;
};

#endif /* JOYSTICK_HPP_ */
