//��������

#include "endInterface.h"

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