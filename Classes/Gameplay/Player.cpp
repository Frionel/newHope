/*
 * Player.cpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#include "Player.hpp"

#define kSpeedWalk 55
#define kSpeedRun 110



bool Player::init()
{
	if(!CCSprite::init())
		return false;

	initWithFile("player.png");

	return true;
}

void Player::update()
{
	move();
}

void Player::setJoystick(Joystick* joystick)
{
	_joystick = joystick;
}

void Player::move()
{
	if(!_joystick->isActive())
		return;

	float dt = CCDirector::sharedDirector()->getDeltaTime();
	const CCPoint& direction = _joystick->getDirection();
	const CCPoint& pos = getPosition();

	float speed = _joystick->inMargin()? kSpeedWalk : kSpeedRun;

	setPositionX(pos.x + direction.x*speed*dt);
	setPositionY(pos.y + direction.y*speed*dt);
}
