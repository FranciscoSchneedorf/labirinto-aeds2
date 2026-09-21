# Saída do Labirinto

Trabalho Prático 1 da disciplina **DCE792 — Algoritmos e Estruturas de Dados II**, do curso de Bacharelado em Ciência da Computação da Universidade Federal de Alfenas (UNIFAL-MG).

## Integrantes

- Francisco Schneedorf Leite Ferreira
- Maick Carvalho

## Descrição

O projeto implementa, em linguagem C, um algoritmo para encontrar um caminho entre a entrada e a saída de um labirinto de tamanho `10 × 10`.

No arquivo que representa o labirinto, são utilizados os seguintes caracteres:

- `E`: entrada do labirinto;
- `S`: saída do labirinto;
- `X`: parede;
- `0`: posição livre.

O programa lê o labirinto a partir de um arquivo de texto, localiza a entrada e procura recursivamente um caminho até a saída. Ao encontrar a saída, as coordenadas que compõem o caminho são apresentadas na ordem correta, da entrada até a saída.

## Estrutura do projeto

```text
labirinto/
├── maze.c
├── Makefile
├── README.md
└── instancias/
    └── labirinto1.txt
```

- `maze.c`: código-fonte do programa;
- `Makefile`: arquivo responsável pela automatização da compilação;
- `README.md`: documentação do projeto;
- `instancias/`: diretório contendo os labirintos utilizados nos testes.

## Estruturas de dados

As coordenadas das posições do caminho são armazenadas na estrutura `Pos`:

```c
typedef struct {
    int h;
    int l;
} Pos;
```

O campo `h` representa a linha da posição, enquanto o campo `l` representa a coluna.

O caminho encontrado é armazenado no vetor:

```c
Pos route[100];
```

Como o labirinto possui `10 × 10` posições, o caminho pode conter, no máximo, 100 coordenadas.

## Algoritmo

A busca pelo caminho é realizada pela função recursiva `progredir`. A partir da posição atual, a função procura continuar o caminho nas seguintes direções:

1. Cima;
2. Direita;
3. Baixo;
4. Esquerda.

Cada posição visitada é marcada com o caractere `1`, impedindo que o algoritmo visite repetidamente a mesma posição.

Quando uma tentativa não conduz à saída, a execução retorna à posição anterior e testa outra direção. Essa estratégia é conhecida como **backtracking**, implementada por meio de uma busca em profundidade.

Quando a saída é encontrada, as posições pertencentes ao caminho são armazenadas durante o retorno das chamadas recursivas. Posteriormente, o vetor é percorrido na ordem inversa para apresentar o caminho da entrada até a saída.

## Formato das instâncias

Cada instância deve ser armazenada em um arquivo de texto contendo exatamente 10 linhas e 10 caracteres válidos por linha.

Exemplo:

```text
EXXXXXXXXX
000XXXXXXX
X000XXXXXX
XXX000XXXX
XXXXX00XXX
XXXXXX0XXX
XXXXXX00XX
XXXXXXX0XX
XXXXXXX000
XXXXXXXXXS
```

Cada labirinto deve possuir uma entrada representada por `E` e uma saída representada por `S`.

## Makefile

O projeto utiliza um arquivo `Makefile` para automatizar a compilação, a execução e a remoção do executável.

O compilador definido é o GCC, com as seguintes opções:

- `-Wall`: habilita os principais avisos do compilador;
- `-Wextra`: habilita avisos adicionais;
- `-std=c11`: utiliza o padrão C11 da linguagem C.

O arquivo `Makefile` contém as seguintes regras:

- `all`: compila o código e gera o executável `maze`;
- `run`: compila o programa, se necessário, e executa-o;
- `clean`: remove o executável gerado.

## Requisitos

Para compilar o projeto, é necessário possuir:

- Compilador GCC;
- GNU Make;
- Terminal ou prompt de comandos.

## Compilação

Abra o terminal no diretório do projeto e execute:

```bash
make
```

Esse comando compila o arquivo `maze.c` e gera o executável chamado `maze`.

A compilação realizada pelo Makefile equivale ao seguinte comando:

```bash
gcc -Wall -Wextra -std=c11 maze.c -o maze
```

## Execução

Para compilar e executar o programa, utilize:

```bash
make run
```

Também é possível executar diretamente o programa após a compilação.

No Linux:

```bash
./maze
```

No Windows:

```powershell
.\maze.exe
```

Durante a execução, o programa solicitará o nome do arquivo que contém o labirinto. Deve-se informar o caminho completo ou relativo para a instância, incluindo a extensão `.txt`.

Exemplo:

```text
instancias/labirinto1.txt
```

## Limpeza dos arquivos de compilação

Para remover o executável gerado, utilize:

```bash
make clean
```

## Compilação no Windows com MinGW

Algumas instalações do MinGW disponibilizam o comando `mingw32-make` no lugar de `make`.

Nesse caso, utilize:

```powershell
mingw32-make
```

Para compilar e executar:

```powershell
mingw32-make run
```

Para remover o executável:

```powershell
mingw32-make clean
```

## Saída

O caminho encontrado é apresentado por meio das coordenadas de cada posição, da entrada até a saída.

Cada coordenada possui o formato:

```text
linha,coluna
```

Exemplo:

```text
0,4
0,3
1,3
2,3
2,2
3,2
4,2
```

## Complexidade

No pior caso, o algoritmo pode visitar todas as posições do labirinto.

Para um labirinto com `L` linhas e `C` colunas, a complexidade de tempo é:

```text
O(L × C)
```

Como o labirinto deste projeto possui tamanho fixo de `10 × 10`, podem ser visitadas até 100 posições.

A complexidade de espaço também é `O(L × C)`, considerando o vetor utilizado para armazenar o caminho e a pilha de chamadas recursivas.