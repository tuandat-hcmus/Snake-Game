#pragma once
#include "Globalvariable.h"
#include "System.h"
#include "Gameplay.h"

//ve ran va food moi sau moi vong lap
void DrawSnakeAndFood(char* str);
//xoa ran cu sau moi vong lap
void DrawSnake(char* str);
//thay doi cac bien can thiet khi ran an food
void Eat();
//ran nhap nhay khi chet
void Dead(char* str);
//xet cac dieu kien can thiet va cap nhat vi tri cho ran khi di chuyen sang phai
void MoveRight();
//xet cac dieu kien can thiet va cap nhat vi tri cho ran khi di chuyen sang trai
void MoveLeft();
//xet cac dieu kien can thiet va cap nhat vi tri cho ran khi di chuyen xuong duoi
void MoveDown();
//xet cac dieu kien can thiet va cap nhat vi tri cho ran khi di chuyen len tren
void MoveUp();
//khung game nhap nhay khi ran di qua cong
void GoThrough();
//cac thao tac sau khi an du food
void Process();
//cac thao tac khi ran chet
void ProcessDead();
//kiem tra ran da chui vao cong hay chua
bool GetIn();