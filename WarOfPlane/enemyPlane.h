//�л���

#pragma once
#include "graphics.h"
#include "playerPlane.h"

class playerPlane;
class playerBullet;

class enemyPlane {
public:
	int x, y;
	int width, height;
	int blood;
	IMAGE img1,img2;
public:
	
	
	//С�л���ʼ��
	void smallPlaneInit(void);
	/*
	* ������ �޷���ֵ
	* ����loadimage����ͼƬ
	* ͼƬ��СΪ40 ��60
	* ͼƬ����Ϊsmallenmy.png 
	* Ϊwidth height��ֵ
	* 450<=x<=750,y=60
	* random ����x����450-750������ ���� ����
	* Ѫ�� blood=1��
	* ��ӡͼƬ
	* ����putimage() ���� x,y
	*/
	//��л���ʼ��
	void largePlaneInit(void);
	/*
		
	* ������ �޷���ֵ
	* ����loadimage����ͼƬ
	* ͼƬ��СΪ150 200
	* ͼƬ����Ϊboss.png
	* Ϊwidth height��ֵ
	* ��ֵx=450/2-width/2;�����������׼������
	*
	* y=0��
	* 
	* Ѫ�� blood=10��
	* ��ӡͼƬ
	* ����putimage() ���� x,y

	*/
	//С�ͻ��ƶ�
	void smallPlaneMove(void);
	/*
	* y+=10;
	* ������ �޷���ֵ
	*/
	//���ͻ�Ѫ����һ
	void enemyBloodMinus(void);
	/*
	* ������ �޷���ֵ
	* blood--
	*/
	void smallPlanePrint(void);
	/*
	* ������ �޷���ֵ
	 ��ӡ ����putimage()���� ���� ���� x��y img1
	*/
	void largePlanePrint(void);
	/*
	������ �޷���ֵ
	* ��ӡ ����putimage()���� ���� ���� x��y img1
	*/
	
};
