#include "Highscore.h"

int DrawScoreBoard(int cornerX, int cornerY, int width, int height) {

	system("cls");

	fstream file;
	string Name;
	char date[11];
	int levEl, scOre;

	file.open("highscore.txt", ios_base::in | ios_base::out);
	file.seekg(0, ios_base::end);
	int x = file.tellg();
	x = x / 29;

	//emty file ?
	if (x == 0) {
		DrawBoard(cornerX, cornerY, width, height);
		printASCII("highscoreText.txt", cornerX + 9, cornerY - 4);
		printASCII("highscoreMess.txt", 1, 7);
		GotoXY(60, 14); cout << "Nothing here :(";
		GotoXY(55, 15); cout << "Press ESC to  back to MENU";
		file.close();
		char ch1;
		while (1) {
			if (_kbhit()) {
				ch1 = _getch();
				if (ch1 == 27) {
					PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
					break;
				}
			}
		}
		system("cls");
		return 1;
	}

	TextColor(6);
	GotoXY(cornerX + 5, cornerY + 2);
	int space = width / 5 - 1;
	cout << setw(space + 1) << left << "Top"
		<< setw(space) << left << "Name"
		<< setw(space + 3) << left << "Score"
		<< setw(space) << left << "Lv"
		<< setw(space) << left << "Date";

	if (x == 16) x = 15;
	file.seekg(0, ios_base::beg);
	for (int i = 0; i < x; i++) {
		file >> Name >> scOre >> levEl;
		file.seekg(2, ios_base::cur);
		file.getline(date, 11);
		GotoXY(cornerX + 5, cornerY + 4 + i);
		cout << setw(space) << left << i + 1
			<< setw(space + 2) << left << Name
			<< setw(space + 3) << left << scOre
			<< setw(space - 2) << left << levEl
			<< setw(space) << left << date;
	}
	file.close();
	// draw frame of load board
	TextColor(0);
	int c = 0;
	int space1 = width / 5;
	DrawBoard(cornerX, cornerY, width, height);
	DrawBoard(cornerX, cornerY, width, 3);
	do
	{
		c += space1;
		DrawBoard(cornerX + c, cornerY, width / 5, height);
	} while (c < WIDTH_CONSOLE / 2);

	GotoXY(cornerX, cornerY + 3); cout << char(204);
	GotoXY(cornerX + width, cornerY + 3); cout << char(185);
	c = 1;
	while (c <= 4)
	{
		GotoXY(cornerX + c * space1, cornerY); cout << char(203);
		GotoXY(cornerX + c * space1, cornerY + 3); cout << char(206);
		GotoXY(cornerX + c * space1, cornerY + height); cout << char(202);
		c++;
	}
	TextColor(0);
	printASCII("highscoreText.txt", cornerX + 9, cornerY - 4);
	printASCII("highscoreMess.txt", 1, 7);
	char ch1;
	while (1) {
		if (_kbhit()) {
			ch1 = _getch();
			if (ch1 == 27) {
				PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
				break;
			}
			else if (ch1 == 'q' || ch1 == 'Q') {
				PlaySound(TEXT("selectclick.wav"), NULL, SND_SYNC);
				clearfile("highscore.txt");
				break;
			}
		}
	}
	system("cls");
	return 0;
}

void SaveHighScore(string nAme) {
	int x = 0; // number of line
	fstream file;
	file.open("highscore.txt", ios_base::in | ios_base::out);
	// line check
	file.seekg(0, ios_base::end);
	x = file.tellg();
	x = x / 29;
	//
	if (x >= 16) {
		file.seekg(-29, ios_base::end);
		file << setw(27) << " ";
		file.seekg(-27, ios_base::cur);
	}
	file << setw(11) << left << nAme << setw(3) << left << SCORE << setw(3) << left << level;

	time_t now = time(0);
	tm* ltm = localtime(&now);

	file << setw(2) << right << ltm->tm_mday << "/";
	file << setw(2) << right << 1 + ltm->tm_mon << "/";
	file << setw(4) << right << 1900 + ltm->tm_year;
	file << "\n";
	// 29 byte per line
	file.close();
}

void highscore_structIn(HighScore x[]) {
	fstream file;
	file.open("highscore.txt", ios_base::in | ios_base::out);
	int nLine = 0;
	file.seekg(0, ios_base::end);
	nLine = file.tellg();
	nLine = nLine / 29;
	file.seekg(0, ios_base::beg);
	for (int i = 0; i < nLine; i++) {
		file >> x[i].nAme >> x[i].score >> x[i].lv;
		file.seekg(2, ios_base::cur);
		file.getline(x[i].dAte, 11);
	}
	file.close();
}

void highscoreSort(HighScore x[]) {
	HighScore temp;
	fstream file;
	file.open("highscore.txt", ios_base::in | ios_base::out);
	int nLine = 0;
	file.seekg(0, ios_base::end);
	nLine = file.tellg();
	nLine = nLine / 29;
	for (int i = 0; i < nLine - 1; i++) {
		for (int j = i + 1; j < nLine; j++) {
			if (x[i].score < x[j].score) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	file.seekg(0, ios_base::beg);
	for (int i = 0; i < nLine; i++) {
		file << setw(11) << left << x[i].nAme << setw(3) << left << x[i].score << setw(3) << left << x[i].lv << x[i].dAte << "\n";
	}
	file.close();
}

void hs(string nAme, HighScore x[]) {
	SaveHighScore(nAme);
	highscore_structIn(x);
	highscoreSort(x);
}

string getNameforHighScore() {
	ClearBoard();
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
	cin.clear();
	string nAme;
	do {
		GotoXY(cornerX + 16, cornerY + 12); cout << "          ";
		GotoXY(cornerX + 16, cornerY + 12);
		cin.clear();
		nAme = LimInput(MAX_NAME);
	} while (NameCheck(nAme, "highscore.txt"));
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
	return nAme;
}

bool NameCheck(string naMe, string filename) {
	fstream file;
	file.open(filename, ios_base::in);
	string NaMe;
	int line = 0;
	file.seekg(0, ios_base::end);
	line = file.tellg();
	if (filename == "highscore.txt") line = line / 29;
	else if (filename == "SaveInf.txt") line = line / 32;

	file.seekg(0, ios_base::beg);
	for (int i = 0; i < line; i++) {
		file >> NaMe;
		if (NaMe == naMe) {
			file.close();
			TextColor(rand() % 5 + 2);
			GotoXY(cornerX + 13, cornerY + 14); cout << "Name already exists";
			TextColor(0);
			return 1;
		}
		if (filename == "highscore.txt") file.seekg(29 * (i + 1), ios_base::beg);
		else if (filename == "SaveInf.txt") file.seekg(32 * (i + 1), ios_base::beg);
	}
	GotoXY(cornerX + 13, cornerY + 14); cout << "                   ";
	file.close();
	return 0;
}

char* LimInput(const int k) {
	char* Out = new char[k + 1];
	int n, index = 0;
	do {
	loop:;
		n = _getch();
		if (((n >= '0' && n <= '9') || (n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z') || n == '.') && index < k)
		{
			cout << char(n);
			Out[index++] = n;
		}
		else if (n == '\b' && index > 0)
		{
			cout << "\b \b";
			Out[--index] = 0;
		}
		if (n == 13 && index == 0) goto loop;
	} while (n != 13);
	Out[index] = 0;
	return Out;
}
