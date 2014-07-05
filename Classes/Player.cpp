/*
 * Player.cpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#include "Player.hpp"

#define kSpeedStep 110



bool Player::init()
{
	if(!CCSprite::init())
		return false;

	initWithFile("player.png");

	return true;
}

void Player::update()
{
	if(_joystick->isActive())
	{
		move(_joystick->getDirection());
	}
}

void Player::setJoystick(Joystick* joystick)
{
	_joystick = joystick;
}

void Player::move(CCPoint direction)
{
	float dt = CCDirector::sharedDirector()->getDeltaTime();

	CCPoint pos = getPosition();
	setPositionX(pos.x + direction.x*kSpeedStep*dt);
	setPositionY(pos.y + direction.y*kSpeedStep*dt);
}
