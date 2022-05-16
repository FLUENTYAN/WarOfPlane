#include <list>             //std::list std::list<>::iterator
#include "interface.h"
#include "playerPlane.h"
#include "enemyPlane.h"
#include "playerBullet.h"
#include "enemyBullet.h"

//Wether bullet or enemyPlane crash into userPlane
bool judgeCarsh(int x1, int y1, int width1, int height1, int x2, int y2, int width2, int height2) {
	double a = pow(x1 - x2 + width1 / 2 - width2 / 2, 2);
	double a1 = pow(y1 - y2 + height1 / 2 - height2 / 2, 2);
	double a2 = pow(width1 + width2, 2) / 4 + pow(height1 / 2 + height2 / 2, 2) / 4;
	return a + a1 < a2;
}

//constant valuables that decide the gap time of bullet and plane's existance
constexpr auto ONE = 30; //normal size enemy plane;
constexpr auto TWO = 30;//user plane bullet
constexpr auto	THREE = 90;//boss bullet
constexpr auto FOUR = 50;//undefeatable time too avoid continous blood loss by one enemy
constexpr auto FIVE = 500;//boss 

//to calculate how many times do the while loop goes
int sum = 1;
void gameStart() {

	bool defeatable = true;//valuable that decide whether or not one is undefeatable
	int sum2 = FOUR;//as you see, it just stores FOUR
	
	//definition of plane and bullet
	playerPlane user;
	std::list<enemyPlane> sEnemy, bEnemy;
	std::list<playerBullet> pBullet;
	std::list<enemyBullet> eBullet;

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
			for (auto iter = pBullet.begin(); iter != pBullet.end(); iter++) {
				iter->bulletMove();
			}
		}

		//这里是敌机子弹移动 
		if (!eBullet.empty()) {
			for (auto iter = eBullet.begin(); iter != eBullet.end(); iter++) {
				iter->enemyBulletMove();
			}
		}

		//敌机移动
		if (!sEnemy.empty()) {
			for (auto iter = sEnemy.begin(); iter != sEnemy.end(); iter++) {
				iter->smallPlaneMove();
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
		if (defeatable && !eBullet.empty()) //判断是否子弹有 是否可被扣血
		{
			for (auto iter = eBullet.begin(); iter != eBullet.end(); ) {
				if (judgeCarsh(user.x, user.y, user.width, user.height, iter->x, iter->y, iter->width, iter->height)) {
					eBullet.erase(iter++);
					user.playerBloodMinus();
					defeatable = false;
					break;
				}
				else
					iter++;
			}
		}
		//玩家飞机和敌机
		if (defeatable && !sEnemy.empty()) {
			for (auto iter = sEnemy.begin(); iter != sEnemy.end(); ) {
				if (judgeCarsh(user.x, user.y, user.width, user.height, iter->x, iter->y, iter->width, iter->height)) {
					sEnemy.erase(iter++);//清理该敌机
					user.playerBloodMinus();
					defeatable = false;
					break;
				}
				else
					iter++;
			}
		}
		//玩家飞机和boss
		if (defeatable && !bEnemy.empty()) {
			if (judgeCarsh(user.x, user.y, user.width, user.height, bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height)) {
				user.playerBloodMinus();
				defeatable = false;
				break;
			}
		}

		//循环判断 敌机和飞机子弹的
		if (!sEnemy.empty() && !pBullet.empty()) {
			for (auto iter1 = sEnemy.begin(); iter1 != sEnemy.end(); ) {
				if (pBullet.empty())//如果出现子弹没了的话直接跳过判断
					break;
				bool isthrought = true;
				for (auto iter2 = pBullet.begin(); iter2 != pBullet.end(); ) {
					if (judgeCarsh(iter1->x, iter1->y, iter1->width, iter1->height, iter2->x, iter2->y, iter2->width, iter2->height) && iter1->y >= 0)
					{
						sEnemy.erase(iter1++);
						pBullet.erase(iter2++);
						isthrought = false;
						break;
					}
					else
						iter2++;
				}
				if (isthrought)
					iter1++;
			}
		}

		//循环判读 boss和飞机子弹是否碰撞 碰撞则减血
		if (!bEnemy.empty() && !pBullet.empty()) {

			for (auto iter = pBullet.begin(); iter != pBullet.end(); ) {
				if (judgeCarsh(bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height, iter->x, iter->y, iter->width, iter->height))
				{
					bEnemy.front().enemyBloodMinus();
					pBullet.erase(iter++);
					break;
				}
				else
					iter++;
			}
		}
		//?		
		if (!bEnemy.empty() && bEnemy.front().blood <= 0) {
			bEnemy.clear();
		}
		//delete the small plane, boss and its bullet if they are not int the screen
		if (!sEnemy.empty()) {
			for (auto iter = sEnemy.begin(); iter != sEnemy.end(); ) {
				if (iter->y >= 750)
				{
					sEnemy.erase(iter++);
				}
				else
					iter++;
			}
		}
		if (!pBullet.empty()) {
			for (auto iter = pBullet.begin(); iter != pBullet.end(); ) {
				if (iter->y <= -iter->height)
				{
					pBullet.erase(iter++);
				}
				else
					iter++;
			}
		}
		if (!eBullet.empty()) {
			for (auto iter = eBullet.begin(); iter != eBullet.end();) {
				if (iter->y > 750)
				{
					eBullet.erase(iter++);
				}
				else
					iter++;
			}
		}

		//jump into pause interface once BLANK is hit
		FlushBatchDraw();
		if (pauseKeyDown()) {
			EndBatchDraw();
			pauseInterface();
		}
		//jump into end interface once user is dead
		FlushBatchDraw();
		if (user.blood <= 0) {
			EndBatchDraw();
			endInterface();
			return;
		}

		FlushBatchDraw();
		cleardevice(); //clear the whole screen
		drawMap();//draw the map
		user.playerPrint();// draw the user plane
		//draw the small enemy that did not die
		if (!sEnemy.empty()) {
			for (auto iter = sEnemy.begin(); iter != sEnemy.end(); iter++) {
				iter->smallPlanePrint();
			}
		}
		//draw the boss's bullet that exist
		if (!eBullet.empty()) {
			for (auto iter = eBullet.begin(); iter != eBullet.end(); iter++) {
				iter->eBulletPrint();
			}
		}
		//draw the existing player bullet
		if (!pBullet.empty()) {
			for (auto iter = pBullet.begin(); iter != pBullet.end(); iter++) {
				iter->bulletPrint();
			}
		}
		//draw the boss if exist
		if (!bEnemy.empty()) {
			bEnemy.front().largePlanePrint();
		}
		//show the remaining life of user plane
		user.bloodShow();
		
		//after certain time of loop, make it defeatable	
		if (!defeatable) {
			sum2--;
			if (sum2 <= 0) {
				defeatable = true;
				sum2 = FOUR;
			}
		}
		//sum increase 1 every loop
		++sum;
		//to avoid bug
		if (sum >= 9999999) {
			sum = 0;
		}
	}
}

int main(void) {
	//jump into start interface once begin	
	startMenu();
	}