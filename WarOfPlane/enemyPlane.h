//敌机类

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
	
	
	//小敌机初始化
	void smallPlaneInit(void);
	/*
	* 参数无 无返回值
	* 利用loadimage加载图片
	* 图片大小为40 ，60
	* 图片名称为smallenmy.png 
	* 为width height赋值
	* 450<=x<=750,y=60
	* random 生成x整数450-750的整数 声明 种子
	* 血量 blood=1；
	* 打印图片
	* 调用putimage() 参数 x,y
	*/
	//大敌机初始化
	void largePlaneInit(void);
	/*
		
	* 参数无 无返回值
	* 利用loadimage加载图片
	* 图片大小为150 200
	* 图片名称为boss.png
	* 为width height赋值
	* 赋值x=450/2-width/2;就是中心轴对准正中心
	*
	* y=0；
	* 
	* 血量 blood=10；
	* 打印图片
	* 调用putimage() 参数 x,y

	*/
	//小型机移动
	inline void smallPlaneMove(void) { y += 5; }
	//大型机血量减一
	inline void enemyBloodMinus(void) { --blood; }
	
	void smallPlanePrint(void);
	/*
	* 参数无 无返回值
	 打印 利用putimage()函数 参数 类中 x，y img1
	*/
	void largePlanePrint(void);
	/*
	参数无 无返回值
	* 打印 利用putimage()函数 参数 类中 x，y img1
	*/
	
};
