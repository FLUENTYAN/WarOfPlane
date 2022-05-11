//玩家飞机类

#pragma once
#include "graphics.h"

class playerBullet {
	//友元
	friend bool smallPlaneShot(void);
private:
	int x, y;
	int width, height;
	int ATK;
	IMAGE img1;
public:
	//子弹初始化
	void playerBulletInit(void);
	//子弹移动（左右条件移动）向上固定移动
	void bulletMove(void);
};
