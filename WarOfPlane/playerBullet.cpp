#include "playerbullet.h"
#include"graphics.h"
#include<easyx.h>
//�ӵ���ʼ��
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
//�ӵ��ƶ������������ƶ������Ϲ̶��ƶ�
void playerBullet::bulletMove(void)
{
		y = y - 10;
}

void playerBullet::bulletPrint(void)
{
	putimage(x-width, y, &img1);
}