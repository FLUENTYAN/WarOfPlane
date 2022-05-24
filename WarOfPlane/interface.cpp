#include<easyx.h>
#include <conio.h>
#include <Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "interface.h"
#pragma comment( lib, "MSIMG32.LIB")

void gameStart(void);
//��ʼ����
// start interface
void startMenu() {
	//������ʼ����
	drawStartMenu();
	while (true) {
		//����������������ڿ�ʼ��ť����
		if (mouseInStartSquare()) {
			//��ʼ��Ϸ;
			gameStart();
		}
		//�������������������ڽ�������
		if (mouseInEndSquare()) {
			//�˳�����
			closegraph();
			return;
		}
	}
}

// ���ű�������
void playBGM() {
	mciSendString("open ./bgm.mp3 alias bgm", 0, 0, 0);
	mciSendString("play bgm repeat", 0, 0, 0);
}

// ��������ͼƬ
void drawMap(void) {
	IMAGE img;
	//loadimage(&img, "./bk.jpg", ui_w, ui_h);
	loadimage(&img, "./bk2.jpg", ui_w, ui_h);
	putimage(0, 0, &img);
}

// ��ر�������
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

// ������ʼ����
void drawStartMenu() {
	// ��ʼ������
	initgraph(ui_w, ui_h);
	playBGM();
	HWND wname = GetHWnd();
	SetWindowText(wname, "�ɻ���ս");
	setbkcolor(RGB(98, 136, 181));
	cleardevice();
	// ��������
	settextcolor(WHITE);
	settextstyle(60, 0, "����", 0, 0, 1000, 0,0,0);
	const char* g_name = "�ɻ���ս";
	const int g_name_x = ui_w / 2 - textwidth(g_name) / 2;
	const int g_name_y = ui_h / 4 - textheight(g_name) / 2;
	outtextxy(g_name_x, g_name_y, g_name);
	// ������ʾ
	settextstyle(40, 0, "����");
	const char* tip = "Tip:";
	outtextxy(ui_w / 2 - textwidth(tip)/2, ui_h / 8 * 7, tip);
	settextstyle(20, 0, "����");
	const char* tip_text = "��ʹ��w��s��a��d���������������ƶ�";
	outtextxy(ui_w / 2 - textwidth(tip_text) / 2, ui_h / 8 * 7 + 50, tip_text);

	// ѡ���
	setfillcolor(WHITE);
	setbkmode(TRANSPARENT);
	solidroundrect(button_x, button_enter_y, button_x + button_w, button_enter_y + button_h, 10, 10);
	solidroundrect(button_x, button_end_y, button_x + button_w, button_end_y + button_h, 10, 10);
	settextcolor(BLACK);
	settextstyle(25, 0, "����");
	const char* enter_g = "������Ϸ";
	const int enter_x = button_x + (button_w - textwidth(enter_g)) / 2;
	const int enter_y = button_enter_y + (button_h - textheight(enter_g)) / 2;
	outtextxy(enter_x, enter_y, enter_g);
	const char* end_g = "�˳���Ϸ";
	const int end_x = button_x + (button_w - textwidth(enter_g)) / 2;
	const int end_y = button_end_y + (button_h - textheight(enter_g)) / 2;
	outtextxy(end_x, end_y, end_g);
}


//��ͣ��������
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
//��ͣ����
void pauseInterface() {
	//������ͣ����
	drawPauseInterface();
	FlushBatchDraw();

	while (true) {
		//����������������ڼ�����Ϸ��ť����
		if (mouseInContinueSquare()) {
			//������Ϸ;
			break;
		}
		//��������������������¿�ʼ��ť����
		else if (mouseInRestartSquare()) {
			//���¿�ʼ��Ϸ;
			gameStart();
		}
		//�������������������ڷ��ز˵�����
		else if (mouseInReturnSquare()) {
			//���ؿ�ʼ�˵�	
			startMenu();
		}
	}
}

//��������
void endInterface() {
	//������������
	drawEndInterface();
	FlushBatchDraw();

	while (true) {
		//��������������������¿�ʼ��ť����
		if (mouseInRestartSquare()) {
			//���¿�ʼ��Ϸ;
			//return;
			gameStart();
		}
		//�������������������ڷ��ز˵�����
		else if (mouseInReturnSquare()) {
			//���ؿ�ʼ�˵�	
			//return;
			startMenu();
		}
	}
}

//������ͣ����
void drawPauseInterface(void) {
	//���ش���͸����Ϣ���м��
	IMAGE src;
	loadimage(&src, _T("./ransparent.png"));
	/*
	//�����ñ���
	IMAGE img;
	loadimage(&img, _T("game.png"), 450, 750);
	putimage(0, 0, &img);
	*/
	// ͸����ͼ
	// BLENDFUNCTION�ṹ��ĵ�������Ա��ʾ�����͸���ȣ�0 ��ʾȫ͸����255 ��ʾ��͸����
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(GetImageHDC(NULL), 0, 0, 450, 750, GetImageHDC(&src), 0, 0, 450, 750, bf);


	/*
	//���ñ�����ɫ
	setfillcolor(BGR(0x6288B5));
	solidrectangle(0, 0, ui_w, ui_h);
	*/

	//��"������Ϸ"��ť
	//�����
	setfillcolor(WHITE);
	solidroundrect(button_x, button_continue_y, button_x + button_w, button_continue_y + button_h, 10, 10);
	//������
	settextstyle(25, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	RECT r = { button_x,button_continue_y,button_x + button_w, button_continue_y + button_h };
	drawtext(_T("������Ϸ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//��"���¿�ʼ"��ť
	  //�����
	setfillcolor(WHITE);
	solidroundrect(button_x, button_restart_y, button_x + button_w, button_restart_y + button_h, 10, 10);
	//������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	r = { button_x, button_restart_y, button_x + button_w, button_restart_y + button_h };
	drawtext(_T("���¿�ʼ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//��"���ز˵�"��ť
	  //�����
	setfillcolor(WHITE);
	solidroundrect(button_x, button_return_y, button_x + button_w, button_return_y + button_h, 10, 10);
	//������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	r = { button_x, button_return_y, button_x + button_w, button_return_y + button_h };
	drawtext(_T("���ز˵�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//roundrect(100, 100, 200, 150,20,20);  ��Բ��������1
	//floodfill(150,125,WHITE);
	//fillroundrect(100, 100, 200, 150, 20, 20);  ��Բ��������2
}

//������������
void drawEndInterface(void) {
	//���ñ�����ɫ
	setfillcolor(BGR(0x6288B5));
	solidrectangle(0, 0, 450, 750);

	//��"���¿�ʼ"��ť
	  //�����
	settextstyle(25, 0, "����");
	setfillcolor(WHITE);
	solidroundrect(button_x, button_restart_y, button_x + button_w, button_restart_y + button_h, 10, 10);
	//������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	RECT r = { button_x, button_restart_y, button_x + button_w, button_restart_y + button_h };
	drawtext(_T("���¿�ʼ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//��"���ز˵�"��ť
	  //�����
	solidroundrect(button_x, button_return_y, button_x + button_w, button_return_y + button_h, 10, 10);
	//������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	r = { button_x, button_return_y, button_x + button_w, button_return_y + button_h };
	drawtext(_T("���ز˵�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

// ����ڿ�ʼ����
bool mouseInStartSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_enter_y && msg.y < button_enter_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

// ����ڽ�������
bool mouseInEndSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_end_y && msg.y < button_end_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

// ����ڼ�����Ϸ����
bool mouseInContinueSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_continue_y && msg.y < button_continue_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

// ��������¿�ʼ����
bool mouseInRestartSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_restart_y && msg.y < button_restart_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

// ����ڷ��ز˵�����
bool mouseInReturnSquare() {
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE) && msg.x > button_x && msg.x < button_x + button_w && msg.y > button_return_y && msg.y < button_return_y + button_h && msg.message == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

