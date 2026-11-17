#include <bits/stdc++.h>
using namespace std;
vector<int> A;
vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
int dr[] = {0, 1};
int dc[] = {1, 0};
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool dfs(string s, int r, int c, int idx) {
  if ((int)s.size() == idx + 1 && s[idx] - '0' == grid[r][c]) return true;
  bool ans = false;
  if (s[idx] - '0' == grid[r][c]) ans |= dfs(s, r, c, idx + 1);

  for (int i = 0; i < 2; i++) {
    int R = r + dr[i];
    int C = c + dc[i];
    if (R < 0 || R >= (int)grid.size()) continue;
    if (C < 0 || C >= (int)grid[0].size()) continue;
    if (grid[R][C] == -1) continue;
    ans |= dfs(s, R, C, idx);
  }
  return ans;
}
void compute() {
  A.reserve(200);
  for (int i = 1; i <= 200; i++) {
    if (dfs(to_string(i), 0, 0, 0)) {
      A.push_back(i);
    }
  }
}

int main() {
  fastIO();
  compute();
  int n;
  cin >> n;
  while (n--) {
    int i = 0;
    cin >> i;
    auto it = lower_bound(A.begin(), A.end(), i);
    // cout<<*it<< ' ' <<*(it-1)<<endl;

    if (i == *it)
      cout << i << endl;
    else {
      if (abs((*it) - i) < abs((*(it - 1)) - i))
        cout << *it << endl;
      else
        cout << *(it - 1) << endl;
    }
  }
  return 0;
}