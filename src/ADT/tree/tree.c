/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotypeTree, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

/* Modul lain yang digunakan : */
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>



/* *** Definisi Type Pohon Biner *** */


/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = NilTree */


/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

/* Manajemen Memory */
addrNode AlokNode(infotypeTree X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NilTree, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = NilTree, Right(P)=NilTree */
/* Jika alokasi gagal, mengirimkan NilTree */
{
  addrNode N = (addrNode)malloc(sizeof(Node));
  if (N != NilTree)
  {
    Akar(N) = X;
    Left(N) = NilTree;
    Right(N) = NilTree;
    return N;
  }
  else
    return NilTree;
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
  free(P);
}

/* *** Konstruktor *** */
BinTree Tree(infotypeTree Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NilTree) jika alokasi gagal */
{
  BinTree T = (BinTree)malloc(sizeof(BinTree));
  if (T != NilTree)
  {
    Akar(T) = Akar;
    Left(T) = L;
    Right(T) = R;
    return T;
  }
  else
    return NilTree;
}

void MakeTree(infotypeTree Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = NilTree jika alokasi gagal. */
{
  (*P) = Tree(Akar, L, R);
}


/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
  return (P == NilTree);
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
  // return !IsTreeEmpty(P) && (((Left(P) != NilTree) | (Right(P) != NilTree)) && !(Left(P) != NilTree && Right(P) != NilTree));
  return !IsTreeEmpty(P) && (Left(P) == NilTree) && (Right(P) == NilTree);
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
  return (Left(P) != NilTree && Right(P) == NilTree);
}
boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
  return (Right(P) != NilTree && Left(P) == NilTree);
}
boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
  return (Right(P) != NilTree && Left(P) != NilTree);
}

/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
  if (IsTreeEmpty(P))
    printf("()");
  else
  {
    printf("(");
    printf("%s", Akar(P));
    PrintPreorder(Left(P));
    PrintPreorder(Right(P));
    printf(")");
  }
}

void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
  printf("(");
  if (!IsTreeEmpty(P))
  {
    PrintInorder(Left(P));
    printf("%s", Akar(P));
    PrintInorder(Right(P));
  }
  printf(")");
}

void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
  if (IsTreeEmpty(P))
    printf("()");
  else
  {
    printf("(");
    PrintPostorder(Left(P));
    PrintPostorder(Right(P));
    printf("%s", Akar(P));
    printf(")");
  }
}

void PrintTree2(BinTree P, int h, int current_indent)
{
  if (!IsTreeEmpty(P))
  {

    printf("%*s%s\n", current_indent, "", Akar(P));

    PrintTree2(Left(P), h, current_indent + h);
    PrintTree2(Right(P), h, current_indent + h);
  }
}

void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
  PrintTree2(P, h, 0);
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infotypeTree X)
/* Mengirimkan true jika ada node dari P yang berNilTreeai X */
{
  if (IsTreeEmpty(P))
    return false;
  else
  {
    if (Akar(P) == X)
      return true;
    else
      return SearchTree(Left(P), X) | SearchTree(Right(P), X);
  }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
  if (IsTreeEmpty(P))
    return 0;
  else
  {
    return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
  }
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
  if (!IsBiner(P))
    return 1;
  else
  {
    return NbDaun(Left(P)) + NbDaun(Right(P));
  }
}

boolean IsSkewLeft(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
  if (IsTreeEmpty(P))
  {
    return true;
  }
  else
  {
    if (IsBiner(P) | IsUnerRight(P))
      return false;
    else
      return IsSkewLeft(Left(P));
  }
}

boolean IsSkewRight(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
  if (IsTreeEmpty(P))
  {
    return true;
  }
  else
  {
    if (IsBiner(P) | IsUnerLeft(P))
      return false;
    else
      return IsSkewRight(Right(P));
  }
}

int Level(BinTree P, infotypeTree X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
  if (Akar(P) == X)
    return 1;
  else
  {
    if (SearchTree(Left(P), X))
    {
      return 1 + Level(Left(P), X);
    }
    else
      return 1 + Level(Right(P), X);
  }
}

int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
  if (IsTreeEmpty(P))
    return 0;
  else
  {
    int mL = Tinggi(Left(P));
    int mR = Tinggi(Right(P));
    if (mL >= mR)
    {
      return 1 + mL;
    }
    else
    {
      return 1 + mR;
    }
  }
}

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotypeTree X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
  if (IsTreeEmpty(*P))
  {
    *P = Tree(X, NilTree, NilTree);
  }
  else
  {
    AddDaunTerkiri(&Left(*P), X);
  }
}

void AddDaun(BinTree *P, infotypeTree X, infotypeTree Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun berNilTreeai X, diambil daun yang paling kiri */
{
  if (IsTreeOneElmt(*P) && Akar(*P) == X)
    if (Kiri)
      Left(*P) = Tree(Y, NilTree, NilTree);
    else
      Right(*P) = Tree(Y, NilTree, NilTree);
  else
  {
    if (SearchTree(Left(*P), X))
      AddDaun(&Left(*P), X, Y, Kiri);
    else
      AddDaun(&Right(*P), X, Y, Kiri);
  }
}

void DelDaunTerkiri(BinTree *P, infotypeTree *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
{
  if (IsTreeOneElmt(*P))
  {
    *X = Akar(*P);
    addrNode temp = *P;
    *P = NilTree;
    DealokNode(temp);
  }
  else
  {
    if (IsUnerRight(*P))
    {
      DelDaunTerkiri(&Right(*P), X);
    }
    else
    {
      DelDaunTerkiri(&Left(*P), X);
    }
  }
}

void DelDaun(BinTree *P, infotypeTree X)
/* I.S. P tidak kosong, minimum ada 1 daun berNilTreeai X. */
/* F.S. Semua daun berNilTreeai X dihapus dari P. */
{
  if (!IsTreeEmpty(*P))
  {

    if (IsTreeOneElmt(*P) && Akar(*P) == X)
    {
      (*P) = NilTree;
      DealokNode(*P);
    }
    else
    {
      DelDaun(&Left(*P), X);
      DelDaun(&Right(*P), X);
    }
  }
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotypeTree X)
/* Mengirimkan true jika ada node dari P yang berNilTreeai X */
{
  return SearchTree(Left(P), X) | SearchTree(Right(P), X);
}

void InsSearch(BinTree *P, infotypeTree X)
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang berNilTreeai X. */
{
  if (IsTreeEmpty(*P))
  {
    MakeTree(X, NilTree, NilTree, P);
  }
  else
  {
    if (X > Akar(*P))
    {
      InsSearch(&Right(*P), X);
    }
    else if (X < Akar(*P))
    {
      InsSearch(&Left(*P), X);
    }
  }
}

