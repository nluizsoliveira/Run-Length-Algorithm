#ifndef _functions_	// diretiva de compilacao
#define _functions_	// diretiva de compilacao

typedef struct 
{
    char type [2];
    int x;
    int y;
    int range; 
    int ** matrix;
} pgm;

pgm* read_and_create_regular_pgm();
void print_regular_pgm(pgm*);
#endif
