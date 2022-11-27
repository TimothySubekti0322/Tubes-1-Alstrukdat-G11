/* File: SnakeOnMeteor.h */
/* Definisi Games SnakeOnMeteor */

// #ifndef SnakeOnMeter_H
#define SnakeOnMeter_H

#include <stdio.h>
#include "time.h"
#include "..\src\console.h"
#include "..\src\ADT\listlinier\listsirkuler.h"

/*------------Fungsi tambahan------------*/

void randomnumbersnake(int *x,int *y);

/*------------Fungsi untuk memeriksa lokasi snake(full component, atau body saja) dan obstacle dalam peta------------*/

boolean IsSnakeLocation(List snake, int input);

boolean IsSnakeBody(List snake, int input);

boolean IsObstacleLocation(StatArray ObstacleLocation, int location);

/*------------Fungsi untuk membuat kompenen dalam peta------------*/

void CreateSnake(List *snake, StatArray ObstacleLocation);

void GenerateFood(StatArray *container, int *FoodLocation, List snake, StatArray ObstacleLocation);

void GenerateMeteor(int *MeteorLocation, int Foodlocation, StatArray ObstacleLocation);

void GenerateObstacle(StatArray *ObstacleLocation, int number);

/*------------Fungsi yang berhubungan dengan inputan yang valid sehingga ular bisa bergerak------------*/

boolean IsCommandValid(Word CWord);

boolean IsTowardSnakeBody(Word CWord, List snake);

boolean IsTowardMeteor(Word Cword, List snake, int MeteorLocation);

boolean IsTowardObstacle(Word Cword, List snake, StatArray ObstacleLocation);

boolean IsNotMoveable(List snake, int MeteorLocation, StatArray ObstacleLocation);

/*------------Fungsi untuk memunculkan keadaan map sekarang------------*/

int ShowSquare(StatArray container);

/*------------Fungsi utama dalam menjalankan program------------*/

void NextTurn(List *snake, int *FoodLocation, boolean *IsFoodAvailable, int Turn, int *MeteorLocation, int *End, int *score, StatArray ObstacleLocation);

void SnakeOnMeteor();