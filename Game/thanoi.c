#include "thanoi.h"

void CreateStackIntA(StackInt *S, int size){
    int i;
    CreateEmptyStackHanoi(S);
    for (i = size ; i > 0; i--) 
    {
        PushStackInt(S, i);
    }
}


void displaystack(StackInt S,int size, int i){
    infotype isi = S.T[i];
    int bintang, spasi;
    bintang = 2 * isi - 1;
    spasi = ((2 * size + 1) - bintang)/2;
    int ascii = 220;
    
    if(isi == NIL)
    {
        for(int j=0; j < size; j++)
        {
            printf(" ");
        }
        printf("|");
        for(int j=0; j < size; j++)
        {
            printf(" ");
        }
        
    }
    else
    {
        for(int j=0;j<spasi;j++)
        {
            printf(" ");
        }
        for(int j = 0; j<bintang; j++){
            printf("%c",ascii);
        }
        for(int j=0;j<spasi;j++)
        {
            printf(" ");
        }
    }
}



void movepiring (char tujuan, boolean found){
    if(found)
    {
        printf("Memindahkan piring ke tiang %c\n",tujuan);
    }
    else
    {
        printf("Salah memilih tiang, pikir lagi\n");
    }    
}

boolean movepiringtotiang(StackInt *awal, StackInt *tujuan, boolean found){
    int Toptiang1, Toptiang2;
    if(awal != tujuan)
    {
        if(!IsStackIntEmpty(*awal))
        {
            PopStackInt(awal,&Toptiang1);
            if(IsStackIntEmpty(*tujuan))
            {
                PushStackInt(tujuan,Toptiang1);
                found = true;
            }
            else
            {
                PopStackInt(tujuan,&Toptiang2);
                if(Toptiang2 > Toptiang1)
                {
                    PushStackInt(tujuan,Toptiang2);
                    PushStackInt(tujuan,Toptiang1);
                    found = true;
                }
                else
                {
                    PushStackInt(tujuan,Toptiang2);
                    PushStackInt(awal,Toptiang1);
                    found = false;
                }
            }
        }
        else
        {
            found = false;
        }
    }
    else
    {
        found = false;
    }
    return found;
}



void bikingaris(StackInt S, int size)
{
    int asciH = 196;

    int spasi,spasikosong,spasiisi;

    spasi = 2 * size + 1;
    spasikosong = (spasi-3)/2;
    spasiisi = (spasi-7)/2;
    
    if(size > 2)
    {
        if (!IsStackIntEmpty(S))
        {
            for(int i = 0; i < spasiisi; i++)
            {
                printf(" ");
            }
            printf("%c%c%c%c%c%c%c",asciH,asciH,asciH,asciH,asciH,asciH,asciH);
            for(int i = 0; i < spasiisi; i++)
            {
                printf(" ");
            }
        }
        else
        {
            for(int i = 0; i < spasikosong; i++)
            {
                printf(" ");
            }
            printf("%c%c%c",asciH,asciH,asciH);
            for(int i = 0; i < spasikosong; i++)
            {
                printf(" ");
            }
        }
    }
    else if(size == 2)
    {
        for(int i = 0; i < spasikosong; i++)
        {
            printf(" ");
        }
        printf("%c%c%c",asciH,asciH,asciH);
        for(int i = 0; i < spasikosong; i++)
        {
            printf(" ");
        }
    }
    else{
        for(int i = 0; i < 1; i++)
        {
            printf(" ");
        }
        printf("%c",asciH);
        for(int i = 0; i < 1; i++)
        {
            printf(" ");
        }
    }

}

void spasitiang (int size){
    if(size > 0)
    {
        for(int i = 0; i < size;i++)
        {
            printf(" ");
        }
    }
    else
    {
        for(int i = 0; i < 1;i++)
        {
            printf(" ");
        }
    }
    
}

void displaytiang(StackInt A, StackInt B, StackInt C, int size){
    
    for (int i=(size-1);i>=0;i-=1)
    {
        displaystack(A,size,i);
        displaystack(B,size,i);
        displaystack(C,size,i);
        printf("\n");

    }
    int i;
    bikingaris(A,size);
    bikingaris(B,size);
    bikingaris(C,size);
    printf("\n");
    spasitiang(size);
    printf("A");
    spasitiang(size);
    spasitiang(size);
    printf("B");
    spasitiang(size);
    spasitiang(size);
    printf("C");
    spasitiang(size);
    printf("\n\n");
}



void commandH (char *awal, char *tujuan, StackInt *A, StackInt *B, StackInt*C, boolean found, int size){
    printf("\n");
    if(*awal == 'A' && *tujuan == 'B')
    {
        found = movepiringtotiang(A, B, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'A' && *tujuan == 'C')
    {
        found = movepiringtotiang(A, C, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'A' && *tujuan == 'A')
    {
        found = movepiringtotiang(A, A, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'B' && *tujuan == 'A')
    {
        found = movepiringtotiang(B, A, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'B' && *tujuan == 'B')
    {
        found = movepiringtotiang(B, B, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'B' && *tujuan == 'C')
    {
        found = movepiringtotiang(B, C, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'C' && *tujuan == 'A')
    {
        found = movepiringtotiang(C, A, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'C' && *tujuan == 'B')
    {
        found = movepiringtotiang(C, B, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'C' && *tujuan == 'C')
    {
        found = movepiringtotiang(C, C, found);
        displaytiang(*A,*B,*C,size);
        movepiring(*tujuan,found);
    }
    else{
        printf("Masukan tiang anda salah, pikir lagi\n");
    }
    
}

int langkahefektif (int size){
    int result;
    if (size < 2)
    {
        return size;
    }
    if(size == 2)
    {
        return 3;
    }

    result = 1 + langkahefektif(size-1)+ langkahefektif(size-1);
    return result;
        
}

int hitungskor (int langkah, int size){
    int skor;
    if (size == 5)
    {
        if(langkah == 31)
        {
            skor = 10;
        }
        else if(langkah >31 && langkah <=37 )
        {
            skor = 9;
        }

        else if(langkah >37 && langkah <=43 )
        {
            skor = 8;
        }
        else if(langkah >43 && langkah <=48 )
        {
            skor = 7;
        }
        else if(langkah >48 && langkah <=54 )
        {
            skor = 6;
        }
        else if(langkah >54 && langkah <=59 )
        {
            skor = 5;
        }
        else if(langkah >59 && langkah <=65 )
        {
            skor = 4;
        }
        else if(langkah >65 && langkah <=71 )
        {
            skor = 3;
        }
        else if(langkah >71 && langkah <=77 )
        {
            skor = 2;
        }
        else if(langkah >77 && langkah <=83 )
        {
            skor = 1;
        }
        else
        {
            skor = 0;
        }
    }

    else
    {
        int efisien = langkahefektif(size);
        if (langkah == efisien)
        {
            skor = 2 * size;
        }
        else
        {
            skor = (2 * size) - (langkah - efisien);
            if (skor < 0)
            {
                skor = 0;
            }
        }
    }

    return skor;
}

void KataToInt(Word kata, int *hasil)
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


void towerhanoi(ArrayDyn ArrayGame, ArrayMap *MapGame){
    StackInt A, B, C;
    boolean found;
    int length,size,optimal;

    size = 0;
    printf("Masukan banyak jumlah piringan: ");
    INPUT();
    KataToInt(CWord,&size);

    while(size >= 28)
    {
        printf("jumlah piringan terlalu banyak kamu gabakal bisa\n");
        printf("\nMasukan banyak jumlah piringan: ");
        INPUT();
        KataToInt(CWord,&size);
    }

    CreateStackIntA(&A,size);
    CreateEmptyStackHanoi(&B);
    CreateEmptyStackHanoi(&C);
    displaytiang(A,B,C,size);
    
    length = LengthStackInt(C);
    found = false;
    char awal,tujuan;
    int langkah = 0;
    int akhir;
    
    while(length != size)
    {
        printf("\nMasukan tiang awal: ");
        INPUT();
        awal = CWord.TabWord[0];
        printf("\nMasukan tiang tujuan: ");
        INPUT();
        tujuan = CWord.TabWord[0];
        commandH(&awal,&tujuan,&A,&B,&C,found,size);
        length = LengthStackInt(C);
        langkah = langkah + 1;
    }
    akhir = hitungskor(langkah,size);
    printf("\nkamu berhasil\n");
    printf("skor yang didapat: %d\n", akhir);
    int index = FindStrArrayDyn(ArrayGame,"TOWER OF HANOI");
    InsertScoreBoard(&MapGame->ElArrMap[index], akhir);
}


