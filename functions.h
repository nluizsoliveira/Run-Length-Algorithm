#ifndef _functions_	// diretiva de compilacao
#define _functions_	// diretiva de compilacao

typedef struct {
    char type [2]; //Tipo do pgm (P1, P2, ... P8)
    int x;         //Numero de colunas da imagem
    int y;         //Numero de linhas da imagem 
    int range;     //Escala que define as tonalidades da imagem
    int ** matrix; //Matriz com os pixels da imagem de fato 
}pgm;

typedef struct {
    int* pointed;
    int start_pos;
    int counter;
} pos;

pgm* read_and_create_regular_pgm();
void print_regular_pgm(pgm*);
#endif
