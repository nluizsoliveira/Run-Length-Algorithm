#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <functions.h>


pgm* read_and_create_regular_pgm(){
    pgm *aux = calloc(1, sizeof(aux));

    scanf("%s ", aux->type);
    scanf("%d %d ", &aux->x, &aux->y);
    scanf("%d ", &aux->range);

    aux->matrix = calloc(aux->y, sizeof(int*));

    for(int i = 0; i < aux->y; i++){
        aux->matrix[i] = calloc(aux->x, sizeof(int));
    }

    for(int i = 0; i < aux->y; i++){
        for(int j = 0; j < aux->x; j++){
            scanf("%d ", &(aux->matrix[i][j]));
        }
    }
    return aux; 
}

void print_regular_pgm(pgm* aux){
    printf("%s\n%d %d\n%d\n", aux->type, aux->x, aux->y, aux->range);
    for(int i = 0; i < aux->y; i++){
        for(int j = 0; j < aux->x; j++){
            scanf("%d ", &(aux->matrix[i][j]));
            printf("%d ", aux->matrix[i][j]);
        }
        printf("\n");
    }
}