#include <iostream>
using namespace std;

#define V 3
void search()
{
}
void addEdge(int graph[][V], int u, int v)
{

  graph[u][v] = 1;
  graph[v][u] = 1;
  cout << graph[v][u];
}

int main()
{
  int graph[V][V] = {0};

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 0);
  addEdge(graph, 2, 0);
  int i, j;

  cout << "Adjacency matrix:" << endl;
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
      cout << graph[i][j] << "   ";
    cout << endl;
  }
}