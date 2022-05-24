#include<easyx.h>
#include <conio.h>
#include <Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "interface.h"
#pragma comment( lib, "MSIMG32.LIB")

void gameStart(void);
//开始界面
// start interface
void startMenu() {
	//画出开始界面
	drawStartMenu();
	while (true) {
		//鼠标左键按下且鼠标在开始按钮框内
		if (mouseInStartSquare()) {
			//开始游戏;
			gameStart();
		}
		//如果鼠标左键按下且鼠标在结束框内
		if (mouseInEndSquare()) {
			//退出程序
			closegraph();
			return;
		}
	}
}

// 播放背景音乐
void playBGM() {
	mciSendString("open ./bgm.mp3 alias bgm", 0, 0, 0);
	mciSendString("play bgm repeat", 0, 0, 0);
}

// 画出背景图片
void drawMap(void) {
	IMAGE img;
	//loadimage(&img, "./bk.jpg", ui_w, ui_h);
	loadimage(&img, "./bk2.jpg", ui_w, ui_h);
	putimage(0, 0, &img);
}

// 相关变量声明
extern const int ui_w = 450;
extern const int ui_h = 750;
extern const int button_x = ui_w / 3;
extern const int button_h = ui_h/12;
extern const int button_enter_y = ui_h / 2 - button_h / 2;
extern const int button_end_y = ui_h / 8 * 5 - button_h / 2;
extern const int button_w = ui_w / 3;
extern const int button_continue_y = ui_h / 8 * 3 - button_h / 2;
extern const int button_restart_y = ui_h / 2 - button_h / 2;
extern const int button_return_y = ui_h / 8 * 5 - button_h / 2;

// 画出开始界面
void drawStartMenu() {
	// 初始化窗口
	initgraph(ui_w, ui_h);
	playBGM();
	HWND wname = GetHWnd();
	SetWindowText(wname, "飞机大战");
	setbkcolor(RGB(98, 136, 181));
	cleardevice();
	// 标题文字
	settextcolor(WHITE);
	settextstyle(60, 0, "黑体", 0, 0, 1000, 0,0,0);
	const char* g_name = "飞机大战";
	const int g_name_x = ui_w / 2 - textwidth(g_name) / 2;
	const int g_name_y = ui_h / 4 - textheight(g_name) / 2;
	outtextxy(g_name_x, g_name_y, g_name);
	// 操作提示
	settextstyle(40, 0, "黑体");
	const char* tip = "Tip:";
	outtextxy(ui_w / 2 - textwidth(tip)/2, ui_h / 8 * 7, tip);
	settextstyle(20, 0, "黑体");
	const char* tip_text = "请使用w、s、a、d来进行上下左右移动";
	outtextxy(ui_w / 2 - textwidth(tip_text) / 2, ui_h / 8 * 7 + 50, tip_text);

	// 选项框
	setfillcolor(WHITE);
	setbkmode(TRANSPARENT);
	solidroundrect(button_x, button_enter_y, button_x + button_w, button_enter_y + button_h, 10, 10);
	solidroundrect(button_x, button_end_y, button_x + button_w, button_end_y + button_h, 10, 10);
	settextcolor(BLACK);
	settextstyle(25, 0, "宋体");
	const char* enter_g = "进入游戏";
	const int enter_x = button_x + (button_w - textwidth(enter_g)) / 2;
	const int enter_y = button_enter_y + (button_h - textheight(enter_g)) / 2;
	outtextxy(enter_x, enter_y, enter_g);
	const char* end_g = "退出游戏";
	const int end_x = button_x + (button_w - textwidth(enter_g)) / 2;
	const int end_y = button_end_y + (button_h - textheight(enter_g)) / 2;
	outtextxy(end_x, end_y, end_g);
}


//暂停按键按下
bool pauseKeyDown(void) {
	if (!_kbhit()) {
		return false;
	}
	else {
		if (_getch() == 32)
			return true;
		else
			return false;
	}
}
//暂停界面
void pauseInterface() {
	//画出暂停界面
	drawPauseInterface();
	FlushBatchDraw();

	while (true) {
		//鼠标左键按下且鼠标在继续游戏按钮框内
		if (mouseInContinueSquare()) {
			//继续游戏;
			break;
		}
		//鼠标左键按下且鼠标在重新开始按钮框内
		else if (mouseInRestartSquare()) {
			//重新开始游戏;
			gameStart();
		}
		//如果鼠标左键按下且鼠标在返回菜单框内
		else if (mouseInReturnSquare()) {
			//返回开始菜单	
			startMenu();
		}
	}
}

//结束界面
void endInterface() {
	//画出结束界面
	drawEndInterface();
	FlushBatchDraw();

	while (true) {
		//鼠标左键按下且鼠标在重新开始按钮框内
		if (mouseInRestartSquare()) {
			//重新开始游戏;
			//return;
			gameStart();
		}
		//如果鼠标左键按下且鼠标在返回菜单框内
		else if (mouseInReturnSquare()) {
			//返回开始菜单	
			//return;
			startMenu();
		}
	}
}

//画出暂停界面
void drawPauseInterface(void) {
	//加载带有透明信息的中间层
	IMAGE src;
	loadimage(&src, _T("./ransparent.png"));
	/*
	//测试用背景
	IMAGE img;
	loadimage(&img, _T("game.png"), 450, 750);
	putimage(0, 0, &img);
	*/
	// 透明贴图
	// BLENDFUNCTION结构体的第三个成员表示额外的透明度，0 表示全透明，255 表示不透明。
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(GetImageHDC(NULL), 0, 0, 450, 750, GetImageHDC(&src), 0, 0, 450, 750, bf);


	/*
	//设置背景颜色
	setfillcolor(BGR(0x6288B5));
	solidrectangle(0, 0, ui_w, ui_h);
	*/

	//画"继续游戏"按钮
	//画外框
	setfillcolor(WHITE);
	solidroundrect(button_x, button_continue_y, button_x + button_w, button_continue_y + button_h, 10, 10);
	//画文字
	settextstyle(25, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	RECT r = { button_x,button_continue_y,button_x + button_w, button_continue_y + button_h };
	drawtext(_T("继续游戏"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//画"重新开始"按钮
	  //画外框
	setfillcolor(WHITE);
	solidroundrect(button_x, button_restart_y, button_x + button_w, button_restart_y + button_h, 10, 10);
	//画文字
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	r = { button_x, button_restart_y, button_x + button_w, button_restart_y + button_h };
	drawtext(_T("重新开始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//画"返回菜单"按钮
	  //画外框
	setfillcolor(WHITE);
	solidroundrect(button_x, button_return_y, button_x + button_w, button_return_y + button_h, 10, 10);
	//画文字
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	r = { button_x, button_return_y, button_x + button_w, button_return_y + button_h };
	drawtext(_T("返回菜单"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//roundrect(100, 100, 200, 150,20,20);  画圆角填充矩形1
	//floodfill(150,125,WHITE);
	//fillroundrect(100, 100, 200, 150, 20, 20);  画圆角填充矩形2
}

//画出结束界面
void drawEndInterface(void) {
	//设置背景颜色
	setfillcolor(BGR(0x6288B5));
	solidrectangle(0, 0, 450, 750);

	//画"重新开始"按钮
	  //画外框
	settextstyle(25, 0, "宋体");
	setfillcolor(WHITE);
	solidroundrect(button_x, button_restart_y, button_x + button_w, button_restart_y + button_h, 10, 10);
	//画文字
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	RECT r = { button_x, button_restart_y, button_x + button_w, button_restart_y + button_h };
	drawtext(_T("重新开始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//画"返回菜单"按钮
	  //画外框
	solidroundrect(button_x, button_return_y, button_x + button_w, button_return_y + button_h, 10, 10);
	//画文字
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	r = { button_x, button_return_y, button_x + button_w, button_return_y + button_h };
	drawtext(_T("返回菜单"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

// 鼠标在开始框内
bool mouseInStartSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_enter_y && msg.y < button_enter_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

// 鼠标在结束框内
bool mouseInEndSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_end_y && msg.y < button_end_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

// 鼠标在继续游戏框内
bool mouseInContinueSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_continue_y && msg.y < button_continue_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

// 鼠标在重新开始框内
bool mouseInRestartSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_restart_y && msg.y < button_restart_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

// 鼠标在返回菜单框内
bool mouseInReturnSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_return_y && msg.y < button_return_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

