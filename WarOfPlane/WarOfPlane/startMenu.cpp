//��ʼ����

#include "startMenu.h"

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