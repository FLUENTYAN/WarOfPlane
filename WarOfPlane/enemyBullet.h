//敌人子弹类

#pragma once
#include "graphics.h"
#include "playerPlane.h"

class playerPlane;

class enemyBullet {
public:
	int x, y;
	int width, height;
	int ATK;
	IMAGE img1, img2;
public:
	//子弹初始化 //xy 
	void enemyBulletInit(int x, int y, int width, int height);//
	/*

		传入参数：x，y-boss图片左上角坐标 width-boss图宽 height-boss图高度
		返回值 无；
		实现效果：子弹在boss正下方 子弹中心轴和boss图片中心轴重合
		根据实现效果求x ，y
		调用load函数 读入bossBullet.png 参数相对路径
		读入图片的大小 20X20
		打印putimage(x,y,&img1) 参数x，y
		初始化ATK 为1
	*/
	//子弹移动 向下固定移动
	inline void enemyBulletMove(void) { y = y + 1; }
	
	void eBulletPrint(void) const;
	/*f
		参数和返回值 无
		功能 实现在x，y处打印图片即可
		打印putimage(x,y,&img) 参数x，y
	*/
};
