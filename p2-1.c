#include<stdio.h>

#define MAX_SIZE 100                //MAX_SIZE를 100으로 정의
float sum(float list[], int);
float input[MAX_SIZE], answer;
int i;

void main(void)
{
    printf("-----Kitak Oh   2017038035-----\n\n");

    for(i=0; i<MAX_SIZE; i++)
        input[i]=i;

        printf("address of input = %p\n", input);   //input의 주소를 출력

        answer=sum(input, MAX_SIZE);
        printf("The sum is : %f\n", answer);        //list의 합을 출력
}

float sum(float list[], int n)          //값을 합하는 함수를 정의
{
    int i;
    float tempsum=0;
    for(i-0; i<n; i++)
        tempsum+=list[i];
        return tempsum;
}