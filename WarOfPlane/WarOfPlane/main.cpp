#include <vector>     //std::vector

#include "interface.h"
#include "playerPlane.h"
#include "enemyPlane.h"
#include "playerBullet.h"
#include "enemyBullet.h"

//������ͣ������ȫ�ֱ���
int PAUSE = 0, END = 0;

void gameStart() {

	//��������Ҫˢ��ͼƬ
	//ˢ����Ҫ��������Ҫ���ص�ͼƬ���м�¼�����ݣ�
	//�ö��д��Ǹ����뷨
	//

	//����������л����ӵ�
	playerPlane user;
	std::vector<enemyPlane> sEnemy(6), bEnemy(1);
	std::vector<playerBullet> pBullet(9);
	std::vector<enemyBullet> eBullet(4);

	//��������ͼ
	drawMap();
	//��������
	playBGM();
	//��ҷɻ���ʼ��
	user.playerPlaneInit();
	//�ӵ���ʼ��
	pBullet[0].playerBulletInit();
	//�л���ʼ��
	sEnemy[0].enemyPlaneInit();
	bEnemy[0].enemyPlaneInit();

	while (true) {

		//�ɻ��ƶ��������ڰ�����ȡ�ƶ�������ĺ�����
		user.planeMove();
		pBullet[0].bulletMove();
		/*
			�����ӵ�λ���ƶ����ж�
			�ӵ�ÿ���ж��ƶ�һ������
			Ȼ�������������¼��Щλ�����ӵ�
			���������жϺ������ײ


		*/
		/*
			
			�ж���ײ����
			Ҫ����x,y,c,b ������λ�ô��ڵķɻ����л�����
			���ӵ�λ���ж� �������Ƿ���ڽ��� 
			���ڷ���true 
		*/

		//�ж�С�ͻ������л��߱�ײ 
		//�˴������ѭ���ж�С�ͻ� ����Ҫ������ʲô��ȡС�ͻ�
		if (sEnemy[0].smallPlaneExist()) {
			if (sEnemy[0].smallPlaneShot() || sEnemy[0].smallPlaneCrash())
				//С�ͻ���ʧ
				sEnemy[0].smallPlaneVanish();
			else
				//ѹ��С�ͻ���Ϣ
		}
		//�жϴ��ͻ�����
		if (bEnemy[0].largePlaneExist()) {
			//�жϴ��ͻ��������ײ
			if (bEnemy[0].largePlaneShot() || bEnemy[0].largePlaneCrash()) {
				//Ѫ����һ
				bEnemy[0].enemyBloodMinus();
				//�ж�Ѫ��
				if (bEnemy[0].bloodQuantity()) {
					//���ͻ���ʧ
					bEnemy[0].largePlaneVanish();
				}
				else
				{
					//ѹ�����,�ȴ������ɣ�
				}
			}
		}

		//�ж�����ܻ�
		if (user.playerPlaneShot() || user.playerPlaneCrash()) {
			//Ѫ����һ
			user.playerBloodMinus();
			//Ѫ��<=0
			if (user.bloodQuantity()) {
				//��ת��������
				END = 1;
				return;
			}
			else
				//ѹ�����,�ȴ������ɣ�
		}

		//�ж��Ƿ���ͣ
		if (pauseKeyDown()) {
			//��ת��ͣ����
			PAUSE = 1;
			return;
		}


		//��վ�ͼ
		//��ӡ��ͼ�ͽ���
		//show(); �����Ϸ���ջ����Ϣһ������ӡ
		//ˢ����ͼ
		//��
	}
}

int main(void) {
	//չʾ��ʼ����
	startMenu();
	while (true) {
		if (PAUSE) {
			//������ͣ����
			PAUSE = 0;
			pauseInterface();
		}
		if (END) {
			//���ý�������
			END = 0;
			endInterface();
		}
	}
}