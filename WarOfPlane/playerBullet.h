//����ӵ���

#pragma once
#include "graphics.h"
#include "enemyPlane.h"

class enemyPlane;

class playerBullet {
public:
	int x, y;//����
	int width, height;//ͼƬ�ߺͿ�
	int ATK;//������ 
	IMAGE img1,img2;
public:
	//�ӵ���ʼ�� 
	void playerBulletInit(int x,int y,int width,int height); 
	//�ӵ��ƶ� ���Ϲ̶��ƶ�
	inline void bulletMove(void) { y -= 10; }
	//��ӡ�ӵ�
	void bulletPrint(void) const;
};
