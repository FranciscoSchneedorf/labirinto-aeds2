#include <stdio.h>
#include <string.h>


int leMatriz(FILE* arch, char maze[10][10])
{
    // Laco para percorrer os elementos da matriz
    for(int i = 0; i < 10; i++){ 
        for(int j = 0; j < 10; j++){
            if((fscanf(arch, " %c", &maze[i][j]) != 1)){ // Le os elementos da matriz controlada por arch e armazena em ordem
                printf("Falha na leitura.");
                return 1; 
            } 
        }
    }
    printf("Leitura realizada com sucesso!");
    return 0;
}


int abreMatriz (char maze[10][10], const char name[]){
    FILE* arch; // Ponteiro que recebera o controle do arquivo aberto
    if((arch = fopen(name, "r")) != NULL) // Verifica se o arquivo foi aberto corretamente
    {
        int result;
        printf("Labirinto aberto com sucesso!\nRealizando a leitura...");
        result = leMatriz(arch, maze); // Chama a funcao para realizar a leitura
        fclose(arch);
        return result;
    } else {
        printf("Nao foi possivel abrir o labirinto. Tente novamente.");
        return 1;
    }
}

int progredir (char maze[10][10], int h, int l){

if (maze[h][l] != '0' && 'E'){
    return 0;
} 
if (maze[h][l] == 'S'){
    return 1;
} 

maze[h][l] = '1';

if (progredir(maze, h-1, l)){
    return 1;
}

if (progredir(maze, h, l+1)){
    return 1;
}

if (progredir(maze, h+1, l)){
    return 1;
}

if (progredir(maze, h, l-1)){
    return 1;
}

}

int main(){
    // Variaveis
    char nome[100];
    char maze[10][10];
    int resultado;
    // Entrada de dados
    printf("Insira o nome do arquivo a ser aberto (inclua .txt):\n");
    scanf("%99s", nome);
    // Chama a funcao e verifica o return
    if((resultado = abreMatriz(maze, nome)) != 0){
        return 1;
    } 
}