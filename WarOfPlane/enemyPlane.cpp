#include "enemyPlane.h"
#include <cstdlib>//rand 头文件a
#include <ctime>  //std::time
//敌机初始化
void enemyPlane::smallPlaneInit(void) {
	loadimage(&img1, ("smallEnemy1.png"), 30, 40);
	loadimage(&img2, ("smallEnemy2.png"), 30, 40);
	blood = 1;
	width = 30, height = 40;
	x = rand() % 360+45; //随机生成450 ~750  如果生成的位置有敌机需要再次生成
	y = -40;
	putimage(x, y, &img1,SRCPAINT);
	putimage(x, y, &img2,SRCAND);

}


void enemyPlane::largePlaneInit(void) {
	// 创建一个矩形区域
	HRGN rgn = CreateRectRgn(x, y, x + 149, y + 199);
	// 将该矩形区域设置为裁剪区
	setcliprgn(rgn);
	// 不再使用 rgn，清理 rgn 占用的系统资源
	DeleteObject(rgn);

	loadimage(&img1, ("boss1.png"), 150, 200);
	loadimage(&img2, ("boss2.png"), 150, 200);
	width = 150, height = 200;
	x = 225-75;//不需要移动 x的值 实现效果位固定在界面的中心轴对齐
	y = 0;
	blood = 10;
	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);

	// 取消之前设置的裁剪区
	setcliprgn(NULL);

}


//小型机移动
void enemyPlane::smallPlaneMove(void) {
	y += 5;
}


//大型机血量减一
void enemyPlane::enemyBloodMinus(void) {
	blood--;
}

void enemyPlane::largePlanePrint(void) {
	// 创建一个矩形区域
	HRGN rgn = CreateRectRgn(x, y, x + 149, y + 199);
	// 将该矩形区域设置为裁剪区
	setcliprgn(rgn);
	// 不再使用 rgn，清理 rgn 占用的系统资源
	DeleteObject(rgn);

	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);

	// 取消之前设置的裁剪区
	setcliprgn(NULL);
}

void enemyPlane::smallPlanePrint(void) {
	putimage(x, y, &img1, SRCPAINT);
	putimage(x, y, &img2, SRCAND);
}
