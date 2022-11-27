#include "SnakeOnMeteor.h"
//Belum lengkap, obstacle, scoreboard belum ditangani

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

void GenerateMeteor(int *MeteorLocation, int Foodlocation){
    int x,y;
    randomnumbersnake(&x,&y);
    while(x + 5*y == Foodlocation){
        randomnumbersnake(&x,&y);
    }
    *MeteorLocation = x + 5*y;
}

boolean IsPointNotEmpty(List snake, int input){
    StatArray coordinat;
    coordinat = CreateStatArray();
    addresslist last = First(snake);
    boolean Found = false;
    if (last->info == input){
        Found = true;
    } else {
        last = Next(last);
    }
    while (!Found && (last != First(snake))){
        if (last->info == input){
            Found = true;
        } else {
            last = Next(last);
        }
    }
    return Found;
}

boolean IsSnakeBody(List snake, int input){
    StatArray coordinat;
    coordinat = CreateStatArray();
    addresslist last = First(snake);
    boolean Found = false;
    if (last->info == input){
        Found = true;
    } else {
        last = Next(last);
    }
    while (!Found && (last->next != First(snake))){
        if (last->info == input){
            Found = true;
        } else {
            last = Next(last);
        }
    }
    return Found;
}

int ShowSquare(StatArray container){
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
            } else if (container.Ar[i]==-10){
                printf(" m |");
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

void NextTurn(List *snake, int *FoodLocation, boolean *IsFoodAvailable, int Turn, int *MeteorLocation, int *End, int *score){
    StatArray container;
    container = CreateStatArray();
    for (int i=0;i<25;i++){
        container.Ar[i] = -100;
    }

    StatArray coordinat;
    coordinat = CreateStatArray();
    addresslist last = First(*snake);
    InsertLStat(&coordinat,last->info);
    while (Next(last) != First(*snake)){
        last = Next(last);
        InsertLStat(&coordinat,last->info);
    }

    int length = coordinat.Neff;

    while (length != 0){
        container.Ar[coordinat.Ar[coordinat.Neff-length]] = coordinat.Neff - length;
        length--;     
    }

    boolean IsHitMeteor = false;

    if (!(*IsFoodAvailable)){
        GenerateFood(&container, FoodLocation);
        *IsFoodAvailable = true;
    } else {
        container.Ar[*FoodLocation] = -1;
    }

    if (Turn > 0){
        GenerateMeteor(MeteorLocation, *FoodLocation);
        printf("%d\n", *MeteorLocation);
        if (IsPointNotEmpty(*snake,*MeteorLocation)){    
            IsHitMeteor = true;
        }
        container.Ar[*MeteorLocation] = -10;
    }

    ShowSquare(container);
    *score = coordinat.Neff*2;

    if (Turn > 0){
        if (IsHitMeteor == false){
            printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
        } else {
            if (container.Ar[snake->First->info] == -10){
                printf("Kepala snake terkena meteor!\n");
                *End = 2;
                *score = (coordinat.Neff-1)*2;
            } else {
                printf("Anda terkena meteor!\n\n");
                int temporary;
                if (container.Ar[coordinat.Ar[coordinat.Neff-1]] == -10){
                    DelVLast(snake, &temporary);
                    container.Ar[coordinat.Ar[coordinat.Neff-1]] == -100;
                    printf("Berikut merupakan peta permainan sekarang:\n");
                    ShowSquare(container);
                    printf("Silahkan lanjutkan permainan\n");
                } else {
                    int i = 1;
                    while (container.Ar[coordinat.Ar[i]] != -10){
                        i++;
                    }
                    for (int j = i + 1;j<coordinat.Neff;j++){
                        container.Ar[coordinat.Ar[j]]--;
                    }
                    printf("Berikut merupakan peta permainan sekarang:\n");
                    ShowSquare(container);
                    printf("Silahkan lanjutkan permainan\n");
                    if (((abs(coordinat.Ar[i-1]-coordinat.Ar[i+1]) == 2 || abs(coordinat.Ar[i-1]-coordinat.Ar[i+1]) == 3) && coordinat.Ar[i-1]/5 == coordinat.Ar[i+1]/5) ||
                        ((abs(coordinat.Ar[i-1]-coordinat.Ar[i+1]) == 10 || abs(coordinat.Ar[i-1]-coordinat.Ar[i+1]) == 15) && coordinat.Ar[i-1]%5 == coordinat.Ar[i+1]%5)){
                        DelVLast(snake,&temporary);
                    } else {
                        DelP(snake, *MeteorLocation);
                    } 
                }
            }
        }
    } 
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
        return(((IsKataSama(CWord,StringtoWord("w")) && !IsSnakeBody(snake,(snake.First->info+20)%25))) ||
               ((IsKataSama(CWord,StringtoWord("s")) && !IsSnakeBody(snake,(snake.First->info+5)%25))) ||
               ((IsKataSama(CWord,StringtoWord("d")) && !IsSnakeBody(snake,(snake.First->info/5)*5 + (snake.First->info+1)%5))) ||
               ((IsKataSama(CWord,StringtoWord("a")) && !IsSnakeBody(snake,(snake.First->info/5)*5 + (snake.First->info+4)%5))));
    } else {
        return false;
    }
}

boolean IsMeteorLocation(Word Cword, List snake, int MeteorLocation){
    if (IsInputValid(CWord)){
        return(((IsKataSama(CWord,StringtoWord("w")) && (snake.First->info+20)%25 != MeteorLocation)) ||
               ((IsKataSama(CWord,StringtoWord("s")) && (snake.First->info+5)%25 != MeteorLocation)) ||
               ((IsKataSama(CWord,StringtoWord("d")) && (snake.First->info/5)*5 + (snake.First->info+1)%5 != MeteorLocation)) ||
               ((IsKataSama(CWord,StringtoWord("a")) && (snake.First->info/5)*5 + (snake.First->info+4)%5 != MeteorLocation)));
    } else {
        return false;
    }
}

int main(){
    boolean IsFoodAvailable = false;
    int FoodLocation = -1;
    int MeteorLocation = -1;
    int Turn = 1;
    int End = 0;
    int score = -1;
    List snake;
    CreateSnake(&snake);

    printf("Selamat datang di snake on meteor!\n\n");
    printf("Mengenerate peta, snake dan makanan . . . \n\n");
    printf("Berhasil digenerate!\n\n");
    printf("Berikut merupakan peta permainan\n");
    NextTurn(&snake, &FoodLocation, &IsFoodAvailable, 0, &MeteorLocation, &End, &score);
    
    int temporary;
    while(End == 0){
        printf("TURN %d:\n", Turn);
        printf("Silahkan masukkan command anda:");
        INPUT();
        while (!IsInputValid(CWord) || !IsMoveable(CWord,snake) || !IsMeteorLocation(CWord,snake,MeteorLocation)){
            if (IsInputValid(CWord) && !IsMoveable(CWord,snake)){
                printf("Command tidak valid! Ularmu tidak dapat berjalan ke badannya\n");
            } else if (IsInputValid(CWord) && !IsMeteorLocation(CWord,snake,MeteorLocation)) {
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut\n");
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
            InsVFirst(&snake, (snake.First->info/5)*5 + (snake.First->info+4)%5);
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
                End = 1;
            }

            IsFoodAvailable = false;
        }

        NextTurn(&snake, &FoodLocation, &IsFoodAvailable, Turn, &MeteorLocation, &End, &score);
        Turn++;
        if (End == 1){
            printf("Ekor ular tidak dapat bertambah.\n");
        }
    }

    printf("Game berakhir. Skor: %d\n", score);
}

