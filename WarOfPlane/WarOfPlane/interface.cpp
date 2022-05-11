#include "interface.h"

void gameStart(void);

//��ʼ����
void startMenu() {
	//������ʼ����
	drawStartMenu();

	while (true) {
		//����������������ڿ�ʼ��ť����
		if (leftKeyDown() && mouseInStartSquare()) {
			//��ʼ��Ϸ;
			gameStart();
		}
		//�������������������ڽ�������
		else if (leftKeyDown() && mouseInEndSquare()) {
			//�˳�����	
			return;
		}
	}
}

//��ͣ����
void pauseInterface() {
	//������ͣ����
	drawPauseInterface();

	while (true) {
		//����������������ڼ�����Ϸ��ť����
		if (leftKeyDown() && mouseInContinueSquare()) {
			//������Ϸ;
			break;
		}
		//��������������������¿�ʼ��ť����
		else if (leftKeyDown() && mouseInRestartSquare()) {
			//���¿�ʼ��Ϸ;
			gameStart();
		}
		//�������������������ڷ��ز˵�����
		else if (leftKeyDown() && mouseInBackToMenuSquare()) {
			//���ؿ�ʼ�˵�	
			startMenu();
		}
	}
}

//��������
void endInterface() {
	//������������
	drawEndInterface();

	while (true) {
		//��������������������¿�ʼ��ť����
		if (leftKeyDown() && mouseInRestartSquare()) {
			//���¿�ʼ��Ϸ;
			gameStart();
		}
		//�������������������ڷ��ز˵�����
		else if (leftKeyDown() && mouseInBackToMenuSquare()) {
			//���ؿ�ʼ�˵�	
			startMenu();
		}
	}
}


//��������ͼƬ
void drawMap(void) {
}
//���ű�������
void playBGM(void) {
}
//��ͣ��ť����
bool pauseKeyDown() {
}
//������ʼ����
void drawStartMenu(void) {
}
//������ͣ����
void drawPauseInterface(void) {
}
//������������
void drawEndInterface(void) {}

//�������
bool leftKeyDown(void) {}
//����ڿ�ʼ����
bool mouseInStartSquare(void) {}
//����ڽ�������
bool mouseInEndSquare(void) {}
//��������Ϸ����
bool mouseInContinueSquare(void) {}
//��������¿�ʼ����
bool mouseInRestartSquare(void) {}
//����ڷ��ز˵�����
bool mouseInBackToMenuSquare(void) {}
