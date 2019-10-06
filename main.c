#include<stdio.h>
#include<functions.h>
#include<stdlib.h>
#include<string.h>

int main (){
    char type[2];
    scanf("%s ", type);

    if(!strcmp("P8", type)){
        //é p8
        print_regular_pgm_by_compressed_pgm();
    }

    else{
        //não é p8
        pgm* image = read_and_create_regular_pgm(type);
        print_compressed_pgm_by_regular_pgm(image);

    }


    //print_regular_pgm(image);
    
    
}
