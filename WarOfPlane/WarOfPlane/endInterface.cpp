//结束界面

#include "endInterface.h"

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