#include "SaveLoad.h"

void Save() {
	fstream file;
	file.open("Save.txt", ios_base::in | ios_base::out);

	file.seekg(0, ios_base::end);
	file << setw(800) << " ";
	file.seekg(-800, ios_base::cur);

	//level
	file << level << " ";
	//score
	file << SCORE << " ";
	// snake
	file << SIZE_SNAKE << " " << SIZE_SNAKE_1 << " ";
	for (int i = SIZE_SNAKE - 1; i >= 0; i--) {
		file << snake[i].x << " " << snake[i].y << " ";
	}
	// food
	file << FOOD_INDEX << " ";
	for (int i = 0; i < MAX_SIZE_FOOD - 1; i++) {
		file << food[i].x << " " << food[i].y << " ";
	}
	// gate
	for (int i = 0; i < 5; i++) {
		file << gate[i].x << " " << gate[i].y << " ";
	}
	file << GATE << " ";
	// moving
	file << MOVING << " " << CHAR_LOCK << " ";
	// speed
	file << SPEED << " ";
	// sth else
	file << flag << " " << outgate << " " << fix << " " << fixcount << " " << play_again << " ";
	// lv 3
	if (level == 3) {
		// object
		for (int i = 0; i < 4; i++) {
			file << object[i].x << " " << object[i].y << " ";
		}
		// sth else
		file << object_state << " "
			<< object_state1 << " "
			<< object_state2 << " "
			<< object_state3 << " "
			<< eated << " "
			<< stoptime << " "
			<< supercount << " "
			<< undying << " "
			<< supercount1 << " "
			<< object_fix << " "
			<< object_fix1 << " ";
		for (int i = 0; i < MAX_SUPER_FOOD; i++) {
			file << superfood_eated[i] << " ";
		}
		for (int i = 0; i < 5; i++) {
			file << superfood[i].x << " " << superfood[i].y << " ";
		}
	}
	//lv 4
	else if (level == 4) {
		//ball
		for (int i = 0; i < 2; i++) {
			file << ball[i].x << " " << ball[i].y << " ";
		}

		file << ball_state << " ";
		//smallwall_hitted
		for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++) {
			file << smallwall_hitted[i] << " ";
		}
		//smallwall_hitted_idx & goalgoalgoal & length_break
		file << smallwall_hitted_idx << " " << goalgoalgoal << " " << length_break;
	}

	file.seekg(0, ios_base::end);
	file << "\n";

	file.close();
}

void LoadFile(int n) {
	int distance = n * 802;
	ifstream filein;
	filein.open("Save.txt", ios_base::in);
	filein.seekg(-distance, ios_base::end);
	filein.seekg(1, ios_base::cur);

	filein >> SCORE >> SIZE_SNAKE >> SIZE_SNAKE_1;

	for (int i = SIZE_SNAKE - 1; i >= 0; i--) {
		filein >> snake[i].x >> snake[i].y;
	}
	filein >> FOOD_INDEX;
	for (int i = 0; i < MAX_SIZE_FOOD - 1; i++) {
		filein >> food[i].x >> food[i].y;
	}
	for (int i = 0; i < 5; i++) {
		filein >> gate[i].x >> gate[i].y;
	}
	filein >> GATE >> MOVING >> CHAR_LOCK >> SPEED
		>> flag >> outgate >> fix >> fixcount >> play_again;
	if (level == 3) {
		for (int i = 0; i < 4; i++) {
			filein >> object[i].x >> object[i].y;
		}
		filein >> object_state
			>> object_state1
			>> object_state2
			>> object_state3
			>> eated
			>> stoptime
			>> supercount
			>> undying
			>> supercount1
			>> object_fix
			>> object_fix1;
		for (int i = 0; i < MAX_SUPER_FOOD; i++) {
			filein >> superfood_eated[i];
		}
		for (int i = 0; i < 5; i++) {
			filein >> superfood[i].x >> superfood[i].y;
		}
	}
	else if (level == 4) {
		for (int i = 0; i < 2; i++) {
			filein >> ball[i].x >> ball[i].y;
		}
		filein >> ball_state;

		for (int i = 0; i < MAX_SIZE_SMALL_WALL; i++) {
			filein >> smallwall_hitted[i];
		}

		filein >> smallwall_hitted_idx >> goalgoalgoal >> length_break;
	}
	filein.close();
}

void SaveInf(char* nAme) {
	fstream file;
	file.open("SaveInf.txt", ios_base::in | ios_base::out);
	file.seekg(0, ios_base::end);

	file << setw(11) << left << nAme;
	file << setw(3) << left << level;
	file << setw(5) << left << SCORE;

	time_t now = time(0);
	tm* ltm = localtime(&now);

	file << setw(2) << right << ltm->tm_mday << setw(1) << "/";
	file << setw(2) << right << 1 + ltm->tm_mon << setw(1) << "/";
	file << setw(5) << left << 1900 + ltm->tm_year << "\n";

	// 30 byte/line (+ \n = 32)
	file.close();
}

void LvLoad(int n) {
	ifstream file;
	int distance = n * 802;
	int lV;
	file.open("Save.txt", ios_base::in | ios_base::out);
	file.seekg(-distance, ios_base::end);
	file >> lV;
	level = lV;
	file.close();
}

int DrawLoadBoard(int cornerX, int cornerY, int width, int height) {
	system("cls");

	fstream file;
	file.open("SaveInf.txt", ios_base::in | ios_base::out);

	int nLine = 0;
	file.seekg(0, ios_base::end);
	nLine = file.tellg();
	nLine = nLine / 32;

	if (nLine == 0) {
		DrawBoard(cornerX, cornerY, width, height);
		printASCII("load.txt", cornerX + 25, cornerY - 5);
		printASCII("messageLoad.txt", 2, 2);
		GotoXY(60, 14); cout << "Nothing here :(";
		GotoXY(55, 15); cout << "Press ESC to  back to MENU";
		file.close();
		return -1;
	}
	GotoXY(cornerX + 9, cornerY + 2);
	int space = width / 4 + 2;
	GotoXY(cornerX + 7, cornerY + 2);
	TextColor(6);
	cout << setw(space) << left << "Name" << setw(space - 2) << left << "Lv" << setw(space - 1) << left << "Score" << setw(space + 100) << left << "Date";
	GotoXY(cornerX + 3, cornerY + 4);

	if (nLine < 15) {
		DrawSaveInf(0, nLine, space);
	}
	else {
		DrawSaveInf(0, 15, space);
	}

	TextColor(0);
	DrawBoard(cornerX, cornerY, width, height);

	int c = 0;
	int space1 = width / 4 + 1;
	DrawBoard(cornerX, cornerY, width, 3);
	do
	{
		c += space1;
		DrawBoard(cornerX + c, cornerY, space1, height);

	} while (c < WIDTH_CONSOLE / 3);

	GotoXY(cornerX, cornerY + 3); cout << char(204);
	GotoXY(cornerX + width, cornerY + 3); cout << char(185);

	c = 1;
	int d = 0;
	while (c <= 3)
	{
		GotoXY(cornerX + c * space1, cornerY); cout << char(203);
		GotoXY(cornerX + c * space1, cornerY + 3); cout << char(206);
		GotoXY(cornerX + c * space1, cornerY + height); cout << char(202);
		c++;
	}
	//menu-----------------
	int i = 1;
	int x = cornerX + 2, y = cornerY + 5, xp = x, yp = y;
	int oldX = 0, oldY = 0;
	bool k = true;
	int mau = 1;

	printASCII("load.txt", cornerX + 25, cornerY - 5);
	printASCII("messageLoad.txt", 2, 2);

	while (1) {
		if (k) {
			GotoXY(oldX, oldY); cout << "  ";
			GotoXY(xp, yp); cout << ">>";
			oldX = xp; oldY = yp;
			k = false;
		}
		if (_kbhit()) {
			char ch = toupper(_getch());
			k = true;
			// draw "LOAD" and "message.txt" with color
			if (mau > 16)
			{
				mau = 1;
			}
			if (mau % 7 == 0 || mau % 15 == 0)
			{
				mau += 2;
			}
			TextColor(mau++);
			printASCII("load.txt", cornerX + 25, cornerY - 5);
			printASCII("messageLoad.txt", 2, 2);
			TextColor(TEXT_COLOR);
			if (ch == 27)
			{
				menuOn = 1;
				return 0;
			}
			else if (ch == 'Q') {
				PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
				clearfile("Save.txt");
				clearfile("SaveInf.txt");
				menuOn = 1;
				return 0;
			}
			if (ch == 'W') {
				if (yp != y) {
					yp--;
					i--;
				}
				else if (i > 1) {
					i--;
					DrawSaveInf(i - 1, i + 14, space);
				}
			}
			else if (ch == 'S') {
				if (nLine < 15) {
					if (yp != nLine - 1 + y) {
						yp++;
						i++;
					}
					else if (i < nLine) {
						i++;
						DrawSaveInf(i - 15, i, space);
					}
				}
				else {
					if (yp != 14 + y) {
						yp++;
						i++;
					}
					else if (i < nLine) {
						i++;
						DrawSaveInf(i - 15, i, space);
					}
				}
			}
			if (ch == 32) {
				PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
				return i;
			}
		}
	}
	return -1;
}

void DrawSaveInf(int start, int end, int space) {
	fstream file;
	file.open("SaveInf.txt", ios_base::out | ios_base::in);
	string Name;
	char date[11];
	int levEl, scOre;
	int j = 0;
	for (int i = start; i < end; i++) {
		file.seekg(-32 * (static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(i) + 1), ios_base::end);
		file >> Name >> levEl >> scOre;
		if (scOre < 10)	 file.seekg(4, ios_base::cur);
		else if (scOre < 100 && scOre >= 10) file.seekg(3, ios_base::cur);
		else if (scOre < 1000 && scOre >= 100) file.seekg(2, ios_base::cur);
		else file.seekg(1, ios_base::cur);
		file.getline(date, 11);
		file.clear();
		TextColor(6);
		GotoXY(cornerX + 7, cornerY + 5 + j); cout << setw(10) << Name;
		GotoXY(cornerX + 7 + space * 1, cornerY + 5 + j); cout << setw(2) << levEl;
		GotoXY(cornerX + 7 + space * 2, cornerY + 5 + j); cout << setw(5) << scOre;
		GotoXY(cornerX + 7 + space * 3 - 6, cornerY + 5 + j); cout << setw(11) << date << endl;
		j++;
	}
	file.close();
}

void LoadGame(int n) {
	if (n == 1) {
		int choice = DrawLoadBoard(cornerX, cornerY, WIDTH_CONSOLE, HEIGH_CONSOLE);
		if (choice == 0) return;
		else if (choice == -1) {
			int ch;
			while (1) {
				if (_kbhit()) {
					ch = _getch();
					if (ch == 27) {
						PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
						menuOn = 1;
						break;
					}
				}
			}
			return;
		}
		else {
			LvLoad(choice);
			DrawInfo(corLx, corLy + 1);
			if (level == 1) {
				StartGame();
			}
			else if (level == 2) {
				StartGame1();
			}
			else if (level == 3) {
				StartGame2();
			}
			else if (level == 4)
			{
				StartGame3();
			}
			LoadFile(choice);

			if (level == 2) {
				ClearBoard();
				DrawCountDown(cornerX + 33, cornerY + 7);
				DrawWall();
			}
			else if (level == 3) {
				DrawCountDown(cornerX + 33, cornerY + 7);
				Object();
				if (FOOD_INDEX >= 2 && FOOD_INDEX <= 3)
				{
					DoubleObject();
				}
				if (FOOD_INDEX == 4)
				{
					SingleObject(object_state3, 3);
					SingleObject(object_state2, 2);
					SingleObject(object_state1, 1);
				}
			}
			else {
				DrawCountDown(cornerX + 33, cornerY + 7);
			}

			if (level == 4 && (GATE == 1 || goalgoalgoal == 1)) {
				if (GATE == 1) goal_celebration = 16;
				DelWall();
			}
		}
	}
	else {
		StartGame();
		play_again = 1;
		SPEED = 1;
		DrawCountDown(cornerX + 33, cornerY + 7);
	}
}

void clearfile(string filename) {
	ofstream file;
	file.open(filename, ofstream::out | ofstream::trunc);
	file.close();
}