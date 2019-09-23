#include<stdio.h>
#include<functions.h>
#include<stdlib.h>

int main (){
    pgm* image = read_and_create_regular_pgm();
    //print_regular_pgm(image);
    
    pos* position = calloc(1, sizeof(pos));
    for(int i = 0; i < image->y; i++){
        position->pointed = image->matrix[i];
        printf("p/ i = %d temos %d\n",i, *position->pointed);

        /*
        for(int j = 0; j < image->x; j++){
            
        }
        */
    }
}