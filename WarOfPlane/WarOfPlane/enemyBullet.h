//敌人飞机类

#pragma once
#include "graphics.h"
#include "playerPlane.h"

class enemyBullet {
	//友元
	friend bool playerPlane::playerPlaneShot(void);
private:
	int x, y;
	int width, height;
	int ATK;
	IMAGE img1;
};
