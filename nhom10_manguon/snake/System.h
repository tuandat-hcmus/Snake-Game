#pragma once
#include "Common.h"

//an con tro nhay
void Nocursortype();
// vo hieu hoa chon man hinh console
void DisableSelection();
//dieu chinh kich thuoc cua cua so console
void FixConsoleWindow();
//dua con tro toi vi tri co toa do x y
void GotoXY(int x, int y);
//dieu chinh mau sac cua background
void BackGroundColor(WORD color);
//dieu chinh mau sac cua ki tu
void TextColor(WORD color);
