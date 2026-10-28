#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;
const int MAX_W = 10005;
const int oo = 10005;
int A[MAX_N];
int memo[MAX_N][MAX_W];
int n;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int dp(int idx, int remW) {
  if (idx == n && remW != 0) return oo;  // base case return infinity
  if (remW == 0) return 0;               // base case return coins used

  int& ans = memo[idx][remW];
  if (ans != -1) return ans;                          // already computed
  if (remW < A[idx]) return ans = dp(idx + 1, remW);  // skip current coin
  return ans = min(dp(idx + 1, remW),
                   dp(idx + 1, remW - A[idx]) + 1);  // check both options
}

void solution() {
  int goal;
  memset(memo, -1, sizeof(memo));
  cin >> goal >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  while (true) {
    int ans = dp(0, goal);
    if (ans != oo) {
      cout << goal << ' ' << ans << endl;
      break;
    }
    goal++;
    assert(goal <= MAX_W);
  }
}
int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}