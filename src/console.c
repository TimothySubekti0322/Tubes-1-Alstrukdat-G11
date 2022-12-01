#include <stdio.h>
#include <stdlib.h>
#include "console.h"


void STARTBNMO(ArrayDyn *gamesBNMO , ArrayMap *MapGame)
{
    /* Membaca file config dan memasukan tiap baris file ke array gamesBNMO*/

    STARTFILE("../data/config.txt");
    int jumlahGame;
    jumlahGame = atoi(CWord.TabWord);
    ADVLINEFILE();

    for(int i = 0; i < jumlahGame; i++){
        char *namaGame;
        namaGame = wordToString(CWord);
        InsertStrIn(gamesBNMO,namaGame,i);
        Map M;
        CreateEmpty(&M);
        InsertMapLast(MapGame,M);
        ADVLINEFILE();
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

char *wordToString(Word CWord)
{
    /* Mengubah Word menjadi string*/
    char *string;

    string = malloc(CWord.Length * sizeof(char));
    int i = 0;
    while (i < CWord.Length)
    {
        *(string+i) = CWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
    return string;
}

boolean CompareString(char *string1 , char *string2)
{
    /* Mengirimkan true jika string1 = string2 */
    boolean equal = true;
    if (stringLength(string1) != stringLength(string2))
    {
        return false;
    }
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
    return equal;
}

boolean IsInQueue(QueueStr *Queue,char *string)
{
    /* Mengirimkan true jika string yang diinput ada didalam Queue*/
    int i = lengthStr(*Queue);
    boolean availabe = false;
    int j = 0;
    while ((j < i) && (!availabe))
    {
        if(CompareString(Queue->buffer[j],string))
        {
            availabe = true;
        }
        else
        {
            j++;
        }
    }
    return availabe;
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
    /* Mengubah Kata to Int
   I.S : Kata dan hasil terdefinisi
   F.S : hasil merupakan integer dari element Kata*/

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
    /* Menyalin kata ke string
   I.S : Input terdefinisi , String , Awal , dan Akhir terdefinisi
   F.S : string berisis elemen elemen kata dari Indeks Awal hingga Indeks Akhir */

    int i;
    int j = 0;
    for(i = Awal ; i <= Akhir  ; i++)
    {
        *(string + j) = Input.TabWord[i];
        j++;
    }
    *(string + j) = '\0';
}

void delay(float seconds)
{
    /* Memberikan Jeda untuk program mengeksekusi baris berikutnya */

    // Convert seconds into milli_seconds
    float milli_seconds = 1000 * seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
    ;
}

int IntLength(int n)
{
/* Menghitung banyak Digit*/
    int count = 0;
    do
    {
        count++;
        n /= 10;
    } while(n != 0);
    return count;

}

void printblank(int n)
{
/* Mencetak Blank Sebanyak n ke layar */
    for (int i = 1 ; i <= n ; i++)
    {
        printf(" ");
    }
}

void printstrip(int n)
{
/* Mencetak '-' sebanyak n ke layar */
    for (int i = 1 ; i <= n ; i++)
    {
        printf("-");
    }
}

void printsingelhorizontalline(int n)
{
/* Mencetak Horizontal line sebanyak n ke layar */
    int horizontalline = 196;
    for (int i = 1 ; i <= n ; i++)
    {
        printf("%c",horizontalline);
    }
}

void printscoreboard(Map M , char *namagame)
{
    /* Melakukan Print scroeboard 1 buah Game*/
    int asciTLC = 218;
    int asciH = 196;
    int asciT = 194;
    int asciTRC = 191;
    int asciTkiri = 195;
    int asciTkanan = 180;
    int asciTbawah = 193;
    int asciBLC = 192;
    int asciBRC = 217;
    int asciV = 179;
    int asciplus = 197;

    int lengamename = stringLength(namagame);

    /* Top */
    for(int i = 1 ; i <= 47 ; i++)
    {
        if (i == 1)
        {
            printf("%c",asciTLC);
        }
        else if(i == 47)
        {
            printf("%c",asciTRC);
        }
        else
        {
            printf("%c",asciH);
        }
    }
    printf("\n");

    // 16 + lengamename + blank = 47 -> 31 = lengamename + blank
    
    /* Title */
    printf("%c",asciV);
    printblank((30 - lengamename)/2);
    printf("SCOREBOARD GAME %s", namagame);
    printblank((29 - lengamename)/2);
    printf("%c",asciV);
    printf("\n");

    /* Title - Head Separator */
    for(int i = 1 ; i <= 47 ; i++)
    {
        if (i == 1)
        {
            printf("%c",asciTkiri);
        }
        else if(i == 47)
        {
            printf("%c",asciTkanan);
        }
        else if (i == 24)
        {
            printf("%c",asciT);
        }
        else
        {
            printf("%c",asciH);
        }
    }
    printf("\n");

    printf("%c ",asciV);
    printf("NAMA");
    int Blank = 17;
    printblank(Blank);
    printf("%c ",asciV);
    printf("SKOR");
    printblank(Blank);
    printf("%c",asciV);
    printf("\n");
    if (!IsEmpty(M))
    {
        /* Head - Body Separator */
        printf("%c",asciTkiri);
        printsingelhorizontalline(22);
        printf("%c",asciplus);
        printsingelhorizontalline(22);
        printf("%c",asciTkanan);
        printf("\n");

        /* Body */
        int i;
        for (i = 0 ; i < M.Count ; i++)
        {
            printf("%c ",asciV);
            printf("%s",M.Elements[i].Key);
            Blank = (21 - stringLength(M.Elements[i].Key));
            printblank(Blank);
            printf("%c ",asciV);
            printf("%d",M.Elements[i].Value);
            Blank = (21 - IntLength(M.Elements[i].Value));
            printblank(Blank);
            printf("%c",asciV);
            printf("\n");
        }

        /* Bottom */
        for(int i = 1 ; i <= 47 ; i++)
        {
            if (i == 1)
            {
                printf("%c",asciBLC);
            }
            else if(i == 47)
            {
                printf("%c",asciBRC);
            }
            else if(i == 24)
            {
                printf("%c",asciTbawah);
            }
            else
            {
                printf("%c",asciH);
            }
        }
        printf("\n");
    }
    else
    {
         /* Head - Body Separator */
        printf("%c",asciTkiri);
        printsingelhorizontalline(22);
        printf("%c",asciTbawah);
        printsingelhorizontalline(22);
        printf("%c",asciTkanan);
        printf("\n");

        /* Body */
        // 30 sisanya
        printf("%c",asciV);
        printblank(14);
        printf("SCOREBOARD KOSONG");
        printblank(14);
        printf("%c",asciV);
        printf("\n");

        /* Bottom */
        for(int i = 1 ; i <= 47 ; i++)
        {
            if (i == 1)
            {
                printf("%c",asciBLC);
            }
            else if(i == 47)
            {
                printf("%c",asciBRC);
            }
            else
            {
                printf("%c",asciH);
            }
        }
        printf("\n");
        // printf("-------------- SCOREBOARD KOSONG --------------\n");
    }
}

boolean IsStringEqual(char *string1 , char* string2)
{
/* Mengirimkan True jika string 1 sama dengan string 2 baik Uppercase maupun Lowercase*/
    int i = 0;
    boolean sama = true;
    if (stringLength(string1) != stringLength(string2))
    {
        sama = false;
        return sama;
    }
    while (*(string1 + i) != '\0' && *(string2 + i) != '\0' && sama)
    {
        int j = *(string2 + i);
        if ((j >= 65) && (j <= 90))
        {
            if ((*(string1 + i) != *(string2 + i)) && (*(string1 + i) != *(string2 + i) + 32))
            {
                sama = false;
            }
        }
        else if ((j >= 97) && (j <= 122))
        {
            if ((*(string1 + i) != *(string2 + i)) && (*(string1 + i) != *(string2 + i) - 32))
            {
                sama = false;
            }
        }
        else
        {
            if(*(string1 + i) != *(string2 + i))
            {
                sama = false;
            }
        }
        i++;
    }
    return sama;
}

boolean IsMemberScoreBoard(Map M, keytype k)
{
/* Mengembalikan true jika k adalah member dari M */
    int i = 0;
    boolean found = false;
    while ((i < M.Count) && (!found))
    {
        if (IsStringEqual((M).Elements[i].Key , k))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

void InsertScoreBoard(Map *M, valuetype v)
{
    printf("Masukan Username [maksimal 20 karakter] : ");
    INPUT();
    char *name;
    // name = (char *) malloc (CWord.Length * sizeof(char)); 
    name = wordToString(CWord);
    printf("\n");
    //printf("\n name = %s\n",name);
    while(IsMemberScoreBoard(*M,name))
    {
        printf("Username sudah dipakai , silahkan gunakan username lain\n");
        printf("Masukan Username [maksimal 20 karakter] : ");
        INPUT();
        // char *name;
        // name = (char *) malloc (CWord.Length * sizeof(char));
        name = wordToString(CWord);
        //printf("\n name = %s\n",name);
    }
    
    int asciLTC = 218;
    int asciLBC = 192;
    int asciRTC = 191;
    int asciRBC = 217;
    int asciV = 179;
    int asciH = 196;
    
    // 34 = 0 huruf
    // 35 =  1 huruf
    
    int NameLen = stringLength(name);

    printf("%c",asciLTC);
    for (int Hor = 1 ; Hor <= 34 + NameLen ; Hor++)
    {
        printf("%c",asciH);
    }
    printf("%c\n",asciRTC);
    printf("%c  USERNAME %s BERHASIL DIDAFTARKAN  %c\n",asciV,name,asciV);
    printf("%c",asciLBC);
    for (int Hor = 1 ; Hor <= 34 + NameLen ; Hor++)
    {
        printf("%c",asciH);
    }
    printf("%c\n",asciRBC);
    printf("\n");

    if(!IsMember(*M,name))
    {
        int i = 0;
        boolean found = false;
        while ((i < M->Count) && (!found))
        {
            if (v > (*M).Elements[i].Value)
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
        int j;
        for(j = M->Count ; j > i ; j--)
        {
            (*M).Elements[j].Key = (*M).Elements[j-1].Key;
            (*M).Elements[j].Value = (*M).Elements[j-1].Value;
        }
        (*M).Elements[i].Key = name;
        (*M).Elements[i].Value = v;
        (*M).Count++;
    }
}

TypeIdx FindStrArrayDynCreateGame(ArrayDyn array, TypeEl elmt) {
	boolean found = false;
	int LocationIdx = -1;
	int i = 0;
	while (i < array.Neff && !found) {
		if (IsStringEqual(array.Ar[i],elmt)) 
		{
			found = true;
			LocationIdx = i;
		}
		i++;
	}
	return LocationIdx;
}

void DeleteHistoryifEqual(StackStr *History , char *string)
{
    /* Menghapus semua Element Stack yang Sama dengan string */
    StackStr temp;
    CreateEmptyStackStr(&temp);
    char *tempstring;
    //tempstring = (char *) malloc (100 * sizeof(char));
    while (!IsStackStrEmpty(*History))
    {
        // printf("\nBerhasil 1\n");
        PopStackStr(History,&tempstring);
        if (!IsStringEqual(tempstring,string))
        {
            // printf("\nBerhasil 2\n");
            PushStackStr(&temp,tempstring);
        }
    }
    while (!IsStackStrEmpty(temp))
    {
        // printf("\nBerhasil 3\n");
        PopStackStr(&temp,&tempstring);
        PushStackStr(History,tempstring);
    }
}

/* COMMAND FUNCTION*/

void LOADFILE(ArrayDyn *Games, char *inputfile, ArrayMap *MapGame , StackStr *History)
{
    /* Melakukan pembacaan file , kemudian menuliskan isinya edalam Array Games
   I.S : File yang diinput terdefinisi , Array Games terdefinisi dan kosong
   F.S : Array games berisis list Game yang ada dalam file*/

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

        int amount = 0;
        WordToInt(CWord,&amount);

        //printf("\namount = %d\n",amount);
        
        ADVLINEFILE(); /* word pertama yang dibaca adalah jumlah game*/

        for (int j = 0; j < amount; j++)
        {
            char *gamename;
            gamename = wordToString(CWord);
            
            // printf("%s\n",gamename);
            // printf("Sampe sini 2\n");
            //InsertStrLast(Games,string);
            
            InsertStrIn(Games, gamename, j);
            
            // printf("%s\n",gamename);
            // ShowStrArrayDyn(*Games);
            // printf("\n%s\n",Games->Ar[j]);
            
            ADVLINEFILE();
        }

        /* Menambahkan History */
        //printf("\nSampai sini load List Berhasil\n");
        
        int amounthistory = 0;
        WordToInt(CWord,&amounthistory);
        ADVLINEFILE();
        for (int k = 0; k < amounthistory; k++)
        {
            char *HistoryGame;
            HistoryGame = wordToString(CWord);
            PushStackStr(History,HistoryGame);
            ADVLINEFILE();
        }
        ReverseStack(History);
        //printf("\nSampai sini load History Berhasil\n");
        
        int amountscoreboard;
        int z , w;
        for (w = 0; w < amount; w++)
        {
            //printf("\nMasuk Loop ke %d\n",w+1);
            
            Map M;
            CreateEmpty(&M);
            amountscoreboard = 0;
            WordToInt(CWord,&amountscoreboard);
            
            //printf("\namountscoreboard = %d\n",amountscoreboard);
            
            IgnoreNewLine();
            ADVWORD();
            
            //printf("\nABIS INI MASUK KE INNER LOOP\n");
            for (z = 0; z < amountscoreboard ; z++)
            {
                //printf("\nz = %d\n",z);
                
                char *scoreboardkey;
                scoreboardkey = wordToString(CWord);
                
                //printf("\nscoreboardkey = %s\n",scoreboardkey);
                
                ADVWORD();
                
                //printf("CWord karakter 1 = %c",CWord.TabWord[1]);
                
                int scoreboardvalue = 0;
                WordToInt(CWord,&scoreboardvalue); 
                
                //printf("\nscoreboardvalue = %d\n",scoreboardvalue);
                
                Insert(&M, scoreboardkey , scoreboardvalue);
                IgnoreNewLine();
                ADVWORD();
                
                //printf("CWord karakter 0 = %c",CWord.TabWord[0]);
                
            }
            
            //printf("\nMap Value = %d\n",M.Elements[z-1].Value);
            
            InsertMapLast(MapGame,M);
        }

        //printf("\nSampai sini load Scoreboard Berhasil\n");
        if (CompareString(path,"../data/config.txt"))
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
        }   
    }
}


void Save(ArrayDyn ArrayGame, char *namafile, StackStr History, ArrayMap MapGame)
{
    /* Melakukan penyimpan
{
   Melkaukan Save file
   I.S : ArrayGame terdefinisi dan nama file terdefinisi
   F.S : Jika file sudah ada maka file di overwrite , Jika tidak ada akan membuat file baru*/

    char placeholder[] = "../data/";
    char path[50];

    concat(placeholder, namafile, path);

    FILE* filebaru;
    filebaru = fopen(path,"w");
    fprintf(filebaru, "%d\n", ArrayGame.Neff);
    int i;
    for (i=0; i<ArrayGame.Neff; i++){
        fprintf(filebaru, "%s\n", ArrayGame.Ar[i]);
    }
    // fprintf(filebaru, "%s", ArrayGame.Ar[i]);
    fprintf(filebaru, "%d\n", History.TOP + 1);
    int j;
    for (j=0; j< History.TOP + 1; j++)
    {
        fprintf(filebaru, "%s\n", History.T[j]);
    }
    int k,l;
    for (k=0; k < MapGame.NeffArrMap ; k++)
    {
        if ((k == MapGame.NeffArrMap-1) && (MapGame.ElArrMap[k].Count == 0))
        {
            fprintf(filebaru, "%d", MapGame.ElArrMap[k].Count);
        }
        else
        {
            fprintf(filebaru, "%d\n", MapGame.ElArrMap[k].Count);
        }
        if(k != MapGame.NeffArrMap-1)
        {
            for(l=0; l < MapGame.ElArrMap[k].Count; l++)
            {
                fprintf(filebaru, "%s %d\n", MapGame.ElArrMap[k].Elements[l].Key , MapGame.ElArrMap[k].Elements[l].Value);
            }
        }
        else
        {
            for(l=0; l < MapGame.ElArrMap[k].Count; l++)
            {
                if (l != MapGame.ElArrMap[k].Count - 1)
                {
                    fprintf(filebaru, "%s %d\n", MapGame.ElArrMap[k].Elements[l].Key , MapGame.ElArrMap[k].Elements[l].Value);
                }
                else
                {
                    fprintf(filebaru, "%s %d", MapGame.ElArrMap[k].Elements[l].Key , MapGame.ElArrMap[k].Elements[l].Value);
                }
            }
        }
    }
    fclose(filebaru);
    printf("Save file berhasil disimpan. \n");
}

void LISTGAME(ArrayDyn arraygames)
{
    /* Menampilkan ListGame yang tersedia 
   I.S : arraygames terdefinisi
   F.S : menampilakn seluruh elemen arraygames*/

    printf("Berikut adalah daftar game yang tersedia");
    printf("\n");
    for (int i = 0; i < arraygames.Neff; i++)
    {
        printf("%d. %s\n", i + 1, arraygames.Ar[i]);
    }

}

void DELETEGAME(ArrayDyn *Games, QueueStr *Queue , ArrayMap *MapGame, StackStr *History)
{
    /* Melakukan penghapusan suatu game
   I.S : Arraygames terdefinisi
   F.S : Melakukan penghapusan game jika ada pada array, mengeluarkan pesan error
         jika tidak terdefinisi atau termasuk dalam game default*/

    int indeksgame = 0;
    LISTGAME(*Games);
    printf("Masukkan nomor game yang akan dihapus: ");
    INPUT();
    printf("\n");
    WordToInt(CWord,&indeksgame);
    //printf("%d\n",indeksgame);
    //int length = StrLength(*Games);
    //printf("%d\n",indeksgame);
    if(indeksgame >= 1 && indeksgame <= 6)
    {
        printf("Game gagal dihapus karena merupakan game default.\n");
    } 
    else if(indeksgame > StrLength(*Games))
    {
        printf("Game gagal dihapus karena indeks yang dimasukkan tidak valid.\n");
    }
    else if(IsInQueue(Queue,GetStr(*Games,indeksgame-1)))
    {
        printf("Game gagal dihapus karena game berada dalam Queue\n");
    }
    else if(indeksgame > 6 && indeksgame <= StrLength(*Games) && !IsInQueue(Queue,GetStr(*Games,indeksgame-1)))
    {
        DeleteHistoryifEqual(History , GetStr(*Games,indeksgame-1));
        CreateEmpty(&MapGame->ElArrMap[indeksgame-1]);
        DeleteMapAt(MapGame,indeksgame-1);
        DeleteStrIn(Games,indeksgame-1);

        printf("Game berhasil dihapus\n");
    }
}

void CreateGame(ArrayDyn* ArrayGame, ArrayMap *MapGame)
{
    /* Melakukan penambahan suatu game
   I.S : ArrayGame terdefinisi
   F.S : Melakukan penambahan game pada array, meminta validasi dengan input 
         ulang jika game sudah ada di dalam array*/

    char *input;
    printf("Masukkan nama game yang akan ditambahkan: ");
    INPUT();
    input = wordToString(CWord);
    //Melakukan validasi input, apakah sudah ada game yang bernama sama dengan input atau belum
    while (FindStrArrayDynCreateGame(*ArrayGame, input) != -1)
    {
        printf("Game sudah ada, silahkan input ulang\n");
        printf("Masukkan nama game yang akan ditambahkan: ");
        INPUT();
        input = wordToString(CWord);           
    }
    //Melakukan penambahan game yang diinput
    InsertStrLast(ArrayGame, input);
    printf("Game berhasil ditambahkan\n");
    Map M;
    CreateEmpty(&M);
    InsertMapLast(MapGame,M);
}

void PlayGame(QueueStr* AntrianGame , StackStr *History , ArrayMap *MapGame , ArrayDyn ArrayGame)
{
    /* Menjalankan suatu game
   I.S : ArrayGame terdefinisi
   F.S : Menjalankan game yang terdapat di paling atas pada ADT Queue yang
         menyimpan antrian game*/

    if (isStrEmpty(*AntrianGame)){
        printf("Tidak ada antrian game untuk dimainkan, silahkan daftar game ke antrian dengan menggunakan command QUEUE GAME");
    } else { 
        printf("Berikut adalah daftar Game-mu\n");
        DisplayStrQueue(*AntrianGame);
        // char game[20];
        char game[20];
        dequeueStr(AntrianGame,game);

        //printf("%s\n",game);
        //printf("Loading %s ...", game);
        if (CompareString(game,"RNG"))
        {
            // printf("SAMPAI SINI 1");
            printf("Loading RNG ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(".\n");
            delay(0.8);
            gameRNG(ArrayGame, MapGame);
        } 
        else if (CompareString(game,"DINER DASH"))
        {
            //printf("SAMPAI SINI 2");
            printf("Loading DINER DASH ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(".\n");
            delay(0.8);
            dinnerdash(ArrayGame, MapGame);
        }
        else if (CompareString(game,"HANGMAN"))
        {
            //printf("SAMPAI SINI 2");
            printf("Loading HANGMAN ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(".\n");
            delay(0.8);
            hangman(ArrayGame, MapGame);
        }

        else if (CompareString(game,"TOWER OF HANOI"))
        {
            //printf("SAMPAI SINI 2");
            printf("Loading TOWER OF HANOI ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(".\n");
            delay(0.8);
            towerhanoi(ArrayGame, MapGame);
        }

        else if (CompareString(game,"SNAKE ON METEOR"))
        {
            //printf("SAMPAI SINI 2");
            printf("Loading SNAKE ON METEOR ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(".\n");
            delay(0.8);
            SnakeOnMeteor(ArrayGame, MapGame);
        }

        else if(CompareString(game,"MOLE"))
        {
            printf("Loading MOLE ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(".\n");
            delay(0.8);
            mole(ArrayGame, MapGame);
        }

        else if (CompareString(game,"TREASURE HUNT"))
        {
            //printf("SAMPAI SINI 2");
            printf("Loading TREASURE HUNT ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(". ");
            delay(0.8);
            printf(".\n");
            delay(0.8);
            treasure_hunt(ArrayGame, MapGame);
        }

        else
        {
            srand(time(NULL));
            int SKOR = rand() % 100 + 1;
            printf("GAME OVER !\n");
            printf("SKOR AKHIR = %d\n", SKOR);
            int index = FindStrArrayDyn(ArrayGame,game);
            InsertScoreBoard(&MapGame->ElArrMap[index], SKOR);
        }

        int length = stringLength(game);
        char *gametohistory;
        gametohistory = (char *) malloc (length * sizeof(char));
        int i;
        for (i = 0 ; i < length ; i++)
        {
            *(gametohistory + i) = game[i];
        }
        gametohistory[i] = '\0';
        PushStackStr(History, gametohistory);
    }
}

void SkipGame(QueueStr* AntrianGame, int number , ArrayMap *MapGame , ArrayDyn ArrayGame , StackStr *History )
{
    
    /* Menjalankan suatu game dengan skip game sebanyak number
   I.S : Arraygames terdefinisi
   F.S : Melewatkan game sebanyak number dari atas, dan menjalankan game apabila
         masih terdapat game dalam ADT Queue*/

    if (isStrEmpty(*AntrianGame)){
        printf("Tidak ada antrian game untuk diskip, silahkan daftar game ke antrian dengan menggunakan command QUEUE GAME");
    } else { 
        printf("Berikut adalah daftar Game-mu\n");
        DisplayStrQueue(*AntrianGame);
        char game[100];
        int i = 0;
        while (!isStrEmpty(*AntrianGame) && i<number){
            dequeueStr(AntrianGame,game);
            i++;
        }

        if (isStrEmpty(*AntrianGame)){
            printf("Tidak ada permainan lagi dalam daftar game-mu");
        } else { 
            dequeueStr(AntrianGame,game);
            if (CompareString(game,"RNG") || CompareString(game,"DINER DASH") || CompareString(game,"MOLE") || CompareString(game,"HANGMAN") || CompareString(game,"TOWER OF HANOI") || CompareString(game,"SNAKE ON METEOR") || CompareString(game,"TREASURE HUNT"))
            { 
                printf("Loading %s ", game);
                delay(1);
                printf(". ");
                delay(1);
                printf(". ");
                delay(1);
                printf(".\n");
                delay(1);
                
                if (CompareString(game,"RNG"))
                {
                    gameRNG(ArrayGame,MapGame);
                } 
                else if (CompareString(game,"DINER DASH"))
                {
                    dinnerdash(ArrayGame, MapGame);
                }
                else if (CompareString(game,"MOLE"))
                {
                    mole(ArrayGame, MapGame);
                }
                else if (CompareString(game,"HANGMAN"))
                {
                    hangman(ArrayGame, MapGame);
                }

                else if (CompareString(game,"TOWER OF HANOI"))
                {
                    towerhanoi(ArrayGame,MapGame);
                }

                else if (CompareString(game,"SNAKE ON METEOR"))
                {
                    SnakeOnMeteor(ArrayGame,MapGame);
                }
                else if (CompareString(game,"TREASURE HUNT"))
                {
                    treasure_hunt(ArrayGame, MapGame);
                }

                
            } 
            else
            {
                srand(time(NULL));
                int SKOR = rand() % 100 + 1;
                printf("GAME OVER !\n");
                printf("SKOR AKHIR = %d\n", SKOR);
                int index = FindStrArrayDyn(ArrayGame,game);
                InsertScoreBoard(&MapGame->ElArrMap[index], SKOR);
            }
            int length = stringLength(game);
            char *gametohistory;
            gametohistory = (char *) malloc (length * sizeof(char));
            int i;
            for (i = 0 ; i < length ; i++)
            {
                *(gametohistory + i) = game[i];
            }
            gametohistory[i] = '\0';
            PushStackStr(History, gametohistory);
        }
    }
}

void HELP() 
{
    /* Menampilkan daftar command-command yang tersedia,
    * apa saja yang dapat dilakukan dengan masing-masing command,
    * dan cara memanggilnya.
    */

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

void QUEUEGAME(QueueStr *BNMOGames, ArrayDyn ListGame) 
{
    /* Menampilkan antrian terkini dari game user, lalu memperbolehkan
    * user untuk menambahkan game sesuai list game yang tersedia di BNMO.
    * Apabila indeks game yang dipilih berada pada rentang indeks game BNMO,
    * game berhasil ditambahkan ke antrian.
    * Jika tidak, akan muncul pesan kesalahan dan game gagal ditambahkan.
    */

	printf("Berikut adalah daftar antrian game-mu\n");
	DisplayStrQueue(*BNMOGames);
	printf("\n");
	LISTGAME(ListGame);
	printf("\n");
	printf("Nomor Game yang mau ditambahkan ke antrian : ");
	int idxgame = 0;
    INPUT();
    WordToInt(CWord,&idxgame);
    printf("\n");
    //printf("%d\n",idxgame);
    if (idxgame >= 1 && idxgame <= StrLength(ListGame)) 
    {
		enqueueStr(BNMOGames, ListGame.Ar[idxgame - 1]);
		printf("Game berhasil ditambahkan ke dalam antrian.\n");
	} 
    else 
    { // Di luar rentang indeks game yang tersedia
		printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
	}
}

void SCOREBOARD(ArrayDyn listgame , ArrayMap M)
{
/* Menampilkan Scoreboard game ke layar */
    printf("\n");
    int i;
    for (i = 0 ; i < M.NeffArrMap ; i++)
    {
        printscoreboard(M.ElArrMap[i] , listgame.Ar[i]);
        printf("\n");
        printf("\n");
    }
}

void HISTORY(StackStr history, int n)
{
    if (!IsStackStrEmpty(history))
    {
        printf("Berikut adalah daftar Game yang telah dimainkan\n");
        int i = 1;
        while ((i <= n) && !IsStackStrEmpty(history))
        {
            char* namagame;
            //printf("%s\n",INFOTop(history));
            PopStackStr(&history,&namagame);
            printf("%d. %s\n",i,namagame);
            i++;
        }
    }
    else
    {
        printf("Belum ada game yang dimainkan\n");
    }
}

void RESETSCOREBOARD(ArrayDyn listgame , ArrayMap *M)
{
    printf("\nDAFTAR SCOREBOARD: \n");
    printf("0. ALL\n");
    int i;
    for(i = 0 ; i < listgame.Neff ; i++)
    {
        printf("%d. %s\n",i+1,listgame.Ar[i]);
    }

    printf("\nSCOREBOARD YANG INGIN DIHAPUS: ");
    INPUT();
    int n = 0;
    WordToInt(CWord,&n);
    if (n == 0)
    {
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
        INPUT();
        char *validasi = wordToString(CWord);
        int asci = 254;
        if (CompareString(validasi,"YA"))
        {
            int j;
            for(j = 0 ; j < listgame.Neff ; j++)
            {
                CreateEmpty(&M->ElArrMap[j]);
            }

            printf("\n%c ALL SCOREBOARD BERHASIL DIHAPUS %c\n",asci,asci);
        }
        else
        {
            printf("\n%c ALL SCOREBOARD GAGAL DIHAPUS %c\n",asci,asci);
        }
    }
    else if (n >= 1 && n <= listgame.Neff)
    {
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ",listgame.Ar[n-1]);
        INPUT();
        char *validasi = wordToString(CWord);
        int asci = 254;
        if (CompareString(validasi,"YA"))
        {
            CreateEmpty(&M->ElArrMap[n-1]);
            printf("\n%c SCOREBOARD %s BERHASIL DIHAPUS %c\n",asci,listgame.Ar[n-1],asci);
        }
        else
        {
            printf("\n%c SCOREBOARD %s GAGAL DIHAPUS %c\n",asci,listgame.Ar[n-1],asci);
        }
    }   
    else
    {
        printf("\nIndex Tidak Valid ! Silahkan Masukan Index yang valid\n");
        RESETSCOREBOARD(listgame,M);
    } 
}

void RESETHISTORY(StackStr *history)
{
    printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HSTORY (YA/TIDAK)? ");
    INPUT();
    printf("\n");
    char *validasi = wordToString(CWord);
    if (CompareString(validasi,"YA"))
    {
        CreateEmptyStackStr(history);
        printf("History berhasil di-reset.\n");
    }
    else if (CompareString(validasi,"TIDAK"))
    {
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        int n = (Top(*history));
        int i;
        int j = 1;
        for (i = n ; i >= 0 ; i--)
        {
            printf("%d. %s\n",j, history->T[i]);
            j++;
        }
    }
}

void QUIT(boolean EndGame)
{
    /*
   I.S : EndGame bernilai false
   F.S : Endgame bernilai true
*/
    EndGame = true;
}

// Melakukan print dengan warna
void PrintGreen(char* input){
   printf(GRN"%s"reset,input);
}

void PrintRed(char* input){
   printf(RED"%s"reset,input);
}

void PrintYellow(char* input){
   printf(YEL"%s"reset,input);
}

void PrintBlue(char* input){
   printf(BLU"%s"reset,input);
}

void PrintGreenchar(char input){
   printf(GRN"%c"reset,input);
}

void PrintRedchar(char input){
   printf(RED"%c"reset,input);
}

void PrintYellowchar(char input){
   printf(YEL"%c"reset,input);
}

void PrintBluechar(char input){
   printf(BLU"%c"reset,input);
}
