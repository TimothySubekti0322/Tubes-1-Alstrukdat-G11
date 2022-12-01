#include <stdio.h>
#include "../src/console.h"
#include "../src/boolean.h"

void LoadWordList(ArrayDyn *ListWord);
/*
    * Melakukan pembacaan file , kemudian menuliskan isinya ke dalam array ListWord
    * I.S : Array ListWord terdefinisi dan kosong
    * F.S : Array ListWord berisi list kata-kata yang ada dalam file listkata.txt
*/

void guessedchars(char *guessed, char current, int pos);
/*
    * Menambahkan current ke array guessed di indeks ke-pos
    * I.S : Array guessed terdefinisi, mungkin kosong (apabila di awal)
    * F.S : Array guessed sudah berisi char current pada indeks ke-pos
*/

void DisplayHangmanWord(char *array, int length);
/*
    * Fungsi untuk menampilkan string (pointer to char) array ke dalam layar
    * Tampilan string memiliki format : "elemen-1 elemen-2 ... elemen-n"
    * Prekondisi : array selalu terdefinisi, dan tidak mungkin kosong
*/

boolean alreadyGuessed(char now, char *guessed);
/* 
    * Bernilai true apabila now sudah pernah ditebak (now merupakan elemen dari array guessed)
    * Mengirimkan false jika sebaliknya
*/

void emptystring(char *guessed, int size);
/* 
    * Fungsi untuk mengosongkan string hasil tebakan pada kata sebelumnya.
    * I.S.  : String guessed berisi huruf-huruf yang ditebak untuk kata sebelumnya, dan berukuran size.
    * F.S.  : String guessed menjadi kosong, yaitu semua elemennya adalah '\0'.
*/

void showFigHangman(int num);
/*
    * Fungsi untuk menampilkan gambar hangman sampai num
*/

void EndCredits();
/*
    * Melakukan pembacaan file , kemudian menampilkan isinya ke layar.
*/

void hangman(ArrayDyn ArrayGame, ArrayMap *MapGame);
/* 
    * Fungsi utama untuk game hangman
    * Setelah game berakhir, nilai user akan dimasukkan ke scoreboard,
    * yaitu MapGame.
*/