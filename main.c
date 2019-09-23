#include<stdio.h>
#include<functions.h>

int main (){
    pgm* image = read_and_create_regular_pgm();
    print_regular_pgm(image);
}