// #include <iostream>
// #include <string>
// using namespace std;
// class Graph
// {
// public:
//   int eddge[15][15], visited[15], n;
//   void DepthFSearch(int v)
//   {
//     int i;
//     visited[v] = 1;
//     for (i = 1; i <= n; i++)
//       if (eddge[v][i] && !visited[i])
//       {

//         DepthFSearch(i);
//       }
//   }
// };

// int main()
// {
//   int i, j, vertex, count = 0;
//   Graph g;
//   cout
//       << "Enter no of vertices: ";
//   cin >> vertex;

//   for (i = 1; i <= vertex; i++)
//     for (j = 1; j <= vertex; j++)
//     {
//       g.visited[i] = 0;
//       g.eddge[i][j] = 0;
//     }

//   cout << "Enter  adjency matrix : \n";

//   for (i = 1; i <= vertex; i++)
//   {
//     for (j = 1; j <= vertex; j++)
//     {
//       cin >> g.eddge[i][j];
//     }
//   }

//   g.DepthFSearch(1);
//   for (i = 1; i <= vertex; i++)
//     if (g.visited[i])
//       count++;
//   if (count == g.n)
//     cout << "Graph is connected.";
//   else
//     cout << "Graph is not connected .";

//   return (0);
// }

#include <iostream>
using namespace std;
#define size 15
int Matrix[size][size], connected[size];
class ConnectedGraph
{
public:
  int V;
  void DepthFSearch(int vertex)
  {
    int i;
    connected[vertex] = 1;
    for (i = 1; i <= V; i++)
      if (Matrix[vertex][i] && !connected[i])
      {
        DepthFSearch(i);
      }
  }
};
int main()
{
  int i, j, connectedEdge = 0;
  ConnectedGraph graph;
  cout << "Enter vertex: ";
  cin >> graph.V;
  for (i = 1; i <= graph.V; i++)
    for (j = 1; j <= graph.V; j++)
    {
      connected[i] = 0;
      Matrix[i][j] = 0;
    }
  cout << "Enter adjency matrix:";
  for (i = 1; i <= graph.V; i++)
    for (j = 1; j <= graph.V; j++)
      cin >> Matrix[i][j];
  graph.DepthFSearch(1);
  for (i = 1; i <= graph.V; i++)
    if (connected[i])
      connectedEdge++;
  if (connectedEdge == graph.V)
    cout << "Graph is connected";
  else
    cout << "Graph is not connected";
  return (0);
}
