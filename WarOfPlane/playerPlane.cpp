#include "playerPlane.h"
#include "graphics.h"
#include "enemyBullet.h"
#include <iostream>
#include <conio.h>


//玩家飞机初始化
void playerPlane::playerPlaneInit(void) {
	loadimage(&img1, ("player1.png"), 70, 80);
	loadimage(&img2, ("player2.png"), 70, 80);

	width = 70, height = 80;
	blood = 5;
	x = 225 - width / 2;
	y = 750 - height;

}
//移动玩家飞机
void playerPlane::planeMove(void) {
	int v = 5; //速度参数 可调整  改这个就可以
	//putimage(x, y, &img1); 如果想在一直移动 就去掉注释
	//while (true) 

	if ((y < 0 || x < 0 || x > 450 - width || y > 750 - height)) {
		if (x < 0) {
			x = 0;
		}
		else if (x > 450 - width) {
			x = 450 - width;
		}
		else if (y < 0) {
			y = 0;
		}
		else if (y > 750 - height) {
			y = 750 - height;
		}
	}
	else {
		if (GetAsyncKeyState('W'))//上移
			y -= v;
		if (GetAsyncKeyState('S'))//下移
			y += v;
		if (GetAsyncKeyState('A'))//左移
			x -= v;
		if (GetAsyncKeyState('D'))//右移
			x += v;
	}
	//putimage(x, y, &img1);
	//system("cls");//清屏  不然速度特别快
//}
}

void playerPlane::playerPrint(void) const {
	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);
}

void playerPlane::bloodShow(void) const {
	IMAGE img3, img4;
	loadimage(&img3, "./blood1.png", 20, 20);
	loadimage(&img4, "./blood2.png", 20, 20);
	for (int i = 0; i < blood; i++)
	{
		putimage(i * 20, 750 - 20, &img3, SRCPAINT);
		putimage(i * 20, 750 - 20, &img4, SRCAND);
	}
}