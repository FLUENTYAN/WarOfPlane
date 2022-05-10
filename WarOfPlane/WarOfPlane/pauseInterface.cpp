//暂停界面

#include "pauseInterface.h"

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
			stratMenu();
		}
	}
}