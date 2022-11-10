#include <stdio.h>
#include "queuestr.h"
#include "../../console.h"

int main()
{
    QueueStr Q;
    printf("Membuat Queue Kosong\n");
    CreateStrQueue(&Q);
    printf("Apakah Queue Kosong ?\n");
    if (isStrEmpty(Q))
    {
        printf("Queue Kosong\n");
    }
    else
    {
        printf("Queue tidak Kosong\n");
    }
    
    printf("Apakah Queue Penuh ?\n");
    if (isStrFull(Q))
    {
        printf("Queue Penuh\n");
    }
    else
    {
        printf("Queue tidak Penuh\n");
    }

    printf("=====================================================\n");

    printf("Queue akan diisi nama nama Member kelompok 11 Alstrukdat Ganesha\n");
    printf("enqueue is starting.......\n");
    enqueueStr(&Q,"Pak Riza");
    enqueueStr(&Q,"Timothy");
    enqueueStr(&Q,"Ken");
    enqueueStr(&Q,"Nicholas");
    enqueueStr(&Q,"Ivan");
    enqueueStr(&Q,"Shulhan");
    printf("enqueue finished\n");
    
    printf("\nberikut adalah nama nama Member kelompok 11 Alstrukdat Ganesha\n");
    DisplayStrQueue(Q);

    printf("Pak Riza bukan bagian dari kelompok 11 Alstrukdat Ganesha , Remove Pak Riza from Queue kelompok\n");
    printf("dequeue is starting.......\n");
    char name[10];
    dequeueStr(&Q,name);
    printf("dequeue finished\n");
    printf("%s\n",name);
    if (CompareString(name,"Pak Riza"))
    {
        printf("Pak Riza berhasil di remove dari kelompok\n");
    }
    else
    {
        printf("Pak Riza gagal di remove dari kelompok\n");
    }

    printf("\nberikut adalah nama nama Member kelompok 11 Alstrukdat Ganesha yang benar\n");
    DisplayStrQueue(Q);
}