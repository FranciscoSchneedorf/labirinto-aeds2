// AEDs 2 - Labirinto
// Alunos: Maick Carvalho e Francisco Schneedorf

#include <stdio.h>
#include "maze.h"

// Definição das variáveis globais declaradas em maze.h
Pos route[100];
int tam = 0;

int leMatriz(FILE *arch, char maze[10][10], int *linhaEntrada, int *colunaEntrada)
{
    int encontrouEntrada = 0;
    // Laco para percorrer os elementos da matriz
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((fscanf(arch, " %c", &maze[i][j]) == 1)) // Se fscanf obteve sucesso na execucao
            {
                if (maze[i][j] == 'E') // Verifica se o caractere naquela posicao e a entrada
                {
                    *linhaEntrada = i;
                    *colunaEntrada = j;
                    encontrouEntrada = 1;
                }
            }
            else
            {
                printf("Falha na leitura.");
                return 1;
            }
        }
    }
    if (encontrouEntrada == 0) // Caso nao encontre a entrada
    {
        printf("O labirinto nao possui entrada.");
        return 1;
    }
    printf("Leitura realizada com sucesso!");
    return 0;
}

int abreMatriz(char maze[10][10], const char name[], int *h, int *l)
{
    FILE *arch; // Ponteiro que recebera o controle do arquivo aberto
    if ((arch = fopen(name, "r")) != NULL) // Verifica se o arquivo foi aberto corretamente
    {
        int result;
        printf("Labirinto aberto com sucesso!\nRealizando a leitura...");
        result = leMatriz(arch, maze, h, l); // Chama a funcao para realizar a leitura
        fclose(arch);
        return result;
    }
    else
    {
        printf("Nao foi possivel abrir o labirinto. Tente novamente.");
        return 1;
    }
}

//Função que efetivamente percorre o labirinto
int progredir(char maze[10][10], int h, int l)
{
    //Checa se o espaço atual é a saída, se sim, retorna que o labirinto está concluído
    if (maze[h][l] == 'S')
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }

    //Checa se a casa atual é um X, se sim, retorna e busca outro caminho
    if (maze[h][l] != '0' && maze[h][l] != 'E')
    {
        return 0;
    }

    //Definde o espaço atual como 1 != 0 para evitar loop
    maze[h][l] = '1';

    if (h>0 && (progredir(maze, h - 1, l))) // Progride para cima
    {
        //Retroativamente salva a posição visitada no vetor de trajeto
        route[tam++] = (Pos){h, l};
        return 1;
    }

    if (l<9 && (progredir(maze, h, l + 1))) // Progride para a direita
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }

    if (h<9 && (progredir(maze, h + 1, l))) // Progride para baixo
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }

    if (l>0 && (progredir(maze, h, l - 1))) // Progride para a esquerda
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }

    //Retorna para o espaço passado caso nenhuma direção esteja disponível
    return 0;
}

int main(void)
{
    // Variaveis
    char nome[100];
    char maze[10][10];
    int resultado;
    int h, l;
    // Entrada de dados
    printf("Insira o nome do arquivo a ser aberto (inclua .txt):\n");
    scanf("%99s", nome);
    // Chama a funcao e verifica o return
    if ((resultado = abreMatriz(maze, nome, &h, &l)) != 0)
    { // Se for == 0, maze esta preenchida e pronta para ser entregue a funcao progredir
        return 1;
    }

    //Começo do labirinto com as coordenadas de "E" como entrada 
    if (progredir(maze, h, l)){
        printf("\nLabirinto Concluido!");

        //Exibição do trajeto percorrido
        for (int i=tam-1; i>=0;i--){
            printf("\n%d, %d",route[i].h, route[i].l);
        }
        printf("\n");

    }else{
        printf("\n Labirinto sem saída!");
    };
}