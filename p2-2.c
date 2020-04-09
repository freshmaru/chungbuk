#include<stdio.h>

void print1(int *ptr, int rows);

int main()
{
    printf("-----Kitak Oh   2017038035-----\n\n");

    int one[]={0, 1, 2, 3, 4};

    printf("one     =%p\n", one);           //one의 주소를 출력
    printf("&one    =%p\n", &one);          //one의 주소를 출력
    printf("&one[0] =%p\n", &one[0]);       //one[0]의 주소를 출력
    printf("\n");

    printf(&one[0], 5);

    return 0;
}

void print1(int *ptr, int rows)         //one의 주소와 값을 출력하는 함수 정의
{
    int i;
    printf("Address \t Contents\n");
    for(i=0; i<rows; i++){
        printf("%p \t %5d", ptr + i, *(ptr + 1));
        printf("\n");
    }
}