#include <vector>     //std::vector

#include "interface.h"
#include "playerPlane.h"
#include "enemyPlane.h"
#include "playerBullet.h"
#include "enemyBullet.h"

//定义暂停和死亡全局变量
int PAUSE = 0, END = 0;

void gameStart() {

	//问题是需要刷新图片
	//刷新需要把所有需要加载的图片进行记录并传递；
	//用队列存是个好想法
	//

	//定义玩机、敌机、子弹
	playerPlane user;
	std::vector<enemyPlane> sEnemy(6), bEnemy(1);
	std::vector<playerBullet> pBullet(9);
	std::vector<enemyBullet> eBullet(4);

	//画出背景图
	drawMap();
	//播放音乐
	playBGM();
	//玩家飞机初始化
	user.playerPlaneInit();
	//子弹初始化
	pBullet[0].playerBulletInit();
	//敌机初始化
	sEnemy[0].enemyPlaneInit();
	bEnemy[0].enemyPlaneInit();

	while (true) {

		//飞机移动（函数内包含读取移动方向键的函数）
		user.planeMove();
		pBullet[0].bulletMove();
		/*
			进行子弹位置移动的判断
			子弹每次判断移动一定距离
			然后整个坐标轴记录那些位置有子弹
			这样才能判断后面的碰撞


		*/
		/*
			
			判断碰撞函数
			要的是x,y,c,b 即其他位置存在的飞机、敌机坐标
			和子弹位置判断 即两者是否存在交集 
			存在返回true 
		*/

		//判断小型机被击中或者被撞 
		//此处仍需加循环判断小型机 还需要考虑用什么存取小型机
		if (sEnemy[0].smallPlaneExist()) {
			if (sEnemy[0].smallPlaneShot() || sEnemy[0].smallPlaneCrash())
				//小型机消失
				sEnemy[0].smallPlaneVanish();
			else
				//压入小型机信息
		}
		//判断大型机存在
		if (bEnemy[0].largePlaneExist()) {
			//判断大型机被射击或被撞
			if (bEnemy[0].largePlaneShot() || bEnemy[0].largePlaneCrash()) {
				//血量减一
				bEnemy[0].enemyBloodMinus();
				//判断血量
				if (bEnemy[0].bloodQuantity()) {
					//大型机消失
					bEnemy[0].largePlaneVanish();
				}
				else
				{
					//压入队列,等待被生成；
				}
			}
		}

		//判断玩家受击
		if (user.playerPlaneShot() || user.playerPlaneCrash()) {
			//血量减一
			user.playerBloodMinus();
			//血量<=0
			if (user.bloodQuantity()) {
				//跳转死亡界面
				END = 1;
				return;
			}
			else
				//压入队列,等待被生成；
		}

		//判断是否暂停
		if (pauseKeyDown()) {
			//跳转暂停界面
			PAUSE = 1;
			return;
		}


		//清空旧图
		//打印地图和界面
		//show(); 根据上方堆栈的信息一个个打印
		//刷新新图
		//先
	}
}

int main(void) {
	//展示开始界面
	startMenu();
	while (true) {
		if (PAUSE) {
			//重置暂停变量
			PAUSE = 0;
			pauseInterface();
		}
		if (END) {
			//重置结束变量
			END = 0;
			endInterface();
		}
	}
}