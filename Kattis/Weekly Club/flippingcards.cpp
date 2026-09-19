#include <bits/stdc++.h>
using namespace std;

void findConnectedComponents(unordered_map<int, vector<int>>& adjList,
                             unordered_map<int, bool>& visited, int node,
                             int& numEdge, int& numVertex) {
  visited[node] = true;
  for (auto& it : adjList[node]) {
    numEdge++;
    if (!visited[it]) {
      numVertex++;
      findConnectedComponents(adjList, visited, it, numEdge, numVertex);
    }
  }
}

void solution() {
  int n;
  unordered_map<int, vector<int>> adjList;
  unordered_map<int, bool> visited;

  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    adjList[b].push_back(a);
    adjList[a].push_back(b);

    visited[a] = false;
    visited[b] = false;
  }
  for (auto& it : adjList) {
    if (!visited[it.first]) {
      int edge = 0, vertex = 1;
      findConnectedComponents(adjList, visited, it.first, edge, vertex);
      // cerr << edge << ' ' << vertex << endl;
      if (vertex * 2 < edge) {
        cout << "impossible" << endl;
        return;
      }
    }
  }
  cout << "possible" << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solution();
  }
  return 0;
}