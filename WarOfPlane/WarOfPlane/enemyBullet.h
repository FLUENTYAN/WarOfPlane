//�����ӵ���

#pragma once
#include "graphics.h"

class playerPlane;

class enemyBullet {
public:
	//��Ԫ
	friend bool playerPlane::playerPlaneShot(void);
private:
	int x, y;
	int width, height;
	int ATK;
	IMAGE img1;
};
