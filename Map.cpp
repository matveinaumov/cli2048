#include "Map.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;
int NumberCount(int a) {
  if (a == 0)
    return 1;
  int b = 0;
  while (a != 0) {
    b++;
    a /= 10;
  }
  return b;
}
void Move(int &a, int &b) {
  if (a == b || b == 0) {
    b += a;
    a = 0;
  }
}
void Map::Display() {
  system("clear");
  cout << "---------------------" << endl;
  for (int i = 0; i < Size; i++) {
    cout << "|";
    for (int j = 0; j < Size; j++) {
      if (Board[i][j] == 0)
        cout << "    |";
      else
        cout << Board[i][j] << string((4 - NumberCount(Board[i][j])), ' ')
             << '|';
    }
    cout << endl;
  }
  cout << "---------------------" << endl;
}
void Map::Down() {
  int x;
  int l;
  for (int i = 2; i >= 0; i--) {
    for (int j = 0; j < Size; j++) {
      x = 0;
      while (i + x < 3 && (Board[i + x][j] == Board[i + x + 1][j] ||
                           Board[i + x + 1][j] == 0)) {
        l = Board[i + x][j];
        Move(Board[i + x][j], Board[i + x + 1][j]);
        if (Board[i + x + 1][j] == l * 2)
          break;
        x++;
      }
    }
  }
}
void Map::Up() {
  int x;
  int l;
  for (int i = 1; i < Size; i++) {
    for (int j = 0; j < Size; j++) {
      x = 0;
      while (i - x > 0 && (Board[i - x][j] == Board[i - x - 1][j] ||
                           Board[i - x - 1][j] == 0)) {
        l = Board[i - x][j];
        Move(Board[i - x][j], Board[i - x - 1][j]);
        if (Board[i - x - 1][j] == l * 2)
          break;
        x++;
      }
    }
  }
}
void Map::Right() {
  int x;
  int l;
  for (int j = 0; j < Size; j++) {
    for (int i = 2; i >= 0; i--) {
      x = 0;
      while (i + x < 3 && (Board[j][i + x] == Board[j][i + x + 1] ||
                           Board[j][i + x + 1] == 0)) {
        l = Board[j][i + x];
        Move(Board[j][i + x], Board[j][i + x + 1]);
        if (Board[j][i + x + 1] == l * 2)
          break;
        x++;
      }
    }
  }
}
void Map::Left() {
  int x;
  int l;
  for (int j = 0; j < Size; j++) {
    for (int i = 1; i < Size; i++) {
      x = 0;
      while (i - x > 0 && (Board[j][i - x] == Board[j][i - x - 1] ||
                           Board[j][i - x - 1] == 0)) {
        l = Board[j][i - x];
        Move(Board[j][i - x], Board[j][i - x - 1]);
        if (Board[j][i - x - 1] == l * 2)
          break;
        x++;
      }
    }
  }
}
void Map::Spawn() {
  int nums[2] = {2, 4};
  int n = nums[rand() % 2], a, b;
  while (true) {
    a = rand() % 4;
    b = rand() % 4;
    if (Board[a][b] == 0) {
      Board[a][b] = n;
      break;
    }
  }
}
bool Map::Check() {
  bool gud = false;
  for (int i = 0; i < Size; i++) {
    for (int j = 0; j < Size; j++) {
      if (Board[i][j] == 0)
        gud = true;
    }
  }
  return gud;
}