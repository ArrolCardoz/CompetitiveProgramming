#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

enum { UNVISITED = -1 };

int dfsCtr = 0;
bool bridge = false;
vi dfsNum, dfsLow, dfsParent;
vvi adjList;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void hasBridge(int u) {
  dfsNum[u] = dfsLow[u] = dfsCtr;
  dfsCtr++;
  for (auto& v : adjList[u]) {
    if (v == u) continue;
    if (dfsNum[v] == UNVISITED) {
      dfsParent[v] = u;

      hasBridge(v);

      if (dfsNum[u] < dfsLow[v]) bridge = true;
      dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    } else if (v != dfsParent[u])
      dfsLow[u] = min(dfsLow[u], dfsNum[v]);
  }
}
bool solution() {
  int p, c;
  cin >> p >> c;
  if (p == 0 && c == 0) return false;

  adjList.assign(p, vector<int>());
  dfsNum.assign(p, UNVISITED);
  dfsLow.assign(p, UNVISITED);
  dfsParent.assign(p, UNVISITED);
  bridge = false;
  dfsCtr = 0;
  while (c--) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  for (int i = 0; i < p; i++) {
    if (dfsNum[i] == UNVISITED) hasBridge(i);
  }
  if (bridge)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return true;
}
int main() {
  fastIO();
  while (solution());
  return 0;
}