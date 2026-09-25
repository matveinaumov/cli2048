#ifndef CLI2048_MAP_H
#define CLI2048_MAP_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
using namespace std;
const int Size = 4;
class Map
{
public:
    int Board[Size][Size] = {0};
    void Display();
    void Down();
    void Up();
    void Left();
    void Right();
    void Spawn();
    bool Check();
};


#endif //CLI2048_MAP_H
