#include <stdio.h>
#include <limits.h>

#define V 9
bool sptSet[V];
int dist[V];
int graph[V][V];



int minDistance()
{
   int min = INT_MAX, index;

   for (int v = 0; v < V; v++)
     if (!sptSet[v] && dist[v] <= min)
         min = dist[v], index = v;

   return index;
}

int printSolution()
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int src)
{

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     dist[src] = 0;

     for (int i = 0; i < V-1; i++)
     {

       int u = minDistance();
       sptSet[u] = true;

       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] &&  dist[v] > dist[u]+graph[u][v])
            dist[v] = dist[u] + graph[u][v];
     }

     printSolution();
}


int main()
{
    int g[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
          for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
              graph[i][j]=g[i][j];
            }
            /* code */
          }

          for (int i = 0; i < V; i++) {
            printf("\nFor node %d \n",i+1 );
            dijkstra(i);
          }


    return 0;
}
