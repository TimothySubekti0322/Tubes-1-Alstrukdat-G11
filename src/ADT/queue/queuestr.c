/* File : queue.c
 * File C yang berisi implementasi fungsi dari file header ADT Queue, queue.h
*/

#include "queuestr.h"
#include "../../console.h"
#include <stdio.h>

/* *** KREATOR QUEUE *** */
void CreateStrQueue(QueueStr *q) {
	IDX_HEAD(*q) = Idx_Undef;
	IDX_TAIL(*q) = Idx_Undef;
}
/*	I.S. sembarang
 * 	F.S. Sebuah queue q kosong terbentuk dengan spesifikasi:
 * 	* Indeks Head (IdxHead) bernilai Idx_Undef;
 * 	* Indeks Tail (IdxTail) bernilai Idx_Undef;
 * 	Dengan fungsi ini, queue dialokasikan dan menjadi kosong.
*/

/* ********** QUEUE PROPERTIES ********** */
boolean isStrEmpty(QueueStr q) {
	return (IDX_HEAD(q) == Idx_Undef && IDX_TAIL(q) == Idx_Undef);
}
/* Mengirimkan nilai true apabila queue kosong, yaitu ketika
 * IdxHead dan IdxTail sama-sama bernilai Idx_Undef
*/
boolean isStrFull(QueueStr q) {
	return (((IDX_TAIL(q) + 1) % InitSize) == IDX_HEAD(q));
}
/* Mengirimkan nilai true apabila queue penuh, yaitu ketika
 * IdxTail akan berada di belakang IdxHead pada buffer melingkar
*/
int lengthStr(QueueStr q) {
	if (isStrEmpty(q)) {
		return 0;
	} else { // Queue tidak kosong
		int i = IDX_HEAD(q);
		int elem = 1;
		while (i != IDX_TAIL(q)) {
			elem++;
			i = (i + 1) % InitSize;
		}
		return elem;
	}
}
/* Mengirimkan banyaknya elemen dalam queue;
 * Mengirimkan 0 apabila queue kosong
*/

/* ********** QUEUE PRIMITIVES ********** */
void enqueueStr(QueueStr *q, ElemType var) {
	if (isStrEmpty(*q)) {
		IDX_HEAD(*q)++;
		IDX_TAIL(*q)++;
	} else if (IDX_TAIL(*q) == InitSize - 1) { // Tail Queue sudah berada di ujung Queue
		IDX_TAIL(*q) = 0;
	} else { // Tail masih berada di "pertengahan" Queue; antara 0 dan InitSize - 1
		IDX_TAIL(*q)++;
	}
	TAIL(*q) = var;
}
/* Menambahkan var pada queue q dengan sifat First In First Out
 * I.S. q sudah terdefinisi dan mungkin kosong,
 * 		tetapi tidak penuh
 * F.S.	var menjadi TAIL yang baru, IdxTail "mundur"
*/
void dequeueStr(QueueStr *q, ElemType var) {
	int j = stringLength(HEAD(*q));
	int i;
    for (i = 0 ; i < j; i++)
    {
        var[i] = (*q).buffer[(*q).IdxHead][i];
    }
	var[i] = '\0';
	if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
		IDX_HEAD(*q) = Idx_Undef;
		IDX_TAIL(*q) = Idx_Undef;
	} else if (IDX_HEAD(*q) == InitSize - 1) { // Head Queue sudah berada di ujung Queue
		IDX_HEAD(*q) = 0;
	} else { // Setelah dequeue, head akan "mundur" seperti biasa
		IDX_HEAD(*q)++;
	}
}
/* Menghapus var pada queue q dengan sifat First In First Out
 * I.S.	q sudah terdefinisi dan tidak mungkin kosong
 * F.S. var = nilai elemen IdxHead pada queue; IdxHead "mundur";
 * 		queue dapat menjadi kosong
*/

/* ********** QUEUE DISPLAYS ********** */
void DisplayStrQueue(QueueStr q) {
	if (!isStrEmpty(q)) { // Queue tidak kosong
		if (IDX_HEAD(q) > IDX_TAIL(q)) {
			int i;
			for (i = IDX_HEAD(q); i < InitSize; i++) {
				printf("%s\n", q.buffer[i]);
			}
			int j;
			for (j = 0; j < IDX_TAIL(q); j++) {
				printf("%s\n", q.buffer[j]);
			}
			printf("%s\n", TAIL(q));
		} else { // Indeks Tail lebih besar dibanding Indeks Head
			int k;
			for (k = IDX_HEAD(q); k < IDX_TAIL(q); k++) {
				printf("%s\n", q.buffer[k]);
			}
			printf("%s\n", TAIL(q));
		}
	}
	printf("\n");
}
/* Menuliskan isi Queue dengan skema pemrosesan traversal, dengan
 * format penulisan elemen diikuti newline sebelum elemen selanjutnya
 * I.S.	q sudah terdefinisi dan mungkin kosong
 * F.S.	apabila q kosong, tidak ada yang ditampilkan.
 * 		apabila q tidak kosong, menampilkan: 
 * 		elemen-1
 * 		elemen-2
 * 		...
 * 		elemen-n
 * 		Setiap display, terlepas q kosong atau tidak, akan diakhiri newline.
*/
