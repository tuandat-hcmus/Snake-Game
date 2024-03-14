#include "Globalvariable.h"

POINT snake[MAX_SIZE_SNAKE]; //snake  //--
POINT food[MAX_SIZE_FOOD]; // food  //--
POINT gate[5];  //--
POINT out[2];
POINT wall[SIZE_WALL];
POINT object[4];  //--
POINT superfood[5];  //--
POINT smallwall[MAX_SIZE_SMALL_WALL];
POINT goal[14];
POINT ball[2];

char mssv[] = "2112041021120426211204302112044221120495";
int CHAR_LOCK;//used to determine the direction my snake cannot move (At a moment, there is one direction my snake cannot move to)  //--
int MOVING;//used to determine the direction my snake moves (At a moment, there are three directions my snake can move)  //--
int SPEED;// Standing for level, the higher the level, the quicker the speed  //--
//int HEIGH_CONSOLE, WIDTH_CONSOLE;// Width and height of console-screen
int FOOD_INDEX; // current food-index  //--
int SIZE_SNAKE; // size of snake, initially maybe 6 units and maximum size maybe 10  //--
int SIZE_SNAKE_1;  //--
int STATE; // State of snake: dead or alive
int GATE;  //--
int SCORE; //--
int flag;  //--
int outgate;  //--
int fix;  //--
int boardcolor[] = { 12, 14, 13, 4 };
int colorboard;
int level; //--
int fixcount;  //--
int object_state;  //--
int object_state1;  //--
int object_state2;  //--
int object_state3;  //--
int eated = 0;  //--
int superfood_eated[MAX_SUPER_FOOD];  //--
int stoptime = 0;  //--
int supercount = 0;  //--
int undying = 0;  //--
int supercount1 = 0;  //--
int colorundying = 0;
int object_fix = 0;
int object_fix1 = 0;
int play_again = 1;  //--
int ball_state;  //--
int smallwall_hitted[MAX_SIZE_SMALL_WALL];
int smallwall_hitted_idx = 0;
int goalgoalgoal = 0;
int length_break = 0;
int Old_smallwall_hitted_idx = 0;
int goal_celebration = 0;


//set ConsoleBoard
int WIDTH_CONSOLE = 71;
int HEIGH_CONSOLE = 20;
int cornerX = 30;
int cornerY = 5;

//set LeftBoard
int corLx = cornerX - 20;
int corLy = cornerY - 2;
int widthL = 15;
int heightL = HEIGH_CONSOLE + 5;

//set FrameBoard
int corFx = cornerX - 22;
int corFy = cornerY - 3;
int widthF = 100;
int heightF = HEIGH_CONSOLE + 7;

//set LevelBoard
int widthLevel = (float(2) / 3) * WIDTH_CONSOLE;
int heightLevel = 4;
int corLevelx = cornerX + WIDTH_CONSOLE / 2 - widthLevel / 2;
int corLevely = cornerY - 5;
char* name;
string nAmE = "0";
int exitgAme = 0;
//-------------------------------Sound------------------------
bool eAt = 0;
bool dIe = 0;
bool nextlv = 0;
bool sUperfood1 = 0;
bool click = 0;
bool goalSound = 0;
bool countdownsound1 = 0;
bool countdownsound2 = 0;
//------------------------------------------------------------
bool menuOn = 1;
int save_load = 0;