#include <bits/stdc++.h>
using namespace std;
using vii = vector<pair<int, double>>;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    vector<int> dist(n, INT_MAX);
    vector<double> ans;
    vector<vii> adjList(n);
    // input
    while (m--) {
      int a, b;
      double f;
      cin >> a >> b >> f;
      adjList[a].push_back({b, f});
      adjList[b].push_back({a, f});
    }
    // dijkstra
    priority_queue<pair<double, int>> pq;
    dist[0] = 0;
    pq.push({1.0, 0});
    bool gotAns = false;
    while (!pq.empty()) {
      //   if (gotAns) break;
      int currentNode = pq.top().second;
      double currentSize = pq.top().first;
      pq.pop();

      for (auto& [node, f] : adjList[currentNode]) {
        double newFactor = currentSize * f;
        // cout << fixed << setprecision(4) << newFactor << '=' << currentSize
        //      << '*' << f << endl;
        if (node == n - 1) {
          //   cout << "ANSSSSSSSSSS---------- " << newFactor << endl;
          ans.push_back(newFactor);
        }
        if (newFactor < dist[node]) {
          dist[node] = newFactor;
          //   cout << '{' << newFactor << ',' << node << '}' << endl;
          pq.push({newFactor, node});
        }
      }
    }
    sort(ans.rbegin(), ans.rend());
    cout << fixed << setprecision(4) << ans[0] << endl;
  }
  return 0;
}