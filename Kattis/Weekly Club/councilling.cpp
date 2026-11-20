/*
Network flow problem implemented same idea as discussed in class
Implementation:-
The maximum number of clubs is not given in each case. So there can either be
all distinct clubs or even only a single club. The index I implemented was an
unorderedmap of string with its index (idxTable). I have everyone using the same
table for idx, but there is a problem when resident or party or club have the
same name. So for that I added a prefix "R:", "P:" and "C:" respectively. It is
not given what characters the name contains but adding ':' passed the final
case.
Once we build the table:
source -> club -> resident -> party -> sink
with party to sink edges having a weight limit as stated in the problem and
other having the weight 1. We check if the maximum flow is equal to the club
count (1-1 relation) and if its true check all the edges from club to resident
and if its used then print the name with the party.
*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int n;

/*
 * Network Flow
 *
 * Author: Howard Cheng
 *
 * The routine network_flow() finds the maximum flow that can be
 * pushed from the source (s) to the sink (t) in a flow network
 * (i.e. directed graph with capacities on the edges).  The maximum
 * flow is returned.  Note that the graph is modified.  If you wish to
 * recover the flow on an edge, it is in the "flow" field, as long as
 * is_real is set to true.
 *
 * Note: if you have an undirected network. simply call add_edge twice
 * with an edge in both directions (same capacity).  Note that 4 edges
 * will be added (2 real edges and 2 residual edges).  To discover the
 * actual flow between two vertices u and v, add up the flow of all
 * real edges from u to v and subtract all the flow of real edges from
 * v to u.  (In fact, for a residual edge the flow is always 0 in this
 * implementation.)
 *
 * This code can also be used for bipartite matching by setting up an
 * appropriate flow network.
 *
 * The code here assumes an adjacency list representation since most
 * problems requiring network flow have sparse graphs.
 *
 * This is the basic augmenting path algorithm and it is not the most
 * efficient.  But it should be good enough for most programming contest
 * problems.  The complexity is O(f m) where f is the size of the flow
 * and m is the number of edges.  This is good if you know that f
 * is small, but can be exponential if f is large.
 *
 */

struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge {
  int to;
  int cap;
  int flow;
  bool is_real;
  EdgeIter partner;

  Edge(int t, int c, bool real = true)
      : to(t), cap(c), flow(0), is_real(real) {};

  int residual() const { return cap - flow; }
};

struct Graph {
  list<Edge>* nbr;
  int num_nodes;
  Graph(int n) : num_nodes(n) { nbr = new list<Edge>[num_nodes]; }

  ~Graph() { delete[] nbr; }

  // note: this routine adds an edge to the graph with the specified capacity,
  // as well as a residual edge.  There is no check on duplicate edge, so it
  // is possible to add multiple edges (and residual edges) between two
  // vertices
  void add_edge(int u, int v, int cap) {
    nbr[u].push_front(Edge(v, cap));
    nbr[v].push_front(Edge(u, 0, false));
    nbr[v].begin()->partner = nbr[u].begin();
    nbr[u].begin()->partner = nbr[v].begin();
  }

  void get_ans(const unordered_set<int>& s,
               unordered_map<int, string>& idxTable) {
    for (auto& it : s) {
      for (auto& e : nbr[it]) {
        if (e.is_real && e.flow > 0)
          cout << idxTable[e.to] << ' ' << idxTable[it] << endl;
      }
    }
  }
};

void push_path(Graph& G, int s, int t, const vector<EdgeIter>& path, int flow) {
  for (int i = 0; s != t; i++) {
    if (path[i]->is_real) {
      path[i]->flow += flow;
      path[i]->partner->cap += flow;
    } else {
      path[i]->cap -= flow;
      path[i]->partner->flow -= flow;
    }
    s = path[i]->to;
  }
}

// the path is stored in a peculiar way for efficiency: path[i] is the
// i-th edge taken in the path.
int augmenting_path(const Graph& G, int s, int t, vector<EdgeIter>& path,
                    vector<bool>& visited, int step = 0) {
  if (s == t) {
    return -1;
  }
  for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
    int v = it->to;
    if (it->residual() > 0 && !visited[v]) {
      path[step] = it;
      visited[v] = true;
      int flow = augmenting_path(G, v, t, path, visited, step + 1);
      if (flow == -1) {
        return it->residual();
      } else if (flow > 0) {
        return min(flow, it->residual());
      }
    }
  }
  return 0;
}

// note that the graph is modified
int network_flow(Graph& G, int s, int t) {
  vector<bool> visited(G.num_nodes);
  vector<EdgeIter> path(G.num_nodes);
  int flow = 0, f;

  do {
    fill(visited.begin(), visited.end(), false);
    if ((f = augmenting_path(G, s, t, path, visited)) > 0) {
      push_path(G, s, t, path, f);
      flow += f;
    }
  } while (f > 0);

  return flow;
}

int getIdx(const string& str, unordered_map<string, int>& m) {
  auto it = m.find(str);
  if (it != m.end()) return it->second;
  int id = (int)m.size();
  m[str] = id;
  return id;
}

void fillGraph(vector<pii>& s, int w, Graph& G) {
  for (auto& [a, b] : s) {
    G.add_edge(a, b, w);
  }
}

void constructGraph(unordered_set<int>& clubIdxs, unordered_set<int>& partyIdxs,
                    vector<pii>& resToParty, vector<pii>& clubToRes, Graph& G) {
  int numClubs = (int)clubIdxs.size();
  int limit = (numClubs - 1) / 2;

  for (int c : clubIdxs) G.add_edge(0, c, 1);
  for (int p : partyIdxs) G.add_edge(p, 1, limit);
  fillGraph(clubToRes, 1, G);
  fillGraph(resToParty, 1, G);
}

void getInput(unordered_map<string, int>& idxTable,
              unordered_map<int, string>& rIdxTable,
              unordered_set<int>& clubIdxs, unordered_set<int>& partyIdxs,
              vector<pii>& resToParty, vector<pii>& clubToRes) {
  int m;
  string resident, party, club;

  for (int i = 0; i < n; i++) {
    cin >> resident >> party >> m;
    int resIdx = getIdx("R:" + resident, idxTable);
    int partyIdx = getIdx("P:" + party, idxTable);
    rIdxTable[resIdx] = resident;
    rIdxTable[partyIdx] = party;
    resToParty.emplace_back(resIdx, partyIdx);
    while (m--) {
      cin >> club;
      int clubIdx = getIdx("C:" + club, idxTable);

      clubIdxs.insert(clubIdx);
      rIdxTable[clubIdx] = club;
      clubToRes.emplace_back(clubIdx, resIdx);
    }

    partyIdxs.insert(partyIdx);
  }
}

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solution() {
  cin >> n;
  unordered_map<string, int> idxTable = {{"Source", 0}, {"Sink", 1}};
  unordered_map<int, string> rIdxTable = {{0, "Source"}, {1, "Sink"}};
  unordered_set<int> clubIdxs, partyIdxs;
  vector<pii> resToParty, clubToRes;
  resToParty.reserve(n);
  clubToRes.reserve(n);

  getInput(idxTable, rIdxTable, clubIdxs, partyIdxs, resToParty, clubToRes);

  Graph G((int)idxTable.size());

  constructGraph(clubIdxs, partyIdxs, resToParty, clubToRes, G);

  int ans = network_flow(G, 0, 1);
  if (ans == (int)clubIdxs.size())
    G.get_ans(clubIdxs, rIdxTable);
  else
    cout << "Impossible." << endl;
}

int main() {
  fastIO();
  int n;
  cin >> n;
  bool ok = false;
  while (n--) {
    if (ok) cout << endl;
    solution();
    ok = true;
  }
  return 0;
}