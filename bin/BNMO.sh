#BNMO.sh
driver :
    gcc gcc main.c console.c ../Game/dinerdash.c ../Game/RNG.c ADT/array/arraydinamikstr.c ADT/array/arraydinamik.c ADT/mesinkarakter/mesinkarakter.c ADT/mesinkata/mesinkata.c ADT/queue/queue.c ADT/queue/queuestr.c ../Game/mole.c -o main
clean :
    rm driver