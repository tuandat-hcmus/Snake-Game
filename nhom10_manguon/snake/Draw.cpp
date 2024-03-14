#include "Draw.h"

void gameIntro()
{
	system("cls");
	// --------Ve khung bao quanh tieu de--------------------
	TextColor(0);
	GotoXY(16, 2); cout << (char)201;
	for (int i = 0; i < 85; i++)
		cout << (char)205;
	GotoXY(102, 2); cout << (char)187;
	GotoXY(16, 10); cout << (char)200;
	for (int i = 0; i < 85; i++)
		cout << (char)205;
	GotoXY(102, 10); cout << (char)188;
	//-----------------in tieu de----------------------
	TextColor(3);
	printASCII("Gametitle.txt", 19, 3);
	//-----------------in ten nhom----------------------
	TextColor(4);
	printASCII("team10.txt", 50, 11);
	TextColor(5);
	GotoXY(21, 12);
	for (int i = 0; i < 30; i++)
		cout << (char)196;
	GotoXY(70, 12);
	for (int i = 0; i < 30; i++)
		cout << (char)196;
	//----------------LOADING------------------------------
	GotoXY(57, 16);
	cout << "LOADING";
	TextColor(0);
	GotoXY(40, 17); cout << (char)201;
	for (int i = 0; i < 39; i++)
		cout << (char)205;
	GotoXY(79, 17); cout << (char)187;
	GotoXY(40, 18); cout << (char)186;
	GotoXY(79, 18); cout << (char)186;
	GotoXY(40, 19); cout << (char)200;
	for (int i = 0; i < 39; i++)
		cout << (char)205;
	GotoXY(79, 19); cout << (char)188;
	TextColor(2);
	GotoXY(41, 18);
	for (int i = 0; i < 38; i++) {
		cout << (char)219;
		Sleep(100);
	}
	GotoXY(57, 16);
	for (int i = 0; i < 10; i++) cout << " ";
	GotoXY(41, 18);
	for (int i = 0; i < 38; i++) cout << " ";
	int color = 1;
	while (true) {
		if (color > 16)
		{
			color = 1;
		}
		if (color % 7 == 0 || color % 15 == 0)
		{
			color += 2;
		}
		TextColor(color++);
		GotoXY(45, 18);
		cout << (char)16 << " Press any key to continue " << (char)17;
		Sleep(150);
		if (_kbhit()) {
			char ch = _getch();
			PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
			break;
		}
	}
}

void printASCII(string fileName, int x, int y)
{
	string line = "";
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			GotoXY(x, y++);
			cout << line << endl;
		}
	}
	else
		cout << "File failed to load" << endl;
	inFile.close();
}

void drawBox(int x, int y, int width, int height, string nd)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	if (height <= 1 || width <= 1)
		return;
	for (int ix = x; ix <= x + width; ix++)
	{
		GotoXY(ix, y);
		cout << char(row);
		GotoXY(ix, y + height);
		cout << char(row);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		GotoXY(x, iy);
		cout << char(col);
		GotoXY(x + width, iy);
		cout << char(col);
	}
	GotoXY(x, y); cout << char(topleft);
	GotoXY(x + width, y); cout << char(topright);
	GotoXY(x, y + height); cout << char(botleft);
	GotoXY(x + width, y + height); cout << char(botright);
	GotoXY(x + 6, y + 1);
	cout << nd;
}

void boxstart(int x, int y, int width, int height, string nd, int pos)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	if (height <= 1 || width <= 1)
		return;
	if (pos == 1)
	{
		BackGroundColor(11);
		TextColor(14);
	}

	else
	{
		TextColor(8);
		BackGroundColor(15);

	}
	GotoXY(x, y);		cout << "                     ";
	GotoXY(x, y + 1); 	cout << "        " << nd << "        ";
	GotoXY(x, y + 2);   cout << "                     ";

	for (int ix = x; ix <= x + width; ix++)
	{
		GotoXY(ix, y);
		cout << char(row);
		GotoXY(ix, y + height);
		cout << char(row);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		GotoXY(x, iy);
		cout << char(col);
		GotoXY(x + width, iy);
		cout << char(col);
	}
	GotoXY(x, y); cout << char(topleft);
	GotoXY(x + width, y); cout << char(topright);
	GotoXY(x, y + height); cout << char(botleft);
	GotoXY(x + width, y + height); cout << char(botright);
	TextColor(0);
	BackGroundColor(15);
}

void boxabout(int x, int y, int width, int height, string nd, int pos)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	if (height <= 1 || width <= 1)
		return;
	if (pos == 2)
	{
		BackGroundColor(11);
		TextColor(14);
	}

	else
	{
		TextColor(8);
		BackGroundColor(15);

	}
	GotoXY(x, y);	  cout << "                     ";
	GotoXY(x, y + 1); cout << "        " << nd << "        ";
	GotoXY(x, y + 2); cout << "                     ";

	for (int ix = x; ix <= x + width; ix++)
	{
		GotoXY(ix, y);
		cout << char(row);
		GotoXY(ix, y + height);
		cout << char(row);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		GotoXY(x, iy);
		cout << char(col);
		GotoXY(x + width, iy);
		cout << char(col);
	}
	GotoXY(x, y); cout << char(topleft);
	GotoXY(x + width, y); cout << char(topright);
	GotoXY(x, y + height); cout << char(botleft);
	GotoXY(x + width, y + height); cout << char(botright);
	TextColor(0);
	BackGroundColor(15);
}

void boxhighscore(int x, int y, int width, int height, string nd, int pos)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	if (height <= 1 || width <= 1)
		return;
	if (pos == 3)
	{
		BackGroundColor(11);
		TextColor(14);
	}

	else
	{
		TextColor(8);
		BackGroundColor(15);

	}
	GotoXY(x, y);		cout << "                     ";
	GotoXY(x, y + 1);   cout << "      " << nd << "     ";
	GotoXY(x, y + 2);   cout << "                     ";

	for (int ix = x; ix <= x + width; ix++)
	{
		GotoXY(ix, y);
		cout << char(row);
		GotoXY(ix, y + height);
		cout << char(row);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		GotoXY(x, iy);
		cout << char(col);
		GotoXY(x + width, iy);
		cout << char(col);
	}
	GotoXY(x, y); cout << char(topleft);
	GotoXY(x + width, y); cout << char(topright);
	GotoXY(x, y + height); cout << char(botleft);
	GotoXY(x + width, y + height); cout << char(botright);
	TextColor(0);
	BackGroundColor(15);
}

void boxloadgame(int x, int y, int width, int height, string nd, int pos)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	if (height <= 1 || width <= 1)
		return;
	if (pos == 4)
	{
		BackGroundColor(11);
		TextColor(14);
	}

	else
	{
		TextColor(8);
		BackGroundColor(15);

	}
	GotoXY(x, y);	  cout << "                     ";
	GotoXY(x, y + 1); cout << "      " << nd << "      ";
	GotoXY(x, y + 2); cout << "                     ";

	for (int ix = x; ix <= x + width; ix++)
	{
		GotoXY(ix, y);
		cout << char(row);
		GotoXY(ix, y + height);
		cout << char(row);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		GotoXY(x, iy);
		cout << char(col);
		GotoXY(x + width, iy);
		cout << char(col);
	}
	GotoXY(x, y); cout << char(topleft);
	GotoXY(x + width, y); cout << char(topright);
	GotoXY(x, y + height); cout << char(botleft);
	GotoXY(x + width, y + height); cout << char(botright);
	TextColor(0);
	BackGroundColor(15);
}

void boxhelp(int x, int y, int width, int height, string nd, int pos)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	if (height <= 1 || width <= 1)
		return;
	if (pos == 5)
	{
		BackGroundColor(11);
		TextColor(14);
	}

	else
	{
		TextColor(8);
		BackGroundColor(15);

	}

	GotoXY(x, y);	  cout << "                     ";
	GotoXY(x, y + 1); cout << "        " << nd << "        ";
	GotoXY(x, y + 2); cout << "                     ";

	for (int ix = x; ix <= x + width; ix++)
	{
		GotoXY(ix, y);
		cout << char(row);
		GotoXY(ix, y + height);
		cout << char(row);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		GotoXY(x, iy);
		cout << char(col);
		GotoXY(x + width, iy);
		cout << char(col);
	}
	GotoXY(x, y); cout << char(topleft);
	GotoXY(x + width, y); cout << char(topright);
	GotoXY(x, y + height); cout << char(botleft);
	GotoXY(x + width, y + height); cout << char(botright);
	TextColor(0);
	BackGroundColor(15);
}

void boxexit(int x, int y, int width, int height, string nd, int pos)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	if (height <= 1 || width <= 1)
		return;
	if (pos == 6)
	{
		BackGroundColor(11);
		TextColor(14);
	}

	else
	{
		TextColor(8);
		BackGroundColor(15);

	}
	GotoXY(x, y); cout << "                     ";
	GotoXY(x, y + 1);
	cout << "        " << nd << "        ";
	GotoXY(x, y + 2); cout << "                     ";
	for (int ix = x; ix <= x + width; ix++)
	{
		GotoXY(ix, y);
		cout << char(row);
		GotoXY(ix, y + height);
		cout << char(row);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		GotoXY(x, iy);
		cout << char(col);
		GotoXY(x + width, iy);
		cout << char(col);
	}
	GotoXY(x, y); cout << char(topleft);
	GotoXY(x + width, y); cout << char(topright);
	GotoXY(x, y + height); cout << char(botleft);
	GotoXY(x + width, y + height); cout << char(botright);
	TextColor(0);
	BackGroundColor(15);
}

void DrawGoal()
{
	for (int i = 0; i < 10; i++)
	{
		GotoXY(goal[i].x, goal[i].y);
		cout << char(205);
	}
	GotoXY(goal[10].x, goal[10].y); cout << char(201);
	GotoXY(goal[11].x, goal[11].y); cout << char(186);
	GotoXY(goal[12].x, goal[12].y); cout << char(187);
	GotoXY(goal[13].x, goal[13].y); cout << char(186);
	GotoXY(goal[11].x + 1, goal[12].y + 1); cout << "__________";
}

void DrawFrame(int x, int y)
{
	TextColor(2);
	int row = 223, col = 219, topleft = 219, topright = 219, botleft = 223, botright = 223;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < widthF; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < heightF + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + widthF, i); cout << char(col);
	}

	// bottom
	GotoXY(x, heightF + y); cout << char(botleft);
	for (int i = 1; i < widthF; i++) {
		cout << char(row);
	}
	cout << char(botright);
}

void DrawCountDown(int x, int y)
{
	TextColor(6);
	int maxWidth = 100;
	printASCII("num3.txt", x, y);
	countdownsound1 = 1;
	Sleep(1000);
	for (int i = x; i < maxWidth; i++)
	{
		for (int j = y + 4; j >= y; j--)
		{
			GotoXY(i, j);
			cout << " ";
		}
	}
	printASCII("num2.txt", x, y);
	countdownsound1 = 1;
	Sleep(1000);
	for (int i = x; i < maxWidth; i++)
	{
		for (int j = y + 4; j >= y; j--)
		{
			GotoXY(i, j);
			cout << " ";
		}
	}

	printASCII("num1.txt", x, y);
	countdownsound1 = 1;
	Sleep(1000);
	for (int i = x; i < maxWidth; i++)
	{
		for (int j = y + 4; j >= y; j--)
		{
			GotoXY(i, j);
			cout << " ";
		}
	}
	printASCII("go.txt", x - 5, y);
	countdownsound2 = 1;
	Sleep(1000);
	for (int i = x - 5; i < maxWidth; i++)
	{
		for (int j = y + 7; j >= y; j--)
		{
			GotoXY(i, j);
			cout << " ";
		}
	}
}

void DeleteFrameLevel(int x, int y)
{
	for (int i = x; i < x + widthLevel; i++)
	{
		for (int j = y; j < y + heightLevel; j++)
		{
			GotoXY(i, j); cout << " ";
		}
	}
}

void DrawFrameLevel(int x, int y)
{

	TextColor(10);
	int row = 223, col = 219, topleft = 219, topright = 219, botleft = 223, botright = 223;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < widthLevel; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < heightLevel + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + widthLevel, i); cout << char(col);
	}

	// bottom
	GotoXY(x, heightLevel + y); cout << char(botleft);
	for (int i = 1; i < widthLevel; i++) {
		cout << char(row);
	}
	cout << char(botright);
	printASCII("level1.txt", x + 11, y + 1);

}
void DrawFrameLevel1(int x, int y)
{
	TextColor(10);
	int row = 223, col = 219, topleft = 219, topright = 219, botleft = 223, botright = 223;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < widthLevel; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < heightLevel + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + widthLevel, i); cout << char(col);
	}

	// bottom
	GotoXY(x, heightLevel + y); cout << char(botleft);
	for (int i = 1; i < widthLevel; i++) {
		cout << char(row);
	}
	cout << char(botright);
	printASCII("level2.txt", x + 11, y + 1);
}
void DrawFrameLevel2(int x, int y)
{
	TextColor(10);
	int row = 223, col = 219, topleft = 219, topright = 219, botleft = 223, botright = 223;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < widthLevel; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < heightLevel + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + widthLevel, i); cout << char(col);
	}

	// bottom
	GotoXY(x, heightLevel + y); cout << char(botleft);
	for (int i = 1; i < widthLevel; i++) {
		cout << char(row);
	}
	cout << char(botright);
	printASCII("level3.txt", x + 11, y + 1);
}
void DrawFrameLevel3(int x, int y)
{
	TextColor(10);
	int row = 223, col = 219, topleft = 219, topright = 219, botleft = 223, botright = 223;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < widthLevel; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < heightLevel + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + widthLevel, i); cout << char(col);
	}

	// bottom
	GotoXY(x, heightLevel + y); cout << char(botleft);
	for (int i = 1; i < widthLevel; i++) {
		cout << char(row);
	}
	cout << char(botright);
	printASCII("level4.txt", x + 11, y + 1);
}

void DrawLeftBoard(int x, int y)
{
	TextColor(10);
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < widthL; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < heightL + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + widthL, i); cout << char(col);
	}

	// bottom
	GotoXY(x, heightL + y); cout << char(botleft);
	for (int i = 1; i < widthL; i++) {
		cout << char(row);
	}
	cout << char(botright);

	// midle
	TextColor(0);
	for (int i = 0; i < widthL - 1; i++)
	{
		GotoXY(x + 1 + i, y + 5);
		cout << (char)167;
	}
}

void DrawInfo(int x, int y)
{
	GotoXY(x + 1, y); cout << "SCORE :" << right << setw(7) << SCORE;
	GotoXY(x + 1, y + 1); cout << "LENGTH:" << setw(7) << SIZE_SNAKE;
	GotoXY(x + 1, y + 2); cout << "SPEED :" << setw(7) << SPEED;
	GotoXY(x + 1, y + 3); cout << "FOOD  :" << setw(5) << FOOD_INDEX << "/" << MAX_SIZE_FOOD - 1;
	TextColor(2);
	if (FOOD_INDEX >= 1)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				GotoXY(x + 1 + j, y + 23 - i);
				cout << (char)176;
			}
		}
	}
	if (FOOD_INDEX >= 2)
	{
		for (int i = 5; i < 10; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				GotoXY(x + 1 + j, y + 24 - i);
				cout << (char)177;
			}
		}
	}
	if (FOOD_INDEX >= 3)
	{
		for (int i = 10; i < 15; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				GotoXY(x + 1 + j, y + 24 - i);
				cout << (char)178;
			}
		}
	}
	if (FOOD_INDEX >= 4)
	{
		for (int i = 15; i < 20; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				GotoXY(x + 1 + j, y + 24 - i);
				cout << (char)219;
			}
		}
	}
}

void DrawBoard(int x, int y, int width, int height, int curPosX, int curPosY)
{

	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + width, i); cout << char(col);
	}

	// bottom
	GotoXY(x, height + y); cout << char(botleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(botright);
}

void DrawBoard1(int x, int y, int width, int height, int curPosX, int curPosY)
{
	TextColor(3);
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + width, i); cout << char(col);
	}

	// bottom
	GotoXY(x, height + y); cout << char(botleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(botright);

	TextColor(TEXT_COLOR);
	GotoXY(curPosX, curPosY);
}

void DrawBoard2(int x, int y, int width, int height, int curPosX, int curPosY)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + width, i); cout << char(col);
	}

	// bottom
	GotoXY(x, height + y); cout << char(botleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(botright);

	TextColor(TEXT_COLOR);

	GotoXY(curPosX, curPosY);
}

void DrawBoard3(int x, int y, int width, int height, int curPosX, int curPosY)
{
	int row = 205, col = 186, topleft = 201, topright = 187, botleft = 200, botright = 188;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + width, i); cout << char(col);
	}

	// bottom
	GotoXY(x, height + y); cout << char(botleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(botright);

	TextColor(TEXT_COLOR);

	DrawSmallWall();
	DrawGoal();
	GotoXY(curPosX, curPosY);
}

void DrawWall()
{
	GotoXY(wall[0].x, wall[0].y); cout << (char)188;
	GotoXY(wall[1].x, wall[1].y); cout << (char)200;
	GotoXY(wall[2].x, wall[2].y); cout << (char)187;
	GotoXY(wall[3].x, wall[3].y); cout << (char)201;
	for (int i = 4; i < 36; i++)
	{
		if (i % 2 == 0)
		{
			GotoXY(wall[i].x, wall[i].y);
			cout << (char)205;
		}
		else
		{
			GotoXY(wall[i].x, wall[i].y);
			cout << (char)186;
		}
	}
	for (int i = 36; i < 52; i++)
	{
		GotoXY(wall[i].x, wall[i].y);
		cout << (char)205;
	}
}

void DrawSmallWall()
{
	for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++)
	{
		if (i == 6 || i == 13 || i == 20 || i == 27)
		{
			for (int j = 0; j < 8; j++)
			{
				GotoXY(smallwall[i].x + j, smallwall[i].y);
				cout << char(220);
			}

		}
		else
		{
			for (int j = 0; j < 9; j++)
			{
				GotoXY(smallwall[i].x + j, smallwall[i].y);
				cout << char(220);
			}
		}
	}
}

void DrawBoard_1(int x, int y, int width, int height)
{
	int row = 196, col = 179, topleft = 218, topright = 191, botleft = 192, botright = 217;
	// top
	GotoXY(x, y); cout << char(topleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(topright);

	// left & right
	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i); cout << char(col);
		GotoXY(x + width, i); cout << char(col);
	}

	// bottom
	GotoXY(x, height + y); cout << char(botleft);
	for (int i = 1; i < width; i++) {
		cout << char(row);
	}
	cout << char(botright);
}

void DrawPause()
{
	if (level == 4)
	{
		TextColor(3);
		for (int i = -1; i < 11; i++)
		{
			GotoXY(goal[0].x + i, goal[0].y);
			cout << char(205);
		}
	}
	TextColor(11);

	// print sub table
	GotoXY(cornerX + 10, cornerY + 7); cout << (char)201;
	for (int i = 1; i < 20; i++)
	{
		GotoXY(cornerX + 10 + i, cornerY + 7); cout << (char)205;
	}

	//cout << "GAME PAUSED";
	//top of sub
	for (int i = 0; i < 20; i++)
	{
		GotoXY(cornerX + 41 + i, cornerY + 7); cout << (char)205;
	}
	GotoXY(cornerX + 61, cornerY + 7); cout << (char)187;
	// left and right of sub
	for (int i = 1; i < 10; i++)
	{
		GotoXY(cornerX + 10, cornerY + 7 + i); cout << (char)186;
		GotoXY(cornerX + 61, cornerY + 7 + i); cout << (char)186;
	}
	// bot of sub
	for (int i = 1; i < 51; i++)
	{
		GotoXY(cornerX + 10 + i, cornerY + 17); cout << (char)205;
	}

	GotoXY(cornerX + 10, cornerY + 17); cout << (char)200;
	GotoXY(cornerX + 61, cornerY + 17); cout << (char)188;
	TextColor(10);
	GotoXY(cornerX + 14, cornerY + 15); cout << "CONTINUE";
	GotoXY(cornerX + 13, cornerY + 16); cout << "[PRESS P]";
	TextColor(13);
	GotoXY(cornerX + 52, cornerY + 15); cout << "STOP";
	GotoXY(cornerX + 50, cornerY + 16); cout << "[PRESS S]";

	TextColor(9);
	printASCII("pause.txt", cornerX + 20, cornerY + 3);
	TextColor(TEXT_COLOR);
	// print heart
	for (int i = 1; i < 5; i++)
	{
		GotoXY(cornerX + 32, cornerY + 9 + i); cout << (char)3;
	}
	for (int i = 1; i < 6; i++)
	{
		GotoXY(cornerX + 32 + i, cornerY + 9 + i); cout << (char)3;
		GotoXY(cornerX + 32 + i, cornerY + 14 - i); cout << (char)3;
	}
	for (int i = 0; i < 8; i++)
	{
		GotoXY(cornerX + 38, cornerY + 8 + i); cout << (char)3;
	}
	GotoXY(0, 0);
}

void ClearBoard()
{
	for (int i = cornerX + 1; i < cornerX + WIDTH_CONSOLE; i++)
	{
		for (int j = cornerY + 1; j < cornerY + HEIGH_CONSOLE; j++)
		{
			GotoXY(i, j); cout << " ";
		}
	}
	TextColor(3);
	TextColor(TEXT_COLOR);
}

void ClearPause()
{
	for (int i = cornerX + 1; i < cornerX + WIDTH_CONSOLE; i++)
	{
		for (int j = cornerY + 1; j < cornerY + HEIGH_CONSOLE; j++)
		{
			GotoXY(i, j); cout << " ";
		}
	}
	TextColor(3);
	if (level == 2)
	{
		DrawBoard1(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE);
		DrawWall();
	}
	if (level == 4)
	{
		DrawBoard3(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE);
	}
	TextColor(TEXT_COLOR);
}

void ResultBoard()
{
	TextColor(4);
	GotoXY(cornerX + 10, cornerY + 7); cout << (char)201;
	for (int i = 1; i < 51; i++)
	{
		GotoXY(cornerX + 10 + i, cornerY + 7); cout << (char)205;
	}
	GotoXY(cornerX + 61, cornerY + 7); cout << (char)187;
	for (int i = 1; i < 10; i++)
	{
		GotoXY(cornerX + 10, cornerY + 7 + i); cout << (char)186;
		GotoXY(cornerX + 61, cornerY + 7 + i); cout << (char)186;
	}
	GotoXY(cornerX + 10, cornerY + 17); cout << (char)200;
	GotoXY(cornerX + 61, cornerY + 17); cout << (char)188;
	for (int i = 1; i < 51; i++)
	{
		GotoXY(cornerX + 10 + i, cornerY + 17); cout << (char)205;
	}
}

void Result()
{
	TextColor(4);
	DrawBoard(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE);
	TextColor(6);
	DrawBoard(cornerX + 20, cornerY + 5, WIDTH_CONSOLE / 2 - 4, HEIGH_CONSOLE / 2 + 2);
	TextColor(12);


	printASCII("result.txt", cornerX + 23, cornerY + 3);

	GotoXY(cornerX + 31, cornerY + 8); cout << "USER INFO";
	GotoXY(cornerX + 31, cornerY + 9); cout << "^^^^^^^^^";
	GotoXY(cornerX + 15, cornerY + 18); cout << "EXIT";
	GotoXY(cornerX + 13, cornerY + 19); cout << "[PRESS E]";
	GotoXY(cornerX + 52, cornerY + 18); cout << "SAVE";
	GotoXY(cornerX + 50, cornerY + 19); cout << "[PRESS S]";
	TextColor(0);
	GotoXY(cornerX + 26, cornerY + 10); cout << "Level        :";
	GotoXY(cornerX + 26, cornerY + 12); cout << "Score        :";
	GotoXY(cornerX + 26, cornerY + 14); cout << "Snake's Size :";
	GotoXY(cornerX + 26, cornerY + 16); cout << "Snake's Speed:";
	TextColor(0);
	GotoXY(cornerX + 42, cornerY + 10); cout << level;
	GotoXY(cornerX + 42, cornerY + 12); cout << SCORE;
	GotoXY(cornerX + 42, cornerY + 14); cout << SIZE_SNAKE_1;
	GotoXY(cornerX + 42, cornerY + 16); cout << SPEED;
}

void ClearSave()
{
	TextColor(4);
	for (int i = cornerX + 1; i < cornerX + WIDTH_CONSOLE; i++)
	{
		for (int j = cornerY + 1; j < cornerY + 21; j++)
		{
			GotoXY(i, j); cout << " ";
		}
	}
	DrawBoard(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE);
}

void SaveBoard()
{
	ClearSave();
	TextColor(9);
	printASCII("savegame.txt", cornerX + 6, cornerY + 2);
	TextColor(0);
	GotoXY(cornerX + 44, cornerY + 7); cout << (char)201;
	GotoXY(cornerX + 69, cornerY + 7); cout << (char)187;
	GotoXY(cornerX + 44, cornerY + 17); cout << (char)200;
	GotoXY(cornerX + 69, cornerY + 17); cout << (char)188;
	for (int i = 1; i < 25; i++)
	{
		GotoXY(cornerX + 44 + i, cornerY + 7); cout << (char)205;
		GotoXY(cornerX + 44 + i, cornerY + 17); cout << (char)205;
	}
	for (int i = 1; i < 10; i++)
	{
		GotoXY(cornerX + 44, cornerY + 7 + i); cout << (char)186;
		GotoXY(cornerX + 69, cornerY + 7 + i); cout << (char)186;
	}
	GotoXY(cornerX + 46, cornerY + 9); cout << "	     ONLY";
	GotoXY(cornerX + 46, cornerY + 10); cout << "alphanumeric characters";
	GotoXY(cornerX + 46, cornerY + 12); cout << "      A - Z (a - z)   ";
	GotoXY(cornerX + 46, cornerY + 14); cout << "	     0-9     ";
	GotoXY(cornerX + 46, cornerY + 16); cout << "[At most 10 characters]";
	GotoXY(cornerX + 15, cornerY + 9); cout << "Enter your name: ";
	GotoXY(cornerX + 10, cornerY + 12); cout << "=>";
	GotoXY(cornerX + 16, cornerY + 12);

	do {
		GotoXY(cornerX + 16, cornerY + 12); cout << "          ";
		GotoXY(cornerX + 16, cornerY + 12);
		cin.clear();
		name = LimInput(MAX_NAME);
	} while (NameCheck(name, "SaveInf.txt"));

	for (int i = cornerX + 6; i < cornerX + 6 + 60; i++)
	{
		for (int j = cornerY + 2; j < cornerY + 2 + 5; j++)
		{
			GotoXY(i, j); cout << " ";
		}

	}
	TextColor(11);
	printASCII("saved.txt", cornerX + 20, cornerY + 2);
	TextColor(0);
	GotoXY(cornerX + 10, cornerY + 12); cout << "Press ANY KEY to  back to MENU";
	char xx = _getch();
}
