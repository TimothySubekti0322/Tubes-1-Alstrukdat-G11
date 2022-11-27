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

boolean IsSnakeLocation(List snake, int input);

boolean IsSnakeBody(List snake, int input);

boolean IsObstacleLocation(StatArray ObstacleLocation, int location);

void CreateSnake(List *snake, StatArray ObstacleLocation);

void GenerateFood(StatArray *container, int *FoodLocation, List snake, StatArray ObstacleLocation);

void GenerateMeteor(int *MeteorLocation, int Foodlocation, StatArray ObstacleLocation);

void GenerateObstacle(StatArray *ObstacleLocation, int number);

boolean IsCommandValid(Word CWord);

boolean IsTowardSnakeBody(Word CWord, List snake);

boolean IsTowardMeteor(Word Cword, List snake, int MeteorLocation);

boolean IsTowardObstacle(Word Cword, List snake, StatArray ObstacleLocation);

boolean IsNotMoveable(List snake, int MeteorLocation, StatArray ObstacleLocation);

int ShowSquare(StatArray container);

void NextTurn(List *snake, int *FoodLocation, boolean *IsFoodAvailable, int Turn, int *MeteorLocation, int *End, int *score, StatArray ObstacleLocation);

void SnakeOnMeteor();