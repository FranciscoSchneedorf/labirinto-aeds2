#include <stdio.h>

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

void escreverlab(char maze[10][10]){
    printf("\n");
    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
}

typedef struct {
    int h, l;
} Pos;

Pos route[100];
int tam=0;

int progredir(char maze[10][10], int h, int l)
{
    if (maze[h][l] == 'S')
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }
    if (maze[h][l] != '0' && maze[h][l] != 'E')
    {
        return 0;
    }

    maze[h][l] = '1';

    if (h>0 && (progredir(maze, h - 1, l))) // Cima
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }

    if (l<9 && (progredir(maze, h, l + 1))) // Direita
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }

    if (h<9 && (progredir(maze, h + 1, l))) // Baixo
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }

    if (l>0 && (progredir(maze, h, l - 1))) // Esquerda
    {
        route[tam++] = (Pos){h, l};
        return 1;
    }

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

    escreverlab(maze);

    if (progredir(maze, h, l)){
        printf("\nLabirinto Concluido!");
        for (int i=tam; i>=0;i--){
            printf("\n%d, %d",route[i].h, route[i].l);
        }
        printf("\n");
    };
}