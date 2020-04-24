#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();

int freeQueue(QueueType *cQ)        //할당된 메모리 해제
{
    if(cQ == NULL)
        free(cQ);
    return 1;
}

int main(void)
{
	QueueType *cQ = createQueue();
	element data;

	char command;

    printf("-----Kitak Oh   2017038035-----\n\n");

	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
            freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}


QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)      //front와 rear가 같으면 queue는 비어있는 상태
{
     if (cQ->front == cQ->rear) 
        return 1;
	else
		return 0;
}

/* complete the function */
int isFull(QueueType *cQ)       //queue는 가득 차 있는 상태
{
    if((cQ->rear+1%MAX_QUEUE_SIZE)==cQ->front)
        return 1;
    else
   		return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)       //queue 입력
{
    if(isFull(cQ)==1)
		printf("Queue is full.\n");             //queue가 차 있을시 "queue is full" 출력
	else
        cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE;
        cQ->queue[cQ->rear]=item;
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)      //queue 삭제
{
    if(isEmpty(cQ)==1)
		printf("Queue is empty.\n");            //queue가 비어 있을시 "queue is emty" 출력
	else
		cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE;
		cQ->queue[cQ->front] = *item;
}


void printQ(QueueType *cQ)      //queue 출력
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}