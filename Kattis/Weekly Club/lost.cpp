#include <bits/stdc++.h>
using namespace std;
// this is apparentlt a msp problem i wanted to practive dijkstra
using vsi = vector<pair<string, int>>;

int main() {
  int n, m;
  cin >> n >> m;
  int count = 0, totalCost = 0;

  unordered_map<string, vsi> adjList;
  unordered_map<string, int> dist;
  while (n--) {
    string input;
    cin >> input;
    dist[input] = INT_MAX;
  }
  while (m--) {
    string l1, l2;
    int cost;
    cin >> l1 >> l2 >> cost;
    adjList[l1].push_back(make_pair(l2, cost));
    adjList[l2].push_back(make_pair(l1, cost));
  }
  dist["English"] = 0;
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

  pq.push(make_pair(0, "English"));
  while (!pq.empty()) {
    int currentCost = pq.top().first;
    string currentLanguage = pq.top().second;
    pq.pop();
    for (auto& [l, c] : adjList[currentLanguage]) {
      //   cout << currentLanguage << ' ' << l << endl;
      if (dist[l] > c) {
        if (dist[l] == INT_MAX) count++;
        dist[l] = c;
        totalCost += c;
        // cout << count << ' ' << dist.size() << ' ' << c << endl;
        if (count == dist.size() - 1) {
          cout << totalCost << endl;
          return 0;
        }
        pq.push(make_pair(c, l));
      }
    }
  }
  cout << "Impossible" << endl;
  return 0;
}