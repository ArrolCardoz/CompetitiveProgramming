#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<int>& visited, int n) {
  visited[n] = 1;
  //   cout << "VISITED " << n << endl;
  for (int i = 0; i < adjList[n].size(); i++) {
    if (!visited[adjList[n][i]]) {
      dfs(adjList, visited, adjList[n][i]);
    }
  }
  return;
}

void solution() {
  int numRoads, n;

  cin >> numRoads >> n;
  vector<int> visited(numRoads, 0);
  vector<vector<int>> adjList(numRoads);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  int ans = -1;
  for (int i = 0; i < numRoads; i++) {
    if (!visited[i]) {
      //   cout << "TEST " << i << endl;
      dfs(adjList, visited, i);
      ans++;
    }
  }
  //   for (auto& it : visited)
  //     if (!it) ans++;
  cout << ans << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}