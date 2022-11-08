#include <stdio.h>
#include <stdlib.h>
#include "console.h"


void STARTBNMO(ArrayDyn *gamesBNMO){
    STARTFILE("../data/config.txt");
    int jumlahGame;
    jumlahGame = atoi(CWord.TabWord);
    ADVLINEFILE();

    int i;
    i = 0;
    while (CC != MARK ){

        int i = 0;
        
        while (i < jumlahGame){
            char *namaGame;
            namaGame = (char*) malloc(CWord.Length * sizeof(char));

            int k = 0;
            while (k < CWord.Length){
                namaGame[k] = CWord.TabWord[k];
                k = k+1;
            }
            InsertStrLast(gamesBNMO, namaGame);
            i = i +1;
            ADVLINEFILE();
        }

    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

boolean IsKataSama(Word InputCommand, Word Command)
{
    /* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */

    boolean sama = true;
    if (InputCommand.Length != Command.Length) {
        return (!sama);
    } else {
        int i = 0;
        while (sama && (i < Command.Length)) {
            if (InputCommand.TabWord[i] != Command.TabWord[i]) {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}

void PrintWord(Word CWord)
{
/* Mencetak current word
   I.S : CWord tidak kosong dan terdefinisi
   F.S : isi dari CWord dicetak ke layar */
   for (int i = 0 ; i < CWord.Length ; i++)
   {
    printf("%c",CWord.TabWord[i]);
   }
   printf("\n");
}

void wordToString(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        *(string + i) = currentWord.TabWord[i];
        i++;
    }
    *(string + i) = '\0';
}

boolean CompareString(char *string1 , char *string2)
{
    boolean equal = true;
    int i = 0;
    while ((*(string1 + i) != '\0') && (*(string2 + i) != '\0') && equal)
    {
        if (*(string1 + i) != *(string2 + i))
        {
            equal = false;
        }
        else
        {
        i++;
        }
    }
}


void PrintString(char *string)
{
    /* Mencetak string
       I.S : String terdefinisi
       F.S : string tercetak ke layar */
    int i = 0;
    while(*(string + i) != '\0')
    {
        printf("%c", *(string + i));
        i++;
    }
    printf("\n");
}

int stringLength (char* string) 
/* Mengirimkan panjang sebuah string */
{
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

Word StringtoWord(char* command) 
/* Mengirimkan kata yang elemen of arraynya berasal dari command */
{
    int i;
    Word output;
    for (i = 0; i < stringLength(command); i++) {
        output.TabWord[i] = command[i];
    }
    output.Length = stringLength(command);
    return output;
}

int StringtoInt(char* string)
{
    /* Mengubah sebuah string menjadi integer*/
    int i = 0;
    int hasil = 0;
    while(*(string + i) != '\0')
    {
        hasil = hasil*10 + (*(string+i) - '0');
        i++;
    }
    return hasil;
}

void WordToInt(Word kata, int *hasil)
{
    int i = 0;
    while (i < kata.Length)
    {
        *hasil = *hasil * 10 + (kata.TabWord[i] - '0');
        i++;
    }
}

void concat(char *string1, char *string2, char *string3)
{
    /* Menggabungkan string 1 dan string 2
   I.S : string 1, string2 , dan string3 terdefinisi ; string 3 kosong
   F.S : string3 berisi gabungan dari string1 dan string2*/
    int i = 0;
    int j = 0;

    while (string1[i] != '\0') {
        string3[j] = string1[i];
        i++;
        j++;
    }

    i = 0;
    while (string2[i] != '\0') {
        string3[j] = string2[i];
        i++;
        j++;
    }
    string3[j] = '\0';
}

void CopyWordtostring(Word Input, char *string, int Awal , int Akhir)
{
    int i;
    int j = 0;
    for(i = Awal ; i <= Akhir  ; i++)
    {
        *(string + j) = Input.TabWord[i];
        j++;
    }
    *(string + i) = '\0';
}

/* COMMAND FUNCTION*/

void LOADFILE(ArrayDyn *Games, char *inputfile)
{
    char placeholder[] = "../data/";
    char path[50];

    concat(placeholder, inputfile, path);

    STARTFILE(path);

    if (EndWord)
    {
        printf("File tidak valid / kosong. Silahkan masukkan nama file lain.\n");
    }
    else
    {
        char string[NMax];
        int amount = 0;
        WordToInt(CWord,&amount);
        ADVLINEFILE();/* word pertama yang dibaca adalah jumlah game*/
        for (int j = 0; j < amount; j++)
        {
            wordToString(CWord, string);
            InsertIn(Games, string, j);
        }
        if (path == "config.txt")
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
        }   
    }
}


void Save(ArrayDyn ArrayGame, char namafile[]){
    //ArrayGame merupakan array yang menyimpan list game yang tersedia
    //namafile merupakan namafile yang diinginkan dilakukan save

    FILE* filebaru;
    filebaru = fopen(namafile,"w");
    fprintf(filebaru, "%d\n", ArrayGame.Neff);
    for (int i=0; i<ArrayGame.Neff; i++){
        fprintf(filebaru, "%s\n", ArrayGame.Ar[i]);
    }
    fclose(filebaru);
}

void LISTGAME(ArrayDyn arraygames)
{
    printf("Berikut adalah daftar game yang tersedia");
    
    for (int i = 0; i < arraygames.Neff; i++)
    {
        printf("%d. %s\n", i + 1, arraygames.Ar[i]);
    }

}

void DELETEGAME(ArrayDyn *Games)
{
    int indeksgame;
    INPUT();
    WordToInt(CWord,&indeksgame);
    if(indeksgame > 5 && indeksgame < Length(*Games)){
        DeleteIn(Games,indeksgame);
    } else if(indeksgame >= 1 && indeksgame <= 5){
        printf("Game gagal dihapus karena merupakan game default.\n");
    } else{
        printf("Game gagal dihapus karena indeks yang dimasukkan tidak valid.\n");
    }
}

void CreateGame(ArrayDyn* ArrayGame){
    //ArrayGame merupakan array yang menyimpan list game

    char input[100];
    INPUT();
    wordToString(CWord,input);
    //Melakukan validasi input, apakah sudah ada game yang bernama sama dengan input atau belum
    while (FindArrayDyn(*ArrayGame, input) != -1){
        printf("Game sudah ada, silahkan input ulang");
        INPUT();
        wordToString(CWord,input);            
    }
    //Melakukan penambahan game yang diinput
    InsertLast(ArrayGame, input);
}

void HELP() 
{
	printf("Selamat datang di fungsi HELP!\n");
	printf("Kalau kamu berada di sini, ");
	printf("itu berarti kamu kebingungan akan bagaimana program ini berjalan!\n");
	printf("Tenang saja, kamu akan dibantu sebisa mungkin!\n\n");
	
	printf("Berikut adalah list-list command ");
	printf("yang dapat kamu pakai disini:\n\n");
	
	printf("1. Start\n");
	printf("Jalankan command ini apabila kamu ingin BNMO dijalankan.\n");
	printf("Untuk menjalankan command ini, cukup ketik : 'START'.\n\n");
	
	printf("2. Load\n");
	printf("Jalankan command ini agar file save-mu dapat dijalankan oleh BNMO.\n");
	printf("Apabila sudah mengetahui nama file, ketikkan : 'LOAD'.");
	printf("lalu diikuti dengan nama save file-mu, lengkap dengan tipenya (.txt).\n");
	printf("Contoh : Apabila ingin load file save.txt, ketikkan : 'LOAD save.txt'.\n\n");
	
	printf("3. Save\n");
	printf("Jalankan command ini apabila kamu merasa ingin ");
	printf("menyimpan progres terbarumu di BNMO.\n");
	printf("Apabila sudah mengetahui nama file yang akan dipakai untuk save, ");
	printf("ketikkan 'LOAD' lalu diikuti dengan nama save file-mu, lengkap dengan tipenya (.txt).\n");
	printf("Contoh : Apabila ingin menyimpan progres ke file backup.txt, ketikkan 'LOAD backup.txt'.\n\n");
	
	printf("4. Create Game\n");
	printf("Jalankan command ini apabila kamu merasa menemukan sebuah ");
	printf("game yang sangat keren, dan kamu ingin menambahkannya ke BNMO!\n");
	printf("Untuk menjalankan command ini, ketik 'CREATE GAME', lalu masukkan nama game-nya!\n");
	printf("Game akan tersimpan di BNMO.\n");
	printf("Contoh : Apabila ingin memasukkan game Snake, ketikkan 'CREATE GAME', lalu di input kedua, ketikkan 'Snake'.\n\n");
	
	printf("5. List Game\n");
	printf("Jalankan command ini apabila kamu ingin melihat game-game yang tersedia di BNMO.\n");
	printf("Untuk menjalankan command ini, ketikkan 'LIST GAME'.\n\n");
	
	printf("6. Delete Game\n");
	printf("Jalankan command ini apabila kamu ingin menghapus game dari BNMO.\n");
	printf("Untuk menjalankan command ini, ketikkan 'DELETE GAME'.\n");
	printf("Game yang tersedia pun akan ditampilkan. Lalu, ketikkan nomor game yang ingin dihapus. \n");
	printf("Kamu tidak bisa menghapus 5 game default pada sistem. Pastikan nomornya valid!\n");
	printf("Contohnya tersedia 10 game dalam BNMO. Apabila kamu ketik 'DELETE GAME', maka list game akan muncul.\n");
	printf("Apabila kamu mengetikkan 2, maka game gagal dihapus, karena game ke-2 adalah game default BNMO.\n");
	printf("Sedangkan jika kamu mengetikkan 7, maka game ke-7 berhasil dihapus.\n\n");
	
	printf("7. Queue Game\n");
	printf("Jalankan command ini apabila kamu ingin menambahkan game BNMO ke antrian permainanmu.\n");
	printf("Harap diingat, saat kamu keluar dari BNMO, game antrianmu ini juga akan hilang.\n");
	printf("Untuk menjalankan command ini, ketikkan 'QUEUE GAME'.\n");
	printf("Game antrianmu dan game BNMO akan ditampilkan. Lalu, ketikkan game yang ingin dimasukkan ke antrianmu.\n");
	printf("Kamu tidak bisa menambahkan game yang nomornya berada di luar game BNMO!\n\n");
	
	printf("8. Play Game\n");
	printf("Jalankan command ini apabila kamu ingin memainkan game teratas dalam antrianmu.\n");
	printf("Apabila game tersedia, game dapat langsung dimainkan, tetapi jika tidak, akan tampil pesan kesalahan.\n");
	printf("Untuk menjalankan command ini, ketikkan 'PLAY GAME.\n\n");
	
	printf("9. Skip Game\n");
	printf("Jalankan command ini apabila kamu ingin melangkahi game antrianmu sebanyak yang kamu mau.\n");
	printf("Untuk menjalankan command ini, ketikkan 'SKIP GAME'.\n");
	printf("Lalu, diikuti dengan bilangan n, banyaknya game yang akan dilangkahi.\n");
	printf("Apabila setelah dilangkahi, masih ada game di antrian, game teratas pada antrian akan dimainkan.\n");
	printf("Apabila game pada antrian kosong setelah dilangkahi, akan muncul pesan yang menandakan tidak ada game lagi di antrianmu.\n\n");
	
	printf("10. Quit\n");
	printf("Jalankan oommand ini apabila kamu ingin keluar dari BNMO.\n");
	printf("Untuk menjalankan command ini, ketikkan 'QUIT'.\n\n");
	
	printf("11. Help\n");
	printf("Kamu sudah berada di help!\n\n");
	
	printf("Harap diingat, command yang dimasukkan selain di atas ini termasuk command yang tidak dikenali BNMO.\n");
	printf("Alhasil akan muncul pesan kesalahan yang menandakan command-mu tidak dikenali.\n\n");
	
	printf("Sekian bantuannya, semoga membantu :)\n");
	printf("Selamat menjalani BNMO ~\n");
}

void QUEUEGAME(QueueStr *BNMOGames, ArrayDyn ListGame) {
	printf("Berikut adalah daftar antrian game-mu\n");
	DisplayStrQueue(*BNMOGames);
	printf("\n");
	LISTGAME(ListGame);
	
	printf("Nomor Game yang mau ditambahkan ke antrian :");
	int idxgame;
    INPUT();
    WordToInt(CWord,&idxgame);
    
    if (idxgame >= 1 && idxgame <= StrLength(ListGame)) {
		enqueueStr(BNMOGames, ListGame.Ar[idxgame - 1]);
		printf("Game berhasil ditambahkan ke dalam antrian.\n");
	} else { // Di luar rentang indeks game yang tersedia
		printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
	}
}

boolean QUIT(boolean EndGame){
    return EndGame = true;
}
