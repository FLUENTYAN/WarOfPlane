//��ҷɻ���

#pragma once
#include "graphics.h"
#include "enemyPlane.h"

class playerBullet {
	//��Ԫ
	friend bool enemyPlane::smallPlaneShot(void);
private:
	int x, y;
	int width, height;
	int ATK;
	IMAGE img1;
public:
	//�ӵ���ʼ��
	void playerBulletInit(void);
	//�ӵ��ƶ������������ƶ������Ϲ̶��ƶ�
	void bulletMove(void);
};
