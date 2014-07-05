/*
 * Joystick.cpp
 *
 *  Created on: 29/06/2014
 *      Author: FrioneL
 */

#include "Joystick.hpp"

bool Joystick::init(Widget* widget)
{
	// Init widget
	if(!Widget::init(widget))
		return false;

	setVisible(false);

	// Load childs
	_joystickMargin = dynamic_cast<ImageView*>(getChildByName("joystickMargin"));
	_joystickController = dynamic_cast<ImageView*>(getChildByName("joystickController"));

	return true;
}

void Joystick::touchBegan(CCTouch* pTouch)
{
	_joystickMargin->setPosition(pTouch->getLocation());
	_joystickController->setPosition(pTouch->getLocation());
	setVisible(true);
}

void Joystick::touchMoved(CCTouch* pTouch)
{
	CCPoint joyPos = _joystickMargin->getPosition();
	CCPoint touchPos = pTouch->getLocation();

	_direction = ccpSub(touchPos, joyPos);
	_direction = ccpNormalize(_direction);

	if(_joystickMargin->hitTest(touchPos))
	{
		// Inside the margin
		_joystickController->setPosition(touchPos);
	}
	else
	{
		// Outside the margin
		float radius = _joystickMargin->getSize().width/2;

		_joystickController->setPositionX(joyPos.x + radius*_direction.x);
		_joystickController->setPositionY(joyPos.y + radius*_direction.y);
	}
}

void Joystick::touchEnded(CCTouch* pTouch)
{
	_joystickController->setPosition(_joystickMargin->getPosition());
	setVisible(false);
}

bool Joystick::isActive()
{
	return isVisible();
}

CCPoint Joystick::getDirection()
{
	return _direction;
}
