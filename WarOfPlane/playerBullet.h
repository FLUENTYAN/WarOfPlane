//玩家子弹类

#pragma once
#include "graphics.h"
#include "enemyPlane.h"

class enemyPlane;

class playerBullet {
public:
	int x, y;//坐标
	int width, height;//图片高和宽
	int ATK;//攻击力 
	IMAGE img1,img2;
public:
	//子弹初始化 
	void playerBulletInit(int x,int y,int width,int height); 
	//子弹移动 向上固定移动
	inline void bulletMove(void) { y -= 10; }
	//打印子弹
	void bulletPrint(void) const;
};
