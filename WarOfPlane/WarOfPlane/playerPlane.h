//��ҷɻ���

#pragma once
#include "graphics.h"

class enemyPlane;
class enemyBullet;

class playerPlane {
public:
	//��Ԫ����
	friend 	bool enemyPlane::smallPlaneCrash(void);
private:
	int x = 450/2, y = 750/2;
	int width, height;
	int blood;
	IMAGE img1;
public:
	//��ҷɻ���ʼ��
	void playerPlaneInit(void);
	//�ƶ���ҷɻ�
	void planeMove(void);
	//��ұ�����
	bool playerPlaneShot(void);
	//��ұ�ײ
	bool playerPlaneCrash(void);
	//�����ʧ
	void playerPlaneVanish(void);
	//���Ѫ����һ
	void playerBloodMinus(void);
	//�ж����Ѫ��
	int bloodQuantity(void);
};
