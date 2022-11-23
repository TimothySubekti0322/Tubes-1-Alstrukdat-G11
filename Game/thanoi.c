#include "thanoi.h"

void CreateStackIntA(StackInt *S){
    int i;
    CreateEmptyStackInt(S);
    for (i = 5 ; i > 0; i--) 
    {
        PushStackInt(S, i);
    }
}


void displaystack(StackInt *S,int i){
    if ((*S).T[i]==1){
        printf("    *    ");
    }
    else if ((*S).T[i]==2){
        printf("   ***   ");
    }
    else if ((*S).T[i]==3){
        printf("  *****  ");
    }
    else if ((*S).T[i]==4){
        printf(" ******* ");
    }        
    else if ((*S).T[i]==5){
        printf("*********");
    }
    else{
        printf("    |    ");
    }

}

/*void displaystackA(StackInt *S,int i){
    if((*S).TOP < i){
        printf("    |    ");
        i = (*S).TOP;
    }
    
}*/



void movepiring (char tujuan){
    printf("Memindahkan piring ke tiang \"%c\"\n");
}

void movepiringtotiang(StackInt *awal, StackInt *tujuan){
    int Toptiang1, Toptiang2;
    infotype x;

    Toptiang1 = InfoTop(*awal);
    Toptiang2 = InfoTop(*tujuan);

    if (Toptiang1 == NIL){
        printf("salah\n");
    }
    else if(Toptiang1 == NIL && Toptiang2==NIL){
        printf("salah\n");
    }
    else if(IsStackIntEmpty(*tujuan)){
        PushStackInt(tujuan, Toptiang1);
        PopStackInt(awal,&x);
        if(IsStackIntEmpty(*awal)){
            Top(*awal) = -1;
        }
    }
    else if(Toptiang2 > Toptiang1){
        PushStackInt(tujuan, Toptiang1);
        PopStackInt(awal,&x);
        if(IsStackIntEmpty(*awal)){
            Top(*awal) = -1;
        }
    }
    else if(Toptiang1 > Toptiang2){
        if(IsStackIntEmpty(*tujuan)){
            PushStackInt(tujuan, Toptiang1);
            PopStackInt(awal,&x);
        }
        else{
            printf("salah");
        }
    }
    

}



void displaytiang(StackInt A, StackInt B, StackInt C){
    
    for (int i=4;i>=0;i-=1){
        displaystack(&A,i);
        printf("                ");
        displaystack(&B,i);
        printf("                ");
        displaystack(&C,i);
        printf("\n");

    }
    printf(" ------- ");
    printf("                ");
    printf(" ------- ");
    printf("                ");
    printf(" ------- ");
    printf("                \n");
    printf("    A    ");
    printf("                ");
    printf("    B    ");
    printf("                ");
    printf("    C    ");
    printf("                \n\n");
}


int main(){
    StackInt A, B, C,D;
    char tujuan, awal;
    int length;
    CreateStackIntA(&A);
    CreateEmptyStackInt(&B);
    CreateEmptyStackInt(&C);
    CreateEmptyStackInt(&D);
    displaytiang(A,B,C);

}