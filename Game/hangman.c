#include "hangman.h"
#include <time.h>

void LoadWordList(ArrayDyn *ListWord) {
/*
    * Melakukan pembacaan file , kemudian menuliskan isinya ke dalam array ListWord
    * I.S : Array ListWord terdefinisi dan kosong
    * F.S : Array ListWord berisi list kata-kata yang ada dalam file listkata.txt
    */

    STARTFILE("../data/listkata.txt");

    int amount = 0;
    WordToInt(CWord, &amount);
    ADVLINEFILE();

    for (int j = 0; j < amount; j++)
    {
        char *words;
        words = wordToString(CWord);
        InsertStrIn(ListWord, words, j);
        ADVLINEFILE();
    }
}

void SaveWordList(ArrayDyn ArrayWord) {
/* 
    * Melakukan penyimpanan (save file)
    * I.S.  : ArrayWord terdefinisi dan nama file mengikuti default
    * F.S.  : File listkata.txt di-overwrite dengan ArrayWord
    * */
    /* Melakukan penyimpan
    {
    /* Melkaukan Save file
    I.S : ArrayWord terdefinisi dan nama file terdefinisi
    F.S : Jika file sudah ada maka file di overwrite*/

    FILE *filebaru;
    filebaru = fopen("../data/listkata.txt", "w");
    fprintf(filebaru, "%d\n", ArrayWord.Neff);
    int i = 0;
    while (i < ArrayWord.Neff) {
        if (i == ArrayWord.Neff - 1) {
            fprintf(filebaru, "%s", ArrayWord.Ar[i]);
        } else {
            fprintf(filebaru, "%s\n", ArrayWord.Ar[i]);
        }
        i++;
    }
    fclose(filebaru);
}

void guessedchars(char *guessed, char current, int pos) {
    /*
        * Menambahkan current ke array guessed di indeks ke-pos
        * I.S : Array guessed terdefinisi, mungkin kosong (apabila di awal)
        * F.S : Array guessed sudah berisi char current pada indeks ke-pos
        */
    guessed[pos] = current;
}

void DisplayHangmanWord(char *array, int length) {
    /*
        * Fungsi untuk menampilkan string (pointer to char) array ke dalam layar
        * Tampilan string memiliki format : "elemen-1 elemen-2 ... elemen-n"
        * Prekondisi : array selalu terdefinisi, dan tidak mungkin kosong
        */
    int z;
    for (z = 0; z < length; z++)
    {
        printf("%c ", array[z]);
    }
    printf("\n");
}

boolean alreadyGuessed(char now, char *guessed) {
    /*
        * Bernilai true apabila now sudah pernah ditebak, yang dalam kata lain,
        * now merupakan elemen dari array guessed.
        * Mengirimkan false jika sebaliknya
        */
    int i = 0;
    boolean already = false;
    while (!already && i < stringLength(guessed)) {
        if (guessed[i] == now) {
            already = true;
        }
        i++;
    }
    return already;
}

void emptystring(char *guessed, int size) {
    for (int i = 0; i < size; i++) {
        guessed[i] = '\0';
    }
}

void hangman(ArrayDyn ArrayGame, ArrayMap * MapGame) {
    /* Fungsi utama untuk game hangman */
    printf("Selamat datang pada game klasik Hangman.\n");
    printf("Anda akan diberikan sebuah kata yang terdiri dari huruf-huruf kecil.\n");
    printf("Anda harus menebak kata tersebut dengan menebak satu huruf per satu.\n");
    printf("Anda hanya memiliki kesempatan 10 kali untuk menebak salah satu huruf.\n");
    printf("Jika Anda berhasil menebak kata tersebut, Anda akan mendapatkan poin sebanyak jumlah huruf pada kata tersebut.\n");
    printf("Jika Anda gagal menebak kata tersebut, Anda akan mendapatkan poin sebanyak 0.\n");
    printf("Selamat bermain!\n\n");

    // Pendefinisian Variabel Global
    char word[20] = {'\0'};         // Array yang berisi kata yang akan ditebak
    char guess[20] = {'\0'};        // Array yang berisi kata yang sudah ditebak
    char characters[30] = {'\0'};   // Array yang berisi karakter yang sudah ditebak
    int mistakes = 0;               // Banyaknya kesalahan
    int i;                          // Variabel untuk keperluan loop incrementation
    int idxword;                    // Variabel untuk menunjukkan index pada array word
    boolean same = false;           // Variabel untuk mengecek apakah kata yang ditebak sama dengan kata yang dirandom
    // bernilai true apabila kata sama, dan false jika sebaliknya
    int score = 0;                  // Variabel untuk menyimpan skor

    // Algoritma Kode (beserta beberapa pendefinisian variabel lokal)
    ArrayDyn HangmanWordList = CreateStrArrayDyn();
    LoadWordList(&HangmanWordList);
    printf("Apakah Anda ingin menambahkan kata baru, atau langsung bermain? Ketik Y apabila ingin, dan N jika tidak. ");
    INPUT();

    if (CWord.TabWord[0] != 'Y' && CWord.TabWord[0] != 'N') {
        while (CWord.TabWord[0] != 'Y' && CWord.TabWord[0] != 'N') {
            printf("Input tidak valid; silahkan masukkan Y apabila ingin menambah kata, dan N jika tidak: ");
            INPUT();
        }
    }
    if (CWord.TabWord[0] == 'Y') {
        while (CWord.TabWord[0] == 'Y') {
            char *newword;
            printf("Masukkan kata yang ingin ditambahkan: ");
            INPUT();
            newword = wordToString(CWord);
            while (FindStrArrayDyn(HangmanWordList, newword) != -1) {
                printf("Kata sudah ada dalam list kata. Silahkan masukkan kata yang lain: ");
                INPUT();
                newword = wordToString(CWord);
            }
            InsertStrLast(&HangmanWordList, newword);
            printf("Apakah ada yang ingin ditambahkan lagi? Ketik Y apabila ingin, dan N jika tidak.");
            INPUT();
        }
    }
    if (CWord.TabWord[0] == 'N') {
        SaveWordList(HangmanWordList);
        DealokasiStrArrayDyn(&HangmanWordList);
        HangmanWordList = CreateStrArrayDyn();
        LoadWordList(&HangmanWordList);
        do {
            srand(time(NULL));
            idxword = rand() % HangmanWordList.Neff; // Mengambil kata secara acak dari list kata dengan penggunaan fungsi rand()
            int p = 0;
            int length = 0; // Panjang kata yang dipilih secara acak
            while (HangmanWordList.Ar[idxword][p] != '\0') {
            // While loop untuk memindahkan kata yang diacak ke variabel lain (word)
                word[p] = HangmanWordList.Ar[idxword][p];
                length++;
                p++;
            }

            int w = 0;
            while (w < length) {
            // While loop untuk inisialisasi array guess dengan '_'
                guess[w] = '_';
                w++;
            }

            int idx = 0;
            while (!same && mistakes < 10) {
            // While loop yang akan berhenti jika kata yang ditebak sudah sama dengan word
                printf("Masukkan tebakan: ");
                INPUT(); // Asumsikan masukan user selalu valid, yaitu 1 karakter dan kapital
                if (alreadyGuessed(CWord.TabWord[0], characters)) {
                    while (alreadyGuessed(CWord.TabWord[0], characters)) {
                        printf("Karakter sudah pernah ditebak sebelumnya!\n");
                        printf("Masukkan tebakan: ");
                        INPUT();
                    }
                }
                int appear = 0; // Variabel untuk menghitung kemunculan huruf yang ditebak dalam kata yang dipilih secara acak
                char curr = CWord.TabWord[0];
                for (i = 0; i < length; i++) {
                    if (97 <= curr <= 122) {
                        if (curr - 32 == word[i]){
                            guess[i] = curr - 32;
                            appear++;
                        }
                    }
                    if (65 <= curr <= 90) {
                        if (curr == word[i]) {
                            guess[i] = curr;
                            appear++;
                        }
                    }
                }
                printf("\n");
                if (appear == 0) {
                // Jika huruf yang ditebak tidak ada dalam kata yang dipilih secara acak
                    mistakes++;
                    printf("Tebakanmu kurang tepat! T_T \n");
                }

                guessedchars(characters, curr, idx);
                idx++;
                printf("Karakter yang sudah ditebak: %s\n", characters); // Menampilkan karakter yang sudah ditebak
                printf("Kata yang sudah ditebak: ");
                DisplayHangmanWord(guess, length);               // Menampilkan progres array guess sejauh setiap tebakan
                printf("Sisa kesempatan : %d\n", 10 - mistakes); // Menampilkan sisa kesempatan

                if (IsStringEqual(guess, word)) {
                // Kata yang ditebak sudah sama dengan kata yang dipilih secara acak
                    printf("\nSelamat, Anda berhasil menebak kata tersebut! \n");
                    printf("Katanya adalah: %s\n", guess);                       // Menampilkan kata yang ditebak
                    printf("Kamu berhasil mendapatkan %d poin! ^-^ \n", length); // Menampilkan score
                    score += length;                                             // Menambahkan score dengan panjang kata yang ditebak
                    same = true;
                }
            }
            same = false; // Nilai boolean direset, dan memungkinkan untuk pengambilan kata acak kembali selama mistakes < 10
            emptystring(characters, 30);
            emptystring(guess, 20);
            emptystring(word, 20);
            printf("\n");
        } while (mistakes < 10);
    }
    if (mistakes == 10) {
        printf("\nKesempatanmu sudah habis! ):( \n");
        printf("Kata yang tepat adalah: %s\n", HangmanWordList.Ar[idxword]);
        printf("Total score yang diperoleh: %d\n", score); // Menampilkan total skor yang diperoleh
        printf("Semoga menikmati permainannya, dan jangan lupa untuk bermain kembali! (sad noises)\n");
    }

    int index = FindStrArrayDyn(ArrayGame, "HANGMAN");
    InsertScoreBoard(&MapGame->ElArrMap[index], score);
}
