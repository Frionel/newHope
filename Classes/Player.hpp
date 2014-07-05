/*
 * Player.hpp
 *
 *  Created on: 24/06/2014
 *      Author: FrioneL
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "cocos2d.h"
#include "Joystick.hpp"

using namespace cocos2d;

class Player : public CCSprite
{

public:
	bool init();

	void update();
	void setJoystick(Joystick* joystick);

private:
	void move(CCPoint direction);

	//
	// Attributes
	//
	Joystick* _joystick;

};



#endif /* PLAYER_HPP_ */
