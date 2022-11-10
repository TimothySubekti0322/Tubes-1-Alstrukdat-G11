#BNMO.sh
main :
    gcc ../src/main.c ../src/console.c ../Game/dinerdash.c ../Game/RNG.c ../src/ADT/mesinkarakter/mesinkarakter.c ../src/ADT/mesinkata/mesinkata.c ../src/ADT/queue/queue.c ../src/ADT/queue/queuestr.c ../Game/mole.c ../src/ADT/array/arraystatis.c -o main
clean :
    rm main