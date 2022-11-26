/* File: SnakeOnMeteor.h */
/* Definisi Games SnakeOnMeteor */

// #ifndef SnakeOnMeter_H
#define SnakeOnMeter_H

#include <stdio.h>
#include "time.h"
#include "..\src\console.h"
#include "..\src\ADT\listlinier\listsirkuler.h"

//Belum lengkap, meteor, obstacle, scoreboard belum ditangani

void randomnumber(int *x,int *y);

void GenerateFood(StatArray *container, int *FoodLocation);

boolean IsPointNotEmpty(List snake, int input);

void ShowSquare(List snake, int *FoodLocation, boolean *IsFoodAvailable);

void CreateSnake(List *snake);

boolean IsInputValid(Word CWord);

boolean IsMoveable(Word CWord, List snake);