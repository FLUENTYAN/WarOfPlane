//敌人子弹类

#pragma once
#include "graphics.h"

class playerPlane;

class enemyBullet {
public:
	//友元
	friend bool playerPlane::playerPlaneShot(void);
private:
	int x, y;
	int width, height;
	int ATK;
	IMAGE img1;
};
