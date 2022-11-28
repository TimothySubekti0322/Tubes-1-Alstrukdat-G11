#include "treasurehunt.h"
#include <stdlib.h>

void ReadStory(BinTree Story){
    printf("%s",Story->info);
}

void ProgressStory(BinTree Story,int *choice,int *score){
    if(!IsTreeOneElmt(Story)){
        boolean valid = false;
        while(valid == false){
            scanf("%d",choice);
            if(*choice == 1){
                ReadStory(Story->left);
                ProgressStory(Story->left,choice,&score);
                valid = true;
                
            } else if(*choice == 2){
                ReadStory(Story->right);
                ProgressStory(Story->right,choice,&score);
                valid = true;
            } else{
                printf("Inputan tidak valid.\n");
            }
        }
    }
    if(Story->info = chest_open){
        score = 100;
    } else if(Story->info = chest_ignore){
        score = 50;
    }
}

void treasure_hunt(ArrayDyn ArrayGame, ArrayMap *MapGame){
    BinTree chest_ignore_tree =  Tree(chest_ignore,Nil,Nil);
    BinTree chest_open_tree = Tree(chest_open,Nil,Nil);
    BinTree mimic_ignore_tree = Tree(mimic_ignore,chest_open_tree,chest_ignore_tree);
    BinTree mimic_open_tree = Tree(mimic_open,Nil,Nil);
    BinTree kraken_fight_tree = Tree(kraken_fight,mimic_open_tree,mimic_ignore_tree);
    BinTree kraken_dodge_tree = Tree(kraken_dodge,Nil,Nil);
    BinTree path_right_tree = Tree(path_right,kraken_dodge_tree,kraken_fight_tree);
    BinTree path_left_sneak_tree = Tree(path_left_sneak,Nil,Nil);
    BinTree path_left_fight_tree = Tree(path_left_fight,Nil,Nil);
    BinTree path_left_tree = Tree(path_left,path_left_sneak_tree,path_left_fight_tree);
    BinTree entrance_tree = Tree(entrance,path_left_tree,path_right_tree);
    BinTree nomushroom_tree = Tree(nomushroom,Nil,Nil);
    BinTree Story = Tree(opening,entrance_tree,nomushroom_tree);
    
    int choice,score = 0;
    ReadStory(Story);
    ProgressStory(Story,&choice,&score);
    int index = FindStrArrayDyn(ArrayGame,"TREASURE HUNT");
    InsertScoreBoard(&MapGame->ElArrMap[index], score);
}