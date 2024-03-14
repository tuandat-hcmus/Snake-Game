#pragma once
#include "Common.h"
#include "Draw.h"
#include "SaveLoad.h"

struct HighScore {
	string nAme;
	int score = 0;
	int lv = 0;
	char dAte[11] = "0";
};

//ve bang diem nguoi choi co diem so cao nhat
int DrawScoreBoard(int cornerX, int cornerY, int width, int height);

//luu thong tin diem so nguoi choi vao file highscore.txt
void SaveHighScore(string nAme);
//gan thong tin nguoi choi vao struct
void highscore_structIn(HighScore x[]);
//so sanh cac phan tu cua struct
void highscoreSort(HighScore x[]);
//tong hop 3 ham phia tren
void hs(string nAme, HighScore x[]);
//ve bang nhap ten nguoi choi can luu diem va luu ten nguoi choi
string getNameforHighScore();
//kiem tra trung ten
bool NameCheck(string naMe, string filename);
//gioi han so ki tu nhap
char* LimInput(const int k);
//http://diendan.congdongcviet.com/threads/t75525::lam-the-nao-de-gioi-han-duoc-so-ki-tu-nhap-vao-trong-chuoi.cpp
