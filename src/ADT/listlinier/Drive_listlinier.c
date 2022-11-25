#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"

int main(){
    List L;
    CreateEmptyList(&L);
    printf("List linier kosong terbentuk? ");
    if(IsEmptyList(L)){
        printf("Ya\n");
    }

    printf("Memasukkan 5 ke dalam list linier\n");
    InsVFirst(&L,5);
    PrintInfo(L);
    printf("\n");
    
    printf("Memasukkan 4 pada awal dan 6 di akhir\n");
    InsVFirst(&L,4);
    InsVLast(&L,6);
    PrintInfo(L);
    printf("\n");
    
    address P = Search(L,5);
    printf("Melakukan search dan print info dengan node 5\n");
    printf("%d\n",P->info);
    
    int x;
    DelVFirst(&L,&x);
    printf("Menghapus elemen pertama list dan memprint elemen pertamanya\n");
    printf("%d\n",x);
    PrintInfo(L);
    printf("\n");

    DelVLast(&L,&x);
    printf("Menghapus elemen pertama list dan memprint elemen pertamanya\n");
    printf("%d\n",x);
    PrintInfo(L);
    printf("\n");
    
    InsertFirst(&L,Alokasi(4));
    InsertLast(&L,Alokasi(7));
    InsertAfter(&L,Alokasi(6),Search(L,5));
    printf("Melakukan insert berdasarkan address\n");
    PrintInfo(L);
    printf("\n");

    printf("Menghapus elemen list berdasarkan address dan memprint hasil addressnya\n");
    printf("DelFirst\n");
    DelFirst(&L,&P);
    printf("%d\n",P->info);
    PrintInfo(L);
    printf("\n");

    printf("DelAfter\n");
    DelAfter(&L,&P,Search(L,5));
    printf("%d\n",P->info);
    PrintInfo(L);
    printf("\n");

    printf("DelLast\n");
    DelLast(&L,&P);
    printf("%d\n",P->info);
    PrintInfo(L);
    printf("\n");

    printf("DelP\n");
    DelP(&L,5);
    PrintInfo(L);
    printf("\n");
}