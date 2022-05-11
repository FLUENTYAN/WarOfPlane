//玩家飞机类

#pragma once
#include "graphics.h"

class playerPlane {
	//友元声明
	friend 	bool smallPlaneCrash(void);
private:
	int x = 450/2, y = 750/2;
	int width, height;
	int blood;
	IMAGE img1;
public:
	//玩家飞机初始化
	void playerPlaneInit(void);
	//移动玩家飞机
	void planeMove(void);
	//玩家被射中
	bool playerPlaneShot(void);
	//玩家被撞
	bool playerPlaneCrash(void);
	//玩家消失
	void playerPlaneVanish(void);
	//玩家血量减一
	void playerBloodMinus(void);
	//判断玩家血量
	int bloodQuantity(void);
};
