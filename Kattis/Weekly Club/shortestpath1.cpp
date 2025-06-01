#include <bits/stdc++.h>
using namespace std;
using vii = vector<pair<int, int>>;

int main() {
  int n, m, q, s;
  while (cin >> n >> m >> q >> s) {
    if (n == 0 && m == 0 && q == 0 && s == 0) return 0;
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vii, greater<>> pq;
    vector<vii> adjList(n);
    // int count = 1;
    // input
    while (m--) {
      int a, b, w;
      cin >> a >> b >> w;
      adjList[a].push_back(make_pair(b, w));
    }
    // dijkstra
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
      int currentDist = pq.top().first;
      int currentNode = pq.top().second;
      pq.pop();
      for (auto& [n, c] : adjList[currentNode]) {
        int totalCost = currentDist + c;
        if (totalCost < dist[n]) {
          pq.push(make_pair(totalCost, n));
          dist[n] = totalCost;
          //   count++;
        }
      }
      //   if (count == dist.size()) break;
    }
    while (q--) {
      int query;
      cin >> query;
      int ans = dist[query];
      if (ans == INT_MAX)
        cout << "Impossible" << endl;
      else
        cout << ans << endl;
    }
    cout << endl;
  }
}