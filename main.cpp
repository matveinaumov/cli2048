#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include "Map.h"
using namespace std;
char getch() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    char ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
int main()
{
    srand(time(0));
    Map m1;
    char x;
    while (m1.Check())
    {
        m1.Spawn();
        m1.Display();
        x = getch();
        switch (x)
        {
            case 'w':
                m1.Up();
                break;
            case 'a':
                m1.Left();
                break;
            case 's':
                m1.Down();
                break;
            case 'd':
                m1.Right();
                break;
            default:
                break;
        }
    };
    cout<<"Game over";
}