#ifndef __CONSOLE__
#define __CONSOLE__

// #include "ADT/array/arraydinamik.h"
#include "ADT/array/arraydinamikstr.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queue/queue.h"
#include "ADT/queue/queuestr.h"
#include "boolean.h"
#include "../Game/RNG.h"
#include "../Game/dinerdash.h"
#include "../Game/mole.h"
#include "ADT/map/map.h"
#include "ADT/stack/stackstr.h"
#include "ADT/stack/stackint.h"
#include "ADT/map/arrayofmap.h"
#include "ADT/tree/tree.h"
#include "ADT/listLinier/listsirkuler.h"
#include "../Game/thanoi.h"
#include "../Game/treasurehunt.h"
#include "../Game/SnakeOnMeteor.h"
#include "../Game/hangman.h"


void STARTBNMO(ArrayDyn *gamesBNMO , ArrayMap *MapGame);
/* Membaca file config dan memasukan tiap baris file ke array gamesBNMO*/

boolean IsKataSama(Word InputCommand, Word Command);
    /* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

void PrintWord(Word CWord);
/* Mencetak current word
   I.S : CWord tidak kosong dan terdefinisi
   F.S : isi dari CWord dicetak ke layar */

char *wordToString(Word kata);
/* Mengubah Word menjadi string*/

boolean CompareString(char *string1 , char *string2);
/* Mengirimkan true jika string1 = string2 */

boolean IsInQueue(QueueStr *Queue,char *string);
/* Mengirimkan true jika string yang diinput ada didalam Queue*/

void PrintString(char *string);
/* Mencetak string
   I.S : String terdefinisi
   F.S : string tercetak ke layar */


int stringLength (char* string);
/* Mengirimkan panjang sebuah string */


Word StringtoWord(char* command);
/* Mengirimkan kata yang elemen of arraynya berasal dari command */


int StringtoInt(char* string);
/* Mengubah sebuah string menjadi integer*/

void concat(char *string1, char *string2, char *string3);
/* Menggabungkan string 1 dan string 2
   I.S : string 1, string2 , dan string3 terdefinisi ; string 3 kosong
   F.S : string3 berisi gabungan dari string1 dan string2*/

void CopyWordtostring(Word Input, char *string, int Awal , int Akhir);
/* Menyalin kata ke string
   I.S : Input terdefinisi , String , Awal , dan Akhir terdefinisi
   F.S : string berisis elemen elemen kata dari Indeks Awal hingga Indeks Akhir */

void WordToInt(Word kata, int *hasil);
/* Mengubah Kata to Int
   I.S : Kata dan hasil terdefinisi
   F.S : hasil merupakan integer dari element Kata*/

void delay(float seconds);
/* Memberikan Jeda untuk program mengeksekusi baris berikutnya */

int IntLength(int n);
/* Menghitung banyak Digit*/

void printblank(int n);
/* Mencetak Blank Sebanyak n ke layar */

void printstrip(int n);
/* Mencetak '-' sebanyak n ke layar */

void printsingelhorizontalline(int n);
/* Mencetak Horizontal line sebanyak n ke layar */

void printscoreboard(Map M , char *namagame);

boolean IsStringEqual(char *string1 , char* string2);
/* Mengirimkan True jika string 1 sama dengan string 2 baik Uppercase maupun Lowercase*/

boolean IsMemberScoreBoard(Map M, keytype k);
/* Memeriksa apakah k merupakan Anggota dari M */

void InsertScoreBoard(Map *M, valuetype v);
/* Memasukan Username dan score game ke Map */

void DeleteHistoryifEqual(StackStr *History , char *string);
/* Menghapus semua Element Stack yang Sama dengan string */

/* COMMAND FUNCTION*/

void LOADFILE(ArrayDyn *Games, char *inputfile, ArrayMap *MapGame , StackStr *History);
/* Melakukan pembacaan file , kemudian menuliskan isinya edalam Array Games
   I.S : File yang diinput terdefinisi , Array Games terdefinisi dan kosong
   F.S : Array games berisis list Game yang ada dalam file*/

void Save(ArrayDyn ArrayGame, char namafile[] , StackStr History, ArrayMap MapGame);
/* Melkaukan Save file
   I.S : ArrayGame terdefinisi dan nama file terdefinisi
   F.S : Jika file sudah ada maka file di overwrite , Jika tidak ada akan membuat file baru*/

void LISTGAME(ArrayDyn arraygames);
/* Menampilkan ListGame yang tersedia 
   I.S : arraygames terdefinisi
   F.S : menampilakn seluruh elemen arraygames*/

void DELETEGAME(ArrayDyn *Games, QueueStr *Queue , ArrayMap *MapGame, StackStr *History);
/* Melakukan penghapusan suatu game
   I.S : Arraygames terdefinisi
   F.S : Melakukan penghapusan game jika ada pada array, mengeluarkan pesan error
         jika tidak terdefinisi atau termasuk dalam game default*/

void CreateGame(ArrayDyn* ArrayGame, ArrayMap *MapGame);
/* Melakukan penambahan suatu game
   I.S : ArrayGame terdefinisi
   F.S : Melakukan penambahan game pada array, meminta validasi dengan input 
         ulang jika game sudah ada di dalam array*/

void PlayGame(QueueStr* AntrianGame , StackStr *History , ArrayMap *MapGame , ArrayDyn ArrayGame);
/* Menjalankan suatu game
   I.S : ArrayGame terdefinisi
   F.S : Menjalankan game yang terdapat di paling atas pada ADT Queue yang
         menyimpan antrian game*/

void SkipGame(QueueStr* AntrianGame, int number , ArrayMap *MapGame , ArrayDyn ArrayGame , StackStr *History);
/* Menjalankan suatu game dengan skip game sebanyak number
   I.S : Arraygames terdefinisi
   F.S : Melewatkan game sebanyak number dari atas, dan menjalankan game apabila
         masih terdapat game dalam ADT Queue*/
         
void HELP();
/* Menampilkan daftar command-command yang tersedia,
 * apa saja yang dapat dilakukan dengan masing-masing command,
 * dan cara memanggilnya.
*/

void QUEUEGAME(QueueStr *BNMOGames, ArrayDyn ListGame);
/* Menampilkan antrian terkini dari game user, lalu memperbolehkan
 * user untuk menambahkan game sesuai list game yang tersedia di BNMO.
 * Apabila indeks game yang dipilih berada pada rentang indeks game BNMO,
 * game berhasil ditambahkan ke antrian.
 * Jika tidak, akan muncul pesan kesalahan dan game gagal ditambahkan.
*/

void SCOREBOARD(ArrayDyn listgame , ArrayMap M);
/* Menampilkan Scoreboard game ke layar */

void HISTORY(StackStr history, int n);
/* Menampilkan History Permainan */

void RESETSCOREBOARD(ArrayDyn listgame , ArrayMap *M);
/* Melakukan Reset Scoreboard */

void RESETHISTORY(StackStr *history);
/* Melakuka Reset History */

void QUIT(boolean EndGame);
/*
   I.S : EndGame bernilai false
   F.S : Endgame bernilai true
*/
#endif
