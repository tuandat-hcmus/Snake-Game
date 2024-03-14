#include "Menu.h"

void MenuGame()
{
	save_load = 0;
	menuOn = 1;
	int n = 0;
	while (1) {
		if (menuOn) {
			n = Menu();
			menuOn = 0;
			LoadGame(n);
		}
		if (!menuOn) break;
	}
}

int Menu()
{
	system("cls");

	int position = 1;
	int keyPressed = 0;

	int spaceBox = 3;
	int Xbox = 49, Ybox = 10;
	int wBox = 20, hBox = 2;

	string file = "menu.txt";

	while (true)
	{
		TextColor(3);
		BackGroundColor(15);
		printASCII(file, 13, 0);

		boxstart(Xbox, Ybox, wBox, hBox, "START", position);

		boxabout(Xbox, Ybox += spaceBox, wBox, hBox, "ABOUT", position);

		boxhighscore(Xbox, Ybox += spaceBox, wBox, hBox, "HIGH SCORE", position);

		boxloadgame(Xbox, Ybox += spaceBox, wBox, hBox, "LOAD GAME", position);


		boxhelp(Xbox, Ybox += spaceBox, wBox, hBox, "HELP", position);


		boxexit(Xbox, Ybox += spaceBox, wBox, hBox, "EXIT", position);

		Ybox = 10;

		keyPressed = _getch();

		if (keyPressed == 115)
		{
			if (position == Max)
			{
				position = Min;
			}
			else
			{
				position++;
			}
		}
		else if (keyPressed == 119)
		{
			if (position == Min)
			{
				position = Max;
			}
			else
			{
				position--;
			}
		}



		if (keyPressed == 32)
		{
			PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
			switch (position)
			{
			case 1: //new game
				return 0;
			case 2:
				About();
				break;
			case 3:
				DrawScoreBoard(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE);
				break;
			case 4: // continue
				return 1;
			case 5:
				Help();
				break;
			case 6:
				Exit();
				break;
			}
		}
	}
	return -1;
}

void About()
{
	system("cls");
	TextColor(4);
	printASCII("introduction.txt", 25, 2);
	int disX = 20;
	TextColor(0);
	for (int i = disX; i < disX + 83; i++)
	{
		GotoXY(i, 10); cout << char(196);
	}
	GotoXY(disX + 30, 10);
	cout << " PROJECT HUNTING SNAKE ";
	int y = 13;
	GotoXY(disX, y++);
	cout << "UNIVERSITY OF SCIENCE - HCMUS";
	GotoXY(disX, y++);
	cout << "Faculty  	Information Technology";
	GotoXY(disX, y++);
	cout << "Course   	Programming Techniques";
	GotoXY(disX, y++);
	cout << "Lecturer 	Truong Toan Thinh";
	GotoXY(disX, 17);
	cout << "Class       21CTT4";

	y = 13;
	int disX2 = disX + 60;

	GotoXY(disX2, y++);
	cout << "21120430 - NGO TUAN DAT";
	GotoXY(disX2, y++);
	cout << "21120410 - NGUYEN TUAN ANH";
	GotoXY(disX2, y++);
	cout << "21120442 - TRAN DANG DUY";
	GotoXY(disX2, y++);
	cout << "21120495 - PHAM THI MY LE";
	GotoXY(disX2, y++);
	cout << "21120426 - HUYNH PHAT DAT";

	TextColor(8);
	GotoXY(disX + 25, 20);
	cout << "Press ANY KEY to  back to MENU";
	int press = _getch();
	PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
	system("cls");
}

void Help()
{
	system("cls");
	TextColor(12);
	BackGroundColor(11);

	int disX = 17, disY = 11;
	GotoXY(disX + 10, disY++); cout << "  DIRECT SNAKE  ";
	GotoXY(disX + 35, disY++); cout << "                 ";
	GotoXY(disX + 35, disY++); cout << "   'W'      " << char(30) << "    ";
	GotoXY(disX + 35, disY++); cout << "   'S'      " << char(31) << "    ";
	GotoXY(disX + 35, disY++); cout << "   'A'      " << char(17) << "    ";
	GotoXY(disX + 35, disY++); cout << "   'D'      " << char(16) << "    ";
	GotoXY(disX + 35, disY++); cout << "   'P'    Pause" << "  ";
	GotoXY(disX + 35, disY++); cout << "   'E'    Exit" << "   ";
	GotoXY(disX + 35, disY++); cout << "                 ";
	TextColor(0);
	BackGroundColor(15);
	disY += 2;
	GotoXY(disX + 10, disY++); cout << char(4) << " Help the snake eat enough food to pass each level!";
	GotoXY(disX + 10, disY++); cout << char(4) << " Eat 4 foods and go through the gate of each level to move to next level.";
	GotoXY(disX + 10, disY++); cout << char(4) << " When you passed 4 level, the game will start again from level 1.";
	GotoXY(disX + 10, disY++); cout << "  the speed of the snake will increase 1 index " << endl;
	GotoXY(disX + 10, disY++); cout << "  and the length of the snake will be unchanged. " << endl;
	GotoXY(disX + 10, disY++); cout << char(4) << " Remember, DO NOT let the snake hit the walls or bite itself.";
	TextColor(8);
	GotoXY(disX + 10, disY++); cout << "		      Press ANY KEY to back to MENU ";
	TextColor(12);
	printASCII("help.txt", 48, 3);

	for (int i = disX; i < disX + 83; i++)
	{
		GotoXY(i, 9); cout << char(196);
	}
	GotoXY(disX + 33, 9);
	cout << " PROJECT HUNTING SNAKE ";

	int press = _getch();
	PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
	system("cls");
}

void Exit()
{
	system("cls");
	int color = 0;
	while (color < 7)
	{
		TextColor(color++);
		printASCII("goodbye.txt", 30, 4);

		TextColor(12);
		GotoXY(47, 23);

		TextColor(4);
		GotoXY(45, 12); cout << "THANKS FOR PLAYING OUR SNAKE GAME";
		GotoXY(45, 13); cout << "   HOPE YOU ENJOY THE GAME";
		GotoXY(45, 14); cout << " GOODBYE AND SEE YOU LATER!!!";
		TextColor(0);
		for (int i = 40; i < 80; i++)
		{
			GotoXY(i, 17); cout << char(196);
		}
		Sleep(100);
	}
	Sleep(1000);
	system("cls");
	exit(0);
}