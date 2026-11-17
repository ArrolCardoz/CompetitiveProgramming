#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvii vector<vii>

enum { UNVISITED = -1, VISITED = 1 };

int dfsCtr = 0;

vi dfsNum, dfsLow;
vvii adjList;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void dfs(int u) {
  dfsNum[u] = VISITED;
  for (auto& [v, state] : adjList[u]) {
    if (v == u || dfsNum[v] == VISITED || state == 0) continue;
    dfsCtr++;
    dfs(v);
  }
}

void assignBridge(int u, int p) {
  dfsNum[u] = dfsLow[u] = dfsCtr++;
  for (auto& [v, state] : adjList[u]) {
    if (dfsNum[v] == UNVISITED) {
      assignBridge(v, u);
      if (dfsLow[u] < dfsLow[v]) {
        state = 0;
      }
      dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    } else if (v != p)
      dfsLow[u] = min(dfsNum[u], dfsLow[v]);
  }
}
int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  dfsNum.assign(n, -1);
  dfsLow.assign(n, -1);
  adjList.assign(n, vii());
  while (m--) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back({b, 1});
    adjList[b].push_back({a, 1});
  }

  assignBridge(0, -1);

  dfsNum.assign(n, -1);
  dfsCtr = 1;
  dfs(0);
  cout << dfsCtr << endl;
  return 0;
}