#include "SnakeOnMeteor.h"
//Belum lengkap, meteor, obstacle, scoreboard belum ditangani

void randomnumbersnake(int *x,int *y){
    srand(time(NULL));
    *x = rand() % 5;
    *y = rand() % 5;
}

void GenerateFood(StatArray *container, int *FoodLocation){
    int x,y;
    randomnumbersnake(&x,&y);
    while(container->Ar[x + 5*y] != -100){
        randomnumbersnake(&x,&y);
    }
    container->Ar[x + 5*y] = -1;
    *FoodLocation = x + 5*y;
}

boolean IsPointNotEmpty(List snake, int input){

    addresslist last = First(snake);
    boolean Found = false;
    while (!Found && (Next(last) != First(snake))){
        if (last->info == input){
            Found = true;
        } else {
            last = Next(last);
        }
    }
    return Found;
}

void ShowSquare(List snake, int *FoodLocation, boolean *IsFoodAvailable){
    StatArray container;
    container = CreateStatArray();
    for (int i=0;i<25;i++){
        container.Ar[i] = -100;
    }

    StatArray coordinat;
    coordinat = CreateStatArray();
    addresslist last = First(snake);
    InsertLStat(&coordinat,last->info);
    while (Next(last) != First(snake)){
        last = Next(last);
        InsertLStat(&coordinat,last->info);
    }

    int length = coordinat.Neff;

    while (length != 0){
        container.Ar[coordinat.Ar[coordinat.Neff-length]] = coordinat.Neff - length;
        length--;     
    }

    if (!(*IsFoodAvailable)){
        GenerateFood(&container, FoodLocation);
        *IsFoodAvailable = true;
    } else {
        container.Ar[*FoodLocation] = -1;
    }

    for (int j = 0; j<5; j++){
        printf("---------------------\n");
        printf("|");
        for (int i = j*5; i<(j+1)*5; i++){
            if (container.Ar[i]==-100){
                printf("   |");
            } else if (container.Ar[i]==0){
                printf(" H |");
            } else if (container.Ar[i]==-1){
                printf(" o |");
            } else if (container.Ar[i]>0 && container.Ar[i]<10){
                printf(" %d |", container.Ar[i]);
            } else {
                printf(" %d|", container.Ar[i]);
            }
        }
        printf("\n");
    }
    printf("---------------------\n");
}

void CreateSnake(List *snake){
    CreateEmptyList(snake);
    int x,y;
    randomnumbersnake(&x,&y);
    InsVLast(snake,y*5+x);
    if (x==0){
        if(y>=2){
            InsVLast(snake,(y*5+x+20)%25);
            InsVLast(snake,(y*5+x+15)%25);
        } else {
            InsVLast(snake,(y*5+x+5)%25);
            InsVLast(snake,(y*5+x+10)%25);
        }
    } else if (x==1){
        if(y==0){
            InsVLast(snake,(y*5+x+24)%25);
            InsVLast(snake,(y*5+x+4)%25);
        } else {
            InsVLast(snake,(y*5+x+24)%25);
            InsVLast(snake,(y*5+x+19)%25);
        }
    } else{
            InsVLast(snake,(y*5+x+24)%25);
            InsVLast(snake,(y*5+x+23)%25);  
    }
}

boolean IsInputValid(Word CWord){
    return (IsKataSama(CWord,StringtoWord("w")) || IsKataSama(CWord,StringtoWord("s")) || IsKataSama(CWord,StringtoWord("a")) || IsKataSama(CWord,StringtoWord("d")));
}

boolean IsMoveable(Word CWord, List snake){
    if (IsInputValid(CWord)){
        return(((IsKataSama(CWord,StringtoWord("w")) && !IsPointNotEmpty(snake,(snake.First->info+20)%25))) ||
               ((IsKataSama(CWord,StringtoWord("s")) && !IsPointNotEmpty(snake,(snake.First->info+5)%25))) ||
               ((IsKataSama(CWord,StringtoWord("d")) && !IsPointNotEmpty(snake,(snake.First->info/5)*5 + (snake.First->info+1)%5))) ||
               ((IsKataSama(CWord,StringtoWord("a")) && !IsPointNotEmpty(snake,(snake.First->info/5)*5 + (snake.First->info-1)%5))));
    } else {
        return false;
    }

}

int main(){
    boolean IsFoodAvailable = false;
    int FoodLocation = -1;
    List snake;
    CreateSnake(&snake);

    printf("Selamat datang di snake on meteor!\n\n");
    printf("Mengenerate peta, snake dan makanan . . . \n\n");
    printf("Berhasil digenerate!\n\n");
    printf("Berikut merupakan peta permainan\n");
    ShowSquare(snake, &FoodLocation, &IsFoodAvailable);
    
    boolean End = false;
    int Turn = 1;
    int temporary;
    while(!End){
        printf("TURN %d:\n", Turn);
        printf("Silahkan masukkan command anda:");
        INPUT();
        while (!IsInputValid(CWord) || !IsMoveable(CWord,snake)){
            if (IsInputValid(CWord)){
                printf("Command tidak valid! Ularmu tidak dapat berjalan ke badannya\n");
            } else {
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
            }
            printf("Silahkan masukkan command anda:");
            INPUT();
        }
        if (IsKataSama(CWord,StringtoWord("w"))){
            InsVFirst(&snake, ((snake.First->info+20)%25));
            DelVLast(&snake, &temporary);
        } else if (IsKataSama(CWord,StringtoWord("s"))){
            InsVFirst(&snake, ((snake.First->info+5)%25));
            DelVLast(&snake, &temporary); 
        } else if (IsKataSama(CWord,StringtoWord("a"))){
            InsVFirst(&snake, (snake.First->info/5)*5 + (snake.First->info-1)%5);
            DelVLast(&snake, &temporary);
        } else {
            InsVFirst(&snake, (snake.First->info/5)*5 + (snake.First->info+1)%5);
            DelVLast(&snake, &temporary);
        }

        if (snake.First->info == FoodLocation){
            DelVLast(&snake,&temporary);
            InsVLast(&snake,temporary);
            if (((temporary/5)*5 + (temporary-1)%5 < temporary) && !IsPointNotEmpty(snake,temporary-1) && temporary-1 >= 0){
                InsVLast(&snake, temporary-1);
            } else if ((temporary+20)%25 < temporary && !IsPointNotEmpty(snake,temporary-5) && temporary-5 >=0){
                InsVLast(&snake, temporary-5);
            } else if ((temporary+5)%25 > temporary && !IsPointNotEmpty(snake,temporary+5 && temporary+5 <=24)){
                InsVLast(&snake, temporary+5);
            } else if (((temporary/5)*5 + (temporary+1)%5 > temporary) && !IsPointNotEmpty(snake,temporary+1) && temporary+1 <= 24){
                InsVLast(&snake, temporary+1);
            } else {
                End = true;
            }

            IsFoodAvailable = false;
        }

        ShowSquare(snake, &FoodLocation, &IsFoodAvailable);
        Turn++;
    }

    printf("Game berakhir.\n");
}