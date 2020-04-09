#include<stdio.h>
#include<stdlib.h>

void main()
{
    printf("-----Kitak Oh   2017038035-----\n\n");

    int list[5];         //크기가 5인 배열을 선언
    int *plist[5];       //5개의 포인터를 가진 배열을 선언

    list[0]=10;
    list[1]=11;

    plist[0]=(int*)malloc(sizeof(int));         //int의 크기만큼 메모리 할당

    printf("list[0]             \t= %d\n", list[0]);        //list[0]의 값을 출력
    printf("address of list     \t= %p\n", list);           //list의 주소를 출력
    printf("address of list[0]  \t= %p\n", &list[0]);       //list[0]의 주소를 출력
    printf("address of list + 0 \t= %p\n", list+0);         //list+0의 주소를 출력
    printf("address of list + 1 \t= %p\n", list+1);         //list+1의 주소를 출력
    printf("address of list + 2 \t= %p\n", list+2);         //list+2의 주소를 출력
    printf("address of list + 3 \t= %p\n", list+3);         //list+3의 주소를 출력
    printf("address of list + 4 \t= %p\n", list+4);         //list+4의 주소를 출력
    printf("address of list[4]  \t= %p\n", &list[4]);       //list[4]의 주소를 출력

    free(plist[0]);     //free함수를 이용하여 메모리 해제
}