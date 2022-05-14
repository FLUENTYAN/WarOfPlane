#ifndef _INTERFACE_H_
#define _ONTERFACE_H_

// ��ʼ�����Ⱥ͸߶�
extern const int ui_w;
extern const int ui_h;
// ��ť����
extern const int button_enter_x;
extern const int button_enter_y;
extern const int button_end_x;
extern const int button_end_y;
extern const int button_w;
extern const int button_h;
extern const int button_continue_y;
extern const int button_restart_y;
extern const int button_return_y;

//��ʼ����
void startMenu();

// ��������ͼƬ
void drawMap(void);
// ���ű������� 
void playBGM(void);
 
// ������ʼ����
void drawStartMenu(void);
//��ͣ����
void pauseInterface();
//������ͣ����
void drawPauseInterface(void);
//��������
void endInterface();
//������������
void drawEndInterface(void);
bool pauseKeyDown(void);

// ����ڿ�ʼ����
bool mouseInStartSquare();
// ����ڽ�������
bool mouseInEndSquare();
// ����ڼ�����Ϸ����
bool mouseInContinueSquare();
// ��������¿�ʼ����
bool mouseInRestartSquare();
// ����ڷ��ز˵�����
bool mouseInReturnSquare();

#endif