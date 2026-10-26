#include <bits/stdc++.h>
using namespace std;

const int MAX_C = 2010;
const int MAX_N = 2010;

int memo[MAX_N][MAX_C];
int A[MAX_N];
int W[MAX_C];

int c, n;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int dp(int idx, int remW) {
  if (remW == 0 || idx == n) return 0;
  int& ans = memo[idx][remW];
  if (ans != -1) return ans;
  if (remW < W[idx]) return ans = dp(idx + 1, remW);
  return ans = max(A[idx] + dp(idx + 1, remW - W[idx]), dp(idx + 1, remW));
}
vector<int> reconstruct() {
  vector<int> picked;
  int remW = c;
  for (int idx = 0; idx < n && remW > 0; idx++) {
    if (remW >= W[idx] &&
        dp(idx, remW) == A[idx] + dp(idx + 1, remW - W[idx])) {
      picked.push_back(idx);
      remW -= W[idx];
    }
  }
  return picked;
}

bool solution() {
  memset(memo, -1, sizeof(memo));
  if (!(cin >> c >> n)) return false;
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> W[i];
  }
  vector<int> ans = reconstruct();
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << endl;

  return true;
}

int main() {
  fastIO();
  while (solution());
  return 0;
}