/* File: SnakeOnMeteor.h */
/* Definisi Games SnakeOnMeteor */

// #ifndef SnakeOnMeter_H
#define SnakeOnMeter_H

#include <stdio.h>
#include "time.h"
#include "..\src\console.h"
#include "..\src\ADT\listlinier\listsirkuler.h"

//Belum lengkap, obstacle, scoreboard belum ditangani

void randomnumbersnake(int *x,int *y);

void GenerateFood(StatArray *container, int *FoodLocation);

void GenerateMeteor(int *MeteorLocation, int Foodlocation);

boolean IsPointNotEmpty(List snake, int input);

boolean IsSnakeBody(List snake, int input);

int ShowSquare(StatArray container);

void NextTurn(List *snake, int *FoodLocation, boolean *IsFoodAvailable, int Turn, int *MeteorLocation, int *End, int *score);

void CreateSnake(List *snake);

boolean IsInputValid(Word CWord);

boolean IsMoveable(Word CWord, List snake);

boolean IsMeteorLocation(Word Cword, List snake, int MeteorLocation);

void SnakeOnMeteor();