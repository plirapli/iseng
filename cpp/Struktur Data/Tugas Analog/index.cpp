#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printPath(vector<vector<int>> &next, int i, int j)
{
  if (next[i][j] == -1)
  {
    cout << j;
  }
  else
  {
    printPath(next, i, next[i][j]);
    cout << " -> " << j;
  }
}

void FloydWarshall(vector<vector<int>> &graph, int numNodes)
{
  vector<vector<int>> distance(graph);

  vector<vector<int>> next(numNodes + 1, vector<int>(numNodes + 1, -1));

  for (int k = 1; k <= numNodes; ++k)
  {
    for (int i = 1; i <= numNodes; ++i)
    {
      for (int j = 1; j <= numNodes; ++j)
      {
        if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
            distance[i][k] + distance[k][j] < distance[i][j])
        {
          distance[i][j] = distance[i][k] + distance[k][j];
          next[i][j] = k;
        }
      }
    }
  }

  if (distance[1][10] == INT_MAX)
  {
    cout << "Tidak ada rute yang tersedia dari node 1 ke node 10" << endl;
  }
  else
  {
    cout << "Rute terpendek dari node 1 ke node 10: ";
    cout << "1 -> ";
    printPath(next, 1, 10);
    cout << endl;
    cout << "Jarak terpendek dari node 1 ke node 10: " << distance[1][10] << endl;
  }
}

int main()
{
  int numNodes = 10;

  vector<vector<int>> graph(numNodes + 1, vector<int>(numNodes + 1, INT_MAX));

  graph[1][1] = 0;
  graph[1][2] = 1;
  graph[1][3] = 4;
  graph[1][4] = 2;

  graph[2][5] = 3;
  graph[2][6] = 1;
  graph[2][7] = 2;
  graph[3][5] = 2;
  graph[3][6] = 4;
  graph[3][7] = 3;
  graph[4][5] = 2;
  graph[4][6] = 4;
  graph[4][7] = 4;

  graph[5][8] = 3;
  graph[5][9] = 4;
  graph[6][8] = 5;
  graph[6][9] = 4;
  graph[7][8] = 2;
  graph[7][9] = 3;

  graph[8][10] = 5;
  graph[9][10] = 1;

  FloydWarshall(graph, numNodes);

  return 0;
}
