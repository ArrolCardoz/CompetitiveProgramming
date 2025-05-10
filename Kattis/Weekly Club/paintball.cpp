#include <bits/stdc++.h>
using namespace std;
bool backtrack(vector<pair<int, int>>& sizeSight, vector<vector<int>>& sight,
               vector<int>& visited, int idx, vector<int>& ans) {
  if (idx >= sight.size()) return true;
  int n = sizeSight[idx].second;
  for (auto& it : sight[n]) {
    if (!visited[it]) {
      visited[it] = 1;
      ans[idx] = it;

      //   cout << idx << endl;

      //   for (auto& it : ans) cout << it << endl;
      //   cout << endl;
      if (backtrack(sizeSight, sight, visited, idx + 1, ans)) return true;
      //   cout << "BACK" << endl;
      visited[it] = 0;
      ans[idx] = -1;
    }
  }

  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << "Impossible" << endl;
    return 0;
  }
  vector<pair<int, int>> sizeSight(n);
  vector<vector<int>> sight(n);
  vector<int> visited(n, 0);

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    sizeSight[a].first++;
    sizeSight[a].second = a;
    sight[a].push_back(b);

    sizeSight[b].first++;
    sizeSight[b].second = b;
    sight[b].push_back(a);
  }
  //   cout << "TEST" << endl;
  sort(sizeSight.begin(), sizeSight.end());
  //   cout << "TEST" << endl;
  vector<int> ans(n);
  if (backtrack(sizeSight, sight, visited, 0, ans))
    for (auto& it : ans) cout << it + 1 << endl;
  else
    cout << "Impossible" << endl;

  return 0;
}