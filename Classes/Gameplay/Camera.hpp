/*
 * Camera.hpp
 *
 *  Created on: 19/07/2014
 *      Author: FrioneL
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <cocos2d.h>
USING_NS_CC;

class Camera {

public:
	Camera(CCNode* node, CCSize size);

	void setOn(const CCPoint& pos);

private:
	//
	// Attributes
	//
	CCNode* _map;
	CCSize _screenSize;
	float _marginLeft;
	float _marginRight;
	float _marginUpper;
	float _marginLower;
};


#endif /* CAMERA_HPP_ */
