#include "enemyPlane.h"
#include <cstdlib>//rand ͷ�ļ�a
#include <ctime>  //std::time
//�л���ʼ��
void enemyPlane::smallPlaneInit(void) {
	loadimage(&img1, ("smallEnemy.png"), 30, 40);
	blood = 1;
	width = 30, height = 40;
	x = rand() % 360+45; //�������450 ~750  ������ɵ�λ���ел���Ҫ�ٴ�����
	y = -40;
	putimage(x, y, &img1);
}


void enemyPlane::largePlaneInit(void) {
	loadimage(&img1, ("boss.png"), 150, 200);
	width = 150, height = 200;
	x = 225-75;//����Ҫ�ƶ� x��ֵ ʵ��Ч��λ�̶��ڽ�������������
	y = 0;
	blood = 10;
	putimage(x, y, &img1);
}


//С�ͻ��ƶ�
void enemyPlane::smallPlaneMove(void) {
	y += 10;
}


//���ͻ�Ѫ����һ
void enemyPlane::enemyBloodMinus(void) {
	blood--;
}

void enemyPlane::largePlanePrint(void) {
	putimage(x, y, &img1);
}

void enemyPlane::smallPlanePrint(void) {
	putimage(x, y, &img1);
}
