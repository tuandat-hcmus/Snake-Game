#pragma once
#include "Globalvariable.h"
#include "Common.h"
#include "Draw.h"
#include "Gameplay.h"

//luu cac thong so vao file Save.txt
void Save();
//tai cac thong so tu file Save.txt vao chuong trinh
void LoadFile(int n);
//luu thong tin nguoi choi vao fie SaveInf.txt
void SaveInf(char* nAme);
//tai so man choi nguoi choi chon choi tiep
void LvLoad(int n);
//ve menu chon man choi tiep
int DrawLoadBoard(int cornerX, int cornerY, int width, int height);
//ve thong tin nguoi choi da luu
void DrawSaveInf(int start, int end, int space);
//chay chuong trinh choi tiep
void LoadGame(int n);
//xoa cac thong tin da viet trong file
void clearfile(string filename);

