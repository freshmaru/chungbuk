#include<stdio.h>
#include<stdlib.h>

void main()
{
    printf("-----Kitak Oh   2017038035-----\n\n");

    int **x;        //**x 선언

    printf("sizeof(x) = %lu\n", sizeof(x));         //x의 크기 출력
    printf("sizeof(*x) = %lu\n", sizeof(*x));       //*x의 크기 출력
    printf("sizeof(**x) = %lu\n", sizeof(**x));     //*x의 정수형 크기 출력
}