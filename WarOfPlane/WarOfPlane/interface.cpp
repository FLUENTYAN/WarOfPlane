#include "interface.h"

void gameStart(void);

//开始界面
void startMenu() {
	//画出开始界面
	drawStartMenu();

	while (true) {
		//鼠标左键按下且鼠标在开始按钮框内
		if (leftKeyDown() && mouseInStartSquare()) {
			//开始游戏;
			gameStart();
		}
		//如果鼠标左键按下且鼠标在结束框内
		else if (leftKeyDown() && mouseInEndSquare()) {
			//退出程序	
			return;
		}
	}
}

//暂停界面
void pauseInterface() {
	//画出暂停界面
	drawPauseInterface();

	while (true) {
		//鼠标左键按下且鼠标在继续游戏按钮框内
		if (leftKeyDown() && mouseInContinueSquare()) {
			//继续游戏;
			break;
		}
		//鼠标左键按下且鼠标在重新开始按钮框内
		else if (leftKeyDown() && mouseInRestartSquare()) {
			//重新开始游戏;
			gameStart();
		}
		//如果鼠标左键按下且鼠标在返回菜单框内
		else if (leftKeyDown() && mouseInBackToMenuSquare()) {
			//返回开始菜单	
			startMenu();
		}
	}
}

//结束界面
void endInterface() {
	//画出结束界面
	drawEndInterface();

	while (true) {
		//鼠标左键按下且鼠标在重新开始按钮框内
		if (leftKeyDown() && mouseInRestartSquare()) {
			//重新开始游戏;
			gameStart();
		}
		//如果鼠标左键按下且鼠标在返回菜单框内
		else if (leftKeyDown() && mouseInBackToMenuSquare()) {
			//返回开始菜单	
			startMenu();
		}
	}
}


//画出背景图片
void drawMap(void) {
}
//播放背景音乐
void playBGM(void) {
}
//暂停按钮按下
bool pauseKeyDown() {
}
//画出开始界面
void drawStartMenu(void) {
}
//画出暂停界面
void drawPauseInterface(void) {
}
//画出结束界面
void drawEndInterface(void) {}

//左键按下
bool leftKeyDown(void) {}
//鼠标在开始框内
bool mouseInStartSquare(void) {}
//鼠标在结束框内
bool mouseInEndSquare(void) {}
//鼠标继续游戏框内
bool mouseInContinueSquare(void) {}
//鼠标在重新开始框内
bool mouseInRestartSquare(void) {}
//鼠标在返回菜单框内
bool mouseInBackToMenuSquare(void) {}
