#include "Sound.h"

bool hittedcheck() {
	if (Old_smallwall_hitted_idx != smallwall_hitted_idx) {
		Old_smallwall_hitted_idx = smallwall_hitted_idx;
		eAt = 1;
		return 1;
	}
	return 0;
}

void Sound() {
	while (1) {
		if (eAt == 1) {
			PlaySound(TEXT("eatingsound.wav"), NULL, SND_SYNC);
			eAt = 0;
		}
		if (sUperfood1 == 1) {
			PlaySound(TEXT("superfood.wav"), NULL, SND_SYNC);
			sUperfood1 = 0;
		}
		if (dIe == 1) {
			PlaySound(TEXT("gameover.wav"), NULL, SND_SYNC);
			dIe = 0;
		}
		if (nextlv == 1) {
			PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
			nextlv = 0;
		}
		if (goalSound == 1) {
			PlaySound(TEXT("goal.wav"), NULL, SND_SYNC);
			goalSound = 0;
		}
		//click/selectclick: DrawLoadBoard();
		if (countdownsound1 == 1) {
			PlaySound(TEXT("countdown1.wav"), NULL, SND_SYNC);
			countdownsound1 = 0;
		}
		if (countdownsound2 == 1) {
			PlaySound(TEXT("countdown2.wav"), NULL, SND_SYNC);
			countdownsound2 = 0;
		}
	}
}