#include <list>
#include<iostream>
#include "interface.h"
#include "playerPlane.h"
#include "enemyPlane.h"
#include "playerBullet.h"
#include "enemyBullet.h"

bool judgeCarsh(int x1, int y1, int width1, int height1, int x2, int y2, int width2, int height2) {
	double a = pow(x1 - x2 + width1 / 2 - width2 / 2, 2);
	double a1 = pow(y1 - y2 + height1 / 2 - height2 / 2, 2);
	double a2 = pow(width1 + width2, 2) / 4 + pow(height1 / 2 + height2 / 2, 2) / 4;
	return a + a1 < a2;
}
constexpr auto ONE = 30; //多少次循环生成敌机;
constexpr auto TWO = 30;//多少次生成飞机子弹
constexpr auto	THREE = 90;//多少次生成boss子弹
constexpr auto FOUR = 50;//计算飞机产生伤害时 多少循环后进行下次伤害判断
constexpr auto FIVE = 500;//boss产生

void gameStart() {
	//问题是需要刷新图片
	//刷新需要把所有需要加载的图片进行记录并传递；

	//定义玩家、敌机、子弹
	bool blood = true;//用于判断是否扣血 真表示可以减少血量 否则无敌
	int sum2 = FOUR;//计数有多少循环玩家处于无法扣血
	//新定义 用链表
	playerPlane user;
	std::list<enemyPlane> sEnemy, bEnemy;//前者是小型机 后者是boss
	std::list<enemyPlane>::iterator s1, b1;//迭代器用于变量访问

	std::list<playerBullet> pBullet;//玩家子弹
	std::list<playerBullet>::iterator p1;//迭代器用于变量访问

	std::list<enemyBullet> eBullet;//敌机子弹
	std::list<enemyBullet>::iterator e1;//迭代器用于变量访问

	//画出背景图'
	drawMap();
	//播放音乐
	playBGM();
	//玩家飞机初始化
	user.playerPlaneInit();

	//大循环
	while (true) {
		//生成敌机 
		BeginBatchDraw();
		if (sum % ONE == 0) {
			enemyPlane* e = new enemyPlane();
		
			e->smallPlaneInit();
			sEnemy.push_back(*e);
		}
		if (bEnemy.empty() && sum % FIVE == 0) {
			enemyPlane* e = new enemyPlane;
			e->largePlaneInit();
			bEnemy.push_back(*e);
		}
		//移动代码块
		//所有存在的对象进行移动操作的部分
#pragma region
		//这里是玩家子弹移动 
		if (!pBullet.empty()) {
			for (p1 = pBullet.begin(); p1 != pBullet.end(); p1++) {
				p1->bulletMove();
			}
		}

		//这里是敌机子弹移动 
		if (!eBullet.empty()) {
			for (e1 = eBullet.begin(); e1 != eBullet.end(); e1++) {
				e1->enemyBulletMove();
			}
		}

		//敌机移动
		if (!sEnemy.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end(); s1++) {
				s1->smallPlaneMove();
			}
		}
		//飞机移动（函数内包含读取移动方向键的函数）
		user.planeMove();

#pragma endregion


		//玩家飞机子弹初始化 
		if (sum % TWO == 0) {
			playerBullet* pb = new playerBullet;
			pb->playerBulletInit(user.x, user.y, user.width, user.height);
			pBullet.push_back(*pb);
		}
		//敌机子弹初始化
		if (!bEnemy.empty() && sum % THREE == 0) {
			enemyBullet* eb = new enemyBullet;
			eb->enemyBulletInit(bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height);
			eBullet.push_back(*eb);
		}

		//子弹碰撞
		//判断循环 首先飞机和子弹的 之后是boss的
		//玩家飞机和子弹
		if (blood && !eBullet.empty()) //判断是否子弹有 是否可被扣血
		{
			for (e1 = eBullet.begin(); e1 != eBullet.end();) {
				if (judgeCarsh(user.x, user.y, user.width, user.height, e1->x, e1->y, e1->width, e1->height)) {
					eBullet.erase(e1++);
					user.playerBloodMinus();
					blood = false;
					break;
				}
				else
					e1++;
			}
		}
		//玩家飞机和敌机
		if (blood && !sEnemy.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end(); ) {
				if (judgeCarsh(user.x, user.y, user.width, user.height, s1->x, s1->y, s1->width, s1->height)) {
					sEnemy.erase(s1++);//清理该敌机
					user.playerBloodMinus();
					blood = false;
					break;
				}
				else
					s1++;
			}
		}
		//玩家飞机和boss
		if (blood && !bEnemy.empty()) {
			if (judgeCarsh(user.x, user.y, user.width, user.height, bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height)) {
				user.playerBloodMinus();
				blood = false;
				break;
			}
		}

		//循环判断 敌机和飞机子弹的
		if (!sEnemy.empty() && !pBullet.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end();) {
				if (pBullet.empty())//如果出现子弹没了的话直接跳过判断
					break;
				bool isthrought = true;
				for (p1 = pBullet.begin(); p1 != pBullet.end(); ) {
					if (judgeCarsh(s1->x, s1->y, s1->width, s1->height, p1->x, p1->y, p1->width, p1->height)&&s1->y>=0)
					{
						sEnemy.erase(s1++);
						pBullet.erase(p1++);
						isthrought = false;
						break;
					}
					else
						p1++;
				}
				if (isthrought)
					s1++;
			}
		}

		//循环判读 boss和飞机子弹是否碰撞 碰撞则减血
		if (!bEnemy.empty() && !pBullet.empty()) {

			for (p1 = pBullet.begin(); p1 != pBullet.end(); ) {
				if (judgeCarsh(bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height, p1->x, p1->y, p1->width, p1->height))
				{
					bEnemy.front().enemyBloodMinus();
					pBullet.erase(p1++);
					break;
				}
				else
					p1++;
			}
		}
				
		if (!bEnemy.empty() && bEnemy.front().blood <= 0) {
			bEnemy.clear();
		}
		//删除模块 2.看看是否有子弹或敌机飞入边界 
		//敌机和敌机子弹都是y坐标>=750 本机子弹是小于等于自身高度 进行删除
		if (!sEnemy.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end(); ) {
				if (s1->y >= 750)
				{
					sEnemy.erase(s1++);
				}
				else
					s1++;
			}
		}
		if (!pBullet.empty()) {
			for (p1 = pBullet.begin(); p1 != pBullet.end(); ) {
				if (p1->y <= -p1->height)
				{
					pBullet.erase(p1++);
				}
				else
					p1++;
			}
		}
		if (!eBullet.empty()) {
			for (e1 = eBullet.begin(); e1 != eBullet.end();) {
				if (e1->y > 750)
				{
					eBullet.erase(e1++);
				}
				else
					e1++;
			}
		}

		//判断是否暂停
		FlushBatchDraw();
		if (pauseKeyDown()) {
			//跳转暂停界面
			EndBatchDraw();
			pauseInterface();
		}
		//删除模块 1.血量为零 直接删除 玩家或boss 
		FlushBatchDraw();
		if (user.blood <= 0) {
			EndBatchDraw();
			endInterface();
			return;
		}

		/*
		* 打印函数
		*经过飞机 子弹 boss 生成函数
		* 飞机子弹移动函数
		* 飞机 子弹boss碰撞函数
		* 飞机子弹boss删除函数 此时
		* 留下玩家飞机 有血 小敌机 未被击中未移出边界 boss 有血且被生成的三段链表
		* 此时进行打印操作
		*/
		FlushBatchDraw();
		cleardevice(); //清除上一次绘图
		drawMap();//画地图
		user.playerPrint();
		if (!sEnemy.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end(); s1++) {
				s1->smallPlanePrint();
			}
		}
		if (!eBullet.empty()) {
			for (e1 = eBullet.begin(); e1 != eBullet.end(); e1++) {
				e1->enemyPrint();
			}
		}
		if (!pBullet.empty()) {
			for (p1 = pBullet.begin(); p1 != pBullet.end(); p1++) {
				p1->bulletPrint();
			}
		}
		if (!bEnemy.empty()) {
			bEnemy.front().largePlanePrint();
		}
		user.bloodShow();
		//清空旧图
		//打印地图和界面
		//show(); 根据上方堆栈的信息一个个打印
		//刷新新图
		//先

		//循环判断 无敌状态
		if (!blood) {
			sum2--;
			if (sum2 <= 0) {
				blood = true;
				sum2 = FOUR;
			}
		}
		++sum;
		//Sleep(100000);
		if (sum >= 9999999) {
			sum = 0;
		}
	}
}

int main(void) {
	//展示开始界面
	startMenu();
	}