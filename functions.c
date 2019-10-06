#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <functions.h>


pgm* read_and_create_regular_pgm(char* type){
    pgm *aux = calloc(1, sizeof(aux));

    strcpy(aux->type, type);
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


void print_compressed_pgm_by_regular_pgm(pgm* image){
    pos* position = calloc(1, sizeof(pos));
    
    printf("P8\n");
    printf("%d %d\n", image->x, image->y);
    printf("%d\n", image->range);

    for(int i = 0; i < image->y; i++){
        position->pointed = image->matrix[i];
        position->start_pos = 0;
        position->counter = 0;

        while((position->start_pos + position->counter < (image->x))){
            if(*position->pointed == image->matrix[i][position->start_pos + position->counter]){
                position->counter++;

                if(position->start_pos + position->counter == (image->x)){
                    if(position->counter>3){
                        printf("@ %d %d ", *position->pointed, position->counter);
                    }

                    else{
                        for (int k = 0; k < position->counter; k++){
                        printf("%d ", *position->pointed);
                        }
                    }
                }
            }

            else{
                if(position->counter>3){
                    printf("@ %d %d ", *position->pointed, position->counter);
                }

                else{
                    for (int k = 0; k < position->counter; k++){
                        printf("%d ", *position->pointed);
                    }
                }

                position->pointed = &(image->matrix[i][position->start_pos + position->counter]);
                position->start_pos = position->start_pos + position->counter;
                position->counter = 0; 
            }
        }
        printf("\n");
    }
}

void print_regular_pgm_by_compressed_pgm(){
    printf("P2\n");
    int x,y,range;
    scanf("%d %d ", &x, &y);
    scanf("%d ", &range);

    printf("%d %d\n",x, y);
    printf("%d\n",range);

    for(int i = 0; i < y; i++){
        char atOrNumber [10];
        char number [10];
        int repeated_times;

        for(int j = 0; j < x; j++){
            scanf("%s", atOrNumber);
                if(atOrNumber[0] == '@'){
                    scanf("%s", number);
                    scanf("%d", &repeated_times);
                    for(int k = 0; k < repeated_times; k++){
                        printf("%s ", number);
                    }
                    j = j + repeated_times -1;
                }

                else printf("%s ", atOrNumber);            
        }   
        printf("\n");
    }

}