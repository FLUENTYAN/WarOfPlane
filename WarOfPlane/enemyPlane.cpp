#include "enemyPlane.h"
#include <cstdlib>//rand ͷ�ļ�a
#include <ctime>  //std::time
//�л���ʼ��
void enemyPlane::smallPlaneInit(void) {
	loadimage(&img1, ("smallEnemy1.png"), 30, 40);
	loadimage(&img2, ("smallEnemy2.png"), 30, 40);
	blood = 1;
	width = 30, height = 40;
	x = rand() % 360+45; //�������450 ~750  ������ɵ�λ���ел���Ҫ�ٴ�����
	y = -40;
	putimage(x, y, &img1,SRCPAINT);
	putimage(x, y, &img2,SRCAND);

}


void enemyPlane::largePlaneInit(void) {
	// ����һ����������
	HRGN rgn = CreateRectRgn(x, y, x + 149, y + 199);
	// ���þ�����������Ϊ�ü���
	setcliprgn(rgn);
	// ����ʹ�� rgn������ rgn ռ�õ�ϵͳ��Դ
	DeleteObject(rgn);

	loadimage(&img1, ("boss1.png"), 150, 200);
	loadimage(&img2, ("boss2.png"), 150, 200);
	width = 150, height = 200;
	x = 225-75;//����Ҫ�ƶ� x��ֵ ʵ��Ч��λ�̶��ڽ�������������
	y = 0;
	blood = 10;
	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);

	// ȡ��֮ǰ���õĲü���
	setcliprgn(NULL);

}


//С�ͻ��ƶ�
void enemyPlane::smallPlaneMove(void) {
	y += 5;
}


//���ͻ�Ѫ����һ
void enemyPlane::enemyBloodMinus(void) {
	blood--;
}

void enemyPlane::largePlanePrint(void) {
	// ����һ����������
	HRGN rgn = CreateRectRgn(x, y, x + 149, y + 199);
	// ���þ�����������Ϊ�ü���
	setcliprgn(rgn);
	// ����ʹ�� rgn������ rgn ռ�õ�ϵͳ��Դ
	DeleteObject(rgn);

	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);

	// ȡ��֮ǰ���õĲü���
	setcliprgn(NULL);
}

void enemyPlane::smallPlanePrint(void) {
	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);
}
