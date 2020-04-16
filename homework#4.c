#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int** create_matrix(int row, int col)
{
    int **matrix = malloc(sizeof(int*)*row);        //2차원 배열의 세로 공간 할당

    for(int i = 0; i < row; i++)
    {
        matrix[i] = malloc(sizeof(int)*col);        //2차원 배열의 가로 공간 할당
    }
    if(row <= 0 || col <=0) 
    {
        printf("Check the sizes of row and col!\n");    
        return NULL;
    }
// check post conditions 
    if(matrix == NULL) 
    {
        printf("error");    // proper actions for unexpected conditions 
    }
    return matrix;
}

/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);         // 2차원 배열의 가로 공간 메모리 해제
    }
    free(matrix);                // 2차원 배열의 세로 공간 메모리 해제
    return 0;
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);      //배열을 출력한다
        }
        printf("\n");    
    }
    printf("\n\n");
}

/* assign random values to the given matrix */
int fill_data(int **matrix, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            matrix[i][j] = rand()%20;   //0 ∼ 19 사이의 값을 갖는 랜덤값 저장
        }
    }
    /* check post conditions */
    if(matrix == NULL) 
    {
/* proper actions for unexpected conditions */
        printf("error");
    }
    return **matrix;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int **matrix, int **matrix_t, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
                matrix_t[j][i] = matrix[i][j];      //행과 열을 교환하여 얻은 값을 할당
        }
    }
    /* check post conditions */
    if(matrix_t == NULL) 
    {
    /* proper actions for unexpected conditions */
        printf("error");
    }
    return **matrix_t;
}

int addition_matrix(int **matrix_a, int **matrix_b, int**matrix_sum, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
                matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];     //matrix_a + matrix_b의 값을 할당
        }
    }
    /* check post conditions */
    if(matrix_sum == NULL) 
    {
/* proper actions for unexpected conditions */
        printf("error");
    }
    return **matrix_sum;
}

int subtraction_matrix(int **matrix_a, int **matrix_b, int**matrix_sub, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
                matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];     //matrix_a - matrix_b의 값을 할당
        }
    }
    /* check post conditions */
    if(matrix_sub == NULL) 
    {
/* proper actions for unexpected conditions */
        printf("error");
    }
    return **matrix_sub;
}

/* matrix_axt = matrix_a x matrix_t */
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)    
        {
                matrix_axt[i][j] = matrix_a[i][j] * matrix_t[i][j];     //matrix_a * matrix_t의 값을 할당
        }
    }
    /* check post conditions */
    if(matrix_axt == NULL) 
    {
/* proper actions for unexpected conditions */
        printf("error");
    }
    return **matrix_axt;
}

int main()
{
    printf("-----Kitak Oh   2017038035-----\n\n");

    int row;
    int col;
    printf("enter row :  ");
    scanf("%d", &row);
    printf("enter column : ");
    scanf("%d", &col);
    
    //create_matrix 함수 이용하여 배열 생성
    int** matrix_a = create_matrix(row, col);       
    int** matrix_b = create_matrix(row, col);
    int** matrix_t = create_matrix(row, col);
    int** matrix_sum = create_matrix(row, col);
    int** matrix_sub = create_matrix(row, col);
    int** matrix_axt = create_matrix(row, col);

    //배열의 값 할당
    fill_data(matrix_a, row, col);
    fill_data(matrix_b, row, col);
    transpose_matrix(matrix_a, matrix_t, row, col);
    addition_matrix(matrix_a, matrix_b, matrix_sum, row, col);
    subtraction_matrix(matrix_a, matrix_b, matrix_sub, row, col);
    multiply_matrix(matrix_a, matrix_t, matrix_axt, row, col);

    srand(time(NULL));              //srand함수 이용하여 난수 초기화
    printf("\n\nmatrix_a\n");
    print_matrix(matrix_a, row, col);

    srand(time(NULL));               //srand함수 이용하여 난수 초기화
    printf("matrix_b\n");
    print_matrix(matrix_b, row, col);

    printf("matrix_t\n");       
    print_matrix(matrix_t, row, col);
    printf("matrix_sum\n");
    print_matrix(matrix_sum, row, col);
    printf("matrix_sub\n");
    print_matrix(matrix_sub, row, col);
    printf("matrix_axt\n");
    print_matrix(matrix_axt, row, col);

    //free_matrix 함수 이용하여 할당된 메모리 해제
    free_matrix(matrix_a, row, col);
    free_matrix(matrix_b, row, col);
    free_matrix(matrix_t, row, col);
    free_matrix(matrix_sum, row, col);
    free_matrix(matrix_sub, row, col);
    free_matrix(matrix_axt, row, col);

    return 0;
}

