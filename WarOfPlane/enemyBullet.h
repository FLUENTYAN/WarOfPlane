//�����ӵ���

#pragma once
#include "graphics.h"
#include "playerPlane.h"

class playerPlane;

class enemyBullet {
public:
	int x, y;
	int width, height;
	int ATK;
	IMAGE img1,img2;
public:
	//�ӵ���ʼ�� //xy 
	void enemyBulletInit(int x,int y,int width,int height);//
	/*
		
		���������x��y-bossͼƬ���Ͻ����� width-bossͼ�� height-bossͼ�߶�
		����ֵ �ޣ�
		ʵ��Ч�����ӵ���boss���·� �ӵ��������bossͼƬ�������غ�
		����ʵ��Ч����x ��y
		����load���� ����bossBullet.png �������·��
		����ͼƬ�Ĵ�С 20X20
		��ӡputimage(x,y,&img1) ����x��y
		��ʼ��ATK Ϊ1
	*/
	//�ӵ��ƶ� ���¹̶��ƶ�
	void enemyBulletMove(void);
	/*
		���� ����ֵҲ����Ҫ 
		�ı�yֵ y+=10 px
	*/
	void enemyPrint(void);
	/*f
		�����ͷ���ֵ ��
		���� ʵ����x��y����ӡͼƬ����
		��ӡputimage(x,y,&img) ����x��y
	*/
};
