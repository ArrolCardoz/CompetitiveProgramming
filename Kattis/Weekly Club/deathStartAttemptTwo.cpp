#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(n));
  for (auto& r : mat) {
    for (auto& c : r) {
      cin >> c;
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[i] |= mat[i][j];
      ans[j] |= mat[i][j];
    }
  }

  for (auto& a : ans) cout << a << ' ';
  cout << endl;
  return 0;
}