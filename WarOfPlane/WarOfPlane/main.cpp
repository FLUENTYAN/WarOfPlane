void gameStart() {

	//画出背景图
	drawMap();
	//播放音乐
	playBGM();
	//玩家飞机初始化
	playerPlaneInit();
	//敌机初始化
	enemyPlaneInit();

	while (true) {

		//判断玩家按下方向键
		if (moveKeyDown()) {
			planeMove();
			bulletMove();
		}
		//判断小型机被这种或者被撞
		if (smallPlaneShot() || smallPlaneCrash())
			//小型机消失
			smallPlaneVanish();
		//判断大型机存在
		if (largePlaneExist()) {
			//判断大型机被射击或被撞
			if (largePlaneShot() || LargePlaneCrash()) {
				//血量减一
				enemyBloodMinus();
				//判断血量
				if (blood <= 0) {
					//大型机消失
					largePlaneVanish();
				}
			}
		}

		//判断玩家受击
		if (playerPlaneShot() || PlayerPlaneCrash()) {
			//血量减一
			playerBloodMinus();
			//血量<=0
			if (blood <= 0)
				//跳转死亡界面
				endInterface();
		}

		//判断是否暂停
		if (pauseKeyDown()) {
			//跳转暂停界面
			pauseInterface();
		}

		//子弹、飞机继续移动
		bulletMove();
		planeMove();
	}
}

int main(void) {
	//展示开始界面
	startMenu();
}