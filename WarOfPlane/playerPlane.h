//��ҷɻ���

#pragma once
#include "graphics.h"
#include "enemyPlane.h"

class enemyPlane;
class enemyBullet;

class playerPlane {
public:
	int x = 0, y = 0;
	int width, height;
	int blood;
	IMAGE img1, img2;
public:
	//��ҷɻ���ʼ��
	void playerPlaneInit(void);

	/*	
		����ͼƬ��img1��ֵ ���� player.png ��С90 120
		��x,y��ֵȡ����
	* �ײ�������Ļ
	* ����������Ļ�м�
	* ��width��height��ֵ 90 120
	* blood ��ֵ3
	* ��ӡ���� ���� ���� x��y img1
	*/
	//�ƶ���ҷɻ�
	void planeMove(void);
	/* �޲��� �޷���ֵ
	���� message e
	GetAsyncKeyState()���ռ���ֵ

	ֻ����һ��
	if�ж�wsad���� x+-5 y+-5
	�����ж�
	x��yָҪ����Ļ0 0 450-w 750-h ֹͣ
	�����ƶ�����Ļ
	*/
	
	//���Ѫ����һ
	void playerBloodMinus(void);
	/*�޲��� �޷���ֵ
	* ʵ��HP-1;
	*/
	void playerPrint(void);
	/*�޲��� �޷���ֵ
	* loadimage ����x��y img1��ӡͼƬ��
	*/
	void bloodShow(void);
};
