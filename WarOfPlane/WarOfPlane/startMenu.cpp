//开始界面

#include "startMenu.h"

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