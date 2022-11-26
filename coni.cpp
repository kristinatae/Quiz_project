#include<iostream>
#include <termios.h>
#include <stdio.h>
static struct termios old, neww;


// clrscr() function definition

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old); //grab old terminal i/o settings
    neww = old; //make new settings same as old settings
    neww.c_lflag &= ~ICANON; //disable buffered i/o
    neww.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
    tcsetattr(0, TCSANOW, &neww); //apply terminal io settings
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* 
Read 1 character without echo 
getch() function definition.
*/
char getch(void)
{
    return getch_(0);
}

char _getch(void)
{
    return getch_(0);
}

/* 
Read 1 character with echo 
getche() function definition.
*/
char getche(void)
{
    return getch_(1);
}
