#pragma once
#include <iostream>
#include<vector>
#include<ctime>
#include "windows.h"
#include<conio.h>
#include<algorithm>

//#include"Function.cpp"
//#include"Draw.cpp"
//#include"Input.cpp"
//#include"Logica.cpp"

void setSnake();
void setArea();
void drawArea();
void setFruit();
void _input();
void Logic();


int const width = 20;
int const heigth = 20;
int Score = 0;
int Level = 1;
char arr[width][heigth];
std::vector< std::pair<int, int>> snakePos{ std::make_pair(width / 2,heigth / 2) };
bool gameOver = false;

std::pair<int, int> fruit{ std::make_pair(1 + rand() % (width - 2),1 + rand() % (heigth - 2)) };
enum class edir { STOP = 0, UP, DOWN, LEFT, RIGHT };
edir dir;


