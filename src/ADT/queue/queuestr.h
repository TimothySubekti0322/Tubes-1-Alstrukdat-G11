/* File : queuestr.h
 * File Header berisi definisi ADT Queue yang direpresentasikan dengan array
 * secara eksplisit dan menggunakan alokasi statis; elemennya adalah string (char*)
 * Tipe Queue : Circular Buffer
*/

#ifndef QUEUE_H
#define QUEUE_H

/* Definisi Boolean */
#define boolean unsigned char
#define true 1
#define false 0

#define Idx_Undef -1
#define InitSize 100

/* ** STRUCT DEFINITIONS ** */
typedef char *ElemType;
typedef struct {
	ElemType buffer[InitSize];
	int IdxHead;
	int IdxTail;
} Queue;

/* ************* AKSES (SELEKTOR; MACRO) ************* */
/* Jika q adalah queue, alternatif cara pengaksesan: */
#define IDX_HEAD(q) (q).IdxHead
#define IDX_TAIL(q) (q).IdxTail
#define 	HEAD(q) (q).buffer[(q).IdxHead]
#define 	TAIL(q) (q).buffer[(q).IdxTail]

/* *** KREATOR QUEUE *** */
void CreateStrQueue(Queue *q);
/*	I.S. sembarang
 * 	F.S. Sebuah queue q kosong terbentuk dengan spesifikasi:
 * 	* Indeks Head (IdxHead) bernilai Idx_Undef;
 * 	* Indeks Tail (IdxTail) bernilai Idx_Undef;
 * 	Dengan fungsi ini, queue dialokasikan dan menjadi kosong.
*/

/* ********** QUEUE PROPERTIES ********** */
boolean isStrEmpty(Queue q);
/* Mengirimkan nilai true apabila queue kosong, yaitu ketika
 * IdxHead dan IdxTail sama-sama bernilai Idx_Undef
*/
boolean isStrFull(Queue q);
/* Mengirimkan nilai true apabila queue penuh, yaitu ketika
 * IdxTail akan berada di belakang IdxHead pada buffer melingkar
*/
int lengthStr(Queue q);
/* Mengirimkan banyaknya elemen dalam queue;
 * Mengirimkan 0 apabila queue kosong
*/

/* ********** QUEUE PRIMITIVES ********** */
void enqueueStr(Queue *q, ElemType var);
/* Menambahkan var pada queue q dengan sifat First In First Out
 * I.S. q sudah terdefinisi dan mungkin kosong,
 * 		tetapi tidak penuh
 * F.S.	var menjadi TAIL yang baru, IdxTail "mundur"
*/
void dequeueStr(Queue *q, ElemType *var);
/* Menghapus var pada queue q dengan sifat First In First Out
 * I.S.	q sudah terdefinisi dan tidak mungkin kosong
 * F.S. var = nilai elemen IdxHead pada queue; IdxHead "mundur";
 * 		queue dapat menjadi kosong
*/

/* ********** QUEUE DISPLAYS ********** */
void DisplayStrQueue(Queue q);
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


#endif
