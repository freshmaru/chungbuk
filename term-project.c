#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 20 /* you can change value 20 */
#define FALSE 0
#define TRUE 1


typedef struct Vertex {
    int num; /* vertex number */
    struct Vertex* link; /* link to a next adjacent vertext */
} Vertex;

typedef struct VertexHead {
    Vertex* head; /* linked list of all adjacent vertices */
} VertexHead;

typedef struct Graph {
    VertexHead* vlist; /* list of all vertices: vlist[MAX_VERTEX] */
} Graph;


typedef struct queue *queuePointer;
typedef struct queue{
	int vertex;
    queuePointer link;
}queue;
queuePointer front, rear;

int createGraph(Graph** h); /* empty graph creation */
int destroyGraph(Graph* h); /* deallocating all allocated memory */
int insertVertex(Graph* h, int key); /* vertex insertion */
int deleteVertex(Graph* h, int key); /* vertex deletion */
int insertEdge(Graph* h, int v1, int v2); /* new edge creation between two vertices */
int deleteEdge(Graph* h, int v1, int v2); /* edge removal */
int depthFS(Graph* h, int key); /* depth firt search using stack */
int breadthFS(Graph* h, int key); /* breadth first search using queue */
int printGraph(Graph* h); /* printing graph with vertices and edges */

short int visited[MAX_VERTEX];  //방문한 배열은 True가 된다
int queueEmpty();   //큐가 비었는지 확인하는 함수
void addq(int);     //큐에서의 삽입
int deleteq();      //큐에서의 삭제

int main()
{

	printf("-----Kitak Oh   2017038035-----\n\n");

	char command;
	int key, key1, key2;
	Graph* graph = NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Term Project                  \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z             Destroy Graph   = d \n");
		printf(" Insert Vertex = i             Delte Vertex    = l \n");
		printf(" Insert Edge   = n             Delete Edge     = e\n");
		printf(" depthFS       = f             breadthFS       = t\n");
		printf(" Print         = p             Quit            = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			createGraph(&graph);
			break;
		case 'p': case 'P':
			printGraph(graph);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertVertex(graph, key);
			break;
        case 'l': case 'L':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteVertex(graph, key);
			break;
		case 'd': case 'D':
			destroyGraph(graph);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d %d", &key1, &key2);
			insertEdge(graph, key1, key2);
			break;
		case 'e': case 'E':
            printf("Your Key = ");
            scanf("%d %d", &key1, &key2);
			deleteEdge(graph, key1, key2);
			break;
		case 'f': case 'F':
            for(int i=0; i<MAX_VERTEX; i++) //다음 사용을 위해 초기화해준다
            {
                visited[i] = 0;
            }
            printf("Your Key = ");
            scanf("%d", &key);
			depthFS(graph, key);
			break;
		case 't': case 'T':
            for(int i=0; i<MAX_VERTEX; i++) //다음 사용을 위해 초기화해준다
            {
                visited[i] = 0;
            }
            printf("Your Key = ");
            scanf("%d", &key);
			breadthFS(graph, key);
			break;
		case 'q': case 'Q':
			destroyGraph(graph);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int createGraph(Graph** h) /* empty graph creation */
{
    if(*h != NULL)
		destroyGraph(*h);

	/* Graph에 대한 메모리를 할당하여 리턴 */
	*h = (Graph*)malloc(sizeof(Graph));
    (*h)->vlist=(VertexHead*)malloc(MAX_VERTEX*sizeof(VertexHead));
    for(int i = 0; i < MAX_VERTEX; i++)
    {
        (*h)->vlist[i].head = NULL;
    }
    return 1;
}

int destroyGraph(Graph* h) /* deallocating all allocated memory */
{   
    for(int i=0; i<MAX_VERTEX; i++)
    {            
        Vertex* p = h -> vlist[i].head;
        Vertex* prev = NULL;
        while(p!=NULL)      //위치를 이동하며 prev의 메모리를 해제한다
        {
            prev = p;
            p = p->link;
            free(prev);
        }
        p = NULL;
    }

    free(h->vlist);     //vlist 메모리 해제
	return 1;
}

int insertVertex(Graph* h, int v) /* vertex insertion */
{
    int i = 0;
    if(v > MAX_VERTEX||v < 0)       //0과 19사이의 수만 입력받는다 아닐 겨우 오류 출력
    {
        printf("Error! wrong insertion");
        return 1;
    }

    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));        //vertex에 삽입할 값을 할당
	newVertex->num = v;             //v값 삽입
    newVertex->link = NULL;         //edge가 없는 상태로 vertex를 삽입하기 때문에 NULL로 초기화
    h->vlist[v].head=newVertex;     //새로운 vertex 값 삽입
	return 1;
}

int deleteVertex(Graph* h, int v) /* vertex deletion */
{
    if(v > MAX_VERTEX||v < 0)       //0과 19사이의 수만 입력받는다 아닐 겨우 오류 출력
    {
        printf("Error! nothing to delete.");
        return 1;
    }
    Vertex* p = h->vlist[v].head;

	Vertex* prev = NULL;
    if (p == NULL)				//삭제할 정점이 존재하지 않는 경우
	{
		printf("nothing to delete.\n");
		return 1;
	}
	while(p != NULL) {      //정점이 존재할 경우 위치를 이동하며 해제해준다
		prev = p;
		p = p->link;
        deleteEdge(h, v, prev->num);        //vertex를 삭제하기 앞서 edge를 제거해준다
		free(prev);
	}
    
	return 0;
}
int insertEdge(Graph* h, int v1, int v2) /* new edge creation between two vertices */
{
    Vertex* temp = NULL;
    if(v1 < 0||v2 < 0||v1 > MAX_VERTEX||v2 > MAX_VERTEX||(!h->vlist[v1].head)||!(h->vlist[v2].head))//0과 19사이의 수만 입력받고 vertex값이 있는 경우
    {
        printf("Error! wrong insertion");
        return 1;
    }
    Vertex* edge = (Vertex*)malloc(sizeof(Vertex));     //edge에 삽입할 값을 할당한 후 삽입
    edge->num = v2;
    edge->link = h->vlist[v1].head;
    h->vlist[v1].head = edge;
	return 0;
}
int deleteEdge(Graph* h, int v1, int v2) /* edge removal */
{
    Vertex* edge = h->vlist[v1].head;
    Vertex* temp  = NULL;
    if(v1 > MAX_VERTEX || v2 > MAX_VERTEX) 
    {         
        printf("Error! Nothing to delete\n"); //0과 19사이의 수만 입력받는다 아닐 겨우 오류 출력
        return 1; 
    } 
    
    while (edge->link != NULL)//이동하며 엣지의 값을 해제해준다
	{
		if (edge->num == v1 || edge->num == v2)
		{
			if (edge->link != NULL)
				temp->link = edge->link;
			else
				temp->link = NULL;
			free(edge);
			return 0;
		}
        temp = edge;
		edge = edge->link;
	}
}
int depthFS(Graph* h, int v) /* depth firt search using stack */
{
    Vertex* w;
    visited[v] = TRUE;      //정점을 방문했음을 표시
    printf("%5d", v);
    for(w = h->vlist[v].head; w; w = w->link)
    {
        if(!visited[w->num])//방문하지 않았을 경우
            depthFS(h, w->num);//재귀함수를 인접 정점으로 이동한다
    }
    return 1;
}
int breadthFS(Graph* h, int v) /* breadth first search using queue */
{
    Vertex* w;
    front = rear= NULL;
    printf("%5d", v);
    visited[v] = TRUE;      //정점을 방문했음을 표시
    addq(v);                //큐에 삽입
    while(front){
        v = deleteq();      //큐에서 삭제
        for(w = h->vlist[v].head; w; w = w->link)
        {
            if(!visited[w->num])    //방문이 안되어 있는 경우
            {
                printf("%5d", w->num);
                addq(w->num);
                visited[w->num] = TRUE;     //정점을 방문했음을 표시
            }
        }
    }
}
int printGraph(Graph* h) /* printing graph with vertices and edges */
{
    for (int i = 0; i < MAX_VERTEX; i++) {
    Vertex* temp = h->vlist[i].head;
    printf("\n Vertex %d\n: ", i);      //vertex 값들을 추력
    while (temp) {
      printf("%d -> ", temp->num);      //edge 값들을 출력
      temp = temp->link;
    }
    printf("\n");
  }
}


int queueEmpty()        //큐가 비었는지 확인
{
	if (front == NULL){
		return 1;
	}
	else return 0;
}

void addq(int item)     //큐에서의 삽입
{
	queuePointer temp;
    temp = (queuePointer)malloc(sizeof(queuePointer));
    temp->vertex = item;
    temp->link = NULL;
    if(!temp)
    {
        rear->link = temp;
    }
    else
        front=temp;
        rear = temp;
	
}

int deleteq()       //큐에서의 삭제
{
	queuePointer temp = front;
    int item;
    if(!temp)       //큐가 비었을 경우
        return queueEmpty();
    item = temp->vertex;
    front = temp->link;
    free(temp);
    return item;
}
