#include "SnakeOnMeteor.h"
#include <stdlib.h>

/*------------Fungsi tambahan------------*/

void randomnumbersnake(int *x,int *y){
    srand(time(NULL));
    *x = rand() % 5;
    *y = rand() % 5;
}

int idxmaxarray(StatArray container, int n)
{
    int i, idxmax;
    idxmax = 0;
    for (i = 1; i < n; i++)
    {
        if (container.Ar[i] > container.Ar[idxmax])
        {
            idxmax = i;
        }
    }
    return idxmax;
}

int idxnol(StatArray container, int n)
{
    int i, idxnol;
    idxnol = 0;
    for (i = 0; i < n; i++)
    {
        if (container.Ar[i] == 0)
        {
            return i;
        }
    }
    return -100;
}

int idxsatu(StatArray container, int n)
{
    int i, idxsatu;
    idxsatu = 0;
    for (i = 0; i < n; i++)
    {
        if (container.Ar[i] == 1)
        {
            return i;
        }
    }
    return -100;
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

/*------------Fungsi untuk memunculkan keadaan map sekarang------------*/
void DisplaySOMMap(StatArray container, Word Cword)
{
    //int board[21][51];
    int**board = (int**) malloc(21*sizeof(int*));
    for (int i = 0; i < 21; i++){
        board[i] = (int*) malloc(51*sizeof(int));
    }

    for(int i = 0 ; i < 21; i++)
    {
        for(int j = 0; j < 51 ; j++)
        {
            board[i][j] = -100;
        }
    }

    // int array[25] = {-100,5,4,-100,-100,
    //                  -100,-100,3,-100,-100,
    //                  -100,-100,2,-100,-100,
    //                  -100,-100,1,-100,-100,
    //                  -100,-100,0,-100,-100};
    
    int idxmaxbody = idxmaxarray(container, 25);
                     
    int asciTLC = 218;
    int asciH = 196;
    int asciV = 179;
    int asciT = 194;
    int asciTRC = 191;
    int asciTkiri = 195;
    int asciTkanan = 180;
    int asciTbawah = 193;
    int asciBLC = 192;
    int asciBRC = 217;
    int asciplus = 197;
    int ascibox = 219;
    int ascicircle = 111;
    int ascicongruent = 240;
    int asciequal = 205;
    int ascislashedzero = 157;
    int asciX = 88;
    int asciM = 77;

    // printf("%d",board[5][11]);

    for(int i = 0 ; i < 21; i++)
    {
        for(int j = 0; j < 51 ; j++)
        {
            if(i % 4 == 0 && j == 0)  /* T kiri */
            {
                board[i][j] = asciTkiri;
            }

            else if(i % 4 == 0 && j == 50)  /* T Kanan*/
            {
                board[i][j] = asciTkanan;
            }

            else if(j % 10 == 0 && i == 0)  /* T Atas */
            {
                board[i][j] = asciT;
            }

            else if(j % 10 == 0 && i == 20)  /* T Bawah */
            {
                board[i][j] = asciTbawah;
            }

            else if((i % 4 == 0) && (j % 10 == 0))  /* T Tengah (Plus) */
            {
                board[i][j] = asciplus;
            }
            else if(i % 4 == 0) /* Garis Horizontal */
            {
                board[i][j] = asciH;
            }

            else if(j % 10 == 0)  /* Garis Vertikal */
            {
                board[i][j] = asciV;
            }
        }
    }

    board[0][0] = asciTLC;
    board[0][50] = asciTRC;
    board[20][0] = asciBLC;
    board[20][50] = asciBRC;

    /* Body */
    for(int i = 0; i < 25; i++)
    {
        if (container.Ar[i] >= 0 && container.Ar[i] < 10)
        {
            for(int j = (i%5)*10 + 5 - 1 ; j < (i%5)*10 + 7; j++)
            {
                board[(i/5)*4 + 3 - 1][j] = ascibox;
            }
        }
    }

    /* Side Up */
    for(int i = 0; i < 25; i++)
    {   //printf("sideup\n");
        if ((container.Ar[i] > 0) && (container.Ar[i] <= 10))
        {   //printf("container.Ar[%d] = %d\n",i,container.Ar[i]);
            if ((i >= 0) && (i <= 4))
            {
                if ((container.Ar[i+20] == container.Ar[i]-1) || (container.Ar[i+20] == container.Ar[i]+1))
                {
                    for (int j = (i%5)*10 + 5 - 1; j < (i%5)*10 + 7; j++)
                    {
                        board[1][j] = ascibox;
                    }

                }
                else if((i == idxmaxbody) && (container.Ar[i+20] == 0))
                {
                    for (int j = (i%5)*10 + 5 - 1; j < (i%5)*10 + 7; j++)
                    {
                        board[1][j] = ascibox;
                    }
                }
                
            }

            else
            {
                if ((container.Ar[i-5] == container.Ar[i]-1) || (container.Ar[i-5] == container.Ar[i]+1))
                {
                    for (int j = (i%5)*10 + 5 - 1; j < (i%5)*10 + 7; j++)
                    {
                        for(int k = (i/5)*4 + 3 - 2 - 1 ; k < (i/5)*4 + 3 - 1; k++)
                        {
                            board[k][j] = ascibox;
                        }
                    }
                }

                else if((i == idxmaxbody) && (container.Ar[i-5] == 0))
                {   
                    for (int j = (i%5)*10 + 5 - 1; j < (i%5)*10 + 7; j++)
                    {
                        for(int k = (i/5)*4 + 3 - 2 - 1 ; k < (i/5)*4 + 3 - 1; k++)
                        {
                            board[k][j] = ascibox;
                        }
                    }
                }
            }
        }
        else if(container.Ar[i] == 0)
        {
            if ((i >= 0) && (i <= 4))
            {
                if (container.Ar[i+20] == 1)
                {
                    for (int j = (i%5)*10 + 5 - 1; j < (i%5)*10 + 7; j++)
                    {
                        board[1][j] = ascibox;
                    }                  
                }  
            }
            else
            {
                if (container.Ar[i-5] == 1)
                {
                    for (int j = (i%5)*10 + 5 - 1; j < (i%5)*10 + 7; j++)
                    {
                        for(int k = (i/5)*4 + 3 - 2 - 1 ; k < (i/5)*4 + 3 - 1; k++)
                        {
                            board[k][j] = ascibox;
                        }
                    }
                }
            }
        }
    }

    /* Side Left */
    for(int i = 0; i < 25; i++)
    {
        if ((container.Ar[i] > 0) && (container.Ar[i] < 10))
        {   //printf("%d = %d\n",i ,container.Ar[i]);
            if (i%5 == 0)
            {
                if ((container.Ar[i+4] == container.Ar[i]-1) || (container.Ar[i+4] == container.Ar[i]+1))
                {
                    for(int j = (i%5)*10 + 5 - 3 - 1 ; j < (i%5)*10 + 5-1 ; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
                else if((i == idxmaxbody) && (container.Ar[i+4] == 0))
                {
                    for(int j = (i%5)*10 + 5 - 3 - 1 ; j < (i%5)*10 + 5-1 ; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
            }
            else
            {
                //printf("Masuk , ");
                if ((container.Ar[i-1] == container.Ar[i]-1) || (container.Ar[i-1] == container.Ar[i]+1))
                {
                    for(int j = (i%5)*10 + 5 - 4 - 1; j < (i%5)*10 + 5-1; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
                
                else if((i == idxmaxbody) && (container.Ar[i-1] == 0))
                {
                    for(int j = (i%5)*10 + 5 - 4 - 1; j < (i%5)*10 + 5-1; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
            }
        }
        else if(container.Ar[i] == 0)
        {
            if (i%5 == 0)
            {
                if (container.Ar[i+4] == 1)
                {
                    for(int j = (i%5)*10 + 5 - 3 - 1 ; j < (i%5)*10 + 5-1 ; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
            }
            else
            {
                //printf("Masuk , ");
                if (container.Ar[i-1] == 1)
                {
                    for(int j = (i%5)*10 + 5 - 4 - 1; j < (i%5)*10 + 5-1; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
            }
        }
    }

    /* Side Right */
    for(int i = 0; i < 25; i++)
    {   //printf("%d\n",i);
        //printf("%d\n",container.Ar[i]);
        if ((container.Ar[i] > 0) && (container.Ar[i] < 10))
        {
            //printf("%d\n",i);
            if ((i + 1)%5 == 0)
            {
                if ((container.Ar[i-4] == container.Ar[i]-1) || (container.Ar[i-4] == container.Ar[i]+1))
                {
                    for (int j = (i%5)*10 + 5 + 3 - 1 ; j < (i%5)*10 + 7 + 3; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
                else if((i == idxmaxbody) && (container.Ar[i-4] == 0))
                {
                    for( int j = (i%5)*10 + 5 + 3 - 1 ; j < (i%5)*10 + 7 + 3; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
            }
            else
            {
                if ((container.Ar[i+1] == container.Ar[i]-1) || (container.Ar[i+1] == container.Ar[i]+1))
                {
                    for (int j = (i%5)*10 + 5 + 3 - 1 ; j < (i%5)*10 + 7 + 3; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
                else if((i == idxmaxbody) && (container.Ar[i+1] == 0))
                {
                    for (int j = (i%5)*10 + 5 + 3 - 1 ; j < (i%5)*10 + 7 + 3; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
            }
        }
        else if(container.Ar[i] == 0)
        {
            if ((i + 1)%5 == 0)
            {
                if (container.Ar[i-4] == 1)
                {
                    for (int j = (i%5)*10 + 5 + 3 - 1 ; j < (i%5)*10 + 7 + 3; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
            }
            else
            {
                if (container.Ar[i+1] == 1)
                {
                    for (int j = (i%5)*10 + 5 + 3 - 1 ; j < (i%5)*10 + 7 + 3; j++)
                    {
                        board[(i/5)*4 + 3 - 1][j] = ascibox;
                    }
                }
            }
        }
    }

    /* Side Down */
    for(int i = 0; i < 25; i++)
    {
        if ((container.Ar[i] > 0) && (container.Ar[i] < 10))
        {
            if ((i >= 20) && (i <= 24))
            {
                if ((container.Ar[i-20] == container.Ar[i]-1) || (container.Ar[i-20] == container.Ar[i]+1))
                {
                    for(int j = (i%5)*10 + 5 - 1 ; j < (i%5)*10 + 7; j++)
                    {
                        board[(i/5)*4 + 3 + 1 - 1][j] = ascibox;
                    }
                }
                else if ((i == idxmaxbody) && (container.Ar[i-20] == 0))
                {
                    for(int j = (i%5)*10 + 5 - 1 ; j < (i%5)*10 + 7; j++)
                    {
                        board[(i/5)*4 + 3 + 1 - 1][j] = ascibox;
                    }
                }
            }
            else
            {
                if ((container.Ar[i+5] == container.Ar[i]-1) || (container.Ar[i+5] == container.Ar[i]+1))
                {
                    for(int j = (i%5)*10 + 5 - 1 ; j < (i%5)*10 + 7; j++)
                    {
                        board[(i/5)*4 + 3 + 1 - 1][j] = ascibox;
                    }
                }

                else if ((i == idxmaxbody) && (container.Ar[i+5] == 0))
                {
                    for(int j = (i%5)*10 + 5 - 1 ; j < (i%5)*10 + 7; j++)
                    {
                        board[(i/5)*4 + 3 + 1 - 1][j] = ascibox;
                    }
                }
            }
        }
        else if (container.Ar[i] == 0)
        {
            //printf("Masuk\n");
            if ((i >= 20) && (i <= 24))
            {
                // printf("container.Ar[%d] = %d\n",idxmaxbody,container.Ar[idxmaxbody]);
                // printf("container.Ar[%d] = %d\n",i,container.Ar[i]);
                if (container.Ar[i-20] == 1)
                {
                    for(int j = (i%5)*10 + 5 - 1 ; j < (i%5)*10 + 7; j++)
                    {
                        board[(i/5)*4 + 3 + 1 - 1][j] = ascibox;
                    }
                }
            }
            else
            {   
                if (container.Ar[i+5] == 1)
                {
                    for(int j = (i%5)*10 + 5 - 1 ; j < (i%5)*10 + 7; j++)
                    {
                        board[(i/5)*4 + 3 + 1 - 1][j] = ascibox;
                    }
                }
            }
        }
    }



    /* Head */
    int idxhead = idxnol(container,25);
    //printf("\nidxhead = %d\n",idxhead);

    /* body before Head */
    int idxprevhead = idxsatu(container,25);
    //printf("\nidxprevhead = %d\n",idxprevhead);

    /* Face Up */
    if(Cword.TabWord[0] == 'w')
    {
        for(int j = (idxhead%5)*10 + 5 - 1 ; j < (idxhead%5)*10 + 7; j++)
        {
            board[(idxhead/5)*4 + 3 - 1 - 1][j] = asciT;
        }
    }

    /* Face Left */
    else if(Cword.TabWord[0] == 'a')
    {
        board[(idxhead/5)*4 + 3 - 1][(idxhead%5)*10 + 5-2] = asciTkiri;
    }

    /* Face Right*/
    else if(Cword.TabWord[0] == 'd')
    {
        board[(idxhead/5)*4 + 3 - 1][(idxhead%5)*10 + 7] = asciTkanan;
    }

    /* Face Down */
    else if(Cword.TabWord[0] == 's')
    {
        for(int j = (idxhead%5)*10 + 5 - 1 ; j < (idxhead%5)*10 + 7; j++)
        {
            board[(idxhead/5)*4 + 3][j] = asciTbawah;
        }
    }

    /* Face Up */
    else if (idxhead == idxprevhead + 20)
    {
        for(int j = (idxhead%5)*10 + 5 - 1 ; j < (idxhead%5)*10 + 7; j++)
        {
            board[(idxhead/5)*4 + 3 - 1 - 1][j] = asciT;
        }
    }

    else if (idxhead == (idxprevhead - 5))
    {
        //printf("\nMasuk\n");
        for(int j = (idxhead%5)*10 + 5 - 1 ; j < (idxhead%5)*10 + 7; j++)
        {
            board[(idxhead/5)*4 + 3 - 1 - 1][j] = asciT;
        }
    }


    /* Face Left */
    else if (idxhead == idxprevhead + 4)
    {
        board[(idxhead/5)*4 + 3 - 1][(idxhead%5)*10 + 5-2] = asciTkiri;
    }

    else if (idxhead == (idxprevhead - 1))
    {
        board[(idxhead/5)*4 + 3 - 1][(idxhead%5)*10 + 5-2] = asciTkiri;
    }


    /* Face Rigth */
    else if (idxhead == (idxprevhead-4))
    {
        board[(idxhead/5)*4 + 3 - 1][(idxhead%5)*10 + 7] = asciTkanan;
    }

    else if (idxhead == (idxprevhead + 1))
    {
        board[(idxhead/5)*4 + 3 - 1][(idxhead%5)*10 + 7] = asciTkanan;
    }


    /* Face Down */
    else if (idxhead == (idxprevhead - 20))
    {
        for(int j = (idxhead%5)*10 + 5 - 1 ; j < (idxhead%5)*10 + 7; j++)
        {
            board[(idxhead/5)*4 + 3][j] = asciTbawah;
        }
    }
    
    else if (idxhead == (idxprevhead + 5))
    {
        for(int j = (idxhead%5)*10 + 5 - 1 ; j < (idxhead%5)*10 + 7; j++)
        {
            board[(idxhead/5)*4 + 3][j] = asciTbawah;
        }
    }

    /* Food */
    for(int i = 0; i < 25; i++)
    {
        if (container.Ar[i] == -1)
        {
            board[(i/5)*4 + 3 - 1][(i%5)*10 + 5] = ascicircle;
        }
    }

    /* Meteor */
    for(int i = 0; i < 25; i++)
    {
        if (container.Ar[i] == -10)
        {
            board[(i/5)*4 + 3 - 1][(i%5)*10 + 5] = asciX;
        }
    }

    /* Obstacle */
    for(int i = 0; i < 25; i++)
    {
        if (container.Ar[i] == -5)
        {
            for(int j = (i/5)*4 + 1 ; j < (i/5)*4 + 4 ; j++)
            {
                for(int k = (i%5)*10 + 1 ; k < (i%5)*10 + 10 ; k++)
                {
                    board[j][k] = ascibox;
                }
            }
        }
    }

    
    /* Melakukan Print*/
    for(int baris = 0 ; baris < 21 ; baris++)
    {
        for(int kolom = 0 ; kolom < 51 ; kolom++)
        {
            if (board[baris][kolom] == -100)
            {
                printf(" ");
            }
            else
            {
                printf("%c",board[baris][kolom]);
            }
        }
        printf("\n");
    }

    for(int i = 0; i < 21; i++)
    {
        free(board[i]);
    }
    free(board);
}

void ShowSquare(StatArray container , Word Cword){
    DisplaySOMMap(container, Cword);
    // for (int j = 0; j<5; j++){
    //     printf("---------------------\n");
    //     printf("|");
    //     for (int i = j*5; i<(j+1)*5; i++){
    //         if (container.Ar[i]==-100){
    //             printf("   |");
    //         } else if (container.Ar[i]==0){
    //             printf(" H |");
    //         } else if (container.Ar[i]==-1){
    //             printf(" o |");
    //         } else if (container.Ar[i]==-5) {
    //             printf(" X |"); 
    //         } else if (container.Ar[i]==-10){
    //             printf(" m |");
    //         } else if (container.Ar[i]>0 && container.Ar[i]<10){
    //             printf(" %d |", container.Ar[i]);
    //         } else {
    //             printf(" %d|", container.Ar[i]);
    //         }
    //     }
    //     printf("\n");
    // }
    // printf("---------------------\n");
    printf("\n");
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

    ShowSquare(container,CWord);
    *score = coordinat.Neff*2;

    if (Turn > 0){
        if (IsHitMeteor == false){
            printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
        } else {
            if (container.Ar[snake->First->info] == -10){
                *End = 2;
                *score = (coordinat.Neff-1)*2;
            } else {
                printf("Anda terkena meteor!\n\n");
                int temporary;
                if (container.Ar[coordinat.Ar[coordinat.Neff-1]] == -10){
                    DelVLast(snake, &temporary);
                    container.Ar[coordinat.Ar[coordinat.Neff-1]] == -100;
                    printf("Berikut merupakan peta permainan sekarang:\n");
                    ShowSquare(container,CWord);
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
                    ShowSquare(container,CWord);
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
    
    if (container.Ar[(snake->First->info+5)%25] != -100 && container.Ar[(snake->First->info+20)%25] != -100 && container.Ar[(snake->First->info/5)*5 + (snake->First->info+4)%5] != -100 && container.Ar[(snake->First->info/5)*5 + (snake->First->info+1)%5] != -100 &&
        container.Ar[(snake->First->info+5)%25] != -10 && container.Ar[(snake->First->info+20)%25] != -10 && container.Ar[(snake->First->info/5)*5 + (snake->First->info+4)%5] != -10 && container.Ar[(snake->First->info/5)*5 + (snake->First->info+1)%5] != -10){
        *End = 4;
    }
}

void SnakeOnMeteor(ArrayDyn ArrayGame, ArrayMap *MapGame){
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
        if (IsTowardObstacle(CWord,snake,ObstacleLocation)){
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
                if (!(IsSnakeLocation(snake,(temporary/5)*5 + (temporary+4)%5) || IsObstacleLocation(ObstacleLocation,(temporary/5)*5 + (temporary+4)%5) || MeteorLocation == (temporary/5)*5 + (temporary+4)%5)){
                    InsVLast(&snake, (temporary/5)*5 + (temporary+4)%5);
                } else if (!(IsSnakeLocation(snake,(temporary+20)%25) || IsObstacleLocation(ObstacleLocation,(temporary+20)%25) || MeteorLocation == (temporary+20)%25)){
                    InsVLast(&snake, (temporary+20)%25);
                } else if (!(IsSnakeLocation(snake,(temporary+5)%25) || IsObstacleLocation(ObstacleLocation,(temporary+5)%25) || MeteorLocation == (temporary+5)%25)){
                    InsVLast(&snake, (temporary+5)%25);
                } else if (!(IsSnakeLocation(snake,(temporary/5)*5 + (temporary+1)%5) || IsObstacleLocation(ObstacleLocation,(temporary/5)*5 + (temporary+1)%5) || MeteorLocation == (temporary/5)*5 + (temporary+1)%5)){
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
    } else if (End == 2){
        printf("Kepala snake terkena meteor!\n");
    } else if (End == 3){
        printf("Ularmu menabrak obstacle!\n");
    } else if (End == 4){
        printf("Ularmu tidak dapat bergerak kemana pun!\n");
    }
    printf("Game berakhir. Skor: %d\n", score);

    int index = FindStrArrayDyn(ArrayGame,"SNAKE ON METEOR");
    InsertScoreBoard(&MapGame->ElArrMap[index], score);
}