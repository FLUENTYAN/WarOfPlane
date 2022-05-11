//�л���

#pragma once
#include "graphics.h"

class playerPlane;
class playerBullet;

class enemyPlane {
public:
	//��Ԫ
	friend bool playerPlane::playerPlaneCrash(void);
private:
	int x, y;
	int width, height;
	int blood;
	IMAGE img1;
public:
	//С�ͻ�����
	bool smallPlaneExist(void);
	//�л���ʼ��
	void enemyPlaneInit(void);
	//С�ͻ�������
	bool smallPlaneShot(void);
	//С�ͻ���ײ
	bool smallPlaneCrash(void);
	//С�ͻ���ʧ
	void smallPlaneVanish(void);
	//���ͻ�����
	bool largePlaneExist(void);
	//���ͻ�������
	bool largePlaneShot(void);
	//���ͻ���ײ
	bool largePlaneCrash(void);
	//���ͻ���ʧ
	void largePlaneVanish(void);
	//���ͻ�Ѫ����һ
	void enemyBloodMinus(void);
	//�жϴ��ͻ�Ѫ��
	int bloodQuantity(void);
};
