#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to, weight, leavingAngle;
};  // weight can be double or other numeric type
typedef vector<Edge>::const_iterator EdgeIter;

struct Node {
  int weight, to, angle;
  bool operator>(const Node &other) const { return weight > other.weight; }
};

// Graph layout
//  -- Each problem has its own Edge structure.
// If you see "typedef int Edge;" at the top of an algorithm, change
//    vector<vector<Edge> > nbr; --->  vector<vector<int> > nbr;

struct Graph {
  vector<vector<Edge>> nbr;
  int num_nodes;
  Graph(int n) : nbr(n), num_nodes(n) {}

  void add_edge_directed(int u, int v, int weight, int leavingAngle) {
    Edge e = {v, weight, leavingAngle};
    nbr[u].push_back(e);
  }
};

// Get path from (src) to (v). Stored in path[0], .. ,path[k-1]
int get_path(int v, int P[], int path[]) {
  int k = 0;
  path[k++] = v;
  while (P[v] != -1) path[k++] = v = P[v];
  reverse(path, path + k);
  return k;
}

// Dijkstra's Algorithm [Dense Graphs] (Directed and Undirected) -- O(n^2)
//  -- Edge weight >= 0. May use get_path to obtain the path.

// Dijkstra's Algorithm [Sparse Graphs] (Directed and Undirected) --
// O((n+m)*log(n+m))
//  -- Edge weight >= 0.  May use get_path to obtain the path.

bool inRange(int angle, int a1, int a2) {
  int low = (angle - a2 + 360) % 360;
  int high = (angle + a1) % 360;

  if (low <= high) {
    return angle >= low && angle <= high;
  } else {
    return angle >= low || angle <= high;
  }
}

void dijkstra(const Graph &G, int src, vector<int> &D, vector<int> &P,
              vector<int> &A, vector<pair<int, int>> &ans, int destination,
              int a1, int a2) {
  typedef struct {
    int weight;
    int to;
    int angle;
  } pii;
  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<Node, vector<Node>, greater<Node>> fringe;

  D.resize(n);
  fill(D.begin(), D.end(), -1);
  P.resize(n);
  fill(P.begin(), P.end(), -1);
  A.resize(n);
  fill(A.begin(), A.end(), 0);

  D[src] = 0;

  for (auto &it : G.nbr[src]) {
    D[it.to] = it.weight;
    P[it.to] = src;
    A[it.to] = it.leavingAngle;
    fringe.push({it.weight, it.to, it.leavingAngle});
  }

  while (!fringe.empty()) {
    Node next = fringe.top();
    fringe.pop();
    int u = next.to;
    if (u == destination) {
      ans.push_back(make_pair(next.weight, next.angle));
    }
    if (used[u]) continue;
    used[u] = true;

    for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it) {
      int v = it->to, weight = it->weight + next.weight,
          angle = it->leavingAngle;

      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
        if (!inRange(angle, a1, a2)) continue;

        D[v] = weight;
        P[v] = u;
        A[v] = angle;

        fringe.push({D[v], v, A[v]});
      }
    }
  }
}

void dijkstra2(const Graph &G, int src, vector<int> &D, vector<int> &P,
               vector<int> &A, vector<pair<int, int>> &ans, int destination,
               int startWeight, int startAngle, int a1, int a2) {
  typedef struct {
    int weight;
    int to;
    int angle;
  } pii;
  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<Node, vector<Node>, greater<Node>> fringe;

  D.resize(n);
  fill(D.begin(), D.end(), -1);
  P.resize(n);
  fill(P.begin(), P.end(), -1);
  A.resize(n);
  fill(A.begin(), A.end(), 0);

  D[src] = 0;

  fringe.push({startWeight, src, startAngle});

  while (!fringe.empty()) {
    Node next = fringe.top();
    fringe.pop();
    int u = next.to;
    if (u == destination) {
      ans.push_back(make_pair(next.weight, next.angle));
    }
    if (used[u]) continue;
    used[u] = true;

    for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it) {
      int v = it->to, weight = it->weight + next.weight,
          angle = it->leavingAngle;

      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
        if (!inRange(angle, a1, a2)) continue;

        D[v] = weight;
        P[v] = u;
        A[v] = angle;

        fringe.push({D[v], v, A[v]});
      }
    }
  }
}

int main() {
  int n, d, a1, a2;
  cin >> n >> d >> a1 >> a2;
  vector<vector<Edge>> adjList(n + 1);
  vector<int> parent(n + 1), distance(n + 1), angle(n + 1);
  Graph G(n);

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int junct, tim, angle;
      Edge temp;
      cin >> temp.to >> temp.weight >> temp.leavingAngle;

      G.add_edge_directed(i, temp.to, temp.weight, temp.leavingAngle);
      adjList[i].push_back(temp);
    }
  }
  vector<pair<int, int>> reachedDest, backToSrc;
  dijkstra(G, 1, distance, parent, angle, reachedDest, d, a1, a2);
  if (reachedDest.size() == 0) {
    cout << "impossible" << endl;
    return 0;
  }
  for (auto &it : reachedDest) {
    dijkstra2(G, d, distance, parent, angle, backToSrc, 1, it.first, it.second,
              a1, a2);
    if (backToSrc.size() != 0) {
      cout << backToSrc[0].first << endl;
      return 0;
    }
  }
  cout << "impossible" << endl;
  return 0;
}