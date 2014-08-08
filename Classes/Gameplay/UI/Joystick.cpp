/*
 * Joystick.cpp
 *
 *  Created on: 29/06/2014
 *      Author: FrioneL
 */

#include "Joystick.hpp"


Joystick::Joystick(Widget* widget) :
	_joystickNode(nullptr),
	_margin(nullptr),
	_controller(nullptr),
	_insideMargin(true),
	_touchId(-1)
{
	init(widget);
}

Joystick::~Joystick()
{
	CC_SAFE_RELEASE_NULL(_joystickNode);
	CC_SAFE_RELEASE_NULL(_margin);
	CC_SAFE_RELEASE_NULL(_controller);
}

void Joystick::init(Widget* widget)
{
	_joystickNode = static_cast<Layout*>(widget);

	// Load childs
	_margin = static_cast<ImageView*>(_joystickNode->getChildByName("joystickMargin"));
	_controller = static_cast<ImageView*>(_joystickNode->getChildByName("joystickController"));

	_joystickNode->setVisible(false);
}

void Joystick::touchBegan(CCTouch* pTouch)
{
	if(_joystickNode->isVisible())
	{
		// Multitouch:
		return;
	}

	_touchId = pTouch->getID();
	CCPoint touchPos = _joystickNode->convertToNodeSpace(pTouch->getLocation());

	_margin->setPosition(touchPos);
	_controller->setPosition(touchPos);
	_joystickNode->setVisible(true);
}

void Joystick::touchMoved(CCTouch* pTouch)
{
	if(pTouch->getID() != _touchId)
	{
		// Multitouch:
		return;
	}

	CCPoint joyPos = _margin->getPosition();
	CCPoint touchPos = pTouch->getLocation();
	CCPoint touchNodePos = _joystickNode->convertTouchToNodeSpace(pTouch);

	_direction = ccpSub(touchNodePos, joyPos);
	_direction = ccpNormalize(_direction);

	if(_margin->hitTest(touchPos))
	{
		// Inside the margin
		_controller->setPosition(touchNodePos);
		_insideMargin = true;
	}
	else
	{
		// Outside the margin
		float radius = _margin->getSize().width/2;

		_controller->setPositionX(joyPos.x + radius*_direction.x);
		_controller->setPositionY(joyPos.y + radius*_direction.y);
		_insideMargin = false;
	}
}

void Joystick::touchEnded(CCTouch* pTouch)
{
	if(pTouch->getID() != _touchId)
	{
		// Multitouch:
		return;
	}

	_controller->setPosition(_margin->getPosition());
	_joystickNode->setVisible(false);
}

bool Joystick::isActive()
{
	return _joystickNode->isVisible();
}

const CCPoint& Joystick::getDirection()
{
	return _direction;
}

bool Joystick::inMargin()
{
	return _insideMargin;
}
