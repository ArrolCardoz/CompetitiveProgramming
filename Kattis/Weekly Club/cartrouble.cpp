#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &visited, int node, vector<vector<int>> &adjList) {
  for (int i = 0; i < adjList[node].size(); i++) {
    if (visited[adjList[node][i]] == 0) {
      visited[adjList[node][i]] = 1;
      //   cout << adjList[node][i] << endl;
      dfs(visited, adjList[node][i], adjList);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adjList(n);
  vector<vector<int>> adjListRev(n);

  vector<int> order(n);
  vector<int> visited(n, 0);
  vector<int> visitedTemp(n, 0);
  visited[0] = 1;
  visitedTemp[0] = 1;

  for (int j = 0; j < n; j++) {
    int id, out;
    cin >> id >> out;
    order[j] = id;

    for (int i = 0; i < out; i++) {
      int input;
      cin >> input;
      adjList[id].push_back(input);
      adjListRev[input].push_back(id);
    }
  }
  dfs(visited, 0, adjList);
  dfs(visitedTemp, 0, adjListRev);

  int problemFound = false;
  for (auto &it : order) {
    if (it == 0) continue;
    // cout << it << ' ' << visited[it] << endl;
    if (!visitedTemp[it]) {
      cout << "TRAPPED " << it << endl;
      problemFound = true;
    }
    if (visited[it] == 0) {
      cout << "UNREACHABLE " << it << endl;
      problemFound = true;
    }
  }
  if (!problemFound) cout << "NO PROBLEMS" << endl;
  return 0;
}