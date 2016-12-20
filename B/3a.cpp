#include <stdio.h>
#include <limits.h>

#define V 3
int pred[V];
int dist[V];
int graph[V][V];




int printSolution()
{
   printf("Vertex   Via   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t %d\t %d\n", i,pred[i], dist[i]);
}

void Bellman(int src)
{

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, pred[i] = NULL;

     dist[src] = 0;
     pred[src]= src;

     for (int i = 0; i < V-1; i++)
       for (int u = 0; u < V; u++)
         for (int v = 0; v < V; v++)
            if (graph[u][v] &&  dist[v] > dist[u]+graph[u][v])
            {
                  dist[v] = dist[u] + graph[u][v];
                  pred[v]=u;
            }

     for (int u = 0; u < V; u++)
       for (int v = 0; v < V; v++)
          if (graph[u][v] &&  dist[v] > dist[u]+graph[u][v])
          {
                printf("Exception: Negative cycle\n");
                return;
          }

     printSolution();
}


int main()
{


      int g[V][V]={{0,-1,0},{0,0,1},{1,0,0}};

          for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
              graph[i][j]=g[i][j];
            }
            /* code */
          }

    for (int i = 0; i < V; i++) {
      printf("\nFor node %d \n",i );
      Bellman(i);
    }


    return 0;
}
