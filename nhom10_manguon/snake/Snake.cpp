#include "Snake.h"

void DrawSnakeAndFood(char* str) {
	if (GATE == 0 && level != 4)
	{
		TextColor(2);
		int x = 254;
		GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
		cout << (char)x;
		TextColor(TEXT_COLOR);
	}
	int m = SIZE_SNAKE_1;
	int n = m - SIZE_SNAKE;
	TextColor(TEXT_COLOR);
	for (int i = SIZE_SNAKE - 1; i >= 0; i--) {
		if (n == 0)
		{
			TextColor(5);
		}
		if (undying)
		{
			if (colorundying % 7 == 0 || colorundying % 15 == 0)
			{
				colorundying += 2;
			}
			TextColor(colorundying++);
		}
		if (n == 40)
		{
			n = 0;
		}
		GotoXY(snake[i].x, snake[i].y);
		cout << *(str + n++);
		TextColor(TEXT_COLOR);
	}
}

void DrawSnake(char* str) {
	for (int i = SIZE_SNAKE - 1; i >= 0; i--) {
		GotoXY(snake[i].x, snake[i].y);
		cout << str;
	}
}

void Eat()
{
	eAt = 1;
	snake[SIZE_SNAKE] = food[FOOD_INDEX];
	if (FOOD_INDEX == MAX_SIZE_FOOD - 2)
	{
		FOOD_INDEX++;
		GATE = 1;
		SCORE++;
	}
	else {
		FOOD_INDEX++;
		SIZE_SNAKE++;
		SIZE_SNAKE_1++;
		SCORE++;
	}
}

void Dead(char* str)
{
	for (int i = 0; i < 5; i++)
	{
		int m = SIZE_SNAKE_1;
		int n = m - SIZE_SNAKE;
		TextColor(12);
		GotoXY(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y);
		cout << (char)35;
		n++;
		for (int j = SIZE_SNAKE - 2; j >= 0; j--) {
			GotoXY(snake[j].x, snake[j].y);
			cout << *(str + n++);
		}
		Sleep(250);
		TextColor(TEXT_COLOR);
		for (int j = SIZE_SNAKE - 1; j >= 0; j--) {
			GotoXY(snake[j].x, snake[j].y);
			cout << " ";
		}
		Sleep(250);
	}
	TextColor(TEXT_COLOR);
}

void MoveRight() {
	if (GATE == 1)
	{
		for (int i = 1; i < 5; i++)
		{
			if (snake[SIZE_SNAKE - 1].x == gate[i].x && snake[SIZE_SNAKE - 1].y == gate[i].y)
			{
				ProcessDead();
				return;
			}
		}
	}
	for (int i = 0; i < SIZE_WALL; i++)
	{
		if (snake[SIZE_SNAKE - 1].x == wall[i].x && snake[SIZE_SNAKE - 1].y == wall[i].y)
		{
			ProcessDead();
			return;
		}
	}
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[SIZE_SNAKE - 1].x + 1 == snake[i].x && snake[SIZE_SNAKE - 1].y == snake[i].y)
		{
			ProcessDead();
		}
	}
	if ((snake[SIZE_SNAKE - 1].x == WIDTH_CONSOLE + cornerX) && snake[SIZE_SNAKE - 1].y != gate[0].y) {
		ProcessDead();
	}
	else {
		if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) {
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x++;
	}
}

void MoveLeft() {
	if (GATE == 1)
	{
		for (int i = 1; i < 5; i++)
		{
			if (snake[SIZE_SNAKE - 1].x == gate[i].x && snake[SIZE_SNAKE - 1].y == gate[i].y)
			{
				ProcessDead();
				return;
			}
		}
	}
	for (int i = 0; i < SIZE_WALL; i++)
	{
		if (snake[SIZE_SNAKE - 1].x == wall[i].x && snake[SIZE_SNAKE - 1].y == wall[i].y)
		{
			ProcessDead();
			return;
		}
	}
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[SIZE_SNAKE - 1].x - 1 == snake[i].x && snake[SIZE_SNAKE - 1].y == snake[i].y)
		{
			ProcessDead();
		}
	}
	if (snake[SIZE_SNAKE - 1].x == cornerX && snake[SIZE_SNAKE - 1].y != gate[0].y) {
		ProcessDead();
	}
	else {
		if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) {
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x--;
	}
}

void MoveDown() {
	if (GATE == 1)
	{
		for (int i = 1; i < 5; i++)
		{
			if (snake[SIZE_SNAKE - 1].y == gate[i].y && snake[SIZE_SNAKE - 1].x == gate[i].x)
			{
				ProcessDead();
				return;
			}
		}
	}
	for (int i = 0; i < SIZE_WALL; i++)
	{
		if (snake[SIZE_SNAKE - 1].y == wall[i].y && snake[SIZE_SNAKE - 1].x == wall[i].x)
		{
			ProcessDead();
			return;
		}
	}
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[SIZE_SNAKE - 1].x == snake[i].x && snake[SIZE_SNAKE - 1].y + 1 == snake[i].y)
		{
			ProcessDead();
		}
	}
	if (snake[SIZE_SNAKE - 1].y == HEIGH_CONSOLE + cornerY && snake[SIZE_SNAKE - 1].x != gate[0].x) {
		ProcessDead();
	}
	else {
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y) {
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y++;
	}
}

void MoveUp() {
	if (GATE == 1)
	{
		for (int i = 1; i < 5; i++)
		{
			if (snake[SIZE_SNAKE - 1].y == gate[i].y && snake[SIZE_SNAKE - 1].x == gate[i].x)
			{
				ProcessDead();
				return;
			}
		}
	}
	for (int i = 0; i < SIZE_WALL; i++)
	{
		if (snake[SIZE_SNAKE - 1].y == wall[i].y && snake[SIZE_SNAKE - 1].x == wall[i].x)
		{
			ProcessDead();
			return;
		}
	}
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if (snake[SIZE_SNAKE - 1].x == snake[i].x && snake[SIZE_SNAKE - 1].y - 1 == snake[i].y)
		{
			ProcessDead();
		}
	}
	if (snake[SIZE_SNAKE - 1].y == cornerY && snake[SIZE_SNAKE - 1].x != gate[0].x) {
		ProcessDead();
	}
	else {
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y) {
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y--;
	}
}

void GoThrough()
{
	TextColor(boardcolor[colorboard++]);
	DrawBoard(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE);
	DrawGate();
	if (colorboard == 4)
	{
		colorboard = 0;
	}
	TextColor(TEXT_COLOR);
}

void Process()
{
	if (GATE == 1)
	{
		DrawGate();
		if (GetIn())
		{
			GoThrough();
			SIZE_SNAKE--;
			if (level == 3)
			{
				stoptime = 1;
				undying = 0;
			}
		}
		if (SIZE_SNAKE == 0)
		{
			if (level == 1)
			{
				StartGame1();
			}
			else if (level == 2)
			{
				StartGame2();
			}
			else if (level == 3)
			{
				StartGame3();
			}
			else
			{
				play_again++;
				int scOre = SCORE;
				ResetGlobal();
				StartGame();
				SCORE = scOre;
			}
		}
	}
}

void ProcessDead()
{
	STATE = 0;
	dIe = 1;
	Dead(mssv);
}

bool GetIn()
{
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == gate[0].x && snake[i].y == gate[0].y)
		{
			nextlv = 1;
			return true;
		}
	}
	return false;
}
