void gameStart() {

	//��������ͼ
	drawMap();
	//��������
	playBGM();
	//��ҷɻ���ʼ��
	playerPlaneInit();
	//�л���ʼ��
	enemyPlaneInit();

	while (true) {

		//�ж���Ұ��·����
		if (moveKeyDown()) {
			planeMove();
			bulletMove();
		}
		//�ж�С�ͻ������ֻ��߱�ײ
		if (smallPlaneShot() || smallPlaneCrash())
			//С�ͻ���ʧ
			smallPlaneVanish();
		//�жϴ��ͻ�����
		if (largePlaneExist()) {
			//�жϴ��ͻ��������ײ
			if (largePlaneShot() || LargePlaneCrash()) {
				//Ѫ����һ
				enemyBloodMinus();
				//�ж�Ѫ��
				if (blood <= 0) {
					//���ͻ���ʧ
					largePlaneVanish();
				}
			}
		}

		//�ж�����ܻ�
		if (playerPlaneShot() || PlayerPlaneCrash()) {
			//Ѫ����һ
			playerBloodMinus();
			//Ѫ��<=0
			if (blood <= 0)
				//��ת��������
				endInterface();
		}

		//�ж��Ƿ���ͣ
		if (pauseKeyDown()) {
			//��ת��ͣ����
			pauseInterface();
		}

		//�ӵ����ɻ������ƶ�
		bulletMove();
		planeMove();
	}
}

int main(void) {
	//չʾ��ʼ����
	startMenu();
}