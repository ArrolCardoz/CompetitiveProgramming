#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<int>& visited,
         unordered_map<string, int> ID, int push, string& ans) {
  //   cout << "POUSH" << push << endl;
  visited[push] = 1;

  for (auto it : adjList[push]) {
    // cout << it << endl;
    if (visited[it]) ans = "safe";

    if (!visited[it]) dfs(adjList, visited, ID, it, ans);
  }
}

int getID(unordered_map<string, int>& ID, string str) {
  if (ID.find(str) == ID.end()) ID[str] = ID.size() - 1;
  return ID[str];
}
void solution() {
  int n;
  cin >> n;
  vector<vector<int>> adjList;
  unordered_map<string, int> ID;
  vector<int> visited(n, 0);
  string a, b;
  int aID, bID;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    int aID = getID(ID, a);
    int bID = getID(ID, b);
    adjList[aID].push_back(bID);
    adjList[bID].push_back(aID);
  }
  while (cin >> a) {
    string ans = "trapped";
    vector<int> visited(n, 0);
    dfs(adjList, visited, ID, getID(ID, a), ans);
    cout << a << " " << ans << endl;
  }
  //   score = 0;
  //   for (auto it : visited) {
  //     if (it) score++;
  //   }
  //   cout << score << endl;
}
int main() {
  solution();

  return 0;
}
