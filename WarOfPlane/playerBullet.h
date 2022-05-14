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
	IMAGE img1;
public:
	//子弹初始化 
	void playerBulletInit(int x,int y,int width,int height); 
	/*
		传入参数：x-玩家所在横坐标 y---玩家所在纵坐标 w-玩家图宽 h-玩家图高度
		返回值 无；
		x由下面式子求this.x+width/2=x+w/2;
		y和boos高度一致 ；
		调用load函数 读入boss bullet.png 参数相对路径
		读入图片的大小 20X20
		打印putimage(x,y,&img1) 参数x，y
		初始化ATK 为1
	*/
	//子弹移动 向上固定移动
	void bulletMove(void);
	/*
	* 传入参数 返回值 无；
	*	y-=10; 
	*/
	void bulletPrint(void);
	/*
	*	参数和返回值 无
		功能 实现在x，y处打印图片即可
		打印putimage(x,y,&img) 参数x，y
	*/
};
