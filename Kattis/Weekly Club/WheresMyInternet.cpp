#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited) {
  visited[node] = true;

  for (int neighbor : adjList[node]) {
    if (!visited[neighbor]) {
      dfs(neighbor, adjList, visited);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<bool> connected(n, false);
  connected[0] = true;
  vector<vector<int>> adjList(n);
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  dfs(0, adjList, connected);

  bool allConnected = true;
  for (int i = 0; i < n; i++) {
    if (!connected[i]) {
      allConnected = false;
      cout << i + 1 << endl;
    }
  }
  if (allConnected) cout << "Connected" << endl;

  return 0;
}
