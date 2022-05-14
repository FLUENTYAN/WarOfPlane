#include "playerbullet.h"
#include"graphics.h"
#include<easyx.h>
//子弹初始化
void playerBullet::playerBulletInit(int x, int y, int width, int height)
{
	this->width = 20;
	this->height = 20;
	this->x = x + width / 2 - this->width / 2+10;
	this->y = y+20;
	ATK = 1;
	loadimage(&img1,"bossBullet.png",20,20);
	putimage(x, y, &img1);

}
//子弹移动（左右条件移动）向上固定移动
void playerBullet::bulletMove(void)
{
		y = y - 10;
}

void playerBullet::bulletPrint(void)
{
	putimage(x-width, y, &img1);
}