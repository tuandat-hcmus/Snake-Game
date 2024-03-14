//contains foods, walls, objs
#pragma once
#include "System.h"
#include "Snake.h"

//food

//kiem tra toa do cua food co trung voi toa do cua ran hay khong
bool IsValid(int x, int y);
//kiem tra toa do cua food co trung voi toa do cua ran va tuong (level 2) hay khong
bool IsValid1(int x, int y);
//kiem tra toa do cua super food (level 3) co trung voi food hay khong
bool IsSuperValid(int x, int y);
//khoi tao toa do cua food
void GenerateFood();
//khoi tao toa do cua food (level 2)
void GenerateFood1();
//khoi tao toa do cua super food (level 3)
void GenerateSuperFood();
//thao tac khi ran an superfood undying
void Undying();
//thao tac khi ran an superfood stoptime
void StopTime();
//co che in superfood va an superfood
void SuperFood();

//obj

//co che di chuyen cua vat the 1 ki tu, dau vao la trang thai cua vat the va thu tu cua vat the
void SingleObject(int& n, int i);
//co che di chuyen cua vat the 2 ki tu
void DoubleObject();
//co che di chuyen va tach ra cua vat the
void Object();
//thao tac khi ran cham vao vat the
void HitObject();

//ball, wall, obj lv4

//co che cua vat the o level 4
void Ball();
//xoa tuong nho khi vat the tiep xuc
void SmallWallHitted();
//ran chet khi cham vao tuong nho
void HitSmallWall();
//thao tac khi vat the di vao khung thanh
void GoalGoalGoal();
//thay doi do dai va score sau khi pha tuong nho
void BreakLength();
//cong them 1 do dai va 1 score khi pha tuong nho
void BreakWall();

//va loi hien thi tuong khi choi tiep lv4
void DelWall();
