#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"

int main(){
    List L;
    CreateEmpty(&L);
    printf("List linier terbentuk? ");
    if(IsEmpty(L)){
        printf("Ya\n");
    }
}