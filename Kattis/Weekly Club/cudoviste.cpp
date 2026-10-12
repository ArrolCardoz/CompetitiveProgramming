#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solution() {
  int r, c;
  cin >> r >> c;
  vector<string> A(r);
  vector<int> ans(5, 0);
  for (auto& it : A) cin >> it;
  int dx[] = {0, 0, -1, -1};
  int dy[] = {0, -1, -1, 0};

  for (int i = 1; i < (int)A.size(); i++) {
    for (int j = 1; j < (int)A[0].size(); j++) {
      int cars = 0;
      bool ok = true;
      for (int k = 0; k < 4; k++) {
        int r = i + dx[k];
        int c = j + dy[k];

        if (A[r][c] == '#') {
          ok = false;
          break;
        }
        if (A[r][c] == 'X') cars++;
      }
      if (ok) ans[cars]++;
    }
  }
  for (auto& it : ans) cout << it << endl;
}
int main() {
  fastIO();

  solution();
  return 0;
}