#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#include<windows.h>
#include"queue.h"
#define INFINITY 9999


// A structure to represent an adjacency list node
typedef struct node {
    int Id;
    struct node* next;
}node;
 
// A structure to represent an adjacency list
typedef struct Adj {
    node* head;
}Adj;
 
// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
typedef struct Graph {
    int V;
    int *visited;
    Adj* array;
}Graph;


node* createNode(int id);
Graph* createGraph(int V);
void printGraph(Graph* G);
void addEdge(Graph* G, int src, int dest,bool direction);
void removeEdge(Graph* G, int src,int dest,bool direction);
void addVertex(Graph *G);
void removeVertex(Graph *G,int n,bool direction);
void searchVertex(Graph* G, int Id);
void dfs(Graph* G,int a);
void bfs(Graph* G,int v);
void pathBetweenAandB(Graph* G,int a,int b);
void Dijkstra(Graph *G,int n,int start);
int calculerDensite(Graph* G);
void Color(int couleurDuTexte,int couleurDeFond);



// Driver program to test above functions
int main(int argc, char *argv[])
{
    int V = 7;
    Graph* G;
    
    int choix,start,end,x,den;
	bool directed;

	do{
	    printf("---------Graph Data Structure Operations----------\n");
	    Color(2,0);
		printf("1-Create the adjecency list.\n");
		Color(3,0);
		printf("2-Display the adjecency list.\n");
	    Color(5,0);
	    printf("3-Add edge to the adjecency list (directed graph).\n");
		Color(6,0);
		printf("4-Add edge to the adjecency list (undirected graph).\n");
		Color(7,0);
		printf("5-Remove edge from the adjecency list.\n");
		Color(8,0);
		printf("6-Add vertex to the adjecency list.\n");
		Color(9,0);
		printf("7-Remove vertex from the adjecency list.\n");
		Color(10,0);
		printf("8-Search vertex.\n");
		Color(11,0);
		printf("9-Search for a vertex and displays its links (using DFS).\n");
		Color(12,0);
		printf("10-Search for a vertex and displays its links (using BFS).\n");
		Color(14,0);
		printf("11-Search for path between two vertexes a and b.\n");
		Color(15,0);
		printf("12- Calcul of the density of the graph.\n");
		Color(4,0);
		printf("13-Exit.");
		Color(15,0);
		printf("\n------------------------------------------------\n");
		printf("donner votre choix:");
		scanf("%d",&choix);
		switch(choix){
			case 1:G = createGraph(V);
			break;
			case 2:printGraph(G);
			break;
			case 3:directed = true;
				   printf("enter the vertex of start:");
				   scanf("%d",&start);
				   printf("enter the vertex of end:");
				   scanf("%d",&end);
				   addEdge(G,start,end,directed);
			break;
			case 4:directed = false;
				   printf("enter the vertex of start:");
				   scanf("%d",&start);
				   printf("enter the vertex of end:");
				   scanf("%d",&end);
				   addEdge(G,start,end,directed);
			break;
			case 5:printf("enter the vertex of start:");
				   scanf("%d",&start);
				   printf("enter the vertex of end:");
				   scanf("%d",&end);	
				   removeEdge(G,start,end,directed);
			break;
			case 6:addVertex(G);
			break;
			case 7:printf("enter the vertex to remove:");
				   scanf("%d",&x);
				   removeVertex(G,x,directed);
			break;
			case 8:printf("enter the vertex to search:");
		   		   scanf("%d",&x);
				   searchVertex(G,x);
			break;
			case 9:printf("enter the vertex of start:");
		   		   scanf("%d",&start);
				   dfs(G,start);
				   printf("\n");
			break;
			case 10:printf("enter the vertex of start:");
		   			scanf("%d",&start);
					bfs(G,start);
					printf("\n");
			break;
			case 11:printf("enter the vertex of start:");
		   			scanf("%d",&start);
				    printf("enter the vertex of end:");
				    scanf("%d",&end);	
					pathBetweenAandB(G,start,end);
			break;
			case 12:den = calculerDensite(G);
					printf("La densite de ce graphe est: %d\n",den);
			break;
			case 13:Color(2,0);
					printf("Thank you very much sir :)");
					Color(15,0);
				    exit(1);	    
			break;	
		}
		
	}while(choix!=13);
	
	
	
	return 0;
}



// function to create a new adjacency list node
node* createNode(int id){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->Id = id;
    newNode->next = NULL;
    return newNode;
}

// function that creates a graph of V vertices
Graph* createGraph(int V){
    
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->V = V;
 
    G->array = (Adj*)malloc(V * sizeof(Adj));
    G->visited = (int*)malloc(V * sizeof(int));
    
    int i;
    for (i = 0; i < V; ++i) {
        G->array[i].head = NULL;
        G->visited[i] = 0;
    }
 
    return G;
}

// function to add an edge to a graph
void addEdge(Graph* G, int src, int dest, bool direction){
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
   if(direction==true){ 	
	    node* check = NULL;
	    node* newNode = createNode(dest);
	 
	    if (G->array[src].head == NULL) {
	        newNode->next = G->array[src].head;
	        G->array[src].head = newNode;
	    }
	    else {
	 
	        check = G->array[src].head;
	        while (check->next != NULL) {
	            check = check->next;
	        }
	        // graph->array[src].head = newNode;
	        check->next = newNode;
	    }
	}else if (direction==false){
		
		node* check = NULL;
	    node* newNode = createNode(dest);
	 
	    if (G->array[src].head == NULL) {
	        newNode->next = G->array[src].head;
	        G->array[src].head = newNode;
	    }
	    else {
	 
	        check = G->array[src].head;
	        while (check->next != NULL) {
	            check = check->next;
	        }
	        // graph->array[src].head = newNode;
	        check->next = newNode;
	    }
	    
	    // Since graph is undirected, add an edge from
	    // dest to src also
	    newNode = createNode(src);
	    if (G->array[dest].head == NULL) {
	        newNode->next = G->array[dest].head;
	        G->array[dest].head = newNode;
	    }
	    else {
	        check = G->array[dest].head;
	        while (check->next != NULL) {
	            check = check->next;
	        }
	        check->next = newNode;
	    }
		
	}
}

// function to remove an edge from a graph
void removeEdge(Graph* G, int src, int dest,bool direction){
    
    if(direction==true){
    	node* current = G->array[src].head;
	    node* prev = NULL;
	    
	    // traverse the linked list and find the node to remove
	    while (current != NULL) {
	        if (current->Id == dest) {
	            if (prev == NULL) {
	                G->array[src].head = current->next;
	            } else {
	                prev->next = current->next;
	            }
	            free(current);
	            break;
	        }
	        prev = current;
	        current = current->next;
	    }
	}else if(direction==false){
		node* current = G->array[src].head;
	    node* prev = NULL;
	    
	    // traverse the linked list and find the node to remove
	    while (current != NULL) {
	        if (current->Id == dest) {
	            if (prev == NULL) {
	                G->array[src].head = current->next;
	            } else {
	                prev->next = current->next;
	            }
	            free(current);
	            break;
	        }
	        prev = current;
	        current = current->next;
	    }
	    
	    // Since graph is undirected, remove the edge from dest to src also
	    current = G->array[dest].head;
	    prev = NULL;
	    while (current != NULL) {
	        if (current->Id == src) {
	            if (prev == NULL) {
	                G->array[dest].head = current->next;
	            } else {
	                prev->next = current->next;
	            }
	            free(current);
	            break;
	        }
	        prev = current;
	        current = current->next;
	    }
	}
}

// function to add a vertex to the graph
void addVertex(Graph *G){
    G->V++;
    G->array = (Adj*)realloc(G->array, G->V * sizeof(Adj));
    G->visited = (int*)realloc(G->visited, G->V * sizeof(int));
    G->array[G->V - 1].head = NULL;
    G->visited[G->V - 1] = 0;
}

// function to remove a vertex from the graph
void removeVertex(Graph *G, int n,bool direction){
    // remove all the edges connected to the vertex
    node* current = G->array[n].head;
    node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        
        if(direction==true){
        	removeEdge(G, n, temp->Id,true);
		}else if(direction==false){
			removeEdge(G, n, temp->Id,false);
		}
    }
    
    // shift all the vertexes after the removed vertex to the left
    int i;
    for (i = n + 1; i < G->V; i++) {
        current = G->array[i].head;
        while (current != NULL) {
            current->Id--;
            current = current->next;
        }
    }
    
    // resize the arrays and update the number of vertexes
    G->V--;
    G->array = (Adj*)realloc(G->array, G->V * sizeof(Adj));
    G->visited = (int*)realloc(G->visited, G->V * sizeof(int));
}

// function to search for a vertex in the graph
void searchVertex(Graph* G, int Id){
    int i;
    for (i = 0; i < G->V; i++) {
        if (i == Id) {
            printf("the vertex %d exists.\n");
        }
    }
}

// A function used by DFS
void dfsUtil(Graph* G, int v){
    G->visited[v] = 1;
    printf("%d ", v);
    
    node* current = G->array[v].head;
    while (current != NULL) {
        if (!G->visited[current->Id]) {
            dfsUtil(G, current->Id);
        }
        current = current->next;
    }
}

// The function to do DFS traversal (DEPTH FIRST SEARCH). It uses recursive dfsUtil()
void dfs(Graph* G, int v){
    // mark all the vertices as not visited
    int i;
    for (i = 0; i < G->V; i++) {
        G->visited[i] = 0;
    }
    
    // call the recursive helper function to print DFS traversal
    dfsUtil(G, v);
}

// A function to perform BFS traversal of a graph (BREADTH FIRST SEARCH)
void bfs(Graph* G, int s){
    // mark all the vertices as not visited
    int i;
    for (i = 0; i < G->V; i++) {
        G->visited[i] = 0;
    }
    
    // create a queue for BFS
    queue* q = (queue*)malloc(sizeof(queue));
    q->size = G->V;
    q->f = -1;
    q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));
 
    // mark the current node as visited and enqueue it
    G->visited[s] = 1;
    enqueue(q, s);
    
    // 'i' will be used to get all the adjacent vertices of a vertex
    node* current;
 
    while (!isEmpty(q)) {
        // dequeue a vertex from queue and print it
        s = dequeue(q);
        printf("%d ", s);
 
        // get all the adjacent vertices of the dequeued vertex s
        // if a adjacent has not been visited, then mark it visited
        // and enqueue it
        current = G->array[s].head;
        while (current != NULL) {
            if (!G->visited[current->Id]) {
                G->visited[current->Id] = 1;
                enqueue(q, current->Id);
            }
            current = current->next;
        }
    }
}

// function to print the adjacency list representation of graph
void printGraph(Graph* G) {
    int v;
    for (v = 0; v < G->V; ++v) {
        node* current = G->array[v].head;
        printf("Vertex %d:", v);
        while (current) {
            printf("(%d->%d)",v, current->Id);
            current = current->next;
        }
        printf("\n");
    }
}

// function to print path between two vertexes
void pathBetweenAandB(Graph* G,int a,int b){
	int v;
    for (v = 0; v < G->V; ++v) {
        if(v==a){
        	node* current = G->array[v].head;
	        while (current) {
	        	if(current->Id==b){
	        		printf("%d is reachable by %d,there is path between these vertexes.",current->Id,v);
				}
				
	            current = current->next;
	        }
		}
    }
}

// function to calculate the density of the graph
int calculerDensite(Graph* G){
	int D = 0;
	for (int v = 0; v < G->V; ++v) {
        node* current = G->array[v].head;
        while (current) {
            D++;
            current = current->next;
        }
    }
    
    return D;
}

// fonction d'affichage de couleurs
void Color(int couleurDuTexte,int couleurDeFond){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

//void Dijkstra(Graph *G,int n,int start){
//
//}

