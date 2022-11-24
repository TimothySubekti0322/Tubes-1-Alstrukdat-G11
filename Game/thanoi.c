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



void movepiring (char tujuan, boolean found){
    if(found){
        printf("Memindahkan piring ke tiang %c\n",tujuan);
    }
    else{
        printf("Salah memilih tiang, pikir lagi\n");
    }    
}

boolean movepiringtotiang(StackInt *awal, StackInt *tujuan, boolean found){
    int Toptiang1, Toptiang2;
    if(awal != tujuan){
        if(!IsStackIntEmpty(*awal)){
            PopStackInt(awal,&Toptiang1);
            if(IsStackIntEmpty(*tujuan)){
                PushStackInt(tujuan,Toptiang1);
                found = true;
            }
            else{
                PopStackInt(tujuan,&Toptiang2);
                if(Toptiang2 > Toptiang1){
                    PushStackInt(tujuan,Toptiang2);
                    PushStackInt(tujuan,Toptiang1);
                    found = true;
                }
                else{
                    PushStackInt(tujuan,Toptiang2);
                    PushStackInt(awal,Toptiang1);
                    found = false;
                }
            }
        }
        else{
            found = false;
        }
    }
    else{
        found = false;
    }
    return found;
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

void commandH (char *awal, char *tujuan, StackInt *A, StackInt *B, StackInt*C, boolean found){
    printf("\n");
    if(*awal == 'A' && *tujuan == 'B')
    {
        found = movepiringtotiang(A, B, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'A' && *tujuan == 'C')
    {
        found = movepiringtotiang(A, C, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'A' && *tujuan == 'A')
    {
        found = movepiringtotiang(A, A, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'B' && *tujuan == 'A')
    {
        found = movepiringtotiang(B, A, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'B' && *tujuan == 'B')
    {
        found = movepiringtotiang(B, B, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'B' && *tujuan == 'C')
    {
        found = movepiringtotiang(B, C, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'C' && *tujuan == 'A')
    {
        found = movepiringtotiang(C, A, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'C' && *tujuan == 'B')
    {
        found = movepiringtotiang(C, B, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else if(*awal == 'C' && *tujuan == 'C')
    {
        found = movepiringtotiang(C, C, found);
        displaytiang(*A,*B,*C);
        movepiring(*tujuan,found);
    }
    else{
        printf("Masukan tiang anda salah, pikir lagi\n");
    }
    
}

void loopHanoi (int *length, StackInt *A, StackInt *B, StackInt*C, boolean found ){
    char awal,tujuan;
    while(*length != 5)
    {
        printf("\nMasukan tiang awal: ");
        INPUT();
        awal = CWord.TabWord[0];
        printf("\nMasukan tiang tujuan: ");
        INPUT();
        tujuan = CWord.TabWord[0];
        commandH(&awal,&tujuan,A,B,C,found);
        *length = LengthStackInt(*C);
    }
}


int main(){
    StackInt A, B, C;
    boolean found;
    int length;
    CreateStackIntA(&A);
    CreateEmptyStackInt(&B);
    CreateEmptyStackInt(&C);
    displaytiang(A,B,C);
    length = LengthStackInt(C);
    found = false;
    loopHanoi(&length, &A, &B, &C,found);

}