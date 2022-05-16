#include "playerbullet.h"
#include"graphics.h"
#include<easyx.h>
//子弹初始化
void playerBullet::playerBulletInit(int x, int y, int width, int height)
{
	this->width = 20;
	this->height = 20;
	this->x = x + width/2 - this->width/2;
	this->y = y + this->height;
	ATK = 1;
	loadimage(&img1,"bossBullet1.png",20,20);
	loadimage(&img2,"bossBullet2.png", 20, 20);
	putimage(this->x, this->y-(this->height) * 2, &img1,SRCPAINT);
	putimage(this->x, this->y - (this->height) * 2, &img2,SRCAND);

}
//子弹移动（左右条件移动）向上固定移动
void playerBullet::bulletMove(void)
{
		y = y - 10;
}

void playerBullet::bulletPrint(void)
{
	//putimage(this->x, this->y-(this->height)*2, &img1);
	putimage(this->x, this->y - (this->height) * 2, &img1, SRCPAINT);
	putimage(this->x, this->y - (this->height) * 2, &img2, SRCAND);
}