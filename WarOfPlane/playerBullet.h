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
	/*
		���������x-������ں����� y---������������� w-���ͼ�� h-���ͼ�߶�
		����ֵ �ޣ�
		x������ʽ����this.x+width/2=x+w/2;
		y��boos�߶�һ�� ��
		����load���� ����boss bullet.png �������·��
		����ͼƬ�Ĵ�С 20X20
		��ӡputimage(x,y,&img1) ����x��y
		��ʼ��ATK Ϊ1
	*/
	//�ӵ��ƶ� ���Ϲ̶��ƶ�
	void bulletMove(void);
	/*
	* ������� ����ֵ �ޣ�
	*	y-=10; 
	*/
	void bulletPrint(void);
	/*
	*	�����ͷ���ֵ ��
		���� ʵ����x��y����ӡͼƬ����
		��ӡputimage(x,y,&img) ����x��y
	*/
};
