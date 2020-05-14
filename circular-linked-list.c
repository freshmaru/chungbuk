
#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더 파일 추가 */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

/* 함수 리스트 */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);



int main()
{

	printf("-----Kitak Oh   2017038035-----\n\n");

	char command;
	int key;
	listNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
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


int initialize(listNode** h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL)
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}

/* 메모리 해제 */
int freeList(listNode* h){
// h와 연결된 listNode메모리 해제
	listNode* p = h->rlink;

	listNode* prev = NULL;
	while(p != h) {
		prev = p;
		p = p->rlink;
		free(prev);
	}
	free(h);		//headNode메모리 해제
	return 0;
}



void printList(listNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}
}


/**
 * list에 key에 대한 노드 하나를 추가
 */
int insertLast(listNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
	listNode* n = h->rlink;
	node->key = key;
	if(h->rlink==h)			//h에 노드가 없는 경우
	{
		node->rlink = h;
		node->llink = h;
		h->rlink = node;
		h->llink = node;
		return 0;
	}
	while(n->rlink!=h)		//노드의 끝단까지 이동하여 노드를 추가
	{
		n = n->rlink;
	}

	n->rlink = node;
	node->llink = n;
	h->llink = node;
	node->rlink = h;

	return 1;
}


/**
 * list의 마지막 노드 삭제
 */
int deleteLast(listNode* h) {

	if (h->rlink == h)			//삭제할 노드가 없는 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}

    listNode* p = h->rlink;
	listNode* prev = NULL;
    
	if(h->rlink == h)		//list의 마지막 노드가 first일때 초기화
	{
		h->rlink = h;
		free(p);
		return 0;
	}

    while(p->rlink != h)		//다음노드가 NULL이 아닐 경우
	{
		prev = p;
		p = p->rlink;
	}

	prev->rlink = h;				//마지막 노드 삭제
	h->llink=prev;
    free(p);
	return 1;
}


/**
 * list 처음에 key에 대한 노드 하나를 추가
 */
int insertFirst(listNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
    listNode* n = h->rlink;
	node->key = key;
    if(h->rlink == NULL)		//입력된 노드가 없는 경우
    {
        h->rlink = node;
        node->llink = h;
        node->rlink = h;
		h->llink = node;
        return 0;
    }				

	node->rlink = h->rlink;		//노드가 존재할시
	h->rlink = node;
	n->llink = node;
	node -> llink = h;

	return 1;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(listNode* h) {
	if (h->rlink == NULL)		//입력된 노드가 없는 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->rlink;

	h->rlink = n->rlink;		//노드가 존재하는 경우
	(n->rlink)->llink = h;

	free(n);

	return 1;
}


/**
 * 리스트의 링크를 역순으로 재배치
 */
int invertList(listNode* h) {

	if(h->rlink == h) {
		printf("nothing to invert...\n");
		return 0;
	}
	listNode*  reversed = NULL;
	listNode* current = h->rlink;
	listNode* temp = NULL;
	while(current != h)
	{
		temp = current;					//temp는 current를 따라간다
		current = current->rlink;		//current 자신의 뒷노드로 이동한다
		temp->rlink = temp->llink;		//temp는 reversed를 가리킨다
        temp->llink = current;			//llink는 current를 가리킨다
	}
	current->llink = current->rlink;		//헤드 노드 값 설정
	current->rlink = temp;

	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(listNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	node->llink = node->rlink = NULL;

	if (h->rlink == h)				//헤드 노드만 존재하는 경우
	{
		h->rlink = node;
        node->llink = h;
        node->rlink = h;
		h->llink = node;
        return 0;
	}

	listNode* n = h->rlink;

	while(n != h) {
		if(n->key >= key) {
			if(n == h->rlink) {					//헤드 노드만 존재하는 경우
				insertFirst(h, key);
			} else { 							//그 외의 경우
				node->rlink = n;
				node->llink = n->llink;
				n->llink->rlink = node;
				n->llink = node;
			}
			return 0;
		}

		n = n->rlink;
	}

	insertLast(h, key);					//마지막 노드까지 이동했을 때 삽입
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(listNode* h, int key) {

	if (h->rlink == NULL)				//삭제할 노드가 존재하지 않는 경우
	{
		printf("nothing to delete.\n");
		return 1;
	}

	listNode* n = h->rlink;

	while(n != NULL) {					
		if(n->key == key) {
			if(n == h->rlink) { 				//처음 검색된 노드를 삭제할 경우
				deleteFirst(h);
			} else if (n->rlink == NULL){ 		//마지막 노드를 삭제할 경우
				deleteLast(h);
			} else { 							//그 외의 경우
				n->llink->rlink = n->rlink;
				n->rlink->llink = n->llink;
				free(n);
			}
			return 1;
		}

		n = n->rlink;
	}

	printf("cannot find the node for key = %d\n", key);
	return 1;
}

