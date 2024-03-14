#pragma once
#include "Common.h"
#include "Globalvariable.h"
#include "System.h"
#include "Highscore.h"

//game intro
void gameIntro();
//in ki tu ASCII tu file
void printASCII(string fileName, int x, int y);

void drawBox(int x, int y, int width, int height, string nd);

void boxstart(int x, int y, int width, int height, string nd, int pos);

void boxabout(int x, int y, int width, int height, string nd, int pos);

void boxhighscore(int x, int y, int width, int height, string nd, int pos);

void boxloadgame(int x, int y, int width, int height, string nd, int pos);

void boxhelp(int x, int y, int width, int height, string nd, int pos);

void boxexit(int x, int y, int width, int height, string nd, int pos);
//ve khung thanh o level 4
void DrawGoal();
//ve khung bao quat ngoai cung
void DrawFrame(int x, int y);
// ve dem nguoc cho level 1
void DrawCountDown(int x, int y);
// xoa 1 phan cua khung bao quat de ve khung level
void DeleteFrameLevel(int x, int y);
// Ve khung va chu level 1,2,3,4
void DrawFrameLevel(int x, int y);
void DrawFrameLevel1(int x, int y);
void DrawFrameLevel2(int x, int y);
void DrawFrameLevel3(int x, int y);
//ve khung thong tin ben trai man hinh
void DrawLeftBoard(int x, int y);
//hien thi cac thong tin trong khung thong tin ben trai man hinh
void DrawInfo(int x, int y);
//ve khung game level 1
void DrawBoard(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0);
//ve khung game level 2
void DrawBoard1(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0);
//ve khung game level 3
void DrawBoard2(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0);
//ve khung game level 4
void DrawBoard3(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0);
//ve tuong cho level 2
void DrawWall();
//ve cac tuong nho trong level 4
void DrawSmallWall();

void DrawBoard_1(int x, int y, int width, int height);
//ve man hinh pause game
void DrawPause();

//xoa tat ca cac ki tu ben trong khung game
void ClearBoard();
//xoa man hinh pause game
void ClearPause();

//ve khung ket qua
void ResultBoard();
//hien thi man hinh ket qua
void Result();
//xoa ki tu ben trong sau khi chon save o man hinh ket qua
void ClearSave();
//hien thi man hinh save game
void SaveBoard();