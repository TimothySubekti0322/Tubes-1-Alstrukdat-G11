#ifndef __CONSOLE__
#define __CONSOLE__

#include "ADT/array/arraydinamik.h"
#include "ADT/array/arraydinamikstr.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queue/queue.h"
#include "ADT/queue/queuestr.h"
#include "boolean.h"

void STARTBNMO(ArrayDyn *gamesBNM0);

boolean IsKataSama(Word InputCommand, Word Command);
    /* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

void PrintWord(Word CWord);
/* Mencetak current word
   I.S : CWord tidak kosong dan terdefinisi
   F.S : isi dari CWord dicetak ke layar */

void wordToString(Word currentWord, char string[]);
/* Mengubah Word menjadi string*/

boolean CompareString(char *string1 , char *string2);
/* Mengirimkan true jika string1 = string2 */


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

/* COMMAND FUNCTION*/

void LOADFILE(ArrayDyn *Games, char *inputfile);
/* Melakukan pembacaan file , kemudian menuliskan isinya edalam Array Games
   I.S : File yang diinput terdefinisi , Array Games terdefinisi dan kosong
   F.S : Array games berisis list Game yang ada dalam file*/

void Save(ArrayDyn ArrayGame, char namafile[]);
/* Melkaukan Save file
   I.S : ArrayGame terdefinisi dan nama file terdefinisi
   F.S : Jika file sudah ada maka file di overwrite , Jika tidak ada akan membuat file baru*/

void LISTGAME(ArrayDyn arraygames);
/* Menampilkan ListGame yang tersedia 
   I.S : arraygames terdefinisi
   F.S : menampilakn seluruh elemen arraygames*/

void DELETEGAME(ArrayDyn *Games);
/* Melakukan penghapusan suatu game
   I.S : Arraygames terdefinisi
   F.S : Melakukan penghapusan game jika ada pada array, mengeluarkan pesan error
         jika tidak terdefinisi atau termasuk dalam game default*/

void CreateGame(ArrayDyn* ArrayGame);

void PlayGame(QueueStr* AntrianGame);

void SkipGame(QueueStr* AntrianGame, int number);
         
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

void QUIT(boolean EndGame);
/*
   I.S : EndGame bernilai false
   F.S : Endgame bernilai true
*/
#endif
