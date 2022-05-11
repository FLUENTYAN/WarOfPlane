#pragma once

//开始界面
void startMenu();
//暂停界面
void pauseInterface();
//结束界面
void endInterface();

//画出背景图片
void drawMap(void);
//播放背景音乐
void playBGM(void);
//暂停按钮按下
bool pauseKeyDown();

//画出开始界面
void drawStartMenu(void);
//画出暂停界面
void drawPauseInterface(void);
//画出结束界面
void drawEndInterface(void);

//左键按下
bool leftKeyDown(void);
//鼠标在开始框内
bool mouseInStartSquare(void);
//鼠标在结束框内
bool mouseInEndSquare(void);
//鼠标继续游戏框内
bool mouseInContinueSquare(void);
//鼠标在重新开始框内
bool mouseInRestartSquare(void);
//鼠标在返回菜单框内
bool mouseInBackToMenuSquare(void);

