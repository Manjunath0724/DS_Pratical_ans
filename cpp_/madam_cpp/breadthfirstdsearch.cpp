#include <iostream>
using namespace std;

int graph[10][10], visited[10], queueArr[10];
int front = 0, rear = 0, n;

void BFS(int start) {

  queueArr[rear++] = start;
  visited[start] = 1;

  while (front < rear) {

    int node = queueArr[front++];

    cout << node << " ";

    for (int i = 0; i < n; i++) {

      if (graph[node][i] == 1 && visited[i] == 0) {

        queueArr[rear++] = i;
        visited[i] = 1;
      }
    }
  }
}

int main() {

  cout << "Enter number of vertices: ";
  cin >> n;

  cout << "Enter adjacency matrix:\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> graph[i][j];
  }

  cout << "BFS Traversal: ";

  BFS(0);

  return 0;
}