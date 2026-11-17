/*
Solution: DFS solution discussed in the lab where we pre compute if a edge is
part of a ssc or not.

DFS:- Its a standard dfs except we need to unmark the visited table before we go
back to the parent recursion. This is important because we need to check for
cycles and so we have to unmark the edges if its not part of current recursion
tree. If it is we mark that a cycle/scc exists in the isSafe table.

After checking all the edges we print read the input and print if the city is
safe or not from the isSafe table.

Other notes:- City indexing is done through an unordered map, unordered since we
do not care about the order in this question.
idSafe also acts as a memo table so if its not -1 it means we have already
computed it earlier and do not need to compute it again.
 */
#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

vvi adjList;
vi visited, isSafe;
unordered_map<string, int> cityIdx;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int getID(const string& str) {
  if (cityIdx.find(str) == cityIdx.end()) cityIdx[str] = (int)cityIdx.size();
  return cityIdx[str];
}

void dfs(int row) {
  visited[row] = 1;  // mark
  vi& currList = adjList[row];
  for (int i = 0; i < (int)currList.size(); i++) {
    int r = currList[i];
    if (visited[r]) {  // cycle detected
      isSafe[row] = 1;
    } else if (isSafe[r] == -1) {  // compute
      dfs(r);
      if (isSafe[r] == 1) isSafe[row] = 1;
    } else if (isSafe[r] == 1) {
      isSafe[row] = 1;  // already computed
    }
  }
  visited[row] = 0;  // unmark
}

int main() {
  // initialize
  fastIO();
  int n;
  cin >> n;
  visited.resize(2 * n);
  isSafe.resize(2 * n);
  adjList.resize(2 * n);
  fill(isSafe.begin(), isSafe.end(), -1);

  // input
  while (n--) {
    string s1, s2;
    int idx1, idx2;
    cin >> s1 >> s2;
    idx1 = getID(s1);
    idx2 = getID(s2);
    adjList[idx1].push_back(idx2);
  }

  // precompute
  for (int i = 0; i < (int)cityIdx.size(); i++)
    if (isSafe[i] == -1) dfs(i);

  // print answer
  string city;
  while (cin >> city) {
    string ans =
        (cityIdx.find(city) != cityIdx.end() && isSafe[getID(city)] == 1)
            ? "safe"
            : "trapped";
    cout << city << ' ' << ans << endl;
  }

  return 0;
}