#include "boolean.h"
#include "queue.c"
#include <stdlib.h>
#include "time.h"
#include "math.h"
typedef struct{
        int indeks[10];
        int durasi[10];
        int count;
} masaksaji;

typedef struct{
    Queue indeks;
    int durasi[25];
    int ketahanan[25];
    int harga[25];
} customers;

void IsMemberMasakSaji(masaksaji m,int custnumber,boolean *found,int *indeks){
    int i;
    for(i = 0;i<m.count;i++){
                    if(m.indeks[i] == custnumber){
                        *found = true;
                        *indeks = i;
                    }
                }    
}
void masaksajiempty(masaksaji *m){
    m->count = 0;
}

int strlen(char *sentence){
    int i = 0;
    while(sentence[i] != '\0'){
        i++;
    }
    return i;
}

boolean serves(char *command){
    if(command[0] == 'S' && command[1] == 'E' && command[2] == 'R' && command[3] == 'V' && command[4] == 'E'){
        return true;
    }
    return false;
}

boolean cooks(char *command){
    if(command[0] == 'C' && command[1] == 'O' && command[2] == 'O' && command[3] == 'K'){
        return true;
    }
    return false;
}

int custnumbers(char *number){
    int i,custnumber=0;
        if(strlen(number)<=3){
            for(i = 1;i<strlen(number)+1;i++){
                custnumber += pow(10,strlen(number)-1-i)*(number[i]-43);
            }
        } else{
            return -1;
        }
    return custnumber;
}

void DeleteMasakSaji(masaksaji *m,int indeks){
    int i;
    m->count -= 1;
    for(i = indeks;i<m->count;i++){
        m->durasi[i] = m->durasi[i+1];
        m->indeks[i] = m->indeks[i+1];
    }
}

void tambahturn(masaksaji *masak, masaksaji *saji,customers *orders){
    enqueue(&orders->indeks,TAIL(orders->indeks)+1);
    int i;
    for(i = 0;i<masak->count;i++){
        masak->durasi[i] -=1;
        if(masak->durasi[i] == 0){
            DeleteMasakSaji(masak,i);
        }
    }
    for(i = 0;i<saji->count;i++){
        saji->durasi[i] -= 1;
        if(saji->durasi[i] == 0){
            DeleteMasakSaji(saji,i);
        }
    }
}

int main(){
    printf("Selamat datang di Diner Dash!\n");
    
    // Deklarasi variabel dan array
    boolean game_over = false,found;
    int saldo = 0,custnumber,indeks;
    customers orders;
    CreateQueue(&orders.indeks);
    
    // Pembuatan random number
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now); 
    int second = tm_struct->tm_sec;
    int i,random = 1;
    for(i = 0;i<25;i++){
        random = (((127*random) + second)%5) + 1;
        orders.durasi[i] = random;
        random = (((127*random) + second)%5) + 1;
        orders.ketahanan[i] = random;
        random = ((((127*random) + second)%41)+ 10)*1000;
        orders.harga[i] = random;
        random = (random/1000)%109;
    }

    //Pembuatan struct untuk masak dan saji
    masaksaji masak,saji;
    masaksajiempty(&masak);
    masaksajiempty(&saji);    

    //Isi command
    char *command,*number;
    command = (char *) malloc (6*sizeof(char));
    number = (char *) malloc (4*sizeof(char));
    //Isi Customer awal
    for(i = 0;i<3;i++){
        enqueue(&orders.indeks,i);
    }
    boolean serve,cook;
    //Bermain Game
    while (!(game_over)){
        //Display Status
        printf("Saldo: %d\n\n",saldo);

        // Status Pesanan
        printf("Daftar Pesanan \n");
        printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
        printf("----------------------------------------------\n");
        for(i = 0;i<length(orders.indeks);i++){
            printf("M%d      | %d              | %d         | %d\n",orders.indeks.buffer[i],orders.durasi[i+HEAD(orders.indeks)],orders.ketahanan[i+HEAD(orders.indeks)],orders.harga[i+HEAD(orders.indeks)]);
        }
        printf("\n");

        // Status masakan
        printf("Daftar Makanan yang sedang dimasak\nMakanan | Sisa durasi memasak\n");
        printf("------------------------------\n");
        if(masak.count == 0){
            printf("        |\n");
        }
        for(i = 0;i<masak.count;i++){
            printf("M%d      | %d\n",masak.indeks[i],masak.durasi[i]);
        }
        printf("\n");

        //Status Penyajian
        printf("Daftar Makanan yang dapat disajikan\nMakanan | Sisa ketahanan makanan\n");
        printf("------------------------------\n");
        if(saji.count == 0){
            printf("        |\n");
        }
        for(i = 0;i<saji.count;i++){
            printf("M%d      | %d\n",saji.indeks[i],saji.durasi[i]);
        }
        boolean valid = false;
        //Pemasukkan command
        while(!valid){
            printf("MASUKKAN COMMAND: ");
            scanf("%s %s",command,number);
            serve = false;
            cook = false;
            if(serves(command)){
                serve = true;
            } else if (cooks(command)){
                cook = true;
            }

            if(serve == true){
                found = false;
                custnumber = custnumbers(number);
                IsMemberMasakSaji(saji,custnumber,&found,&indeks);

            if(found){
                if(custnumber == HEAD(orders.indeks)){
                    saldo += orders.harga[custnumber];
                    dequeue(&orders.indeks);
                    saji.count -= 1;
                    for(i = indeks;i<saji.count;i++){
                        saji.indeks[i] = saji.indeks[i+1];
                        saji.durasi[i] = saji.durasi[i+1];
                    }
                    valid = true;
                } else {
                    printf("M%d belum dapat disajikan karena M%d belum selesai\n",custnumber,HEAD(orders.indeks));                    
                }
            } else{
                printf("Indeks makanan belum siap disaji atau tidak valid.\n");
            }
        } else if(cook == true){
            custnumber = custnumbers(number);
            found = false;
            for(i = 0;i<length(orders.indeks);i++){
                if(custnumber == orders.indeks.buffer[i]){
                    found = true;
                }
            }
            if (masak.count <= 5){
                if(found){
                    masak.count+=1;
                    masak.durasi[masak.count-1] = orders.durasi[custnumber]+1;
                    masak.indeks[masak.count-1] = custnumber;
                    valid = true;
                } else{
                    printf("Indeks masakan tidak dalam queue customer.\n");
                }
            } else{
                printf("Batas jumlah masakan sudah tercapai. Input ulang command.\n");
            }
        }
    }

        tambahturn(&masak,&saji,&orders);
        if(HEAD(orders.indeks) == 15){
            printf("Selamat anda sudah memenangkan game. Skor Anda %d.\n",saldo);
            game_over = true;
        }
        if(length(orders.indeks) > 7){
            printf("Maaf. Anda kalah karena customer sudah melebihi 7. Skor anda %d.\n",saldo);
            game_over = true;
        }

    }
    
}
