//���˷ɻ���

#pragma once
#include "graphics.h"
#include "playerPlane.h"

class enemyBullet {
	//��Ԫ
	friend bool playerPlane::playerPlaneShot(void);
private:
	int x, y;
	int width, height;
	int ATK;
	IMAGE img1;
};
