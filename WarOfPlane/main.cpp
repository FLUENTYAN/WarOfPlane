#include <list>
#include<iostream>
#include "interface.h"
#include "playerPlane.h"
#include "enemyPlane.h"
#include "playerBullet.h"
#include "enemyBullet.h"

bool judgeCarsh(int x1, int y1, int width1, int height1, int x2, int y2, int width2, int height2) {
	double a = pow(x1 - x2 + width1 / 2 - width2 / 2, 2);
	double a1 = pow(y1 - y2 + height1 / 2 - height2 / 2, 2);
	double a2 = pow(width1 + width2, 2) / 4 + pow(height1 / 2 + height2 / 2, 2) / 4;
	return a + a1 < a2;
}
constexpr auto ONE = 30; //���ٴ�ѭ�����ɵл�;
constexpr auto TWO = 30;//���ٴ����ɷɻ��ӵ�
constexpr auto	THREE = 90;//���ٴ�����boss�ӵ�
constexpr auto FOUR = 50;//����ɻ������˺�ʱ ����ѭ��������´��˺��ж�
constexpr auto FIVE = 500;//boss����

void gameStart() {
	//��������Ҫˢ��ͼƬ
	//ˢ����Ҫ��������Ҫ���ص�ͼƬ���м�¼�����ݣ�

	//������ҡ��л����ӵ�
	bool blood = true;//�����ж��Ƿ��Ѫ ���ʾ���Լ���Ѫ�� �����޵�
	int sum2 = FOUR;//�����ж���ѭ����Ҵ����޷���Ѫ
	//�¶��� ������
	playerPlane user;
	std::list<enemyPlane> sEnemy, bEnemy;//ǰ����С�ͻ� ������boss
	std::list<enemyPlane>::iterator s1, b1;//���������ڱ�������

	std::list<playerBullet> pBullet;//����ӵ�
	std::list<playerBullet>::iterator p1;//���������ڱ�������

	std::list<enemyBullet> eBullet;//�л��ӵ�
	std::list<enemyBullet>::iterator e1;//���������ڱ�������

	//��������ͼ'
	drawMap();
	//��������
	playBGM();
	//��ҷɻ���ʼ��
	user.playerPlaneInit();

	//��ѭ��
	while (true) {
		//���ɵл� 
		BeginBatchDraw();
		if (sum % ONE == 0) {
			enemyPlane* e = new enemyPlane();
		
			e->smallPlaneInit();
			sEnemy.push_back(*e);
		}
		if (bEnemy.empty() && sum % FIVE == 0) {
			enemyPlane* e = new enemyPlane;
			e->largePlaneInit();
			bEnemy.push_back(*e);
		}
		//�ƶ������
		//���д��ڵĶ�������ƶ������Ĳ���
#pragma region
		//����������ӵ��ƶ� 
		if (!pBullet.empty()) {
			for (p1 = pBullet.begin(); p1 != pBullet.end(); p1++) {
				p1->bulletMove();
			}
		}

		//�����ǵл��ӵ��ƶ� 
		if (!eBullet.empty()) {
			for (e1 = eBullet.begin(); e1 != eBullet.end(); e1++) {
				e1->enemyBulletMove();
			}
		}

		//�л��ƶ�
		if (!sEnemy.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end(); s1++) {
				s1->smallPlaneMove();
			}
		}
		//�ɻ��ƶ��������ڰ�����ȡ�ƶ�������ĺ�����
		user.planeMove();

#pragma endregion


		//��ҷɻ��ӵ���ʼ�� 
		if (sum % TWO == 0) {
			playerBullet* pb = new playerBullet;
			pb->playerBulletInit(user.x, user.y, user.width, user.height);
			pBullet.push_back(*pb);
		}
		//�л��ӵ���ʼ��
		if (!bEnemy.empty() && sum % THREE == 0) {
			enemyBullet* eb = new enemyBullet;
			eb->enemyBulletInit(bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height);
			eBullet.push_back(*eb);
		}

		//�ӵ���ײ
		//�ж�ѭ�� ���ȷɻ����ӵ��� ֮����boss��
		//��ҷɻ����ӵ�
		if (blood && !eBullet.empty()) //�ж��Ƿ��ӵ��� �Ƿ�ɱ���Ѫ
		{
			for (e1 = eBullet.begin(); e1 != eBullet.end();) {
				if (judgeCarsh(user.x, user.y, user.width, user.height, e1->x, e1->y, e1->width, e1->height)) {
					eBullet.erase(e1++);
					user.playerBloodMinus();
					blood = false;
					break;
				}
				else
					e1++;
			}
		}
		//��ҷɻ��͵л�
		if (blood && !sEnemy.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end(); ) {
				if (judgeCarsh(user.x, user.y, user.width, user.height, s1->x, s1->y, s1->width, s1->height)) {
					sEnemy.erase(s1++);//����õл�
					user.playerBloodMinus();
					blood = false;
					break;
				}
				else
					s1++;
			}
		}
		//��ҷɻ���boss
		if (blood && !bEnemy.empty()) {
			if (judgeCarsh(user.x, user.y, user.width, user.height, bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height)) {
				user.playerBloodMinus();
				blood = false;
				break;
			}
		}

		//ѭ���ж� �л��ͷɻ��ӵ���
		if (!sEnemy.empty() && !pBullet.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end();) {
				if (pBullet.empty())//��������ӵ�û�˵Ļ�ֱ�������ж�
					break;
				bool isthrought = true;
				for (p1 = pBullet.begin(); p1 != pBullet.end(); ) {
					if (judgeCarsh(s1->x, s1->y, s1->width, s1->height, p1->x, p1->y, p1->width, p1->height)&&s1->y>=0)
					{
						sEnemy.erase(s1++);
						pBullet.erase(p1++);
						isthrought = false;
						break;
					}
					else
						p1++;
				}
				if (isthrought)
					s1++;
			}
		}

		//ѭ���ж� boss�ͷɻ��ӵ��Ƿ���ײ ��ײ���Ѫ
		if (!bEnemy.empty() && !pBullet.empty()) {

			for (p1 = pBullet.begin(); p1 != pBullet.end(); ) {
				if (judgeCarsh(bEnemy.front().x, bEnemy.front().y, bEnemy.front().width, bEnemy.front().height, p1->x, p1->y, p1->width, p1->height))
				{
					bEnemy.front().enemyBloodMinus();
					pBullet.erase(p1++);
					break;
				}
				else
					p1++;
			}
		}
				
		if (!bEnemy.empty() && bEnemy.front().blood <= 0) {
			bEnemy.clear();
		}
		//ɾ��ģ�� 2.�����Ƿ����ӵ���л�����߽� 
		//�л��͵л��ӵ�����y����>=750 �����ӵ���С�ڵ�������߶� ����ɾ��
		if (!sEnemy.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end(); ) {
				if (s1->y >= 750)
				{
					sEnemy.erase(s1++);
				}
				else
					s1++;
			}
		}
		if (!pBullet.empty()) {
			for (p1 = pBullet.begin(); p1 != pBullet.end(); ) {
				if (p1->y <= -p1->height)
				{
					pBullet.erase(p1++);
				}
				else
					p1++;
			}
		}
		if (!eBullet.empty()) {
			for (e1 = eBullet.begin(); e1 != eBullet.end();) {
				if (e1->y > 750)
				{
					eBullet.erase(e1++);
				}
				else
					e1++;
			}
		}

		//�ж��Ƿ���ͣ
		FlushBatchDraw();
		if (pauseKeyDown()) {
			//��ת��ͣ����
			EndBatchDraw();
			pauseInterface();
		}
		//ɾ��ģ�� 1.Ѫ��Ϊ�� ֱ��ɾ�� ��һ�boss 
		FlushBatchDraw();
		if (user.blood <= 0) {
			EndBatchDraw();
			endInterface();
			return;
		}

		/*
		* ��ӡ����
		*�����ɻ� �ӵ� boss ���ɺ���
		* �ɻ��ӵ��ƶ�����
		* �ɻ� �ӵ�boss��ײ����
		* �ɻ��ӵ�bossɾ������ ��ʱ
		* ������ҷɻ� ��Ѫ С�л� δ������δ�Ƴ��߽� boss ��Ѫ�ұ����ɵ���������
		* ��ʱ���д�ӡ����
		*/
		FlushBatchDraw();
		cleardevice(); //�����һ�λ�ͼ
		drawMap();//����ͼ
		user.playerPrint();
		if (!sEnemy.empty()) {
			for (s1 = sEnemy.begin(); s1 != sEnemy.end(); s1++) {
				s1->smallPlanePrint();
			}
		}
		if (!eBullet.empty()) {
			for (e1 = eBullet.begin(); e1 != eBullet.end(); e1++) {
				e1->enemyPrint();
			}
		}
		if (!pBullet.empty()) {
			for (p1 = pBullet.begin(); p1 != pBullet.end(); p1++) {
				p1->bulletPrint();
			}
		}
		if (!bEnemy.empty()) {
			bEnemy.front().largePlanePrint();
		}
		user.bloodShow();
		//��վ�ͼ
		//��ӡ��ͼ�ͽ���
		//show(); �����Ϸ���ջ����Ϣһ������ӡ
		//ˢ����ͼ
		//��

		//ѭ���ж� �޵�״̬
		if (!blood) {
			sum2--;
			if (sum2 <= 0) {
				blood = true;
				sum2 = FOUR;
			}
		}
		++sum;
		//Sleep(100000);
		if (sum >= 9999999) {
			sum = 0;
		}
	}
}

int main(void) {
	//չʾ��ʼ����
	startMenu();
	}