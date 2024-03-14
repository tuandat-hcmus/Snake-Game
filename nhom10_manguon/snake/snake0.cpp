#include "Common.h"
#include "System.h"
#include "Globalvariable.h"
#include "Draw.h"
#include "SaveLoad.h"
#include "Highscore.h"
#include "Gameplay.h"
#include "Menu.h"
#include "Snake.h"
#include "Obj.h"
#include "Sound.h"

// main function
int main() {
	HighScore H[16];
	system("chcp 437");
	int temp;
	FixConsoleWindow();
	DisableSelection();
	Nocursortype();
	BackGroundColor(BACK_GROUND_COLOR);
	TextColor(TEXT_COLOR);

	thread t2(Sound); //sound
	gameIntro();

	while (true)
	{
		ResetGlobal();
		MenuGame();

		thread t1(ThreadFunc); //Create thread for snake
		HANDLE handle_t1 = t1.native_handle(); //Take handle of thread
		while (1) {
			temp = toupper(_getch());
			if (STATE == 1) {
				if (temp == 'P') {
					PauseGame(handle_t1);
					if (save_load == 1)
					{
						if (t1.joinable())
						{
							t1.detach();
						}
						break;
					}
				}
				else if (temp == 27) { // esc
					SuspendThread(handle_t1);
					Exit();
				}
				else {
					ResumeThread(handle_t1);
					if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S'))
					{
						if (temp == 'D') CHAR_LOCK = 'A';
						else if (temp == 'W') CHAR_LOCK = 'S';
						else if (temp == 'S') CHAR_LOCK = 'W';
						else CHAR_LOCK = 'D';
						MOVING = temp;
					}
				}
			}
			else {
				SuspendThread(handle_t1);
				if (temp == 'E')
				{
					if (t1.joinable())
					{
						t1.detach();
					}
					break;
				}
				else if (temp == 'S') {
					hs(getNameforHighScore(), H);
					if (t1.joinable())
					{
						t1.detach();
					}
					break;
				}
			}
		}
	}

	return 0;
}



