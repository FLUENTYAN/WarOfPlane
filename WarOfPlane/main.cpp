#include <memory>			//std::shared_ptr std::make_shared
#include <list>             //std::list		  std::list<>::iterator
#include "interface.h"
#include "playerPlane.h"
#include "enemyPlane.h"
#include "playerBullet.h"
#include "enemyBullet.h"

//判断用户飞机或者敌机是否相撞，或者是否与子弹接触
//Wether bullet or Plane hit each other
bool judgeCarsh(int x1, int y1, int width1, int height1, int x2, int y2, int width2, int height2) {
	double a = pow(x1 - x2 + width1 / 2 - width2 / 2, 2);
	double a1 = pow(y1 - y2 + height1 / 2 - height2 / 2, 2);
	double a2 = pow(width1 + width2, 2) / 4 + pow(height1 / 2 + height2 / 2, 2) / 4;
	return a + a1 < a2;
}

//用于决定飞机、子弹出现频率的常量
//constant valuables that decide the gap time of bullet and plane's existance
constexpr auto ONE = 30; //normal size enemy plane 普通敌机
constexpr auto TWO = 30;//user bullet  玩家的子弹
constexpr auto	THREE = 90;//boss bullet 敌机子弹
constexpr auto FOUR = 50;//undefeatable time too avoid continous blood loss by one enemy 玩家飞机被撞后的无敌时间
constexpr auto FIVE = 500;//boss 大型敌机

//计算循环进行次数
//to calculate how many times do the while loop goes
int sum = 1;
void gameStart() {

	bool defeatable = true;//valuable that decide whether or not one is undefeatable 决定是否无敌
	int sum2 = FOUR;//as you see, it just stores FOUR 存储无敌时间

	//定义所有飞机、子弹
	//definition of plane and bullet
	playerPlane user;
	std::list<enemyPlane> sEnemy, bEnemy;
	std::list<playerBullet> pBullet;
	std::list<enemyBullet> eBullet;

	//画背景
	//draw back ground picture
	drawMap();
	//放音乐
	//play Background music
	playBGM();
	//初始化玩家飞机
	//initializing player plane
	user.playerPlaneInit();
	
	//使用死循环让游戏一直进行
	//to keep the game going
	while (true) {
		//生成敌机 
		//create enemy plane
		BeginBatchDraw();
		if (sum % ONE == 0) {
			std::shared_ptr<enemyPlane> sEnemyPtr = std::make_shared<enemyPlane>();
			sEnemyPtr->smallPlaneInit();
			sEnemy.push_back(*sEnemyPtr);
		}
		if (bEnemy.empty() && sum % FIVE == 0) {
			std::shared_ptr<enemyPlane> bEnemyPtr = std::make_shared<enemyPlane>();
			bEnemyPtr->largePlaneInit();
			bEnemy.push_back(*bEnemyPtr);
		}
		//移动代码块
		//所有存在的对象进行移动操作的部分
#pragma region
		//这里是玩家子弹移动 
		//player bullet movement
		if (!pBullet.empty()) {
			for (auto iter = pBullet.begin(); iter != pBullet.end(); iter++) {
				iter->bulletMove();
			}
		}

		//这里是敌机子弹移动 
		//enemy bullet movement
		if (!eBullet.empty()) {
			for (auto iter = eBullet.begin(); iter != eBullet.end(); iter++) {
				iter->enemyBulletMove();
			}
		}

		//敌机移动
		//enemy plane movement
		if (!sEnemy.empty()) {
			for (auto iter = sEnemy.begin(); iter != sEnemy.end(); iter++) {
				iter->smallPlaneMove();
			}
		}
		//飞机移动（函数内包含读取移动方向键的函数）
		//move the plane
		user.planeMove();

#pragma endregion


		//玩家飞机子弹初始化 
		//initializing player bullet
		if (sum % TWO == 0) {
			std::shared_ptr<playerBullet> pBulletPtr = std::make_shared<playerBullet>();
			pBulletPtr->playerBulletInit(user.x, user.y, user.width, user.height);
			pBullet.push_back(*pBulletPtr);
		}
		//敌机子弹初始化
		//enemy bullet initializing
		if (!bEnemy.empty() && sum % THREE == 0) {
			std::shared_ptr<enemyBullet> eBulletPtr = std::make_shared<enemyBullet>();
			eBulletPtr->enemyBulletInit(bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height);
			eBullet.push_back(*eBulletPtr);
		}

		//受击判断
		//whether shot or crash		
		//玩家飞机和子弹
		//player plane with enemy bullet
		if (defeatable && !eBullet.empty()) //defeatable and enemy bullets exist 判断是否子弹有 是否可被扣血
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
		//player plane with enemy plane
		if (defeatable && !sEnemy.empty()) {
			for (auto iter = sEnemy.begin(); iter != sEnemy.end(); ) {
				if (judgeCarsh(user.x, user.y, user.width, user.height, iter->x, iter->y, iter->width, iter->height)) {
					sEnemy.erase(iter++);//delete the enemy plane when crashed 碰撞后清理该敌机
					user.playerBloodMinus();
					defeatable = false;
					break;
				}
				else
					iter++;
			}
		}
		//玩家飞机和boss
		//player plane with boss
		if (defeatable && !bEnemy.empty()) {
			if (judgeCarsh(user.x, user.y, user.width, user.height, bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height)) {
				user.playerBloodMinus();
				defeatable = false;
				break;
			}
		}

		//循环判断 敌机和飞机子弹的
		//enemy plane with player bullet
		if (!sEnemy.empty() && !pBullet.empty()) {
			for (auto iter1 = sEnemy.begin(); iter1 != sEnemy.end(); ) {
				if (pBullet.empty())//is no bullet remain, just break the loop 如果出现子弹没了的话直接跳过判断
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
		//boss with player plane
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
		
		if (!bEnemy.empty() && bEnemy.front().blood <= 0) {
			bEnemy.clear();
		}
		//delete the small plane, boss and its bullet if they are not int the screen
		//如果敌机、子弹飞到了屏幕边界，删除它
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
		//按下空格键跳转暂停界面
		FlushBatchDraw();
		if (pauseKeyDown()) {
			EndBatchDraw();
			pauseInterface();
		}
		//jump into end interface once user is dead
		//玩家死亡跳转结束界面
		FlushBatchDraw();
		if (user.blood <= 0) {
			EndBatchDraw();
			endInterface();
			return;
		}

		FlushBatchDraw();
		cleardevice(); //clear the whole screen 每次循环后清除整个屏幕
		drawMap();//draw the map  重新画背景
		user.playerPrint();// draw the user plane  画用户飞机
		//draw the small enemy that did not die
		//画还活着的小敌机
		if (!sEnemy.empty()) {
			for (auto iter = sEnemy.begin(); iter != sEnemy.end(); iter++) {
				iter->smallPlanePrint();
			}
		}
		//draw the boss's bullet that exist
		//画还存在的boss的子弹
		if (!eBullet.empty()) {
			for (auto iter = eBullet.begin(); iter != eBullet.end(); iter++) {
				iter->eBulletPrint();
			}
		}
		//draw the existing player bullet
		//画还存在的玩家的子弹
		if (!pBullet.empty()) {
			for (auto iter = pBullet.begin(); iter != pBullet.end(); iter++) {
				iter->bulletPrint();
			}
		}
		//draw the boss if exist
		//画boss
		if (!bEnemy.empty()) {
			bEnemy.front().largePlanePrint();
		}
		//show the remaining life of user plane
		//显示玩家血量
		user.bloodShow();
		
		//after certain time of loop, make it defeatable	
		//当被撞一定循环次数后关闭无敌状态
		if (!defeatable) {
			sum2--;
			if (sum2 <= 0) {
				defeatable = true;
				sum2 = FOUR;
			}
		}
		//sum increase 1 every loop
		//循环计数
		++sum;
		//to avoid bug
		//当循环次数一定后归零
		if (sum >= 9999999) {
			sum = 0;
		}
	}
}

int main(void) {
	//jump into start interface once begin
	//跳转开始界面
	startMenu();
}