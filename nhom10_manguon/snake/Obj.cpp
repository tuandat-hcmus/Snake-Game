#include "Obj.h"

bool IsValid(int x, int y)
{
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == x && snake[i].y == y)
		{
			return false;
		}
	}
	return true;
}

bool IsValid1(int x, int y)
{
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == x && snake[i].y == y)
		{
			return false;
		}
	}
	for (int i = 0; i < SIZE_WALL; i++)
	{
		if (wall[i].x == x && wall[i].y == y)
		{
			return false;
		}
	}
	return true;
}

bool IsSuperValid(int x, int y)
{
	for (int i = 0; i < MAX_SIZE_FOOD; i++)
	{
		if (food[i].x == x && food[i].y == y)
		{
			return false;
		}
	}
	return true;
}

void GenerateFood()
{
	int x, y;
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE_FOOD - 1; i++) {
		do {
			x = rand() % (WIDTH_CONSOLE - 2) + (cornerX + 2);
			y = rand() % (HEIGH_CONSOLE - 2) + (cornerY + 2);
		} while (IsValid(x, y) == false);
		food[i] = { x,y };
	}
}

void GenerateFood1()
{
	int x, y;
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE_FOOD; i++) {
		do {
			x = rand() % (WIDTH_CONSOLE - 2) + (cornerX + 2);
			y = rand() % (HEIGH_CONSOLE - 2) + (cornerY + 2);
		} while (IsValid1(x, y) == false);
		food[i] = { x,y };
	}
}

void GenerateSuperFood()
{
	int x, y;
	srand(time(NULL));
	for (int i = 0; i < MAX_SUPER_FOOD; i++) {
		do {
			x = rand() % (WIDTH_CONSOLE - 2) + (cornerX + 2);
			y = rand() % (HEIGH_CONSOLE - 2) + (cornerY + 2);
		} while (IsSuperValid(x, y) == false);
		superfood[i] = { x,y };
	}
}

void Undying()
{
	supercount1++;
	if (supercount1 == 40)
	{
		undying = 0;
		supercount1 = 0;
	}
}

void StopTime()
{
	supercount++;
	if (supercount == 40)
	{
		stoptime = 0;
		supercount = 0;
	}
}

void SuperFood()
{

	for (int i = 0; i < MAX_SUPER_FOOD; i++)
	{
		int is_eated = 0;
		for (int j = 0; j < eated; j++)
		{
			if (i == superfood_eated[j])
			{
				is_eated = 1;
				break;
			}
		}
		if (is_eated == 1)
		{
			continue;
		}
		if (i == MAX_SUPER_FOOD - 1)
		{
			TextColor(4);
		}
		else
		{
			TextColor(5);
		}
		GotoXY(superfood[i].x, superfood[i].y);
		cout << char(254);
	}
	TextColor(TEXT_COLOR);
	for (int i = 0; i < MAX_SUPER_FOOD; i++)
	{
		int repeated = 0;
		if (snake[SIZE_SNAKE - 1].x == superfood[i].x && snake[SIZE_SNAKE - 1].y == superfood[i].y)
		{
			for (int j = 0; j < eated; j++)
			{
				if (i == superfood_eated[j])
				{
					repeated = 1;
					break;
				}
			}
			if (repeated == 1)
			{
				continue;
			}
			if (i == 4)
			{
				undying = 1;
			}
			else
			{
				stoptime = 1;
				supercount = 0;
			}
			superfood_eated[eated] = i;
			eated++;
			sUperfood1 = 1;
			GotoXY(superfood[i].x, superfood[i].y);
			cout << " ";
		}
	}
}

void SingleObject(int& n, int i)
{
	GotoXY(object[i].x, object[i].y);
	cout << " ";
	if (object[i].y - 1 == cornerY)
	{
		if (n == 4 || n == -3)
		{
			n = 1;
		}
		else
		{
			n = -1;
		}
	}
	if (object[i].x + 1 == cornerX + WIDTH_CONSOLE)
	{
		if (n == 1 || n == -2)
		{
			n = 2;
		}
		else
		{
			n = -4;
		}
	}
	if (object[i].y + 1 == cornerY + HEIGH_CONSOLE)
	{
		if (n == 2 || n == -1)
		{
			n = 3;
		}
		else
		{
			n = -3;
		}
	}
	if (object[i].x - 1 == cornerX)
	{
		if (n == 3 || n == -4)
		{
			n = 4;
		}
		else
		{
			n = -2;
		}
	}
	switch (n)
	{
	case 1:
		object[i].x++;
		object[i].y++;
		break;
	case 2:
		object[i].x--;
		object[i].y++;
		break;
	case 3:
		object[i].x--;
		object[i].y--;
		break;
	case 4:
		object[i].x++;
		object[i].y--;
		break;
	case -4:
		object[i].x--;
		object[i].y--;
		break;
	case -1:
		object[i].x--;
		object[i].y++;
		break;
	case -2:
		object[i].x++;
		object[i].y++;
		break;
	case -3:
		object[i].x++;
		object[i].y--;
		break;
	default:
		break;
	}
	TextColor(11);
	GotoXY(object[i].x, object[i].y);
	cout << (char)219;
	TextColor(TEXT_COLOR);
}

void DoubleObject()
{
	for (int i = 2; i < 4; i++)
	{
		GotoXY(object[i].x, object[i].y);
		cout << " ";
	}
	if (object[2].y - 1 == cornerY)
	{
		if (object_state2 == 4 || object_state2 == -3)
		{
			object_state2 = 1;
		}
		else
		{
			object_state2 = -1;
		}
	}
	if (object[2].x + 2 == cornerX + WIDTH_CONSOLE)
	{
		if (object_state2 == 1 || object_state2 == -2)
		{
			object_state2 = 2;
		}
		else
		{
			object_state2 = -4;
		}
	}
	if (object[2].y + 1 == cornerY + HEIGH_CONSOLE)
	{
		if (object_state2 == 2 || object_state2 == -1)
		{
			object_state2 = 3;
		}
		else
		{
			object_state2 = -3;
		}
	}
	if (object[2].x - 1 == cornerX)
	{
		if (object_state2 == 3 || object_state2 == -4)
		{
			object_state2 = 4;
		}
		else
		{
			object_state2 = -2;
		}
	}
	switch (object_state2)
	{
	case 1:
		for (int i = 2; i < 4; i++)
		{
			object[i].x++;
			object[i].y++;
		}
		break;
	case 2:
		for (int i = 2; i < 4; i++)
		{
			object[i].x--;
			object[i].y++;
		}
		break;
	case 3:
		for (int i = 2; i < 4; i++)
		{
			object[i].x--;
			object[i].y--;
		}
		break;
	case 4:
		for (int i = 2; i < 4; i++)
		{
			object[i].x++;
			object[i].y--;
		}
		break;
	case -4:
		for (int i = 2; i < 4; i++)
		{
			object[i].x--;
			object[i].y--;
		}
		break;
	case -1:
		for (int i = 2; i < 4; i++)
		{
			object[i].x--;
			object[i].y++;
		}
		break;
	case -2:
		for (int i = 2; i < 4; i++)
		{
			object[i].x++;
			object[i].y++;
		}
		break;
	case -3:
		for (int i = 2; i < 4; i++)
		{
			object[i].x++;
			object[i].y--;
		}
		break;
	default:
		break;
	}
	TextColor(11);
	for (int i = 2; i < 4; i++)
	{
		GotoXY(object[i].x, object[i].y);
		cout << (char)219;
	}
}

void Object()
{
	int n = 4;
	if (FOOD_INDEX >= 2 && FOOD_INDEX <= 3)
	{
		n = 2;
	}
	if (FOOD_INDEX == 4)
	{
		n = 1;
	}
	for (int i = 0; i < n; i++)
	{
		GotoXY(object[i].x, object[i].y);
		cout << " ";
	}
	if (object[0].y - 1 == cornerY)
	{
		if (object_state == 4 || object_state == -3)
		{
			object_state = 1;
		}
		else
		{
			object_state = -1;
		}
	}
	if (object[0].x + 2 == cornerX + WIDTH_CONSOLE)
	{
		if (object_state == 1 || object_state == -2)
		{
			object_state = 2;
		}
		else
		{
			object_state = -4;
		}
	}
	if (object[0].y + 2 == cornerY + HEIGH_CONSOLE)
	{
		if (object_state == 2 || object_state == -1)
		{
			object_state = 3;
		}
		else
		{
			object_state = -3;
		}
	}
	if (object[0].x - 1 == cornerX)
	{
		if (object_state == 3 || object_state == -4)
		{
			object_state = 4;
		}
		else
		{
			object_state = -2;
		}
	}
	switch (object_state)
	{
	case 1:
		for (int i = 0; i < n; i++)
		{
			object[i].x++;
			object[i].y++;
		}
		break;
	case 2:
		for (int i = 0; i < n; i++)
		{
			object[i].x--;
			object[i].y++;
		}
		break;
	case 3:
		for (int i = 0; i < n; i++)
		{
			object[i].x--;
			object[i].y--;
		}
		break;
	case 4:
		for (int i = 0; i < n; i++)
		{
			object[i].x++;
			object[i].y--;
		}
		break;
	case -4:
		for (int i = 0; i < n; i++)
		{
			object[i].x--;
			object[i].y--;
		}
		break;
	case -1:
		for (int i = 0; i < n; i++)
		{
			object[i].x--;
			object[i].y++;
		}
		break;
	case -2:
		for (int i = 0; i < n; i++)
		{
			object[i].x++;
			object[i].y++;
		}
		break;
	case -3:
		for (int i = 0; i < n; i++)
		{
			object[i].x++;
			object[i].y--;
		}
		break;
	default:
		break;
	}
	TextColor(11);
	for (int i = 0; i < n; i++)
	{
		GotoXY(object[i].x, object[i].y);
		cout << (char)219;
	}
	TextColor(TEXT_COLOR);
	if (FOOD_INDEX >= 2 && FOOD_INDEX <= 3)
	{
		if (object_fix == 0)
		{
			object_state2 = -object_state;
			object_fix = 1;
		}
		DoubleObject();
	}
	if (FOOD_INDEX == 4)
	{
		if (object_fix1 == 0)
		{
			object_state3 = -object_state2;
			object_state1 = -object_state;
			object_fix1 = 1;
		}
		SingleObject(object_state3, 3);
		SingleObject(object_state2, 2);
		SingleObject(object_state1, 1);
	}
}

void HitObject()
{
	int dead = 0;
	if (!undying)
	{
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (snake[i].x == object[j].x && snake[i].y == object[j].y)
				{
					ProcessDead();
					dead = 1;
					break;
				}
			}
			if (dead == 1)
			{
				break;
			}
		}
	}
}

void Ball()
{
	for (int i = 0; i < 2; i++)
	{
		GotoXY(ball[i].x, ball[i].y);
		cout << " ";
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if ((ball[0].y - 1 == snake[i].y && ball[0].x == snake[i].x) || (ball[1].y - 1 == snake[i].y && ball[1].x == snake[i].x))
		{
			if (ball_state == 4 || ball_state == -3)
			{
				ball_state = 1;
			}
			else
			{
				ball_state = -1;
			}
			break;
		}
	}
	for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++)
	{
		int hitted = 0;
		for (int k = 0; k < smallwall_hitted_idx; k++)
		{
			if (smallwall_hitted[k] == i)
			{
				hitted = 1;
				break;
			}
		}
		if (hitted == 1)
		{
			continue;
		}
		for (int j = 0; j < 10; j++)
		{
			if ((ball[0].y - 1 == smallwall[i].y && ball[0].x == smallwall[i].x + j) || (ball[1].y - 1 == smallwall[i].y && ball[1].x == smallwall[i].x + j))
			{
				if (ball_state == 4 || ball_state == -3)
				{
					ball_state = 1;
				}
				else
				{
					ball_state = -1;
				}
				smallwall_hitted[smallwall_hitted_idx++] = i;
				break;
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if ((ball[i].x == goal[11].x && ball[i].y - 1 == goal[11].y) || (ball[i].x == goal[13].x && ball[i].y - 1 == goal[13].y))
		{
			if (ball_state == 4 || ball_state == -3)
			{
				ball_state = 1;
			}
			else
			{
				ball_state = -1;
			}
			break;
		}
	}
	if (ball[0].y - 1 == cornerY)
	{
		if (ball_state == 4 || ball_state == -3)
		{
			ball_state = 1;
		}
		else
		{
			ball_state = -1;
		}
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (ball[0].x + 2 == snake[i].x && ball[0].y == snake[i].y)
		{
			if (ball_state == 1 || ball_state == -2)
			{
				ball_state = 2;
			}
			else
			{
				ball_state = -4;
			}
			break;
		}
	}
	for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++)
	{
		int hitted = 0;
		for (int k = 0; k < smallwall_hitted_idx; k++)
		{
			if (smallwall_hitted[k] == i)
			{
				hitted = 1;
				break;
			}
		}
		if (hitted == 1)
		{
			continue;
		}
		if (ball[0].x + 2 == smallwall[i].x && ball[0].y == smallwall[i].y)
		{
			if (ball_state == 1 || ball_state == -2)
			{
				ball_state = 2;
			}
			else
			{
				ball_state = -4;
			}
			smallwall_hitted[smallwall_hitted_idx++] = i;
		}
	}
	if (ball[0].x + 2 == cornerX + WIDTH_CONSOLE)
	{
		if (ball_state == 1 || ball_state == -2)
		{
			ball_state = 2;
		}
		else
		{
			ball_state = -4;
		}
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if ((ball[0].y + 1 == snake[i].y && ball[0].x == snake[i].x) || (ball[1].y + 1 == snake[i].y && ball[1].x == snake[i].x))
		{
			if (ball_state == 2 || ball_state == -1)
			{
				ball_state = 3;
			}
			else
			{
				ball_state = -3;
			}
			break;
		}
	}
	for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++)
	{
		int hitted = 0;
		for (int k = 0; k < smallwall_hitted_idx; k++)
		{
			if (smallwall_hitted[k] == i)
			{
				hitted = 1;
				break;
			}
		}
		if (hitted == 1)
		{
			continue;
		}
		for (int j = 0; j < 10; j++)
		{
			if ((ball[0].y + 1 == smallwall[i].y && ball[0].x == smallwall[i].x + j) || (ball[1].y + 1 == smallwall[i].y && ball[1].x == smallwall[i].x + j))
			{
				if (ball_state == 2 || ball_state == -1)
				{
					ball_state = 3;
				}
				else
				{
					ball_state = -3;
				}
				smallwall_hitted[smallwall_hitted_idx++] = i;
				break;
			}
		}
	}
	if (ball[0].y + 1 == cornerY + HEIGH_CONSOLE)
	{
		if (ball_state == 2 || ball_state == -1)
		{
			ball_state = 3;
		}
		else
		{
			ball_state = -3;
		}
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (ball[0].x - 1 == snake[i].x && ball[0].y == snake[i].y)
		{
			if (ball_state == 3 || ball_state == -4)
			{
				ball_state = 4;
			}
			else
			{
				ball_state = -2;
			}
			break;
		}
	}
	for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++)
	{
		int hitted = 0;
		for (int k = 0; k < smallwall_hitted_idx; k++)
		{
			if (smallwall_hitted[k] == i)
			{
				hitted = 1;
				break;
			}
		}
		if (hitted == 1)
		{
			continue;
		}
		if (ball[0].x - 1 == smallwall[i].x && ball[0].y == smallwall[i].y)
		{
			if (ball_state == 3 || ball_state == -4)
			{
				ball_state = 4;
			}
			else
			{
				ball_state = -2;
			}
			smallwall_hitted[smallwall_hitted_idx++] = i;
		}
	}
	if (ball[0].x - 1 == cornerX)
	{
		if (ball_state == 3 || ball_state == -4)
		{
			ball_state = 4;
		}
		else
		{
			ball_state = -2;
		}
	}
	if (ball[1].x + 1 == goal[11].x && ball[1].y == goal[11].y)
	{
		ball_state = 2;
	}
	if (ball[0].x - 1 == goal[13].x && ball[0].y == goal[13].y)
	{
		ball_state = 1;
	}
	switch (ball_state)
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			ball[i].x++;
			ball[i].y++;
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			ball[i].x--;
			ball[i].y++;
		}
		break;
	case 3:
		for (int i = 0; i < 2; i++)
		{
			ball[i].x--;
			ball[i].y--;
		}
		break;
	case 4:
		for (int i = 0; i < 2; i++)
		{
			ball[i].x++;
			ball[i].y--;
		}
		break;
	case -4:
		for (int i = 0; i < 2; i++)
		{
			ball[i].x--;
			ball[i].y--;
		}
		break;
	case -1:
		for (int i = 0; i < 2; i++)
		{
			ball[i].x--;
			ball[i].y++;
		}
		break;
	case -2:
		for (int i = 0; i < 2; i++)
		{
			ball[i].x++;
			ball[i].y++;
		}
		break;
	case -3:
		for (int i = 0; i < 2; i++)
		{
			ball[i].x++;
			ball[i].y--;
		}
		break;
	default:
		break;
	}
	TextColor(11);
	for (int i = 0; i < 2; i++)
	{
		GotoXY(ball[i].x, ball[i].y);
		cout << (char)219;
	}
	TextColor(TEXT_COLOR);
}

void SmallWallHitted()
{
	for (int i = 0; i < smallwall_hitted_idx; i++)
	{
		GotoXY(smallwall[smallwall_hitted[i]].x, smallwall[smallwall_hitted[i]].y);
		if (smallwall_hitted[i] == 6 || smallwall_hitted[i] == 13 || smallwall_hitted[i] == 20 || smallwall_hitted[i] == 27)
		{
			cout << "        ";
		}
		else
		{
			cout << "         ";
		}
	}
}

void HitSmallWall()
{
	for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++)
	{
		int hitted = 0;
		for (int k = 0; k < smallwall_hitted_idx; k++)
		{
			if (i == smallwall_hitted[k])
			{
				hitted = 1;
				break;
			}
		}
		if (hitted == 1)
		{
			continue;
		}
		for (int j = 0; j < 10; j++)
		{
			if (snake[SIZE_SNAKE - 1].x == smallwall[i].x + j && snake[SIZE_SNAKE - 1].y == smallwall[i].y)
			{
				ProcessDead();
				break;
			}
		}
	}
	if ((snake[SIZE_SNAKE - 1].x == goal[11].x && snake[SIZE_SNAKE - 1].y == goal[11].y) || (snake[SIZE_SNAKE - 1].x == goal[13].x && snake[SIZE_SNAKE - 1].y == goal[13].y))
	{
		ProcessDead();
	}
	for (int i = 1; i < 11; i++)
	{
		if (snake[SIZE_SNAKE - 1].x == goal[11].x + i && snake[SIZE_SNAKE - 1].y == goal[11].y)
		{
			ProcessDead();
			break;
		}
	}
}

void GoalGoalGoal()
{
	if (goalgoalgoal == 0)
	{
		for (int i = 0; i < 11; i++)
		{
			if (ball[0].x == goal[i].x && ball[0].y - 1 == goal[i].y)
			{
				goalSound = 1;
				GotoXY(ball[0].x, ball[0].y);
				cout << "  ";
				goalgoalgoal = 1;
				for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++)
				{
					GotoXY(smallwall[i].x, smallwall[i].y);
					if (i == 6 || i == 13 || i == 20 || i == 27)
					{
						cout << "        ";
					}
					else
					{
						cout << "         ";
					}
				}
				break;
			}
		}
	}
	if (goal_celebration < 15 && goalgoalgoal == 1)
	{
		if (goal_celebration % 2 == 0)
		{
			TextColor(4);
			DrawGoal();
			TextColor(TEXT_COLOR);
			goal_celebration++;
		}
		else
		{
			DrawGoal();
			goal_celebration++;
		}
	}
	if (goal_celebration == 15 && goalgoalgoal == 1)
	{
		TextColor(3);
		for (int i = 0; i < 10; i++)
		{
			GotoXY(goal[i].x, goal[i].y);
			cout << char(205);
		}
		GotoXY(goal[10].x, goal[10].y); cout << char(205);
		GotoXY(goal[11].x, goal[11].y); cout << "            ";
		GotoXY(goal[12].x, goal[12].y); cout << char(205);
		TextColor(TEXT_COLOR);
		GATE = 1;
		goal_celebration++;
	}
}

void BreakLength()
{
	if (length_break < smallwall_hitted_idx)
	{
		BreakWall();
		length_break++;
	}
}

void BreakWall()
{
	switch (MOVING)
	{
	case 'A':
		snake[SIZE_SNAKE] = { snake[SIZE_SNAKE - 1].x - 1, snake[SIZE_SNAKE - 1].y };
		SIZE_SNAKE++;
		SIZE_SNAKE_1++;
		SCORE++;
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x--;
		break;
	case 'W':
		snake[SIZE_SNAKE] = { snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y - 1 };
		SIZE_SNAKE++;
		SIZE_SNAKE_1++;
		SCORE++;
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y--;
		break;
	case 'D':
		snake[SIZE_SNAKE] = { snake[SIZE_SNAKE - 1].x + 1, snake[SIZE_SNAKE - 1].y };
		SIZE_SNAKE++;
		SIZE_SNAKE_1++;
		SCORE++;
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x++;
		break;
	case 'S':
		snake[SIZE_SNAKE] = { snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y + 1 };
		SIZE_SNAKE++;
		SIZE_SNAKE_1++;
		SCORE++;
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y++;
		break;
	default:
		break;
	}
}

void DelWall() {
	for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++)
	{
		GotoXY(smallwall[i].x, smallwall[i].y);
		if (i == 6 || i == 13 || i == 20 || i == 27)
		{
			cout << "        ";
		}
		else
		{
			cout << "         ";
		}
	}
	TextColor(3);
	for (int i = 0; i < 10; i++)
	{
		GotoXY(goal[i].x, goal[i].y);
		cout << char(205);
	}
	GotoXY(goal[10].x, goal[10].y); cout << char(205);
	GotoXY(goal[11].x, goal[11].y); cout << "            ";
	GotoXY(goal[12].x, goal[12].y); cout << char(205);
	TextColor(TEXT_COLOR);
}
