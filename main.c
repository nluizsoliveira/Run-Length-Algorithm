#include<stdio.h>
#include<functions.h>
#include<stdlib.h>

int main (){
    pgm* image = read_and_create_regular_pgm();
    print_regular_pgm(image);
    
    pos* position = calloc(1, sizeof(pos));
    for(int i = 0; i < image->y; i++){
        position->pointed = image->matrix[i];
        position->start_pos = 0;
        position->counter = 0; 
        printf("p/ i = %d temos %d\n",i, *(position->pointed));

        int contador = 0;
        while(((position->start_pos) + (position->counter)) < ((image->x) - 1)){
            if(image->matrix[i][position->counter + position->start_pos + 1] == *(position->pointed)){
                printf("Tenho um %d em matrix[%d][%d] igual a %d e na posição posterior em  matrix[%d][%d]\n",*(position->pointed), i, position->counter + position->start_pos,image->matrix[i][position->counter + position->start_pos + 1], i, position->counter + position->start_pos + 1);
                position->counter++;
            }

            else{
                if(position->counter>3){
                    printf("Tenho %d %d em seguidos a partir de matrix[%d][%d]", position->counter, *(position->pointed), i, position->start_pos);
                }
                position->pointed  = position->pointed + position->counter; 
                position->start_pos = position->start_pos + position->counter;
            }
            
        } 
        printf("Saí do while. position->start_pos = %d conteudo de Position->pointed = %d, position->counter= %d",position->start_pos, *(position->pointed), position->counter );
        
    }
    
}
