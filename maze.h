// AEDs 2 - Labirinto
// Alunos: Maick Carvalho e Francisco Schneedorf

#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>

// Estrutura para registro do trajeto
typedef struct {
    int h, l;
} Pos;

// Variáveis globais para registro do percurso
extern Pos route[100];
extern int tam;


int leMatriz(FILE *arch, char maze[10][10], int *linhaEntrada, int *colunaEntrada);
int abreMatriz(char maze[10][10], const char name[], int *h, int *l);
int progredir(char maze[10][10], int h, int l);

#endif
