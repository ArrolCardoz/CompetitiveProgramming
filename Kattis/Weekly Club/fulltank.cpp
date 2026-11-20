#include <bits/stdc++.h>
using namespace std;
/*
I used dijkstra to get the SSSP, I could either write my own dijkstra so that we
can use a pair as the index or have an indexing system based on location and
fuel. Since the max capacity is only 100 and max vertices is 1000, we can work
with a single index since 1000*100 = 100'000 is not a lot.
The indexing is as explained in the Youtube video.
Graph:- The weights on the edges is only if we add fuel in the car(increment of
1) since we are minimizing the fule cost. So every location itself has maximum
of 100 vertices and depending on if we have enough fuel to enter the adjacent
vertices we connect them respectively.
Optimizations:
1.We can build the graph only once. And for the difference in capacity for every
query, if the next adjacent vertex has more fuel than the given capacity we do
not visit that vertex.
2.We can exit dijkstra early if we reached the destination: Since we only care
about the start to end destination and dijkstra finds the shortest path first.
*/
// indexing
int n;
int getIdx(int locationIdx, int fuel) { return locationIdx * 101 + fuel; }
int getLocationFromIdx(int idx) { return idx / 101; }
int getFuelFromIdx(int idx) { return idx % 101; }
/*
 * Dijkstra's Algorithm for sparse graphs
 *
 * Author: Howard Cheng
 *
 * Given a weight matrix representing a graph and a source vertex, this
 * algorithm computes the shortest distance, as well as path, to each
 * of the other vertices.  The paths are represented by an inverted list,
 * such that if v preceeds immediately before w in a path from the
 * source to vertex w, then the path P[w] is v.  The distances from
 * the source to v is given in D[v] (-1 if not connected).
 *
 * Call get_path to recover the path.
 *
 * Note: Dijkstra's algorithm only works if all weight edges are
 *       non-negative.
 *
 * This version works well if the graph is not dense.  The complexity
 * is O((n + m) log (n + m)) where n is the number of vertices and
 * m is the number of edges.
 *
 */
struct Edge {
  int to;
  int weight;  // can be double or other numeric type
  Edge(int t, int w) : to(t), weight(w) {}
};

typedef vector<Edge>::iterator EdgeIter;

struct Graph {
  vector<Edge>* nbr;
  int num_nodes;
  Graph(int n) : num_nodes(n) { nbr = new vector<Edge>[num_nodes]; }

  ~Graph() { delete[] nbr; }

  // note: There is no check on duplicate edge, so it is possible to
  // add multiple edges between two vertices
  //
  // If this is an undirected graph, be sure to add an edge both
  // ways
  void add_edge(int u, int v, int weight) { nbr[u].push_back(Edge(v, weight)); }
};

/* assume that D and P have been allocated */
int dijkstra(const Graph& G, int src, int end, vector<int>& D, int capacity) {
  typedef pair<int, int> pii;

  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<pii, vector<pii>, greater<pii> > fringe;

  D.resize(n);
  fill(D.begin(), D.end(), -1);
  int start = getIdx(src, 0);
  D[start] = 0;
  fringe.push(make_pair(D[start], start));

  while (!fringe.empty()) {
    pii next = fringe.top();
    fringe.pop();
    int u = next.second;
    if (end == getLocationFromIdx(u)) return next.first;
    if (used[u]) continue;
    used[u] = true;
    for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it) {
      int v = it->to;
      int weight = it->weight + next.first;
      int currCapacity = getFuelFromIdx(v);

      if (currCapacity > capacity) continue;
      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
        D[v] = weight;
        fringe.push(make_pair(D[v], v));
      }
    }
  }
  return -1;
}

void buildGraph(Graph& G, vector<int>& price) {
  int m, u, v, weight;
  cin >> m;
  // edge if you fill gas with the given weight
  for (int i = 0; i < n; i++) {
    cin >> price[i];
    int temp = 0;
    while (temp < 100) {
      int a = getIdx(i, temp);
      int b = getIdx(i, temp + 1);
      G.add_edge(a, b, price[i]);
      temp++;
    }
  }
  // edge if travel to new location
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> weight;
    int temp = 100;
    while (temp - weight >= 0) {
      int a1 = getIdx(u, temp);
      int b1 = getIdx(v, temp);
      int a2 = getIdx(u, temp - weight);
      int b2 = getIdx(v, temp - weight);
      G.add_edge(a1, b2, 0);
      G.add_edge(b1, a2, 0);
      temp--;
    }
  }
}

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  int numOfQueries, start, end, capacity, ans;
  cin >> n;
  vector<int> price(n, 0);
  Graph G(getIdx(n, 100));

  buildGraph(G, price);

  cin >> numOfQueries;
  while (numOfQueries--) {
    cin >> capacity >> start >> end;
    vector<int> D;
    ans = dijkstra(G, start, end, D, capacity);
    if (ans != -1)
      cout << ans << endl;
    else
      cout << "impossible" << endl;
  }

  return 0;
}
