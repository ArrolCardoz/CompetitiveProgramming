#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vii = vector<pii>;
void processTrial(set<pii>& ansTrail, vector<int>& prev, int n) {
  while (n != 0) {
    ansTrail.insert(make_pair(n, prev[n]));
    n = prev[n];
  }
}

int main() {
  int n, m, ansFound = INT_MAX, ans = 0;
  cin >> n >> m;
  vector<int> dist(n, INT_MAX), prev(n, 0);
  vector<vii> adjList(n);
  priority_queue<pii, vii, greater<>> pq;
  set<pii> ansTrail;
  pq.push(make_pair(0, 0));
  dist[0] = 0;

  // input
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    adjList[a].push_back(make_pair(b, w));
    adjList[b].push_back(make_pair(a, w));
  }

  // dijkstra
  while (!pq.empty()) {
    int currentDist = pq.top().first;
    int currentTrail = pq.top().second;
    pq.pop();
    if (ansFound < currentDist) break;
    if (currentTrail == dist.size() - 1) {
      processTrial(ansTrail, prev, currentTrail);
    }

    for (auto& [n, w] : adjList[currentTrail]) {
      int addDist = currentDist + w;
      if (addDist <= dist[n]) {
        pq.push(make_pair(addDist, n));
        dist[n] = addDist;
        prev[n] = currentTrail;
      }
    }
  }
  for (auto& [a, b] : ansTrail) {
    for (auto& [a1, b1] : adjList[a]) {
      if (a1 == b) {
        ans += b1;
        cout << b1 << endl;
        break;
      }
    }
  }

  cout << ans * 2 << endl;
  return 0;
}
