#include "enemyBullet.h"
#include<easyx.h>

//�ӵ���ʼ�� 
void  enemyBullet::enemyBulletInit(int x, int y, int w, int h)
{
	/*
	* boss���·� �������������
	* this.x this.y ��ֵ
	*/
	this->width = 20;
	this->height = 20;
	this->x = x + w / 2 - 10;
	this->y = y+20+h;
	ATK = 1;
	loadimage(&img1,"bossBullet1.png",20, 20);
	loadimage(&img2, "bossBullet2.png", 20, 20);
	putimage(this->x, this->y, &img1,SRCPAINT);
	putimage(this->x, this->y, &img2,SRCAND);
	

}
//�ӵ��ƶ� ���¹̶��ƶ�
void  enemyBullet::enemyBulletMove(void)
{
	y = y + 1;
}
//�ӵ���ӡ
void enemyBullet::enemyPrint(void) {
	putimage(x, y, &img1,SRCPAINT);
	putimage(x, y, &img2, SRCAND);
}