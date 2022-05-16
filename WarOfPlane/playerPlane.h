//玩家飞机类

#pragma once
#include "graphics.h"
#include "enemyPlane.h"

class enemyPlane;
class enemyBullet;

class playerPlane {
public:
	int x = 0, y = 0;
	int width, height;
	int blood;
	IMAGE img1, img2;
public:
	//玩家飞机初始化
	void playerPlaneInit(void);

	/*	
		读入图片对img1赋值 名称 player.png 大小90 120
		对x,y赋值取决于
	* 底部对齐屏幕
	* 中心轴在屏幕中间
	* 对width，height赋值 90 120
	* blood 赋值3
	* 打印功能 参数 类中 x，y img1
	*/
	//移动玩家飞机
	void planeMove(void);
	/* 无参数 无返回值
	定义 message e
	GetAsyncKeyState()接收键盘值

	只接收一次
	if判读wsad产生 x+-5 y+-5
	补充判断
	x和y指要在屏幕0 0 450-w 750-h 停止
	不能移动出屏幕
	*/
	
	//玩家血量减一
	void playerBloodMinus(void);
	/*无参数 无返回值
	* 实现HP-1;
	*/
	void playerPrint(void);
	/*无参数 无返回值
	* loadimage 根据x，y img1打印图片；
	*/
	void bloodShow(void);
};
