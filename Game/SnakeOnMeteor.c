#include "SnakeOnMeteor.h"

void randomnumbersnake(int *x,int *y){
    srand(time(NULL));
    *x = rand() % 5;
    *y = rand() % 5;
}

/*------------Fungsi untuk memeriksa lokasi snake(full component, atau body saja) dan obstacle dalam peta------------*/

boolean IsSnakeLocation(List snake, int input){
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

boolean IsObstacleLocation(StatArray ObstacleLocation, int location){
    boolean Found = false;
    int i = 0;
    while (!Found && i < ObstacleLocation.Neff){
        if (ObstacleLocation.Ar[i] == location){
            Found = true;
        } else {
            i++;
        }
    }
    return Found;
}

/*------------Fungsi untuk membuat kompenen dalam peta------------*/

void CreateSnake(List *snake, StatArray ObstacleLocation){
    CreateEmptyList(snake);
    int x,y;
    randomnumbersnake(&x,&y);
    while (IsObstacleLocation(ObstacleLocation, x + 5*y)){
        randomnumbersnake(&x,&y);
    }
    int coordinat = x + 5*y;
    InsVLast(snake,coordinat);
    for (int i=0; i<2; i++){
        if (!IsObstacleLocation(ObstacleLocation, (coordinat/5)*5 + (coordinat+4)%5)){
            InsVLast(snake,(coordinat/5)*5 + (coordinat+4)%5);
            coordinat = (coordinat/5)*5 + (coordinat+4)%5;
        } else if (!IsObstacleLocation(ObstacleLocation, (coordinat+20)%25)){
            InsVLast(snake,(coordinat+20)%25);
            coordinat = (coordinat+20)%25;            
        } else if (!IsObstacleLocation(ObstacleLocation, (coordinat+5)%25)){
            InsVLast(snake,(coordinat+5)%25);
            coordinat = (coordinat+5)%25;      
        } else if (!IsObstacleLocation(ObstacleLocation, (coordinat/5)*5 + (coordinat+1)%5)){
            InsVLast(snake,(coordinat/5)*5 + (coordinat+1)%5);
            coordinat = (coordinat/5)*5 + (coordinat+1)%5;
        }
    }
}

void GenerateFood(StatArray *container, int *FoodLocation, List snake, StatArray ObstacleLocation){
    int x,y;
    randomnumbersnake(&x,&y);
    while(container->Ar[x + 5*y] != -100 || IsObstacleLocation(ObstacleLocation, x + 5*y) || IsSnakeLocation(snake, x + 5*y)){
        randomnumbersnake(&x,&y);
    }
    container->Ar[x + 5*y] = -1;
    *FoodLocation = x + 5*y;
}

void GenerateMeteor(int *MeteorLocation, int Foodlocation, StatArray ObstacleLocation){
    int x,y;
    randomnumbersnake(&x,&y);
    while(x + 5*y == Foodlocation || IsObstacleLocation(ObstacleLocation, x + 5*y)){
        randomnumbersnake(&x,&y);
    }
    *MeteorLocation = x + 5*y;
}

void GenerateObstacle(StatArray *ObstacleLocation, int number){
    int x,y;
    for (int i = 0; i < number; i++){
        randomnumbersnake(&x,&y);
        while (IsObstacleLocation(*ObstacleLocation, x + 5*y)){
            randomnumbersnake(&x,&y);
        }
        InsertLStat(ObstacleLocation, x + 5*y);
    }
}

/*------------Fungsi yang berhubungan dengan inputan yang valid sehingga ular bisa bergerak------------*/

boolean IsCommandValid(Word CWord){
    return (IsKataSama(CWord,StringtoWord("w")) || IsKataSama(CWord,StringtoWord("s")) || IsKataSama(CWord,StringtoWord("a")) || IsKataSama(CWord,StringtoWord("d")));
}

boolean IsTowardSnakeBody(Word CWord, List snake){
    if (IsCommandValid(CWord)){
        return(((IsKataSama(CWord,StringtoWord("w")) && IsSnakeBody(snake,(snake.First->info+20)%25))) ||
               ((IsKataSama(CWord,StringtoWord("s")) && IsSnakeBody(snake,(snake.First->info+5)%25))) ||
               ((IsKataSama(CWord,StringtoWord("d")) && IsSnakeBody(snake,(snake.First->info/5)*5 + (snake.First->info+1)%5))) ||
               ((IsKataSama(CWord,StringtoWord("a")) && IsSnakeBody(snake,(snake.First->info/5)*5 + (snake.First->info+4)%5))));
    } else {
        return false;
    }
}

boolean IsTowardMeteor(Word Cword, List snake, int MeteorLocation){
    if (IsCommandValid(CWord)){
        return(((IsKataSama(CWord,StringtoWord("w")) && (snake.First->info+20)%25 == MeteorLocation)) ||
               ((IsKataSama(CWord,StringtoWord("s")) && (snake.First->info+5)%25 == MeteorLocation)) ||
               ((IsKataSama(CWord,StringtoWord("d")) && (snake.First->info/5)*5 + (snake.First->info+1)%5 == MeteorLocation)) ||
               ((IsKataSama(CWord,StringtoWord("a")) && (snake.First->info/5)*5 + (snake.First->info+4)%5 == MeteorLocation)));
    } else {
        return false;
    }
}

boolean IsTowardObstacle(Word Cword, List snake, StatArray ObstacleLocation){
    if (IsCommandValid(CWord)){
        return(((IsKataSama(CWord,StringtoWord("w")) && IsObstacleLocation(ObstacleLocation, (snake.First->info+20)%25))) ||
               ((IsKataSama(CWord,StringtoWord("s")) && IsObstacleLocation(ObstacleLocation, (snake.First->info+5)%25))) ||
               ((IsKataSama(CWord,StringtoWord("d")) && IsObstacleLocation(ObstacleLocation, (snake.First->info/5)*5 + (snake.First->info+1)%5))) ||
               ((IsKataSama(CWord,StringtoWord("a")) && IsObstacleLocation(ObstacleLocation, (snake.First->info/5)*5 + (snake.First->info+4)%5))));
    } else {
        return false;
    }
}

boolean IsNotMoveable(List snake, int MeteorLocation, StatArray ObstacleLocation){
    char w[1] = {'w'};
    char s[1] = {'s'};
    char d[1] = {'d'};
    char a[1] = {'a'};
    return ((IsTowardSnakeBody(StringtoWord(w),snake) || IsTowardMeteor(StringtoWord(w),snake,MeteorLocation) || IsTowardObstacle(StringtoWord(w),snake,ObstacleLocation)) &&
            (IsTowardSnakeBody(StringtoWord(s),snake) || IsTowardMeteor(StringtoWord(s),snake,MeteorLocation) || IsTowardObstacle(StringtoWord(s),snake,ObstacleLocation)) &&
            (IsTowardSnakeBody(StringtoWord(d),snake) || IsTowardMeteor(StringtoWord(d),snake,MeteorLocation) || IsTowardObstacle(StringtoWord(d),snake,ObstacleLocation)) &&
            (IsTowardSnakeBody(StringtoWord(a),snake) || IsTowardMeteor(StringtoWord(a),snake,MeteorLocation) || IsTowardObstacle(StringtoWord(a),snake,ObstacleLocation)));
}

/*------------Fungsi untuk memunculkan keadaan map sekarang------------*/

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
            } else if (container.Ar[i]==-5) {
                printf(" X |"); 
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

/*------------Fungsi utama dalam menjalankan program------------*/

void NextTurn(List *snake, int *FoodLocation, boolean *IsFoodAvailable, int Turn, int *MeteorLocation, int *End, int *score, StatArray ObstacleLocation){
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

    for (int i = 0; i < ObstacleLocation.Neff; i++){
        container.Ar[ObstacleLocation.Ar[i]] = -5;
    }

    if (!(*IsFoodAvailable)){
        GenerateFood(&container, FoodLocation, *snake, ObstacleLocation);
        *IsFoodAvailable = true;
    } else {
        container.Ar[*FoodLocation] = -1;
    }

    boolean IsHitMeteor = false;
    if (Turn > 0){
        GenerateMeteor(MeteorLocation, *FoodLocation, ObstacleLocation);
        if (IsSnakeLocation(*snake,*MeteorLocation)){    
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

void SnakeOnMeteor(){
    boolean IsFoodAvailable = false;
    int FoodLocation = -1;
    int MeteorLocation = -1;
    StatArray ObstacleLocation;
    ObstacleLocation = CreateStatArray();
    int Turn = 1;
    int End = 0;
    int score = -1;
    List snake;

    printf("Selamat datang di snake on meteor!\n\n");
    printf("Apa Anda ingin menggunakan obstacle untuk permainan ini?\n");
    printf("Input(y|n) : " );
    INPUT();
    while (!IsKataSama(CWord,StringtoWord("n")) && !IsKataSama(CWord,StringtoWord("y"))){
        printf("Input Anda tidak valid!\n");
        printf("Silakan input ulang!\n");
        printf("Input(y|n) : " );
        INPUT();
    }
    printf("\n");
    if (IsKataSama(CWord,StringtoWord("y"))){
        printf("Berapa jumlah obstacle yang Anda inginkan?\n");
        printf("Input(1-2) : ");
        INPUT();
        while (!IsKataSama(CWord,StringtoWord("1")) && !IsKataSama(CWord,StringtoWord("2"))){
            printf("Input Anda tidak valid! Jawab dalam range 1 sampai 2\n");
            printf("Silakan input ulang!\n");
            printf("Input(1-2) : ");
            INPUT();
        }
        if (IsKataSama(CWord,StringtoWord("1"))){
            GenerateObstacle(&ObstacleLocation, 1);
        } else {
            GenerateObstacle(&ObstacleLocation, 2);
        }
    }
    printf("\n");
    printf("Mengenerate peta, snake dan makanan . . . \n\n");
    printf("Berhasil digenerate!\n\n");
    printf("Berikut merupakan peta permainan\n");
    CreateSnake(&snake, ObstacleLocation);
    NextTurn(&snake, &FoodLocation, &IsFoodAvailable, 0, &MeteorLocation, &End, &score, ObstacleLocation);
    
    int temporary;
    while(End == 0){
        printf("TURN %d:\n", Turn);
        printf("Silahkan masukkan command anda:");
        INPUT();
        /* if (IsNotMoveable(snake,MeteorLocation,ObstacleLocation)) {
            End = 4;
        } else */ if (IsTowardObstacle(CWord,snake,ObstacleLocation)){
            End = 3;
        } else {
            while (!IsCommandValid(CWord) || IsTowardSnakeBody(CWord,snake) || IsTowardMeteor(CWord,snake,MeteorLocation)){
                if (IsCommandValid(CWord) && IsTowardSnakeBody(CWord,snake)){
                    printf("Command tidak valid! Ularmu tidak dapat berjalan ke badannya\n");
                } else if (IsCommandValid(CWord) && IsTowardMeteor(CWord,snake,MeteorLocation)) {
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
                if (!IsSnakeLocation(snake,(temporary/5)*5 + (temporary-1)%5)){
                    InsVLast(&snake, (temporary/5)*5 + (temporary-1)%5);
                } else if (!IsSnakeLocation(snake,(temporary+20)%25)){
                    InsVLast(&snake, (temporary+20)%25);
                } else if (!IsSnakeLocation(snake,(temporary+5)%25)){
                    InsVLast(&snake, (temporary+5)%25);
                } else if (!IsSnakeLocation(snake,(temporary/5)*5 + (temporary+1)%5)){
                    InsVLast(&snake, (temporary/5)*5 + (temporary+1)%5);
                } else {
                    End = 1;
                }
                IsFoodAvailable = false;
            }

            NextTurn(&snake, &FoodLocation, &IsFoodAvailable, Turn, &MeteorLocation, &End, &score, ObstacleLocation);
            Turn++;
        }
    }

    if (End == 1){
        printf("Ekor ular tidak dapat bertambah!\n");
    } else if (End == 3){
        printf("Ularmu menabrak obstacle!\n");
    } else if (End == 4){
        printf("Ularmu tidak dapat bergerak kemana pun!\n");
    }
    printf("Game berakhir. Skor: %d\n", score);
}