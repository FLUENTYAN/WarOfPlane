//��ͣ����

#include "pauseInterface.h"

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
			stratMenu();
		}
	}
}