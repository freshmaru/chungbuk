#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
    -initialize와 왜 다른지 이해 할것
    -이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	printf("-----Kitak Oh   2017038035-----\n\n");
	
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
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
			initialize(&headnode);
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


int initialize(headNode** h) {
    
	if(*h != NULL)			//headNode가 NULL이 아니면 freeList를 호출하여 초기화한다
		freeList(*h);
	headNode* temp = (headNode*)malloc(sizeof(headNode));	//headNode에 다시 메모리를 할당하여 반환
	temp->first = NULL;
    *h = temp;
	return 1;
}

int freeList(headNode* h){
    // h와 연결된 listNode메모리 해제
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->rlink;
		free(prev);
	}
	free(h);		//headNode메모리 해제
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
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list에 key에 대한 노드 하나를 추가
 */
int insertLast(headNode* h, int key) {
    listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->rlink = NULL;
    node->llink = NULL;

	if (h->first == NULL)	//h에 노드가 없는 경우
	{
		h->first = node;
		return 0;
	}

	listNode* n = h->first;
	while(n->rlink != NULL)		//노드의 끝단까지 이동하여 노드 추가
    {
		n = n->rlink;
	}
    n->rlink = node;
	node->llink = n;
    node->rlink = NULL;			//노드의 오른쪽에 아무것도 없으니 NULL을 가리키게 한다
	return 0;
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {

    if (h->first == NULL)			//삭제할 노드가 없는 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}

    listNode* p = h->first;
	listNode* prev = NULL;
    
    while(p->rlink != NULL)		//다음노드가 NULL이 아닐 경우
	{
		prev = p;
		p = p->rlink;
	}
	if(h->first == p)		//list의 마지막 노드가 first일때 초기화
	{
		h->first = NULL;
	}
	else					//마지막 노드 삭제
	{
		prev->rlink = NULL;
	}
    free(p);

	return 0;
}



/**
 * list 처음에 key에 대한 노드 하나를 추가
 */
int insertFirst(headNode* h, int key) {

    listNode* node = (listNode*)malloc(sizeof(listNode));
    listNode* n = h->first;
	node->key = key;
    if(h->first == NULL)		//입력된 노드가 없는 경우
    {
        h->first = node;
        node->llink = NULL;
        node->rlink = NULL;
        return 0;
    }

	node->rlink = h->first;		//노드가 존재할시
	h->first = node;
    n->llink = node;
	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

    if (h->first == NULL)		//입력된 노드가 없는 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first;

    if(n->rlink == NULL)		//노드가 한개만 있을시 초기화 후 할당된 메모리를 풀어준다
    {
        h->first = NULL;
        free(n);
        return 0;
    }
	h->first = n->rlink;
	free(n);

	return 0;
}



/**
 * 리스트의 링크를 역순으로 재배치
 */
int invertList(headNode* h) {
    listNode*  reversed = NULL;
	listNode* current = h->first;
	listNode* temp = NULL;
	while(current != NULL)
	{
		temp = current;					//temp는 current를 따라간다
		current = current->rlink;		//current 자신의 뒷노드로 이동한다
		temp->rlink = reversed;			//temp는 reversed를 가리킨다
        temp->llink = current;			//llink는 current를 가리킨다(singly-linked-list와의 차이점)
		reversed = temp;				//reversed는 temp를 따라간다
	}
	h->first = reversed;				//시행이 완료되었을 때 null값을 가진 를 reversed가 가르키므로 첫번째 값을 넣어서 완성해준다 

	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
    listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->llink = NULL;			//왼쪽과 오른쪽 링크를 초기화한다
    node->rlink = NULL;

	if (h->first == NULL)		//노드가 하나도 없는 경우 h->first는 node를 가리킨다
	{
		h->first = node;
        node->rlink = NULL;
		return 0;
	}

	listNode* n = h->first;
	listNode* prev = h->first;

	while(n != NULL) {
		if(n->key >= key) {
			if(n == h->first) 			//입력된 노드가 한 개일 경우
			{
				h->first = node;
				node->rlink = h->first;
                n->llink = node;
			} 
            else 						//그 외의 경우
            	{ 
					node->rlink = n;
					prev->rlink = node;
                	node->llink = prev;
				}
			return 0;
		}

		prev = n;
		n = n->rlink;
	}

	prev->rlink = node;
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
    if (h->first == NULL)		//노드가 하나도 없는 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first;
	listNode* prev = NULL;

	while(n != NULL) {				//노드가 존재할 경우
		if(n->key == key) {

			if(n == h->first) {			//입력된 노드가 한개일 경우
				h->first = n->rlink;
			} 
            else						//그 외의 경우 
            {	
				prev->rlink = n->rlink;
			}
			free(n);
			return 0;
		}

		prev = n;
		n = n->rlink;
	}

	printf("cannot find the node for key = %d\n", key);
	return 1;
}

