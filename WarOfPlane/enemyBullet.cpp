#include "enemyBullet.h"
#include<easyx.h>

//子弹初始化 
void  enemyBullet::enemyBulletInit(int x, int y, int w, int h)
{
	/*
	* boss正下方 而且中心轴对齐
	* this.x this.y 赋值
	*/
	this->width = 20;
	this->height = 20;
	this->x = x + w / 2 - 10;
	this->y = y + 20 + h;
	ATK = 1;
	loadimage(&img1, "bossBullet1.png", 20, 20);
	loadimage(&img2, "bossBullet2.png", 20, 20);
	putimage(this->x, this->y, &img1, SRCPAINT);
	putimage(this->x, this->y, &img2, SRCAND);
	

}
//子弹打印
void enemyBullet::eBulletPrint(void) const {
	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);
}