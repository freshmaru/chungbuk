#include <stdio.h>

struct student1{        //student1 값을 저장하기 위해 정의
    char lastName;
    int studentId;
    char grade;
};

typedef struct {        //student2 값을 저장하기 위해 정의(키워드 생략)
    char lastName;
    int studentId;
    char grade;
} student2;

int main() {
    printf("-----Kitak Oh   2017038035-----\n\n");

    struct student1 st1={'A', 100, 'A'};                //student1의 정보 입력

    printf("st1.lastName = %c\n", st1.lastName);        //student1의 정보를 출력
    printf("st1.studentId=%d\n", st1.studentId);
    printf("st1.grade=%c\n", st1.grade);

    student2 st2={'B', 200, 'B'};                       //student2의 정보를 입력

    printf("\nst2.lastName=%c\n", st2.lastName);        //student2의 정보를 출력
    printf("st2.studentId=%d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);

    student2 st3;

    st3 = st2;          //student3의 정보를 입력(현재 컴파일러로는 직접적인 대입 가능)

    printf("\nst3.lastName=%c\n", st3.lastName);        //student3의 정보를 출력
    printf("st3.studentId=%d\n", st3.studentId);
    printf("st3.grade=%c\n", st3.grade);

    /*equality test        이대로 진행시 오류가 나며 일일이 비교를 해주어야 함
    if(strcmp(st3 == st2)
        printf("equal\n");
    else
        printf("not equal\n");
    
    return 0;
    */
}