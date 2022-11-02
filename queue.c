/* File : queue.c */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik 
Nama: Nicholas
NIM: 18221165
Topik Praktikum: Queue
Deskripsi: Implementasi dari file header queue.h
*/

#include<stdio.h>
#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 25

/* Definisi elemen dan address */
typedef int ElType;
typedef struct {
	ElType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}
/* ********* Prototype ********* */
boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    if(IDX_HEAD(q) == 0){
        return IDX_TAIL(q) == CAPACITY-1;
    } else{
        return IDX_TAIL(q) == IDX_HEAD(q)-1;
    }
}
int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if(IDX_TAIL(q) == IDX_UNDEF && IDX_HEAD(q) == IDX_UNDEF){ 
        return 0;
    } else if (IDX_HEAD(q)<=IDX_TAIL(q)) {
        return IDX_TAIL(q)-IDX_HEAD(q) +1;
    } else{
        return (CAPACITY-IDX_HEAD(q)) + (IDX_TAIL(q)+1);
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if(q->idxHead == IDX_UNDEF){
        q->idxHead = 0;
        q->idxTail = 0;
        q->buffer[q->idxTail] = val;
    } else{
        if (q->idxTail != CAPACITY-1){
            q->idxTail++;
            q->buffer[q->idxTail] = val;
        } else{
            q->idxTail = 0;
            q->buffer[q->idxTail] = val;
        }
    }
}

void dequeue(Queue *q){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    if (q->idxHead == q->idxTail){
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    } else if (q->idxHead != CAPACITY-1){
        q->idxHead++;
    } else{
        q-> idxHead = 0;
    }
}
/* *** Display Queue *** */
void displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis []  */
    printf("[");
    if (q.idxHead != IDX_UNDEF && q.idxTail != IDX_UNDEF){
        for(int i = 0;i<length(q);i++){
            if(IDX_HEAD(q)+i<CAPACITY){
                printf("%d",q.buffer[i+IDX_HEAD(q)]);
                if(i+IDX_HEAD(q) != IDX_TAIL(q)){
                printf(",");
                }
            } else{
                printf("%d",q.buffer[i+IDX_HEAD(q)-CAPACITY]);
                if(i+IDX_HEAD(q)-CAPACITY != IDX_TAIL(q)){
                printf(",");
                }
            }
        }
    }
    printf("]\n");
}

