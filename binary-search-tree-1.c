/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{

	printf("-----Kitak Oh   2017038035-----\n\n");

	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)	//중위 순회
{
	if(ptr)
	{
		inorderTraversal(ptr->left);
		printf("%d", ptr->key);
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr)	//전위 순회
{
	if(ptr)
	{
		printf("%d", ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr)		//후위 순회
{
    if(ptr)
	{
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf("%d,", ptr->key);
	}
}


int insert(Node* head, int key)
{
	Node* ptr = (Node*)malloc(sizeof(Node));
	Node* h = head->left;
	Node* prev = NULL;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->key = key;
	if(head->left == NULL)		//h에 노드가 없는 경우
	{
		head->left = ptr;
		return 0;
	}
	
	while(h!=NULL)				//노드가 존재하는 경우 key값에 따라 위치 이동
	{
		prev = h;
		if(key < h->key)
		{
			h = h->left;
		}
		else
		{
			h = h->right;
		}
	}
		if(key < prev->key)		//노드 추가
		{
			prev->left = ptr;
		}
		else
		{
			prev->right = ptr;
		}

	return 1;
}

int deleteLeafNode(Node* head, int key)
{
	Node* h = head->left;
	Node* prev = NULL;

	if (head->left == NULL)				//삭제할 노드가 존재하지 않는 경우
	{
		printf("nothing to delete.\n");
		return 1;
	}

	while(h!=NULL)
	{
		if(h->key == key) 
		{
			if(h->right == NULL && h->left == NULL)
			{
				if (prev->right == NULL)		//좌측 자식 노드일 경우 초기화
				{
					prev->left =NULL;
				}
				else							//우측 자식 노드일 경우 초기화
				{
					prev->right = NULL;
				}
				free(h);
				return 1;
			}
			else
			{
				printf("delete error");
				return 1;
			}
			
		}
			if(key < h->key)			//key 값에 따라 위치 이동
			{
				prev = h;
				h = h->left;
			}
			else
			{
				prev = h;
				h = h->right;
			}
	}
	
	printf("cannot find the node for key = %d\n", key);
	return 0;
}

Node* searchRecursive(Node* ptr, int key)		
{
	if(!ptr) return NULL;						//노드가 존재하지 않는 경우 
	if(key == ptr->key) return ptr;				//입력한 key값과 같을 경우 반환
	if(key < ptr-> key)							//key값에 따라 위치 이동
		return searchRecursive(ptr->left, key);
	return searchRecursive(ptr->right, key);
}

Node* searchIterative(Node* head, int key)
{
	Node* h = head->left;
	while(h != NULL)					
	{
		if(key == h->key) return h;		//입력한 key값과 같을 경우 반환
		if(key < h->key)				//key값에 따라 위치 이동
			h = h->left;
		else
		{
			h = h->right;
		}
		
	}
	return 0;
}

int freeBST(Node* head)
{
	Node* h = head->left;
	if(h!=NULL)				//head와 연결된 메모리 해제
	{
		freeBST(h->left);
		freeBST(h->right);
		free(h);
	}

	free(head);			//헤더 노드 메모리 해제
	return 0;
}