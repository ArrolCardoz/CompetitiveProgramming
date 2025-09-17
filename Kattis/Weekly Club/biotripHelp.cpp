#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to, weight;
};

struct Graph {
  vector<vector<Edge>> nbr;
  int num_nodes;
  Graph(int n) : nbr(n), num_nodes(n) {}
  void add_edge(int u, int v, int weight) { nbr[u].push_back({v, weight}); }
};

struct Node {
  int weight, to;
  bool operator>(const Node &other) const { return weight > other.weight; }
};

int n, d, a1, a2;

struct Vertex {
  int m;
  vector<int> to, t, a;
  vector<pair<int, int>> inangle;  // (angle, node_id)

  void read() {
    cin >> m;
    to.resize(m);
    t.resize(m);
    a.resize(m);
    for (int i = 0; i < m; i++) {
      cin >> to[i] >> t[i] >> a[i];
      to[i]--;  // make 0-indexed
    }
    for (int i = 0; i < m; i++) {
      int ang = (a[i] + 180) % 360;  // incoming angle
      if (find(ang) == -1) {
        inangle.emplace_back(ang, -1);
      }
    }
  }

  int find(int ang) const {
    for (auto [x, id] : inangle)
      if (x == ang) return id;
    return -1;
  }

  int find_match(int from) const {
    int ang = -1;
    for (int i = 0; i < m; i++) {
      if (to[i] == from) ang = (a[i] + 180) % 360;
    }
    return find(ang);
  }
};

Vertex v[1005];

bool can_use_edge(int station, int curr_angle, int next_angle) {
  if (station == 0) return true;  // free rotation at station 1
  int ccw = next_angle - curr_angle;
  if (ccw < 0) ccw += 360;
  if (ccw <= a1) return true;
  int cw = curr_angle - next_angle;
  if (cw < 0) cw += 360;
  if (cw <= a2) return true;
  return false;
}

int process_inangle() {
  int idx = 0;
  for (int i = 0; i < n; i++) {
    for (auto &p : v[i].inangle) {
      p.second = idx++;
    }
  }
  return idx;
}

void build_graph(Graph &G) {
  for (int i = 0; i < n; i++) {
    for (auto [ang, src] : v[i].inangle) {
      for (int k = 0; k < v[i].m; k++) {
        if (!can_use_edge(i, ang, v[i].a[k])) continue;
        int dest_station = v[i].to[k];
        int dest = v[dest_station].find_match(i);
        G.add_edge(src, dest, v[i].t[k]);
      }
    }
  }
}

void dijkstra(const Graph &G, int src, vector<int> &D) {
  D.assign(G.num_nodes, -1);
  vector<bool> used(G.num_nodes, false);
  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push({0, src});
  D[src] = 0;
  while (!pq.empty()) {
    auto [dist, u] = pq.top();
    pq.pop();
    if (used[u]) continue;
    used[u] = true;
    for (auto &e : G.nbr[u]) {
      int v = e.to, w = dist + e.weight;
      if (D[v] == -1 || w < D[v]) {
        D[v] = w;
        pq.push({w, v});
      }
    }
  }
}

int main() {
  cin >> n >> d >> a1 >> a2;
  d--;
  for (int i = 0; i < n; i++) v[i].read();

  int num_nodes = process_inangle();
  Graph G(num_nodes);
  build_graph(G);

  int ans = INT_MAX;
  for (auto [ang_dest, dest_node] : v[d].inangle) {
    vector<int> D1, D2;
    dijkstra(G, v[0].inangle[0].second, D1);
    if (D1[dest_node] == -1) continue;
    dijkstra(G, dest_node, D2);
    for (auto [ang_src, src_node] : v[0].inangle) {
      if (D2[src_node] == -1) continue;
      ans = min(ans, D1[dest_node] + D2[src_node]);
    }
  }

  if (ans < INT_MAX)
    cout << ans << "\n";
  else
    cout << "impossible\n";
}
