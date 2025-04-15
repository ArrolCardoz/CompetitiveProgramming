#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<int>& visited, int& score,
         int push) {
  score++;
  //   cout << "POUSH" << push << endl;
  visited[push] = 1;

  for (auto it : adjList[push]) {
    // cout << it << endl;
    if (!visited[it]) {
      dfs(adjList, visited, score, it);
    }
  }
}
void solution() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<vector<int>> adjList(n + 1);
  vector<int> visited(n + 1, 0);
  int score = 0;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adjList[a].push_back(b);
  }
  for (int i = 0; i < l; i++) {
    cin >> a;
    adjList[0].push_back(a);
  }

  dfs(adjList, visited, score, 0);

  cout << score - 1 << endl;
  //   score = 0;
  //   for (auto it : visited) {
  //     if (it) score++;
  //   }
  //   cout << score << endl;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    solution();
  }

  return 0;
}
