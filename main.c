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

        //printf("Entrei em um i novo. Estou em matrix[%d][%d] position->start_pos = %d conteudo de Position->pointed = %d, position->counter= %d\n",i, ((position->start_pos) + (position->counter)) ,position->start_pos, *(position->pointed), position->counter );

        //printf("p/ i = %d temos %d\n",i, *(position->pointed));

        while(((position->start_pos) + (position->counter)) < ((image->x))){
            //if(i == 1) printf("Dentro do While, position aponta para matrix[%d][%d] = , e o proximo eh matrix[%d][%d] = %d\n",i,((position->start_pos)+position->counter),i,position->counter + position->start_pos + 1,image->matrix[i][position->counter + position->start_pos + 1]);

            if((image->matrix[i][position->counter + position->start_pos + 1] == *(position->pointed))){
                //printf("Counter = %d. Tenho um %d em matrix[%d][%d] igual a %d e na posição posterior em  matrix[%d][%d]\n",position->counter,*(position->pointed), i, position->counter + position->start_pos,image->matrix[i][position->counter + position->start_pos + 1], i, position->counter + position->start_pos + 1);
                position->counter++;

                if(position->counter +1 == image->x){
                   printf("@ %d %d ", *(position->pointed),position->counter+1);
                }
            }

            else{
                if(position->counter>3){
                    printf("@ %d %d ", *(position->pointed),position->counter);
                    //printf("Tenho %d %d em seguidos a partir de matrix[%d][%d]\n", position->counter, *(position->pointed), i, position->start_pos);
                }
                position->counter++;
                position->pointed  = position->pointed + position->counter; 
                position->start_pos = position->start_pos + position->counter;
            }
            
        } 
        printf("\n");
        //printf("Saí do while. Estou em matrix[%d][%d] position->start_pos = %d conteudo de Position->pointed = %d, position->counter= %d\n",i, ((position->start_pos) + (position->counter)) ,position->start_pos, *(position->pointed), position->counter );

    }
    
}
