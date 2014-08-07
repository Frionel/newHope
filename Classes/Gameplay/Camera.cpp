/*
 * Camera.cpp
 *
 *  Created on: 19/07/2014
 *      Author: FrioneL
 */
#include "Camera.hpp"

#define kMarginPercent 0.15


Camera::Camera(CCNode* node, CCSize size) :
	_node(node),
	_screenSize(size)
{
	_marginLeft = size.width*kMarginPercent;
	_marginRight = size.width*(1 - kMarginPercent);
	_marginUpper = size.height*(1 - kMarginPercent);
	_marginLower = size.height*kMarginPercent;
}

void Camera::setOn(const CCPoint& pos)
{
	const CCPoint& nodePos = _node->getPosition();

	CCPoint newNodePos = nodePos;

	float limitLeft = _marginLeft - nodePos.x;
	float limitRight = _marginRight - nodePos.x;

	if(limitLeft > pos.x)
		newNodePos.x = nodePos.x + (limitLeft - pos.x);
	else if(limitRight < pos.x)
		newNodePos.x = nodePos.x - (pos.x - limitRight);

	float limitBottom = _marginLower - nodePos.y;
	float limitUpper = _marginUpper - nodePos.y;

	if(limitBottom > pos.y)
		newNodePos.y = nodePos.y + (limitBottom - pos.y);
	else if(limitUpper < pos.y)
		newNodePos.y = nodePos.y - (pos.y - limitUpper);

	//if(nodePos != newNodePos)
		_node->setPosition(newNodePos);
}

