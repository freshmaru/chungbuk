#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* link;      // 노드. 자기자신을 가지는 링크와 키를 가짐
} listNode;

typedef struct Head {
	struct Node* first;     // 헤더 노드의 first가 노드를 가리키게 되어 있음
}headNode;



/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	printf("-----Kitak Oh   2017038035-----\n\n");

	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h와 연결된 listNode메모리 해제
	 * headNode메모리도 해제되어야 함.*/
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}


/**
 * list 처음에 key에 대한 노드 하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;				//node에 key값 입력

	node->link = h->first;
	h->first = node;

	return 0;
}


/* 리스트를 검색하여 입력받은 key보다 큰 값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	listNode* p = h->first;
	listNode* prev = NULL;
	if(h->first !=NULL && p->key > key)		//first가 key값보다 큰 경우
		{
			newNode->key = key;
			newNode->link = h->first;
			h->first = newNode;
		}
	else
		while(p!=NULL) 						//key값보다 큰값이 나오는 노드 앞에 삽입
		{
			if(p->key > key)
			{
				newNode->key = key;
				newNode->link = prev->link;
				prev->link = newNode;
				return 0;
			}
			prev = p;
			p = p->link;
		}
    	
	return 0;
}

/**
 * list에 key에 대한 노드를 하나 추가
 */
int insertLast(headNode* h, int key) {

    listNode* lastNode = (listNode*)malloc(sizeof(listNode));
	listNode* p = h->first;
	lastNode->key = key;

    while(p->link != NULL) p = p->link;
	p->link = lastNode;
	lastNode->link = NULL;

	return 0;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

    listNode* p = h->first;
   	h->first = p->link;
    free(p);

	return 0;
}


/**
 * list의 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

    listNode* p = h->first;
	listNode* prev = NULL;
	while(p!=NULL) 
	{
		if(key == p->key)			//입력받은 key와 값이 일치할 경우 노드 삭제
		{
			prev->link = p->link;

			break;
		}
		prev = p;
		p = p->link;
	}
    free(p);

	return 0;
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {

    listNode* p = h->first;
	listNode* prev = NULL;
    while(p->link != NULL)	
	{
		prev = p;
		p = p->link;
	}
	if(h->first == p)		//list의 마지막 노드가 first일때 초기화
	{
		h->first = NULL;
	}
	else					//마지막 노드 삭제
	{
		prev->link = NULL;
	}
    free(p);
	return 0;
}


/**
 * 노드의 순서를 역으로
 */
int invertList(headNode* h) {

	listNode*  reversed = NULL;
	listNode* current = h->first;
	listNode* temp = NULL;
	while(current != NULL)
	{
		temp = current;			//temp는 current를 따라간다
		current = current->link;	//currrent 자신의 뒷 노드로 이동한다
		temp->link = reversed;		//temp는 reversed를 가리킨다
		reversed = temp;		//reversed는 temp를 따라간다
	}
	h->first = reversed;	//시행이 완료되었을 때 null값을 가진 를 reversed가 가르키므로 첫번째 값을 넣어서 완성해준다 

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}
