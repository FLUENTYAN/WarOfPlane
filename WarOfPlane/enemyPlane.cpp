#include "enemyPlane.h"
#include <cstdlib>//rand 头文件a
#include <ctime>  //std::time
//敌机初始化
void enemyPlane::smallPlaneInit(void) {
	loadimage(&img1, ("smallEnemy.png"), 30, 40);
	blood = 1;
	width = 30, height = 40;
	x = rand() % 360+45; //随机生成450 ~750  如果生成的位置有敌机需要再次生成
	y = -40;
	putimage(x, y, &img1);
}


void enemyPlane::largePlaneInit(void) {
	loadimage(&img1, ("boss.png"), 150, 200);
	width = 150, height = 200;
	x = 225-75;//不需要移动 x的值 实现效果位固定在界面的中心轴对齐
	y = 0;
	blood = 10;
	putimage(x, y, &img1);
}


//小型机移动
void enemyPlane::smallPlaneMove(void) {
	y += 10;
}


//大型机血量减一
void enemyPlane::enemyBloodMinus(void) {
	blood--;
}

void enemyPlane::largePlanePrint(void) {
	putimage(x, y, &img1);
}

void enemyPlane::smallPlanePrint(void) {
	putimage(x, y, &img1);
}
