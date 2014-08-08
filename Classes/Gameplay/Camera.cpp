/*
 * Camera.cpp
 *
 *  Created on: 19/07/2014
 *      Author: FrioneL
 */
#include "Camera.hpp"

#define kMarginPercent 0.15


Camera::Camera(CCNode* map, CCSize size) :
	_map(map),
	_screenSize(size)
{
	_marginLeft = size.width*kMarginPercent;
	_marginRight = size.width*(1 - kMarginPercent);
	_marginUpper = size.height*(1 - kMarginPercent);
	_marginLower = size.height*kMarginPercent;
}

void Camera::setOn(const CCPoint& pos)
{
	const CCPoint& mapPos = _map->getPosition();
	CCPoint newMapPos = mapPos;

	// Calculate horizontal displacement
	float limitLeft = _marginLeft - mapPos.x;
	float limitRight = _marginRight - mapPos.x;

	if(limitLeft > pos.x)
		newMapPos.x = mapPos.x + (limitLeft - pos.x);
	else if(limitRight < pos.x)
		newMapPos.x = mapPos.x - (pos.x - limitRight);

	// Calculate vertical displacement
	float limitBottom = _marginLower - mapPos.y;
	float limitUpper = _marginUpper - mapPos.y;

	if(limitBottom > pos.y)
		newMapPos.y = mapPos.y + (limitBottom - pos.y);
	else if(limitUpper < pos.y)
		newMapPos.y = mapPos.y - (pos.y - limitUpper);

	// Bounds
	float mapWidth = _map->getContentSize().width;
	if(fabs(newMapPos.x) + _screenSize.width > mapWidth)
		newMapPos.x = _screenSize.width - mapWidth;
	else if(newMapPos.x > 0)
		newMapPos.x = 0;

	float mapHeight = _map->getContentSize().height;
	if(fabs(newMapPos.y) + _screenSize.height > mapHeight)
		newMapPos.y = _screenSize.height - mapHeight;
	else if(newMapPos.y > 0)
		newMapPos.y = 0;

	// Update just if any change:
	if(!newMapPos.equals(mapPos))
		_map->setPosition(newMapPos);
}

