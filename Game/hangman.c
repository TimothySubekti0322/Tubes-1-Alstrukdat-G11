#include "hangman.h"

void LoadWordList(ArrayDyn *ListWord)
{
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
    for (z = 0; z < length; z++) {
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

void emptyguessed(char *guessed)
{
    for (int i = 0; i < 30; i++)
    {
        guessed[i] = '\0';
    }
}

void hangman(ArrayDyn ArrayGame, ArrayMap *MapGame)
{
    /* Fungsi utama untuk game hangman */
    printf("Selamat datang pada game klasik Hangman.\n");
    printf("Anda akan diberikan sebuah kata yang terdiri dari huruf-huruf kecil.\n");
    printf("Anda harus menebak kata tersebut dengan menebak satu huruf per satu.\n");
    printf("Anda hanya memiliki kesempatan 10 kali untuk menebak salah satu huruf.\n");
    printf("Jika Anda berhasil menebak kata tersebut, Anda akan mendapatkan poin sebanyak jumlah huruf pada kata tersebut.\n");
    printf("Jika Anda gagal menebak kata tersebut, Anda akan mendapatkan poin sebanyak 0.\n");
    printf("Selamat bermain!\n\n");

    // Pendefinisian Variabel Global
    char word[20];                // Array yang berisi kata yang akan ditebak
    char guess[20];               // Array yang berisi kata yang sudah ditebak
    char characters[30] = {'\0'}; // Array yang berisi karakter yang sudah ditebak
    int mistakes = 0;             // Banyaknya kesalahan
    int i;                        // Variabel untuk keperluan loop incrementation
    int idxword;                  // Variabel untuk menunjukkan index pada array word
    boolean same = false;         // Variabel untuk mengecek apakah kata yang ditebak sama dengan kata yang dirandom
    // bernilai true apabila kata sama, dan false jika sebaliknya
    int score = 0; // Variabel untuk menyimpan skor

    // Algoritma Kode (beserta beberapa pendefinisian variabel lokal)
    ArrayDyn HangmanWordList = CreateStrArrayDyn();
    LoadWordList(&HangmanWordList);

    while (mistakes < 10)
    {
        idxword = rand() % HangmanWordList.Neff; // Mengambil kata secara acak dari list kata dengan penggunaan fungsi rand()
        int p = 0;
        int length = 0; // Panjang kata yang dipilih secara acak
        while (HangmanWordList.Ar[idxword][p] != '\0')
        { // While loop untuk memindahkan kata yang diacak ke variabel lain (word)
            word[p] = HangmanWordList.Ar[idxword][p];
            length++;
            p++;
        }

        int w = 0;
        while (w < length)
        { // While loop untuk inisialisasi array guess dengan '_'
            guess[w] = '_';
            w++;
        }

        int idx = 0;
        while (!same && mistakes < 10)
        { // While loop yang akan berhenti jika kata yang ditebak sudah sama dengan word
            printf("Masukkan tebakan: ");
            INPUT();
            if (alreadyGuessed(CWord.TabWord[0], characters))
            {
                while (alreadyGuessed(CWord.TabWord[0], characters))
                {
                    printf("Karakter sudah pernah ditebak sebelumnya!\n");
                    printf("Masukkan tebakan: ");
                    INPUT();
                }
            }
            int appear = 0; // Variabel untuk menghitung kemunculan huruf yang ditebak dalam kata yang dipilih secara acak
            char curr = CWord.TabWord[0];
            for (i = 0; i < length; i++)
            {
                if (curr == word[i])
                {
                    guess[i] = curr;
                    appear++;
                }
            }
            if (appear == 0)
            { // Jika huruf yang ditebak tidak ada dalam kata yang dipilih secara acak
                mistakes++;
            }

            guessedchars(characters, curr, idx);
            idx++;
            printf("Karakter yang sudah ditebak: %s\n", characters); // Menampilkan karakter yang sudah ditebak
            printf("Kata yang sudah ditebak: ");
            DisplayHangmanWord(guess, length);               // Menampilkan progres array guess sejauh setiap tebakan
            printf("Sisa kesempatan : %d\n", 10 - mistakes); // Menampilkan sisa kesempatan

            if (IsStringEqual(guess, word))
            { // Kata yang ditebak sudah sama dengan kata yang dipilih secara acak
                printf("\nSelamat, Anda berhasil menebak kata tersebut!\n");
                printf("Katanya adalah: %s\n", guess);                  // Menampilkan kata yang ditebak
                printf("Kamu berhasil mendapatkan %d poin!\n", length); // Menampilkan score
                score += length;                                        // Menambahkan score dengan panjang kata yang ditebak
                same = true;
            }
        }
        same = false; // Nilai boolean direset, dan memungkinkan untuk pengambilan kata acak kembali selama mistakes < 10
        emptyguessed(characters);
    }

    printf("\nKesempatanmu sudah habis!\n");
    printf("Total score yang diperoleh: %d\n", score); // Menampilkan total skor yang diperoleh
    printf("Semoga menikmati permainannya, dan jangan lupa untuk bermain kembali!\n");

    int index = FindStrArrayDyn(ArrayGame, "HANGMAN");
    InsertScoreBoard(&MapGame->ElArrMap[index], score);
}