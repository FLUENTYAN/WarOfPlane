#pragma once

//��ʼ����
void startMenu();
//��ͣ����
void pauseInterface();
//��������
void endInterface();

//��������ͼƬ
void drawMap(void);
//���ű�������
void playBGM(void);
//��ͣ��ť����
bool pauseKeyDown();

//������ʼ����
void drawStartMenu(void);
//������ͣ����
void drawPauseInterface(void);
//������������
void drawEndInterface(void);

//�������
bool leftKeyDown(void);
//����ڿ�ʼ����
bool mouseInStartSquare(void);
//����ڽ�������
bool mouseInEndSquare(void);
//��������Ϸ����
bool mouseInContinueSquare(void);
//��������¿�ʼ����
bool mouseInRestartSquare(void);
//����ڷ��ز˵�����
bool mouseInBackToMenuSquare(void);

