#include<stdio.h>
#include <stdlib.h>

void main()
{
    printf("-----Kitak Oh   2017038035-----\n\n");
    
    int list[5];                    //크기가 5인 배열을 선언
    int *plist[5] = {NULL, };       //5개의 포인터를 가진 배열을 선언
    
    plist[0]=(int *)malloc(sizeof(int));    //int의 크기만큼 메모리 할당

    list[0]=1;
    list[1]=100;

    *plist[0]=200;

    printf("value of list[0]          =%d\n", list[0]);       //list[0]의 값을 출력
    printf("address of list[0]        =%p\n", &list[0]);      //list[0]의 주소를 출력
    printf("value of list             =%p\n", list);          //list의 값을 출력
    printf("address of list(&list)    =%p\n", &list);         //list의 주소를 출력

    printf("---------------------------------------------\n\n");

    printf("value of list[1]        =%d\n", list[1]);          //list[0]의 값을 출력
    printf("address of list[1]      =%p\n", &list[1]);         //list[0]의 주소를 출력
    printf("value of list *(list+1) =%d\n", *(list + 1));      //list + 1의 값을 출력
    printf("address of list*1       =%p\n", list+1);           //list의 주소를 출력

    printf("---------------------------------------------\n\n");

    printf("value of *plist[0] =%d\n", *plist[0]);      //*plist[0]의 값을 출력
    printf("&plist[0]          =%p\n", &plist[0]);      //plist[0]의 주소를 출력
    printf("&plist             =%p\n", &plist);         //plist의 주소를 출력
    printf("plist              =%p\n", plist);          //plist의 값을 출력

    printf("plist[0]           =%p\n", plist[0]);         //plist[0], [1], [2], [3], [4], [5]의 주소를 출력
    printf("plist[1]           =%p\n", plist[1]);             
    printf("plist[2]           =%p\n", plist[2]);             
    printf("plist[3]           =%p\n", plist[3]);             
    printf("plist[4]           =%p\n", plist[4]);                

    free(plist[0]);     //free함수를 이용하여 메모리 해제
}