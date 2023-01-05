#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#include<windows.h>
#include "queue.h"
#define INFINITY 9999


// Globally declared visited array
int vis[100],visited[20];
 
// Graph structure to store number
// of vertices and edges and
// Adjacency matrix

typedef struct Graph {
    int V;
    int E;
    int** Adj;
}Graph;


Graph* adjMatrix();
void initMatrix(Graph *G);
void displayAdjacencyMatrix(Graph *G);
void addEdge(Graph *G,int x,int y,bool direction);
void removeEdge(Graph *G,int x,int y);
void addVertex(Graph *G);
void removeVertex(Graph *G);
void searchVertex(Graph* G,int n);
void dfs(Graph* G,int a);
void bfs(Graph* G,int v);
void pathBetweenAandB(Graph* G,int a,int b);
void Dijkstra(Graph *G,int n,int start);
int calculerDensite(Graph* G);
void Color(int couleurDuTexte,int couleurDeFond);



// Driver code
int main(int argc, char *argv[]){

	int choix,start,end,x,den;
	bool directed;
	
	Graph *G;

    do{
      	printf("---------Graph Data Structure Operations----------\n");
      	Color(2,0);
	    printf("1-Create the adjecency matrix.\n");
	    Color(3,0);
	    printf("2-Initialize the adjecency matrix.\n");
	    Color(4,0);
	    printf("3-Display the adjecency matrix.\n");
	    Color(5,0);
	    printf("4-Add edge to the adjecency matrix (directed graph).\n");
	    Color(6,0);
		printf("5-Add edge to the adjecency matrix (undirected graph).\n");
		Color(7,0);
		printf("6-Remove edge from the adjecency matrix.\n");
		Color(8,0);
		printf("7-Add vertex to the adjecency matrix.\n");
		Color(9,0);
		printf("8-Remove vertex from the adjecency matrix.\n");
		Color(10,0);
		printf("9-Search vertex.\n");
		Color(11,0);
		printf("10-Search for a vertex and displays its links (using DFS).\n");
		Color(12,0);
		printf("11-Search for a vertex and displays its links (using BFS).\n");
		Color(14,0);
		printf("12-Search for path between two vertexes a and b.\n");
		Color(15,0);
		printf("13-Search for shortest path between two vertexes a and b (using Dijkstra).\n");
		Color(2,0);
		printf("14- Calcul of the density of the graph.\n");
		Color(4,0);
		printf("15-Exit.");
		Color(15,0);
	    printf("\n------------------------------------------------\n");
	    printf("donner votre choix:");
	   	scanf("%d",&choix);
	   	switch(choix){
	   		case 1:G = adjMatrix();
	   		break;
	   		case 2:initMatrix(G);
	   		break;
	   		case 3:displayAdjacencyMatrix(G);
	   		break;
	   		case 4:directed = true;
					printf("enter the vertex of start:");
					scanf("%d",&start);
					printf("enter the vertex of end:");
					scanf("%d",&end);
				    addEdge(G,start,end,directed);
	   		break;
	   		case 5:directed = false;
					printf("enter the vertex of start:");
					scanf("%d",&start);
					printf("enter the vertex of end:");
					scanf("%d",&end);
					addEdge(G,start,end,directed);
	   		break;
	   		case 6:printf("enter the vertex of start:");
			   	   scanf("%d",&start);
				   printf("enter the vertex of end:");
				   scanf("%d",&end);	
			   	   removeEdge(G,start,end);
	   		break;
	   		case 7:addVertex(G);
	   		break;
	   		case 8:removeVertex(G);
	   		break;
	   		case 9:printf("enter the vertex to search:");
	   			   scanf("%d",&x);
				   searchVertex(G,x);
			break;
			case 10:printf("enter the vertex of start:");
	   			   scanf("%d",&start);
				   dfs(G,start);
				   printf("\n");
			break;
			case 11:printf("enter the vertex of start:");
	   			    scanf("%d",&start);
					bfs(G,start);
					printf("\n");
			break;
			case 12:printf("enter the vertex of start:");
	   			    scanf("%d",&start);
				    printf("enter the vertex of end:");
				    scanf("%d",&end);	
					pathBetweenAandB(G,start,end);
			break;
			case 13:printf("enter the vertex of start:");
	   			    scanf("%d",&start);
					Dijkstra(G,G->V,start);
					printf("9999 is a default value.\n");
			break;
			case 14:den = calculerDensite(G);
					printf("La densite de ce graphe est: %d\n",den);
	   		break;
			case 15:Color(2,0);
					printf("Thank you very much sir :)");
					Color(15,0);
					exit(1);
			break;	   		
		}	    
	
	}while(choix!=15);
	
	
	return 0;  
}


// fonction qui crée la matrice d'adjacence d'un graphe
Graph* adjMatrix(){
    Graph* G = (Graph*)
        malloc(sizeof(Graph));
    if (!G) {
        printf("Memory Error\n");
        return NULL;
    }
    G->V = 7;
    G->E = 7;
 
    G->Adj = (int**)malloc((G->V) * sizeof(int*));
    for (int k = 0; k < G->V; k++) {
        G->Adj[k] = (int*)malloc((G->V) * sizeof(int));
    }
    
    return G;
}

// fonction qui initialise un la matrice d'adjacence
void initMatrix(Graph *G){
	for (int u = 0; u < G->V; u++) {
        for (int v = 0; v < G->V; v++) {
            G->Adj[u][v] = 0;
        }
    }
}

// fonction qui affiche la matrice d'adjacence du graphe
void displayAdjacencyMatrix(Graph *G){
	
	printf("  ");
	for(int u = 0; u < G->V; u++){
		printf("%d ",u);
	}
	printf("\n");
    for (int u = 0; u < G->V; u++) {
		printf("%d ",u);
       	for (int v = 0; v < G->V;v++) {
		   printf("%d ",G->Adj[u][v]);
        }
		printf("\n");
    }
}

// fonction qui ajoute un arc entre deux sommets
void addEdge(Graph *G,int x,int y,bool direction){
	
	if(direction==true){
		G->Adj[x][y] = 1;
		G->Adj[y][x] = 0;
	}else if(direction==false){
	  	G->Adj[x][y] = 1;
		G->Adj[y][x] = 1;
	}
}

// fonction qui supprime un arc entre deux sommets
void removeEdge(Graph *G,int x,int y){
		G->Adj[x][y] = 0;
		G->Adj[y][x] = 0;	
}

// fonction qui ajoute un noeud à un graphe
void addVertex(Graph *G){
    // increasing the number of vertices
   	G->V++;
	  
    G->Adj = (int**)malloc((G->V) * sizeof(int*));
    for (int k = 0; k < G->V; k++) {
        G->Adj[k] = (int*)malloc((G->V) * sizeof(int));
    }
   
    initMatrix(G);
}

// fonction qui supprime un noeud d'un graphe
void removeVertex(Graph *G){
	
   	G->V--;
	  
    G->Adj = (int**)malloc((G->V) * sizeof(int*));
    for (int k = 0; k < G->V; k++) {
        G->Adj[k] = (int*)malloc((G->V) * sizeof(int));
    }
   
   initMatrix(G);  
}

// fonction qui cherche l'existence d'un noeud
void searchVertex(Graph* G,int n){
	
	if(n < G->V){
		printf("the vertex %d exists.\n",n);	   	
	}else{
		printf("the vertex %d doesn't exists.\n",n);	
	}

}

// fonction qui cherche un noeud a et affiche ses liens (en utilisant depth first search)
void dfs(Graph* G,int a){
 
	int i;
	
	vis[a]=1;
	
	for(i=0;i<G->V;i++){
		if(G->Adj[a][i] && !vis[i]){
		    printf("%d->%d ",a,i);
			dfs(G,i);
		}
	}

}

// fonction qui cherche un noeud a et affiche ses liens (en utilisant breadth first search)
void bfs(Graph* G,int v){
    queue q;
    q.size = G->V;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int)); 
	int node;
    int i = v;
    int visited[G->V];
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < G->V; j++)
        {
            if(G->Adj[i][j] == 1 && visited[j] == 0){
                printf("%d->%d ",i,j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}

// fonction qui cherche un chemin entre a et b
void pathBetweenAandB(Graph* G,int a,int b){
	for (int u = 0; u < G->V; u++) {
        for (int v = 0; v < G->V; v++) {
            if(a==u && b==v){
            	if(G->Adj[u][v] == 1){
					printf("le chemin entre %d est %d est: %d->%d \n",u,v,u,v);	
				}
			}
        }
    }
}

// fonction qui cherche le plus court chemin entre a et b
void Dijkstra(Graph *G,int n,int start){
  int cost[G->V][G->V], distance[G->V], pred[G->V];
  int visited[G->V], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  	for (int u = 0; u < G->V; u++) {
       	for (int v = 0; v < G->V;v++) {
		    if (G->Adj[u][v] == 0)
		        cost[u][v] = INFINITY;
		      else
		        cost[u][v] = G->Adj[u][v];
        }
    }

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("Distance from vertex of start to %d: %d\n", i, distance[i]);
    }
}

// fonction qui calcule la densité d'un graphe 
int calculerDensite(Graph* G){
	
	int D = 0;
	for(int i=0;i<G->V;i++){
		for (int j = 0; j < G->V;j++) {
		   if(G->Adj[i][j] == 1){
		   		D++;
		   }
        }
	}
	
	return D;
}

// fonction d'affichage de couleurs
void Color(int couleurDuTexte,int couleurDeFond){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


