#include "treasurehunt.h"
#include <stdlib.h>

void ReadStory(BinTree Story){
    printf("%s",Story->info);
}

void ProgressStory(BinTree Story,int *choice,int *score)
{
    char *chest_open =
    "You open the chest and find a gemstone. Red in color and shining bright\n"
    "You discover that it could make anything you imagine.\n"
    "With this your village definitely will be the greatest superpower the world has ever seen\n"
    "GEM\n";

    char *chest_ignore =
    "You ignore the chest not willing to take a risk that it may be another mimic\n"
    "You find a light at the end of the tunnel leading outside.\n"
    "The WanPis might just be a myth after all, you thought.\n"
    "You used your experience found in the journey to lead your village to prosper.\n"
    "LEADER\n";
    if(!IsTreeOneElmt(Story)){
        boolean valid = false;
        while(valid == false)
        {
            *choice = 0;
            INPUT();
            WordToInt(CWord,choice);
            if(*choice == 1){
                ReadStory(Story->left);
                ProgressStory(Story->left,choice,score);
                valid = true;
                
            } else if(*choice == 2){
                ReadStory(Story->right);
                ProgressStory(Story->right,choice,score);
                valid = true;
            } else{
                printf("Inputan tidak valid.\n");
            }
        }
    }
    if(Story->info == chest_open){
        *score = 100;
        PrintGreen("THE END\n");
    } else if(Story->info == chest_ignore){
        *score = 50;
        PrintGreen("THE END\n");
    } else{
        PrintRed("GAME OVER.\n");
    }
}

void treasure_hunt(ArrayDyn ArrayGame, ArrayMap *MapGame)
{   
        char *ascii = 
    "*******************************************************************************\n"
    "          |                   |                  |                     |\n"
    " _________|________________.=''_;=.______________|_____________________|_______\n"
    "|                   |  ,-'_,=''     `'=.|                  |\n"
    "|___________________|__'=._o`'-._        `'=.______________|___________________\n"
    "          |                `'=._o`'=._      _`'=._                     |\n"
    " _________|_____________________:=._o '=._.'_.-='''=.__________________|_______\n"
    "|                   |    __.--' , ; `'=._o.' ,-'''-._ '.   |\n"
    "|___________________|_._'  ,. .` ` `` ,  `'-._'-._   '. '__|___________________\n"
    "          |           |o`'=._` , '` `; .'. ,  '-._'-._; ;              |\n"
    " _________|___________| ;`-.o`'=._; .'' ` '`.'\\` . '-._ /_______________|_______\n"
    "|                   | |o;    `'-.o`'=._``  '` ' ,__.--o;   |\n"
    "|___________________|_| ;     (#) `-.o `'=.`_.--'_o.-; ;___|___________________\n"
    "____/______/______/___|o;._    '      `'.o|o_.--'    ;o;____/______/______/____\n"
    "/______/______/______/_'=._o--._        ; | ;        ; ;/______/______/______/_\n"
    "____/______/______/______/__'=._o--._   ;o|o;     _._;o;____/______/______/____\n"
    "/______/______/______/______/____'=._o._; | ;_.--'o.--'_/______/______/______/_\n"
    "____/______/______/______/______/_____'=.o|o_.--''___/______/______/______/____\n"
    "/______/______/______/______/______/______/______/______/______/______/______/_\n"
    "*******************************************************************************\n\n";
        char *opening=  
        "In front of you is a cave said to harbor the treasure of a 13th century king, The WanPis.\n"
        "It is said that many adventurers come for the challenge of claiming the treasure\n"
        "but none make it safely home.\n\n"
        
        "As you take a step towards the cave, you turn on your flashlight but it just so happens to run out.\n"
        "You then start to have second thoughts, but you've spent every single penny for your trip here.\n"
        "\"There's no going back from this.\" You think to yourself.\n"
        "Hence, you take a brave step forward, hoping to bring back glory back to your village\n\n"
        
        "As you approach the cave entrance, you find a suspicious looking mushroom. With a red cap\n"
        "and blue stalk. Maybe it has something to do with this cave. Eat the mushroom?\n"
        "1. Eat the mushroom\n"
        "2. Don't eat the mushroom. It might be poisonous\n"
        "(Pick your choice with the corresponding number)\n";

    char *entrance =
        "You feel your eyes burn for a few seconds. Then everything you see takes on a green tint.\n"
        "You see just a few steps into the cave, a raised tile with a darker shade of green, feels like a button.\n"
        "You throw a rock into it and a flurry of arrows rain down, a trap, just like you expected.\n\n"
        
        "You then venture along inside the cave. There you find two passages left and right. Where do you go?\n"
        "1. Left\n"
        "2. Right\n";

    char *nomushroom = 
        "As you take a few steps into the dark cave. You sense a slight but sudden fall below your right foot\n"
        "Just like clockwork, you feel a needle pierce through your arm then many more. Your journey ends here.\n"
        "PIERCE THROUGH THE HEART ENDING\n";

    char *path_left =
        "You peek through a passage and see a sleeping beast with a lion head, bear body and a hawk's wings\n"
        "What do you do?\n"
        "1. Sneak past through it\n"
        "2. Fight it!\n";

    char *path_left_fight =
        "You use your sword to pierce through its eye\n"
        "Irritated, the beast swipes at you\n"
        "You die. What were you even thinking trying to fight such a beast?\n"
        "At least you've put a mark by half blinding the beast, at least\n"
        "AN EYE FOR A LIFE ENDING\n";

    char *path_left_sneak =
        "Just a step past the beast makes the beast swipe at you.\n"
        "You go flying and crash a boulder inside the cave\n"
        "Nice try I guess?\n"
        "ALL EARS ON YOU ENDING\n";

    char *path_right =
        "You peek through a corridor and see a kraken-like monster.\n"
        "It notices you and reaches one of its tentacle onto you.\n"
        "What do you do?\n"
        "1. Dodge it\n"
        "2. Slice it\n";

    char *kraken_dodge = 
        "You successfully dodge the tentacle by doing a limbo.\n"
        "However, you lose your footing and the kraken lifts you up into its mouth.\n"
        "KRAKEN MEAL ENDING\n";

    char *kraken_fight =
        "You slice through the tentacle and notice another tentacle coming after you.\n"
        "With a swift move, you use your blade to slice through every tentacles closing towards you.\n"
        "The kraken is defeated and you decide to bring its head as a trophy.\n\n"
        
        "You walk through a corridor and find a closed chest lying on a corner.\n"
        "Might this be the WanPis that is rumoured about?\n"
        "What do you do?\n"
        "1. Open the chest\n"
        "2. Ignore it\n";

    char *mimic_open =
        "You open the chest and see a pile of gold inside it.\n"
        "As you put your arm inside it, the chest grew teeth and bites your arm off.\n"
        "You fall for the mimic's trap and suffered from severe blood loss.\n\n"
        "ALL THAT GLITTERS ISN'T GOLD\n";

    char *mimic_ignore =
        "You decide to ignore the chest and find a small note slipping out beside the chest.\n"
        "It is an infographic of the mimic monster which looks exactly like the chest.\n"
        "You sigh in relief, having not fallen for the mimic's trap\n"
        "You then walk through a passage and find an identical chest from the previous one.\n"
        "What do you do?\n"
        "1. Open the chest\n"
        "2. Ignore it\n";

    char *chest_open =
        "You open the chest and find a gemstone. Red in color and shining bright\n"
        "You discover that it could make anything you imagine.\n"
        "With this your village definitely will be the greatest superpower the world has ever seen\n"
        "GEM\n";

    char *chest_ignore =
        "You ignore the chest not willing to take a risk that it may be another mimic\n"
        "You find a light at the end of the tunnel leading outside.\n"
        "The WanPis might just be a myth after all, you thought.\n"
        "You used your experience found in the journey to lead your village to prosper.\n"
        "LEADER\n";

    BinTree chest_ignore_tree =  Tree(chest_ignore,NilTree,NilTree);
    BinTree chest_open_tree = Tree(chest_open,NilTree,NilTree);
    BinTree mimic_ignore_tree = Tree(mimic_ignore,chest_open_tree,chest_ignore_tree);
    BinTree mimic_open_tree = Tree(mimic_open,NilTree,NilTree);
    BinTree kraken_fight_tree = Tree(kraken_fight,mimic_open_tree,mimic_ignore_tree);
    BinTree kraken_dodge_tree = Tree(kraken_dodge,NilTree,NilTree);
    BinTree path_right_tree = Tree(path_right,kraken_dodge_tree,kraken_fight_tree);
    BinTree path_left_sneak_tree = Tree(path_left_sneak,NilTree,NilTree);
    BinTree path_left_fight_tree = Tree(path_left_fight,NilTree,NilTree);
    BinTree path_left_tree = Tree(path_left,path_left_sneak_tree,path_left_fight_tree);
    BinTree entrance_tree = Tree(entrance,path_left_tree,path_right_tree);
    BinTree nomushroom_tree = Tree(nomushroom,NilTree,NilTree);
    BinTree Story = Tree(opening,entrance_tree,nomushroom_tree);
    
    int choice,score = 0;
    printf("%s",ascii);
    ReadStory(Story);
    ProgressStory(Story,&choice,&score);
    int index = FindStrArrayDyn(ArrayGame,"TREASURE HUNT");
    InsertScoreBoard(&MapGame->ElArrMap[index], score);
}