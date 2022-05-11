//敌机类

#pragma once
#include "graphics.h"
#include "playerPlane.h"

class enemyPlane {
	//友元
	friend bool playerPlane::playerPlaneCrash(void);
private:
	int x, y;
	int width, height;
	int blood;
	IMAGE img1;
public:
	//小型机存在
	bool smallPlaneExist(void);
	//敌机初始化
	void enemyPlaneInit(void);
	//小型机被射中
	bool smallPlaneShot(void);
	//小型机被撞
	bool smallPlaneCrash(void);
	//小型机消失
	void smallPlaneVanish(void);
	//大型机存在
	bool largePlaneExist(void);
	//大型机被射中
	bool largePlaneShot(void);
	//大型机被撞
	bool largePlaneCrash(void);
	//大型机消失
	void largePlaneVanish(void);
	//大型机血量减一
	void enemyBloodMinus(void);
	//判断大型机血量
	int bloodQuantity(void);
	//大型机消失
	void largePlaneVanish(void);
};
