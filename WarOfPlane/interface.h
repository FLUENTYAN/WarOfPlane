#ifndef _INTERFACE_H_
#define _ONTERFACE_H_

// 开始界面宽度和高度
extern const int ui_w;
extern const int ui_h;
// 按钮参数
extern const int button_enter_x;
extern const int button_enter_y;
extern const int button_end_x;
extern const int button_end_y;
extern const int button_w;
extern const int button_h;
extern const int button_continue_y;
extern const int button_restart_y;
extern const int button_return_y;

//开始界面
void startMenu();

// 画出背景图片
void drawMap(void);
// 播放背景音乐 
void playBGM(void);
 
// 画出开始界面
void drawStartMenu(void);
//暂停界面
void pauseInterface();
//画出暂停界面
void drawPauseInterface(void);
//结束界面
void endInterface();
//画出结束界面
void drawEndInterface(void);
bool pauseKeyDown(void);

// 鼠标在开始框内
bool mouseInStartSquare();
// 鼠标在结束框内
bool mouseInEndSquare();
// 鼠标在继续游戏框内
bool mouseInContinueSquare();
// 鼠标在重新开始框内
bool mouseInRestartSquare();
// 鼠标在返回菜单框内
bool mouseInReturnSquare();

#endif