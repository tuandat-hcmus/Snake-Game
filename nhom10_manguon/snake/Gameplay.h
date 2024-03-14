#pragma once
#include "Common.h"
#include "Globalvariable.h"
#include "Draw.h"
#include "Snake.h"
#include "Obj.h"
#include "Sound.h"


//khoi tao cac bien can thiet cho level 1
void ResetData();
//khoi tao cac bien can thiet cho level 2
void ResetData1();
//khoi tao cac bien can thiet cho level 3
void ResetData2();
//khoi tao cac bien can thiet cho level 4
void ResetData3();
//reset lai mot so bien can thiet khi hoan thanh 4 level lap lai tu dau
void ResetGlobal();
//khoi tao lai toa do cua tuong sau khi hoan thanh level 2 ra khoi khung game
void ResetWall();
//khoi tao toa do cua cong xuat hien khi hoan thanh level
void GateInit();
//khoi tao toa do cua tuong (level 2)
void WallInit();
//khoi tao toa do cho vat the (level 3)
void ObjectInit();
//khoi tao toa do cho vat the o level 4
void BallInit();
//khoi tao toa do cho khung thanh o level 4
void GoalInit();
//khoi tao toa do cho cac tuong nho o level 4
void SmallWallInit();
//khoi tao lai toa do cua vat the o level 3 khi qua level 4 ra khoi khung game
void ResetObject();
//khoi tao lai toa do cua food o level 4 ra khoi khung game
void ResetFood();

//bat dau level 1
void StartGame();
//bat dau level 2
void StartGame1();
//bat dau level 3
void StartGame2();
//bat dau level 4
void StartGame3();
//ve cong sau khi hoan thanh level
void DrawGate();

//khoi tao ran khi bat dau level tiep theo
void GetOut();
//ve cong cho ran chui ra khi bat dau level
void GateOut();
//va lai lo hong khi ran chui ra
void Fix();

//tam dung game
void PauseGame(HANDLE t);

//Thread
void ThreadFunc();