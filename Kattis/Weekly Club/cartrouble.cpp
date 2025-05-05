// failed attempt
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
  int num = 2000;

  vector<vector<int>> adjList(num);
  vector<vector<int>> adjListRev(num);

  vector<int> order(num);
  vector<int> visited(num, 0);
  unordered_map<int, int> idToAddress;

  visited[0] = 1;

  for (int j = 0; j < n; j++) {
    int id, out;
    cin >> id >> out;
    order[j] = id;
    idToAddress[id] = j;

    for (int i = 0; i < out; i++) {
      int input;
      cin >> input;
      adjList[id].push_back(input);
      adjListRev[input].push_back(id);
    }
  }
  dfs(visited, 0, adjList);

  int problemFound = false;
  for (auto &it : order) {
    if (it == 0) continue;
    vector<int> visitedTemp(num, 0);

    dfs(visitedTemp, it, adjList);
    // cout << it << ' ' << visited[it] << endl;
    if (visitedTemp[0] == 0) {
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