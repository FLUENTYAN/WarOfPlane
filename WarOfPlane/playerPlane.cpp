#include "playerPlane.h"
#include "graphics.h"
#include "enemyBullet.h"
#include <iostream>
#include <conio.h>


//��ҷɻ���ʼ��
void playerPlane::playerPlaneInit(void) {
	loadimage(&img1, ("player1.png"), 70, 80);
	loadimage(&img2, ("player2.png"), 70, 80);

	width = 70, height = 80;
	blood = 5;
	x = 225 - width / 2;
	y = 750 - height;

}
//�ƶ���ҷɻ�
void playerPlane::planeMove(void) {
	int v = 5; //�ٶȲ��� �ɵ���  ������Ϳ���
	//putimage(x, y, &img1); �������һֱ�ƶ� ��ȥ��ע��
	//while (true) 

	if ((y < 0 || x < 0 || x > 450 - width || y > 750 - height)) {
		/*if (x <= 0) {
			x += 1;
		}
		else if (x >= 450 - 90) {
			x -= 1;
		}
		else if (y <= 0) {
			y += 1;
		}
		else if (y >= 750 - 120) {
			y -= 1;
		}
	}*/
		if (x < 0) {
			x = 0;
		}
		else if (x > 450 - width) {
			x = 450 - width;
		}
		else if (y < 0) {
			y = 0;
		}
		else if (y > 750 - height) {
			y = 750 - height;
		}
	}
	else {
		if (GetAsyncKeyState('W'))//����
			y -= v;
		if (GetAsyncKeyState('S'))//����
			y += v;
		if (GetAsyncKeyState('A'))//����
			x -= v;
		if (GetAsyncKeyState('D'))//����
			x += v;
	}
	//putimage(x, y, &img1);
	//system("cls");//����  ��Ȼ�ٶ��ر��
//}
}

//���Ѫ����һ
void playerPlane::playerBloodMinus(void) {
	blood--;
}

void playerPlane::playerPrint(void) {
	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);
}

void playerPlane::bloodShow(void) {
	IMAGE img3, img4;
	loadimage(&img3, "./blood1.png", 20, 20);
	loadimage(&img4, "./blood2.png", 20, 20);
	for (int i = 0; i < blood; i++)
	{
		putimage(i * 20, 750 - 20, &img3, SRCPAINT);
		putimage(i * 20, 750 - 20, &img4, SRCAND);
	}
}