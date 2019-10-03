#include<stdio.h>
#include<functions.h>
#include<stdlib.h>

int main (){

    pgm* image = read_and_create_regular_pgm();
    //print_regular_pgm(image);
    print_compressed_pgm_by_regular_pgm(image);
    
}
