#include <stdio.h>
#include "queue.h"

int main()
{
    Queue Q;
    printf("Membuat Queue Kosong\n");
    CreateQueue(&Q);

    printf("Apakah Queue Kosong ? Jika kosong maka isi queue sebanyak 5 Element \n");

    if (isEmpty(Q))
    {
        printf("Queue Kosong\n");
        printf("Queue akan diisi dengan 5 element\n");
        int i;
        scanf("%d",&i);
        int count = 1;
        while (count <= 5)
        {
        
            if (count < 5)
            {
                enqueue(&Q, i);
                scanf("%d",&i);
            }
            else
            {
                enqueue(&Q,i);
            }
            count++;
        }
        printf("\n");
        printf("Isi Dari Queue adalah : \n");
        DisplayQueue(Q);
    }
    else
    {
        printf("Queue tidak Kosong");
    }

    printf("Apakah Queue Penuh ?\n");
    if (isFull(Q))
    {
        printf("Sudah\n");
    }
    else
    {
        printf("Belum\n");
    }
    printf("===================================================================\n");

    printf("Menghasilkan penjumlahan dari seluruh Queue dan mengkosongkan Queue\n");
    int k = length(Q);
    int hasil = 0;
    int temp = 0;
    for (int l = 0 ; l < k ; l++)
    {
        dequeue(&Q ,&temp);
        hasil += temp;
    }
    printf("Hasil penjumlahan = %d\n", hasil);
    printf("Apakah Array sudah kosong ?\n");
    if (isEmpty(Q))
    {
        printf("Sudah\n");
    }
    else
    {
        printf("Belum\n");
    }

    return 0;
}