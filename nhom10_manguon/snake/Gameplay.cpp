#include "Gameplay.h"

void ResetData()
{
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1; FOOD_INDEX = 0, WIDTH_CONSOLE = 71, HEIGH_CONSOLE = 20, SIZE_SNAKE = 0;
	GATE = 0;
	SCORE = 0;
	SIZE_SNAKE_1 = 6;
	GenerateFood();
	GateInit();
	out[0] = { cornerX, 10 + cornerY };
	out[1].x = gate[0].x;
	out[1].y = gate[0].y;
	flag = 0;
	outgate = 0;
	colorboard = 0;
	level = 1;
	fix = 1;
	fixcount = 0;
	SPEED = play_again;
}

void ResetData1()
{
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1; FOOD_INDEX = 0, WIDTH_CONSOLE = 71, HEIGH_CONSOLE = 20, SIZE_SNAKE = 0;
	GATE = 0;
	WallInit();
	GenerateFood1();
	GateInit();
	out[0] = { cornerX,10 + cornerY };
	flag = 0;
	outgate = 0;
	fix = 1;
	colorboard = 0;
	level = 2;
	fixcount = 0;
	SPEED = play_again;
}

void ResetData2()
{
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1; FOOD_INDEX = 0, WIDTH_CONSOLE = 71, HEIGH_CONSOLE = 20, SIZE_SNAKE = 0;
	GATE = 0;
	GenerateFood();
	GateInit();
	out[0] = { cornerX,10 + cornerY };
	flag = 0;
	outgate = 0;
	fix = 1;
	colorboard = 0;
	level = 3;
	fixcount = 0;
	ObjectInit();
	object_state = 4;
	ResetWall();
	object_state1 = 4;
	object_state2 = 1;
	object_state3 = 1;
	GenerateSuperFood();
	SPEED = play_again;
}

void ResetData3()
{
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1; FOOD_INDEX = 4, WIDTH_CONSOLE = 71, HEIGH_CONSOLE = 20, SIZE_SNAKE = 0;
	GATE = 0;
	BallInit();
	SmallWallInit();
	GoalInit();
	ResetObject();
	ResetFood();
	GateInit();
	out[0] = { cornerX,10 + cornerY };
	flag = 0;
	outgate = 0;
	fix = 1;
	colorboard = 0;
	level = 4;
	fixcount = 0;
	SPEED = play_again;
	ball_state = 1;
}

void ResetGlobal()
{
	eated = 0;
	stoptime = 0;
	supercount = 0;
	undying = 0;
	supercount1 = 0;
	object_fix = 0;
	object_fix1 = 0;
	smallwall_hitted_idx = 0;
	goalgoalgoal = 0;
	length_break = 0;
	Old_smallwall_hitted_idx = 0;
	goal_celebration = 0;
	ResetWall();
}

void ResetWall()
{
	for (int i = 0; i < SIZE_WALL; i++)
	{
		wall[i] = { i,0 };
	}
}

void GateInit()
{
	int x, y;
	srand(time(NULL));
	x = rand() % 2;
	if (x == 0)
	{
		x = rand() % (WIDTH_CONSOLE - 1) + 1 + cornerX;
		y = rand() % 2;
		if (y == 0) // top
		{
			y = cornerY;
			gate[0] = { x, y };
			gate[1] = { x + 1, y };
			gate[2] = { x - 1, y };
			gate[3] = { x + 1, y + 1 };
			gate[4] = { x - 1, y + 1 };
		}
		else // bottom
		{
			y = HEIGH_CONSOLE + cornerY;
			gate[0] = { x, y };
			gate[1] = { x + 1, y };
			gate[2] = { x - 1, y };
			gate[3] = { x + 1, y - 1 };
			gate[4] = { x - 1, y - 1 };
		}
	}
	else
	{
		y = rand() % (HEIGH_CONSOLE - 1) + 1 + cornerY;
		x = rand() % 2;
		if (x == 0) // left
		{
			x = cornerX;
			gate[0] = { x, y };
			gate[1] = { x, y + 1 };
			gate[2] = { x, y - 1 };
			gate[3] = { x + 1, y + 1 };
			gate[4] = { x + 1, y - 1 };
		}
		else // right
		{
			x = WIDTH_CONSOLE + cornerX;
			gate[0] = { x, y };
			gate[1] = { x, y + 1 };
			gate[2] = { x, y - 1 };
			gate[3] = { x - 1, y + 1 };
			gate[4] = { x - 1, y - 1 };
		}
	}
}

void WallInit()
{
	int n = 1;
	wall[0] = { WIDTH_CONSOLE / 2 + 28, HEIGH_CONSOLE / 2 + 3 };
	wall[n++] = { wall[0].x + 5, wall[0].y };
	wall[n++] = { wall[0].x, wall[0].y + 5 };
	wall[n++] = { wall[0].x + 5, wall[0].y + 5 };
	for (int i = 1; i < 5; i++)
	{
		//top left
		wall[n++] = { wall[0].x - i, wall[0].y };
		wall[n++] = { wall[0].x, wall[0].y - i };
		//top right
		wall[n++] = { wall[0].x + 5 + i, wall[0].y };
		wall[n++] = { wall[0].x + 5, wall[0].y - i };
		//bottom left
		wall[n++] = { wall[0].x - i, wall[0].y + 5 };
		wall[n++] = { wall[0].x, wall[0].y + 5 + i };
		//bottom right
		wall[n++] = { wall[0].x + 5 + i, wall[0].y + 5 };
		wall[n++] = { wall[0].x + 5, wall[0].y + 5 + i };
	}
	for (int i = 0; i < 4; i++)
	{
		wall[n++] = { wall[0].x - 5 - i, wall[0].y };
		wall[n++] = { wall[0].x + 10 + i, wall[0].y };
		wall[n++] = { wall[0].x - 5 - i, wall[0].y + 5 };
		wall[n++] = { wall[0].x + 10 + i, wall[0].y + 5 };
	}
}

void ObjectInit()
{
	object[0] = { cornerX + WIDTH_CONSOLE / 2, cornerY + 1 };
	object[1] = { cornerX + WIDTH_CONSOLE / 2 + 1, cornerY + 1 };
	object[2] = { cornerX + WIDTH_CONSOLE / 2, cornerY + 2 };
	object[3] = { cornerX + WIDTH_CONSOLE / 2 + 1, cornerY + 2 };
}

void BallInit()
{
	ball[0] = { cornerX + 40, cornerY + 10 };
	ball[1] = { cornerX + 41, cornerY + 10 };
}

void GoalInit()
{
	for (int i = 0; i < 10; i++)
	{
		goal[i] = { cornerX + 30 + i, cornerY };
	}
	goal[10] = { goal[0].x - 1, goal[0].y };
	goal[11] = { goal[0].x - 1, goal[0].y + 1 };
	goal[12] = { goal[9].x + 1, goal[9].y };
	goal[13] = { goal[9].x + 1, goal[9].y + 1 };
}

void SmallWallInit()
{
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			smallwall[idx++] = { cornerX + 2 + 10 * j, cornerY + 2 + i };
		}
	}
}

void ResetObject()
{
	for (int i = 0; i < 4; i++)
	{
		object[i] = { 1 + i, 0 };
	}
}

void ResetFood()
{
	for (int i = 0; i < MAX_SIZE_FOOD; i++)
	{
		food[i] = { 1 + i, 0 };
	}
}

void StartGame() {
	system("cls");
	ResetData(); // Intialize original data
	DrawFrame(corFx, corFy);
	DrawLeftBoard(corLx, corLy);
	DeleteFrameLevel(corLevelx, corLevely);
	DrawFrameLevel(corLevelx, corLevely);
	TextColor(3);
	DrawBoard(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE); // Draw game
	STATE = 1;//Start running Thread
}
void StartGame1() {
	system("cls");
	ResetData1(); // Intialize original data
	DeleteFrameLevel(corLevelx, corLevely);
	DrawFrame(corFx, corFy);
	DeleteFrameLevel(corLevelx, corLevely);
	DrawFrameLevel1(corLevelx, corLevely);
	DrawLeftBoard(corLx, corLy);
	TextColor(3);
	DrawBoard1(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE); // Draw game
	DrawWall();
	STATE = 1;//Start running Thread
}
void StartGame2() {
	system("cls");
	ResetData2(); // Intialize original data	DrawFrame(corFx, corFy);
	DrawFrame(corFx, corFy);
	DeleteFrameLevel(corLevelx, corLevely);
	DrawFrameLevel2(corLevelx, corLevely);
	DrawLeftBoard(corLx, corLy);
	TextColor(3);
	DrawBoard(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE); // Draw game
	STATE = 1;//Start running Thread
}
void StartGame3() {
	system("cls");
	ResetData3(); // Intialize original data
	DeleteFrameLevel(corLevelx, corLevely);
	DrawFrame(corFx, corFy);
	DeleteFrameLevel(corLevelx, corLevely);
	DrawFrameLevel3(corLevelx, corLevely);
	DrawLeftBoard(corLx, corLy);
	TextColor(3);
	DrawBoard3(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE); // Draw game
	STATE = 1;
}

void DrawGate()
{
	if (gate[0].x == cornerX)
	{
		TextColor(3);
		GotoXY(gate[0].x, gate[0].y);
		cout << "O";
		TextColor(4);
		GotoXY(gate[1].x, gate[1].y);
		cout << char(200);
		GotoXY(gate[2].x, gate[2].y);
		cout << char(201);
		GotoXY(gate[3].x, gate[3].y);
		cout << char(185);
		GotoXY(gate[4].x, gate[4].y);
		cout << char(185);
		TextColor(TEXT_COLOR);
	}
	else if (gate[0].x == WIDTH_CONSOLE + cornerX)
	{
		TextColor(3);
		GotoXY(gate[0].x, gate[0].y);
		cout << "O";
		TextColor(4);
		GotoXY(gate[1].x, gate[1].y);
		cout << char(188);
		GotoXY(gate[2].x, gate[2].y);
		cout << char(187);
		GotoXY(gate[3].x, gate[3].y);
		cout << char(204);
		GotoXY(gate[4].x, gate[4].y);
		cout << char(204);
		TextColor(TEXT_COLOR);
	}
	else if (gate[0].y == cornerY)
	{
		TextColor(3);
		GotoXY(gate[0].x, gate[0].y);
		cout << "O";
		TextColor(4);
		GotoXY(gate[1].x, gate[1].y);
		cout << char(187);
		GotoXY(gate[2].x, gate[2].y);
		cout << char(201);
		GotoXY(gate[3].x, gate[3].y);
		cout << char(202);
		GotoXY(gate[4].x, gate[4].y);
		cout << char(202);
		TextColor(TEXT_COLOR);
	}
	else
	{
		TextColor(3);
		GotoXY(gate[0].x, gate[0].y);
		cout << "O";
		TextColor(4);
		GotoXY(gate[0].x, gate[0].y);
		GotoXY(gate[1].x, gate[1].y);
		cout << char(188);
		GotoXY(gate[2].x, gate[2].y);
		cout << char(200);
		GotoXY(gate[3].x, gate[3].y);
		cout << char(203);
		GotoXY(gate[4].x, gate[4].y);
		cout << char(203);
		TextColor(TEXT_COLOR);
	}
}

void GetOut()
{
	while (SIZE_SNAKE < SIZE_SNAKE_1)
	{
		snake[SIZE_SNAKE] = out[0];
		SIZE_SNAKE++;
	}
}

void GateOut()
{
	if (outgate < SIZE_SNAKE_1)
	{
		TextColor(5);
		GotoXY(out[0].x, out[0].y + 1); cout << char(175);
		GotoXY(out[0].x, out[0].y - 1); cout << char(175);
		TextColor(3);
		GotoXY(out[0].x, out[0].y); cout << '0';
		outgate++;
		TextColor(TEXT_COLOR);
		if (outgate == SIZE_SNAKE_1)
		{
			TextColor(3);
			GotoXY(out[0].x, out[0].y + 1); cout << (char)186;
			GotoXY(out[0].x, out[0].y - 1); cout << (char)186;
			GotoXY(out[0].x, out[0].y); cout << (char)186;
			TextColor(TEXT_COLOR);
			if (fix == 1)
			{
				fix = 0;
			}
		}
	}
}

void Fix()
{
	TextColor(3);
	GotoXY(out[0].x, out[0].y); cout << (char)186;
	TextColor(TEXT_COLOR);
}

void PauseGame(HANDLE t)
{
	SuspendThread(t);
	TextColor(3);
	ClearBoard();
	TextColor(3);
	if (GATE == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			GotoXY(gate[i].x, gate[i].y);
			if (gate[0].x == cornerX || gate[0].x == cornerX + WIDTH_CONSOLE)
			{
				cout << char(186);
			}
			else
			{
				cout << char(205);
			}
		}
	}
	TextColor(TEXT_COLOR);
	DrawPause();
	int temp;
	while (true)
	{
		temp = toupper(_getch());
		if (temp == 'P')
		{
			ClearPause();
			ResumeThread(t);
			break;
		}
		else if (temp == 'S')
		{
			STATE = 0;
			ClearBoard();
			Result();
			int temp2;
			while (1) {
				temp2 = toupper(_getch());
				if (temp2 == 'S') {
					save_load = 1;
					Save();
					SaveBoard();
					SaveInf(name);
					break;
				}
				else if (temp2 == 'E') {
					save_load = 1;
					break;
				}
			}
			break;
		}
		else
		{
			continue;
		}
	}
}

void ThreadFunc() {
	while (1) {
		if (STATE == 1) {//If my snake is alive
			if (flag == 0)
			{
				GetOut();
				flag = 1;
			}
			char ch[] = " ";
			DrawSnake(ch);
			switch (MOVING) {
			case 'A':
				MoveLeft();
				Process();
				break;
			case 'D':
				MoveRight();
				Process();
				break;
			case 'W':
				MoveUp();
				Process();
				break;
			case 'S':
				MoveDown();
				Process();
				break;
			}
			DrawInfo(corLx, corLy + 1);
			if (level == 3)
			{
				HitObject();
				SuperFood();
				if (undying)
				{
					Undying();
				}
				if (stoptime)
				{
					StopTime();
				}
				else
				{
					Object();
				}
			}
			if (level == 4)
			{
				if (goalgoalgoal == 0)
				{
					HitSmallWall();
					SmallWallHitted();
					Ball();
					hittedcheck();
					BreakLength();
				}
				GoalGoalGoal();
			}
			DrawSnakeAndFood(mssv);
			GateOut();
			if (fix == 0 && fixcount < SIZE_SNAKE_1 + 2)
			{
				Fix();
				fixcount++;
			}
			Sleep(100 / SPEED);
			if (STATE == 0) {
				ClearBoard();
				Result();
			}
		}
	}
}
