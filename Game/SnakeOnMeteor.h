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
/* Membuat 2 random number untuk program snake 
    I.S. sembarang
    F.S. random number tersimpan di x dan y. */

int idxmaxarray(StatArray container, int n);
/* Mengembalikan indeks dari elemen maksimum dalam array */

int idxnol(StatArray container, int n);
/* Mengembalikan indeks dari elemen pertama yang bernilai 0 */


int idxsatu(StatArray container, int n);
/* Mengembalikan indeks dari elemen pertama yang bernilai 1 */

/*------------Fungsi untuk memeriksa lokasi snake(full component, atau body saja) dan obstacle dalam peta------------*/

boolean IsSnakeLocation(List snake, int input);
/* Mengecek jika sebuah titik dalam board adalah bagian dalam snake (digunakan dalam generasi makanan)
    I.S. Game dimulai, snake dalam board
    F.S. Mengecek jika titik dalam board berisi snake*/

boolean IsSnakeBody(List snake, int input);
/*Mengecek jika sebuah titik dalam board adalah bagian dalam snake, kecuali ekor(digunakan dalam gerakan ular
    karena ular bisa bergerak menuju ekor karena ular jika bergerak, ekor akan ikut bergerak)
    I.S. Game dimulai, snake dalam board
    F.S. Mengecek jika titik dalam board adalah badan snake*/

boolean IsObstacleLocation(StatArray ObstacleLocation, int location);
/* Mengecek jika suatu titik pada board adalah lokasi dimana location berada 
    I.S. Game sudah dimulai, snake dan obstacle terdefinisi, obstacle ada dalam board.
    F.S. Mengembalikan true jika titik merupakan tempat di mana location berada, dan false jika sebaliknya. */

/*------------Fungsi untuk membuat kompenen dalam peta------------*/

void CreateSnake(List *snake, StatArray ObstacleLocation);
/* Membuat snake kosong. 
    I.S. Game dimulai, Obstacle ada dalam board
    F.S. Membuat snake pada board dan menmbuat ulang jika ada pada obstacle*/

void GenerateFood(StatArray *container, int *FoodLocation, List snake, StatArray ObstacleLocation);
/* Membuat makanan dalam board
    I.S. Game dimulai, Obstacle ada dalam board, snake ada dalam board
    F.S. Membuat makanan, mengulangi generasi jika random pada snake atau obstacle.*/

void GenerateMeteor(int *MeteorLocation, int Foodlocation, StatArray ObstacleLocation);
/* Membuat meteor pada board
    I.S. Game dimulai, snake dalam board, obstacle dalam board, dan food dalam board
    F.S. Membuat sebuah meteor dan generasi ulang jika meteor ada pada obstacle atau food*/

void GenerateObstacle(StatArray *ObstacleLocation, int number);
/* Membuat sebuah obstacle pada awal game
    I.S. Game dimulai
    F.S. Obstacle dibuat pada board dengan jumlah number*/

/*------------Fungsi yang berhubungan dengan inputan yang valid sehingga ular bisa bergerak------------*/

boolean IsCommandValid(Word CWord);
/* Mengecek jika command oleh user valid
    I.S. Game dimulai
    F.S. Mengecek jika command yang diberikan oleh user valid, ada dalam spesifikasi game. (w,a,s,d)*/

boolean IsTowardSnakeBody(Word CWord, List snake);
/* Mengecek jika snake sedang bergerak menuju badan sendiri 
    I.S. Game dimulai, command sudah diinput dan valid
    F.S. Mengecek jika inputan command user menyebabkan snake bergerak ke badannya sendiri.*/

boolean IsTowardMeteor(Word Cword, List snake, int MeteorLocation);
/* Mengecek jika snake sedang bergerak menuju meteor yang baru saja jatuh
    I.S. Game dimulai, command sudah diinput dan valid, Meteor dalam board
    F.S. Mengecek jika inputan command user menyebabkan snake bergerak ke meteor*/

boolean IsTowardObstacle(Word Cword, List snake, StatArray ObstacleLocation);
/* Mengecek jika snake sedang bergerak menuju obstacle
    I.S. Game dimulai, command sudah diinput dan valid, Obstacle dalam board
    F.S. Mengecek jika inputan command user menyebabkan snake bergerak ke obstacle*/

/*------------Fungsi untuk memunculkan keadaan map sekarang------------*/
void DisplaySOMMap(StatArray container);
/* Memunculkan map dengan Tampilan Design Asci
    I.S. Game dimulai
    F.S. Memunculkan map dengan tampilan design asci*/


void ShowSquare(StatArray container);
/* Memunculkan kondisi map sekarang
    I.S. Game dimulai
    F.S. Menampilkan kondisi map sekarang*/

/*------------Fungsi utama dalam menjalankan program------------*/

void NextTurn(List *snake, int *FoodLocation, boolean *IsFoodAvailable, int Turn, int *MeteorLocation, int *End, int *score, StatArray ObstacleLocation);
/* Melakukan lanjutan dan kondisi papan dalam game ketika user menginput command yang valid
    I.S. Game dimulai, Command valid sudah diinput
    F.S. Melakukan lanjutan turn dan membuat kondisi yang sesuai*/

void SnakeOnMeteor(ArrayDyn ArrayGame, ArrayMap *MapGame);
/* Memainkan game snake
    I.S. sembarang
    F.S. Game snake dimainkan*/