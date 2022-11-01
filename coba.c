#include <stdio.h>
#include "boolean.h"

int main(){
    int dom;
    scanf("%d", &dom);
    boolean invalid;
    invalid = false;
    while(invalid){
        if (dom == 1){
            printf("benar\n");
            invalid = true;
        }
        else{
            printf("masukan ulang\n");
            scanf("%d", &dom);
        }
        return 0;
    }
}