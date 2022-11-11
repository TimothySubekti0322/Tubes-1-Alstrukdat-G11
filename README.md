# Tubes-1-Alstrukdat-G11

## Deskripsi
<ul>
BNMO (dibaca: Binomo) adalah sebuah robot video game console yang dimiliki oleh Indra dan Doni. Dua bulan yang lalu, ia mengalami kerusakan dan telah berhasil diperbaiki. Sayangnya, setelah diperbaiki ia justru mendapatkan lebih banyak bug dalam sistemnya. Oleh karena itu, Indra dan Doni mencari programmer lain yang lebih handal untuk ulang memprogram robot video game console kesayangannya.

Setelah BNMO diperbaiki kelompok 12 K1, akhirnya BNMO dapat berfungsi. BNMO dapat berfungsi sebagai game console. Saat game pertama kali berjalan user dapat memasukan command "START" atau "LOAD". Command "START" akan membaca file config default pada BNMO. Command "LOAD" membaca file yang nama filenya dimasukan oleh user.

Setelah itu user dapat memasukan command - command lainnya diantaranya adalah "CREATE GAME", "LIST GAME", "DELETE GAME", "QUEUE GAME", "PLAY GAME", "SKIP GAME", "HELP", "SAVE", atau "EXIT".
<ul>

## Anggota Kelompok G17
1. 18221045 Ivan Aldy Ganesen 
2. 18221051 Muhammad Shulhan
3. 18221063 Timothy Subekti
4. 18221107 Ken Azizan
5. 18221165 Nicholas

## HOW TO PLAY
<b>[Go to src Folder]</b> <br />
cd src

<b>[compile the program]</b> <br />
gcc ADT/array/arraydinamik.c ADT/array/arraydinamikstr.c ADT/mesinkarakter/mesinkarakter.c ADT/mesinkata/mesinkata.c ADT/queue/queue.c ADT/queue/queuestr.c ../Game/RNG.c ../Game/dinerdash.h console.c main.c -o main

## Available File Configuration
config.txt

## Cara mengcompile File Program melalui Bash Shell Script File
<h3 style="font-size:0.5vw"><b>Windows</b></h3>
<ul> 
    <li> <b>Langkah 1</b> : Mengubah current directory ke bin -> cd bin </li>
    <li> <b>Langkah 2</b> : Mengcompile file.c -> bash BNMO.sh </li>
</ul>
