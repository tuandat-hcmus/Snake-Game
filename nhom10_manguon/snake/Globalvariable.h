#pragma once
#include "Common.h"

extern POINT snake[MAX_SIZE_SNAKE]; //snake  //--
extern POINT food[MAX_SIZE_FOOD]; // food  //--
extern POINT gate[5];  //--
extern POINT out[2];
extern POINT wall[SIZE_WALL];
extern POINT object[4];  //--
extern POINT superfood[5];  //--
extern POINT smallwall[MAX_SIZE_SMALL_WALL];
extern POINT goal[14];
extern POINT ball[2];

extern char mssv[41];
extern int CHAR_LOCK;//used to determine the direction my snake cannot move (At a moment, there is one direction my snake cannot move to)  //--
extern int MOVING;//used to determine the direction my snake moves (At a moment, there are three directions my snake can move)  //--
extern int SPEED;// Standing for level, the higher the level, the quicker the speed  //--
//int HEIGH_CONSOLE, WIDTH_CONSOLE;// Width and height of console-screen
extern int FOOD_INDEX; // current food-index  //--
extern int SIZE_SNAKE; // size of snake, initially maybe 6 units and maximum size maybe 10  //--
extern int SIZE_SNAKE_1;  //--
extern int STATE; // State of snake: dead or alive
extern int GATE;  //--
extern int SCORE; //--
extern int flag;  //--
extern int outgate;  //--
extern int fix;  //--
extern int boardcolor[4];
extern int colorboard;
extern int level; //--
extern int fixcount;  //--
extern int object_state;  //--
extern int object_state1;  //--
extern int object_state2;  //--
extern int object_state3;  //--
extern int eated;  //--
extern int superfood_eated[MAX_SUPER_FOOD];  //--
extern int stoptime;  //--
extern int supercount;  //--
extern int undying;  //--
extern int supercount1;  //--
extern int colorundying;
extern int object_fix;
extern int object_fix1;
extern int play_again;  //--
extern int ball_state;  //--
extern int smallwall_hitted[MAX_SIZE_SMALL_WALL];
extern int smallwall_hitted_idx;
extern int goalgoalgoal;
extern int length_break;
extern int Old_smallwall_hitted_idx;
extern int goal_celebration;


//set ConsoleBoard
extern int WIDTH_CONSOLE;
extern int HEIGH_CONSOLE;
extern int cornerX;
extern int cornerY;

//set LeftBoard
extern int corLx;
extern int corLy;
extern int widthL;
extern int heightL;

//set FrameBoard
extern int corFx;
extern int corFy;
extern int widthF;
extern int heightF;

//set LevelBoard
extern int widthLevel;
extern int heightLevel;
extern int corLevelx;
extern int corLevely;

extern char* name;

extern string nAmE;
extern int exitgAme;

//-------------------------------Sound------------------------
extern bool eAt;
extern bool dIe;
extern bool nextlv;
extern bool sUperfood1;
extern bool click;
extern bool goalSound;
extern bool countdownsound1;
extern bool countdownsound2;
//------------------------------------------------------------
extern bool menuOn;
extern int save_load;